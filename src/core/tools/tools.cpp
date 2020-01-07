/**
 * MK4duo Firmware for 3D Printer, Laser and CNC
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (C) 2013 Alberto Cotronei @MagoKimbra
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * tools.cpp
 *
 * Copyright (C) 2017 Alberto Cotronei @MagoKimbra
 */

#include "../../../MK4duo.h"

#if EXTRUDERS > 0

  Tools tools;

  uint8_t Tools::active_extruder    = 0,
          Tools::previous_extruder  = 0,
          Tools::target_extruder    = 0,
  	  	  Tools::target_driver      = 0;

  int16_t Tools::flow_percentage[DRIVER_EXTRUDERS]       = ARRAY_BY_EXTRUDERS(100),
          Tools::density_percentage[DRIVER_EXTRUDERS]    = ARRAY_BY_EXTRUDERS(100);
  float   Tools::e_factor[DRIVER_EXTRUDERS]              = ARRAY_BY_EXTRUDERS(1.0);
  
  #if ENABLED(VOLUMETRIC_EXTRUSION)
    float Tools::filament_size[DRIVER_EXTRUDERS]         = ARRAY_BY_EXTRUDERS(DEFAULT_NOMINAL_FILAMENT_DIA),
          Tools::volumetric_area_nominal          = CIRCLE_AREA((DEFAULT_NOMINAL_FILAMENT_DIA) * 0.5),
          Tools::volumetric_multiplier[DRIVER_EXTRUDERS] = ARRAY_BY_EXTRUDERS(1.0);
  #endif

  float   Tools::hotend_offset[XYZ][HOTENDS] = { 0.0 };

  float   Tools::switch_offset_x = 0;
  float   Tools::switch_offset_y = 0;

  uint8_t   Tools::cut_servo_id = 0;
  uint8_t   Tools::cut_neutral_angle = 0;
  uint8_t   Tools::cut_active_angle = 0;

  bool Tools::fiber_is_cut = true;
  bool Tools::printing_with_fiber = false;

#if ENABLED(EG6_EXTRUDER)
  ToolSwitchPos Tools::hotend_switch_path[HOTENDS][CHANGE_MOVES] = {0.0, 0.0, 0.0, false};
  float Tools::wipepark_return_position[XYZ] = {0, 0, 0};
  bool Tools::parked_near_wipe = false;
#endif

  #if HAS_EXT_ENCODER
    uint8_t Tools::encLastSignal[DRIVER_EXTRUDERS]           = ARRAY_BY_EXTRUDERS(0);
    int8_t  Tools::encLastDir[DRIVER_EXTRUDERS]              = ARRAY_BY_EXTRUDERS(1);
    int32_t Tools::encStepsSinceLastSignal[DRIVER_EXTRUDERS] = ARRAY_BY_EXTRUDERS(0),
            Tools::encLastChangeAt[DRIVER_EXTRUDERS]         = ARRAY_BY_EXTRUDERS(0),
            Tools::encErrorSteps[DRIVER_EXTRUDERS]           = ARRAY_BY_EXTRUDERS(ENC_ERROR_STEPS);
  #endif

  #if ENABLED(PID_ADD_EXTRUSION_RATE)
    int Tools::lpq_len = 20;
  #endif

  void Tools::change(const uint8_t tmp_extruder, const float fr_mm_s/*=0.0*/, bool no_move/*=false*/, bool force /*=false*/, bool clean /*=false*/) {

    #if ENABLED(COLOR_MIXING_EXTRUDER) && MIXING_VIRTUAL_TOOLS > 1

      mixing_tool_change(tmp_extruder);

    #else // !MIXING_EXTRUDER || MIXING_VIRTUAL_TOOLS <= 1

      if (tmp_extruder >= EXTRUDERS)
        return invalid_extruder_error(tmp_extruder);

      #if HOTENDS > 1

        const float old_feedrate_mm_s = fr_mm_s > 0.0 ? fr_mm_s : mechanics.feedrate_mm_s;

        mechanics.feedrate_mm_s = fr_mm_s > 0.0 ? fr_mm_s : XY_PROBE_FEEDRATE_MM_S;

        if ((tmp_extruder != active_extruder) || force) {
          if (!no_move) {
        	 if (mechanics.axis_unhomed_error())
        	 {
                 SERIAL_EM("Homing before toolchange");
                 mechanics.home(true, true, true);
        	 }

          }
          // Save current position to mechanics.destination, for use later
          mechanics.set_destination_to_current();

          #if HAS_LEVELING
            // Set current position to the physical position
            const bool leveling_was_active = bedlevel.leveling_active;
            bedlevel.set_bed_leveling_enabled(false);
          #endif

          #if ENABLED(DUAL_X_CARRIAGE)

            dualx_tool_change(tmp_extruder, no_move); // Can modify no_move

          #else // !DUAL_X_CARRIAGE

            #if HAS_DONDOLO
              // Always raise by at least 1 to avoid workpiece
              const float z_diff  = hotend_offset[Z_AXIS][active_extruder] - hotend_offset[Z_AXIS][tmp_extruder];
              mechanics.current_position[Z_AXIS] += (z_diff > 0.0 ? z_diff : 0.0) + 1;
              planner.buffer_line_kinematic(mechanics.current_position, mechanics.max_feedrate_mm_s[Z_AXIS], active_extruder);
              stepper.synchronize();
              move_extruder_servo(tmp_extruder);
            #endif

            const float x_diff = hotend_offset[X_AXIS][tmp_extruder] - hotend_offset[X_AXIS][active_extruder],
                        y_diff = hotend_offset[Y_AXIS][tmp_extruder] - hotend_offset[Y_AXIS][active_extruder],
            			z_diff = hotend_offset[Z_AXIS][tmp_extruder] - hotend_offset[Z_AXIS][active_extruder];

            #if ENABLED(DEBUG_LEVELING_FEATURE)
              if (printer.debugLeveling()) {
                SERIAL_MV("Offset Tool XY by { ", x_diff);
                SERIAL_MV(", ", y_diff);
                SERIAL_EM(" }");
              }
            #endif

             //Serial.println("Before toolchange");
              //Serial.println(mechanics.current_position[Z_AXIS]);

            // The newly-selected extruder XYZ is actually at...
            mechanics.current_position[X_AXIS] += x_diff;
            mechanics.current_position[Y_AXIS] += y_diff;
            mechanics.current_position[Z_AXIS] += z_diff;

            // Set the new active extruder
            previous_extruder = active_extruder;
            #if ENABLED(DONDOLO_SINGLE_MOTOR)
              active_extruder = tmp_extruder;
              active_driver = 0;
            #else
              active_extruder = tmp_extruder;
            #endif

          #endif // !DUAL_X_CARRIAGE

          #if HAS_LEVELING
            // Restore leveling to re-establish the logical position
            bedlevel.set_bed_leveling_enabled(leveling_was_active);
          #endif

          #if HAS_DONDOLO
            mechanics.current_position[Z_AXIS] -= zdiff;
          #endif

          // Tell the planner the new "current position"
          mechanics.sync_plan_position_mech_specific();

          #if ENABLED(DELTA)
            const bool safe_to_move = mechanics.current_position[Z_AXIS] < mechanics.delta_clip_start_height - 1;
          #else
            constexpr bool safe_to_move = true;
          #endif

          //Serial.println("After toolchange");
          //Serial.println(mechanics.current_position[Z_AXIS]);
          //Serial.println(mechanics.destination[Z_AXIS]);
          //Serial.println(endstops.soft_endstop_max[Z_AXIS]);

          // Raise, move, and lower again
          if (safe_to_move && !no_move && printer.isRunning()) {
            #if !HAS_DONDOLO
              // Do a small lift to avoid the workpiece in the move back (below)
        	  float additional_z_lift = 1.5;
			  if (mechanics.destination[Z_AXIS]+additional_z_lift>(endstops.soft_endstop_max[Z_AXIS])) additional_z_lift = 0;

        	  if (mechanics.destination[Z_AXIS]>mechanics.current_position[Z_AXIS])
        	  {
        		  mechanics.do_blocking_move_to_z(mechanics.destination[Z_AXIS]+additional_z_lift, mechanics.max_feedrate_mm_s[Z_AXIS]);
        	  }
        	  else
        	  {
        		  mechanics.do_blocking_move_to_z(mechanics.current_position[Z_AXIS]+additional_z_lift, mechanics.max_feedrate_mm_s[Z_AXIS]);
        	  }
            #endif
            #if ENABLED(DEBUG_LEVELING_FEATURE)
              if (printer.debugLeveling()) DEBUG_POS("Move back", mechanics.destination);
            #endif
            // Move back to the original (or tweaked) position

            #if ENABLED(EG6_EXTRUDER)
              	float x_target, y_target;
                //Making moves to physically switch extruder
                for (uint8_t i=0; i<CHANGE_MOVES; i++)
                {
                	if (hotend_switch_path[active_extruder][i].Speed>0 && (hotend_switch_path[active_extruder][i].SwitchMove || clean))
                	{
                		x_target = hotend_switch_path[active_extruder][i].SwitchMove ? hotend_switch_path[active_extruder][i].X + tools.switch_offset_x : hotend_switch_path[active_extruder][i].X;
                		y_target = hotend_switch_path[active_extruder][i].SwitchMove ? hotend_switch_path[active_extruder][i].Y + tools.switch_offset_y : hotend_switch_path[active_extruder][i].Y;
						mechanics.do_blocking_move_to(
								Mechanics::homeCS2toolCS(active_extruder, x_target, AxisEnum::X_AXIS),
								Mechanics::homeCS2toolCS(active_extruder, y_target, AxisEnum::Y_AXIS),
								mechanics.current_position[Z_AXIS],
								hotend_switch_path[active_extruder][i].Speed);
                	}
                }

                //Returning to original position
                if (parked_near_wipe)
                {
                	unpark_from_wipe();
                	//mechanics.set_current_to_destination();
                }
                else
                {
    				mechanics.do_blocking_move_to(mechanics.destination[X_AXIS], mechanics.destination[Y_AXIS], mechanics.current_position[Z_AXIS]);
    				mechanics.do_blocking_move_to_z(mechanics.destination[Z_AXIS], mechanics.max_feedrate_mm_s[Z_AXIS]);
                }


			#else
				mechanics.do_blocking_move_to(mechanics.destination[X_AXIS], mechanics.destination[Y_AXIS], mechanics.destination[Z_AXIS]);
			#endif

          }
          #if HAS_DONDOLO
            else {
              // Move back down. (Including when the new tool is higher.)
              mechanics.do_blocking_move_to_z(destination[Z_AXIS], planner.max_feedrate_mm_s[Z_AXIS]);
            }
          #endif



        } // (tmp_extruder != active_extruder)




        stepper.synchronize();

        #if ENABLED(EXT_SOLENOID)
          disable_all_solenoids();
          enable_solenoid_on_active_extruder();
        #endif

        mechanics.feedrate_mm_s = old_feedrate_mm_s;

      #else // HOTENDS <= 1

        UNUSED(fr_mm_s);
        UNUSED(no_move);

        #if HAS_MKMULTI_TOOLS
          MK_multi_tool_change(tmp_extruder);
        #else
          // Set the new active extruder
          previous_extruder = active_extruder;
          active_extruder = tmp_extruder;
        #endif

      #endif // HOTENDS <= 1

      SERIAL_LMV(ECHO, MSG_ACTIVE_EXTRUDER, (int)active_extruder);

    #endif // !MIXING_EXTRUDER || MIXING_VIRTUAL_TOOLS <= 1
  }
  
  #if ENABLED(EXT_SOLENOID)

    void Tools::enable_solenoid(const uint8_t e) {
      switch(e) {
        case 0:
          OUT_WRITE(SOL0_PIN, HIGH);
          break;
          #if HAS_SOLENOID_1 && EXTRUDERS > 1
            case 1:
              OUT_WRITE(SOL1_PIN, HIGH);
              break;
          #endif
          #if HAS_SOLENOID_2 && EXTRUDERS > 2
            case 2:
              OUT_WRITE(SOL2_PIN, HIGH);
              break;
          #endif
          #if HAS_SOLENOID_3 && EXTRUDERS > 3
            case 3:
              OUT_WRITE(SOL3_PIN, HIGH);
              break;
          #endif
          #if HAS_SOLENOID_4 && EXTRUDERS > 4
            case 4:
              OUT_WRITE(SOL4_PIN, HIGH);
              break;
          #endif
          #if HAS_SOLENOID_5 && EXTRUDERS > 5
            case 5:
              OUT_WRITE(SOL5_PIN, HIGH);
              break;
          #endif
        default:
          SERIAL_LM(ER, MSG_INVALID_SOLENOID);
          break;
      }
    }

    void Tools::enable_solenoid_on_active_extruder() { enable_solenoid(active_extruder); }

    void Tools::disable_all_solenoids() {
      OUT_WRITE(SOL0_PIN, LOW);
      #if HAS_SOLENOID_1 && EXTRUDERS > 1
        OUT_WRITE(SOL1_PIN, LOW);
      #endif
      #if HAS_SOLENOID_2 && EXTRUDERS > 2
        OUT_WRITE(SOL2_PIN, LOW);
      #endif
      #if HAS_SOLENOID_3 && EXTRUDERS > 3
        OUT_WRITE(SOL3_PIN, LOW);
      #endif
      #if HAS_SOLENOID_4 && EXTRUDERS > 4
        OUT_WRITE(SOL4_PIN, LOW);
      #endif
      #if HAS_SOLENOID_5 && EXTRUDERS > 5
        OUT_WRITE(SOL5_PIN, LOW);
      #endif
    }

  #endif

  void Tools::invalid_extruder_error(const uint8_t e) {
    SERIAL_SMV(ER, "T", (int)e);
    SERIAL_EM(" " MSG_INVALID_EXTRUDER);
}

bool Tools::extruder_driver_is_plastic(const AxisEnum driver_extruder) {
	const uint8_t plastic_extruders[] = PLASTIC_DRIVER_EXTRUDERS;
	if (driver_extruder > NUM_AXIS) return 0;
	return (plastic_extruders[driver_extruder-E_AXIS] == 1);
}

int8_t Tools::extruder_driver_to_extruder(uint8_t extruder_driver) {
	const uint8_t hotends[] = DRIVER_EXTRUDERS_HOTENDS;
	if (extruder_driver<DRIVER_EXTRUDERS)
	{
		return hotends[extruder_driver];
	}
	return -1;
}

int8_t Tools::plastic_driver_of_extruder(uint8_t e) {
	const uint8_t extruders[] = DRIVER_EXTRUDERS_HOTENDS;
	const uint8_t plastic_extruders[] = PLASTIC_DRIVER_EXTRUDERS;
	LOOP_EXTRUDERS(drv_ext)
	{
		if (extruders[drv_ext]==e && plastic_extruders[drv_ext] == 1)
		{
			return drv_ext;
		}
	}
    SERIAL_SMV(ER, "T", (int)e);
    SERIAL_EM(" " MSG_INVALID_EXTRUDER);
	return -1;
}

void Tools::cut_fiber() {
	stepper.synchronize();
    MOVE_SERVO(cut_servo_id, cut_active_angle);
    MOVE_SERVO(cut_servo_id, cut_neutral_angle);
    fiber_is_cut = true;
}

#if ENABLED(EG6_EXTRUDER)

void Tools::park_to_wipe() {

	wipepark_return_position[X_AXIS] = mechanics.current_position[X_AXIS];
	wipepark_return_position[Y_AXIS] = mechanics.current_position[Y_AXIS];
	wipepark_return_position[Z_AXIS] = mechanics.current_position[Z_AXIS];

	stepper.synchronize();
	float x_target, y_target;
	uint8_t next_extruder = 0;
	if (active_extruder==0) next_extruder = 1;
	if (hotend_switch_path[next_extruder][0].Speed>0)
	{
		mechanics.do_blocking_move_to_xy(
				Mechanics::homeCS2toolCS(active_extruder, hotend_switch_path[next_extruder][0].X, AxisEnum::X_AXIS),
				Mechanics::homeCS2toolCS(active_extruder, hotend_switch_path[next_extruder][0].Y, AxisEnum::Y_AXIS),
				hotend_switch_path[next_extruder][0].Speed);
		parked_near_wipe = true;
	}
}

void Tools::unpark_from_wipe() {
	if (parked_near_wipe)
	{
		stepper.synchronize();
		float x_target, y_target;
		uint8_t next_extruder = 0;
		if (active_extruder==0) next_extruder = 1;
		if (hotend_switch_path[next_extruder][0].Speed>0)
		{
			mechanics.do_blocking_move_to_xy(
					wipepark_return_position[X_AXIS],
					wipepark_return_position[Y_AXIS],
					hotend_switch_path[next_extruder][0].Speed);
			mechanics.do_blocking_move_to_z(wipepark_return_position[Z_AXIS], mechanics.max_feedrate_mm_s[Z_AXIS]);
			parked_near_wipe = false;
		}
	}
}

#endif

  #if ENABLED(VOLUMETRIC_EXTRUSION)

    /**
     * Get a volumetric multiplier from a filament diameter.
     * This is the reciprocal of the circular cross-section area.
     * Return 1.0 with volumetric off or a diameter of 0.0.
     */
    float Tools::calculate_volumetric_multiplier(const float diameter) {
      if (!printer.isVolumetric() || diameter == 0) return 1.0;
      return 1.0 / CIRCLE_AREA(diameter * 0.5);
    }

    /**
     * Convert the filament sizes into volumetric multipliers.
     * The multiplier converts a given E value into a length.
     */
    void Tools::calculate_volumetric_multipliers() {
      for (uint8_t e = 0; e < EXTRUDERS; e++) {
        volumetric_multiplier[e] = calculate_volumetric_multiplier(filament_size[e]);
        refresh_e_factor(e);
      }
    }

  #endif // ENABLED(VOLUMETRIC_EXTRUSION)

  #if ENABLED(MKSE6)

    void Tools::MK_multi_tool_change(const uint8_t e) {

      stepper.synchronize(); // Finish all movement

      const int angles[EXTRUDERS] = ARRAY_BY_EXTRUDERS_N (
        MKSE6_SERVOPOS_E0, MKSE6_SERVOPOS_E1,
        MKSE6_SERVOPOS_E2, MKSE6_SERVOPOS_E3,
        MKSE6_SERVOPOS_E4, MKSE6_SERVOPOS_E5
      );
      MOVE_SERVO(MKSE6_SERVO_INDEX, angles[e]);

      #if (MKSE6_SERVO_DELAY > 0)
        printer.safe_delay(MKSE6_SERVO_DELAY);
      #endif

      // Set the new active extruder
      previous_extruder = active_extruder;
      active_extruder = e;
      active_driver = 0;
    }

  #elif ENABLED(MKR4)

    void Tools::MK_multi_tool_change(const uint8_t e) {

      stepper.synchronize(); // Finish all movement
      stepper.disable_e_steppers();

      #if (EXTRUDERS == 4) && HAS_E0E2 && HAS_E1E3 && (DRIVER_EXTRUDERS == 2)

        switch(e) {
          case 0:
            WRITE_RELE(E0E2_CHOICE_PIN, LOW);
            WRITE_RELE(E1E3_CHOICE_PIN, LOW);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          case 1:
            WRITE_RELE(E0E2_CHOICE_PIN, LOW);
            WRITE_RELE(E1E3_CHOICE_PIN, LOW);
            active_driver = 1;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E1();
            break;
          case 2:
            WRITE_RELE(E0E2_CHOICE_PIN, HIGH);
            WRITE_RELE(E1E3_CHOICE_PIN, LOW);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E2();
            break;
          case 3:
            WRITE_RELE(E0E2_CHOICE_PIN, LOW);
            WRITE_RELE(E1E3_CHOICE_PIN, HIGH);
            active_driver = 1;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E3();
            break;
        }

      #elif (EXTRUDERS == 3) && HAS_E0E2 && (DRIVER_EXTRUDERS == 2)

        switch(e) {
          case 0:
            WRITE_RELE(E0E2_CHOICE_PIN, LOW);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          case 1:
            WRITE_RELE(E0E2_CHOICE_PIN, LOW);
            active_driver = 1;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E1();
            break;
          case 2:
            WRITE_RELE(E0E2_CHOICE_PIN, HIGH);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
        }

      #elif (EXTRUDERS == 2) && HAS_E0E1 && (DRIVER_EXTRUDERS == 1)

        switch(e) {
          case 0:
            WRITE_RELE(E0E1_CHOICE_PIN, LOW);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          case 1:
            WRITE_RELE(E0E1_CHOICE_PIN, HIGH);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
        }

      #endif // E0E1_CHOICE_PIN E0E2_CHOICE_PIN E1E3_CHOICE_PIN

      // Set the new active extruder
      previous_extruder = active_extruder;
      active_extruder = e;
    }

  #elif ENABLED(MKR6) || ENABLED(MKR12)

    void Tools::MK_multi_tool_change(const uint8_t e) {

      stepper.synchronize(); // Finish all movement
      stepper.disable_e_steppers();

      #if (EXTRUDERS == 2) && HAS_EX1 && (DRIVER_EXTRUDERS == 1)

        switch(e) {
          case 0:
            WRITE_RELE(EX1_CHOICE_PIN, LOW);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          case 1:
            WRITE_RELE(EX1_CHOICE_PIN, HIGH);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
        }

      #elif (EXTRUDERS == 3) && HAS_EX1 && HAS_EX2 && (DRIVER_EXTRUDERS == 1)

        switch(e) {
          case 0:
            WRITE_RELE(EX1_CHOICE_PIN, LOW);
            WRITE_RELE(EX2_CHOICE_PIN, LOW);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          case 1:
            WRITE_RELE(EX1_CHOICE_PIN, HIGH);
            WRITE_RELE(EX2_CHOICE_PIN, LOW);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          case 2:
            WRITE_RELE(EX1_CHOICE_PIN, HIGH);
            WRITE_RELE(EX2_CHOICE_PIN, HIGH);
            active_driver = 0;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
        }

      #elif (EXTRUDERS > 3) && HAS_EX1 && HAS_EX2

        uint8_t multiply = e, driver;

        for (driver = 0; driver < DRIVER_EXTRUDERS; driver++) {
          if (multiply < 3) break;
          multiply -= 3;
        }

        switch(multiply) {
          case 0:
            WRITE_RELE(EX1_CHOICE_PIN, LOW);
            WRITE_RELE(EX2_CHOICE_PIN, LOW);
            active_driver = driver;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          case 1:
            WRITE_RELE(EX1_CHOICE_PIN, HIGH);
            WRITE_RELE(EX2_CHOICE_PIN, LOW);
            active_driver = driver;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          case 2:
            WRITE_RELE(EX1_CHOICE_PIN, HIGH);
            WRITE_RELE(EX2_CHOICE_PIN, HIGH);
            active_driver = driver;
            printer.safe_delay(500); // 500 microseconds delay for relay
            enable_E0();
            break;
          default:
            SERIAL_LM(ER, "More Driver Extruders");
            break;
        }

      #endif

      // Set the new active extruder
      previous_extruder = active_extruder;
      active_extruder = e;
    }

  #endif

  #if HAS_DONDOLO

    void Tools::move_extruder_servo(const uint8_t e) {
      constexpr int16_t angles[] = { DONDOLO_SERVOPOS_E0, DONDOLO_SERVOPOS_E1 };
      stepper.synchronize();
      MOVE_SERVO(DONDOLO_SERVO_INDEX, angles[e]);
      #if (DONDOLO_SERVO_DELAY > 0)
        printer.safe_delay(DONDOLO_SERVO_DELAY);
      #endif
    }

  #endif

  #if ENABLED(MIXING_EXTRUDER) && MIXING_VIRTUAL_TOOLS > 1

    void Tools::mixing_tool_change(const uint8_t tmp_extruder) {
      if (tmp_extruder >= MIXING_VIRTUAL_TOOLS)
        return invalid_extruder_error(tmp_extruder);

      // T0-Tnnn: Switch virtual tool by changing the mix
      for (uint8_t j = 0; j < MIXING_STEPPERS; j++)
        mixing_factor[j] = mixing_virtual_tool_mix[tmp_extruder][j];

      SERIAL_EMV(MSG_ACTIVE_COLOR, (int)tmp_extruder);
    }

  #endif

  #if ENABLED(DUAL_X_CARRIAGE)

    void Tools::dualx_tool_change(const uint8_t tmp_extruder, bool &no_move) {
      #if ENABLED(DEBUG_LEVELING_FEATURE)
        if (printer.debugLeveling()) {
          SERIAL_MSG("Dual X Carriage Mode ");
          switch (mechanics.dual_x_carriage_mode) {
            case DXC_DUPLICATION_MODE: SERIAL_EM("DXC_DUPLICATION_MODE"); break;
            case DXC_AUTO_PARK_MODE: SERIAL_EM("DXC_AUTO_PARK_MODE"); break;
            case DXC_FULL_CONTROL_MODE: SERIAL_EM("DXC_FULL_CONTROL_MODE"); break;
          }
        }
      #endif

      const float xhome = mechanics.x_home_pos(active_extruder);
      if (mechanics.dual_x_carriage_mode == DXC_AUTO_PARK_MODE
          && printer.isRunning()
          && (mechanics.delayed_move_time || mechanics.current_position[X_AXIS] != xhome)
      ) {
        float raised_z = mechanics.current_position[Z_AXIS] + TOOLCHANGE_PARK_ZLIFT;
        #if ENABLED(MAX_SOFTWARE_ENDSTOPS)
          NOMORE(raised_z, endstops.soft_endstop_max[Z_AXIS]);
        #endif
        #if ENABLED(DEBUG_LEVELING_FEATURE)
          if (printer.debugLeveling()) {
            SERIAL_EMV("Raise to ", raised_z);
            SERIAL_EMV("MoveX to ", xhome);
            SERIAL_EMV("Lower to ", mechanics.current_position[Z_AXIS]);
          }
        #endif
        // Park old head: 1) raise 2) move to park position 3) lower
        for (uint8_t i = 0; i < 3; i++)
          planner.buffer_line(
            i == 0 ? mechanics.current_position[X_AXIS] : xhome,
            mechanics.current_position[Y_AXIS],
            i == 2 ? mechanics.current_position[Z_AXIS] : raised_z,
            mechanics.current_position[E_AXIS],
            mechanics.max_feedrate_mm_s[i == 1 ? X_AXIS : Z_AXIS],
            active_extruder
          );
        stepper.synchronize();
      }

      // apply Y & Z extruder offset (x offset is already used in determining home pos)
      mechanics.current_position[Y_AXIS] -= hotend_offset[Y_AXIS][active_extruder] - hotend_offset[Y_AXIS][tmp_extruder];
      mechanics.current_position[Z_AXIS] -= hotend_offset[Z_AXIS][active_extruder] - hotend_offset[Z_AXIS][tmp_extruder];

      // Activate the new extruder
      active_extruder = active_driver = tmp_extruder;

      // This function resets the max/min values - the current position may be overwritten below.
      mechanics.set_axis_is_at_home(X_AXIS);

      #if ENABLED(DEBUG_LEVELING_FEATURE)
        if (printer.debugLeveling()) DEBUG_POS("New Extruder", mechanics.current_position);
      #endif

      // Only when auto-parking are carriages safe to move
      if (mechanics.dual_x_carriage_mode != DXC_AUTO_PARK_MODE) no_move = true;

      switch (mechanics.dual_x_carriage_mode) {
        case DXC_FULL_CONTROL_MODE:
          // New current position is the position of the activated hotend
          mechanics.current_position[X_AXIS] = mechanics.inactive_hotend_x_pos;
          // Save the inactive hotend's position (from the old mechanics.current_position)
          mechanics.inactive_hotend_x_pos = mechanics.destination[X_AXIS];
          break;
        case DXC_AUTO_PARK_MODE:
          // record raised toolhead position for use by unpark
          COPY_ARRAY(mechanics.raised_parked_position, mechanics.current_position);
          mechanics.raised_parked_position[Z_AXIS] += TOOLCHANGE_UNPARK_ZLIFT;
          #if ENABLED(MAX_SOFTWARE_ENDSTOPS)
            NOMORE(mechanics.raised_parked_position[Z_AXIS], endstops.soft_endstop_max[Z_AXIS]);
          #endif
          mechanics.active_hotend_parked = true;
          mechanics.delayed_move_time = 0;
          break;
        case DXC_DUPLICATION_MODE:
          // If the new hotend is the left one, set it "parked"
          // This triggers the second hotend to move into the duplication position
          mechanics.active_hotend_parked = (active_extruder == 0);

          if (mechanics.active_hotend_parked)
            mechanics.current_position[X_AXIS] = mechanics.inactive_hotend_x_pos;
          else
            mechanics.current_position[X_AXIS] = mechanics.destination[X_AXIS] + mechanics.duplicate_hotend_x_offset;
          mechanics.inactive_hotend_x_pos = mechanics.destination[X_AXIS];
          mechanics.hotend_duplication_enabled = false;
          #if ENABLED(DEBUG_LEVELING_FEATURE)
            if (printer.debugLeveling()) {
              SERIAL_EMV("Set inactive_hotend_x_pos=", mechanics.inactive_hotend_x_pos);
              SERIAL_EM("Clear hotend_duplication_enabled");
            }
          #endif
          break;
      }

      #if ENABLED(DEBUG_LEVELING_FEATURE)
        if (printer.debugLeveling()) {
          SERIAL_EMV("Active hotend parked: ", mechanics.active_hotend_parked ? "yes" : "no");
          DEBUG_POS("New hotend (parked)", mechanics.current_position);
        }
      #endif
    }

  #endif // DUAL_X_CARRIAGE

#endif // EXTRUDERS > 0
