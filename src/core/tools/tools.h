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
 * tools.h
 *
 * Copyright (C) 2017 Alberto Cotronei @MagoKimbra
 */

#ifndef _TOOLS_H_
#define _TOOLS_H_

#if EXTRUDERS > 0

#if ENABLED(EG6_EXTRUDER)
	struct ToolSwitchPos
	{
		float X,Y,Speed;
		bool SwitchMove;
	};
#endif


  class Tools {

    public: /** Constructor */

      Tools() {};

    public: /** Public Parameters */

      static uint8_t  active_extruder,
                      previous_extruder,
                      target_extruder,
					  target_driver;

      static int16_t  flow_percentage[DRIVER_EXTRUDERS],       // Extrusion factor for each extruder
                      density_percentage[DRIVER_EXTRUDERS];    // Extrusion density factor for each extruder
      static float    e_factor[DRIVER_EXTRUDERS];              // The flow percentage and volumetric multiplier combine to scale E movement

      #if ENABLED(VOLUMETRIC_EXTRUSION)
        static float  filament_size[DRIVER_EXTRUDERS],         // Diameter of filament (in millimeters), typically around 1.75 or 2.85, 0 disables the volumetric calculations for the tools.
                      volumetric_area_nominal,          // Nominal cross-sectional area
                      volumetric_multiplier[DRIVER_EXTRUDERS]; // Reciprocal of cross-sectional area of filament (in mm^2). Pre-calculated to reduce computation in the planner
                                                        // May be auto-adjusted by a filament width sensor
      #endif

      // Hotend offset
      static float    hotend_offset[XYZ][HOTENDS];
      static float    switch_offset_x;
      static float    switch_offset_y;

      static uint8_t   cut_servo_id;
      static uint8_t   cut_active_angle;
      static uint8_t   cut_neutral_angle;

      static bool fiber_is_cut;
      static bool printing_with_fiber;

	  #if ENABLED(EG6_EXTRUDER)
        static ToolSwitchPos hotend_switch_path[HOTENDS][CHANGE_MOVES];
        static float wipepark_return_position[XYZ];
        static bool parked_near_wipe;


	  #endif

      #if HAS_EXT_ENCODER
        static uint8_t  encLastSignal[DRIVER_EXTRUDERS];           // what was the last signal
        static int8_t   encLastDir[DRIVER_EXTRUDERS];
        static int32_t  encStepsSinceLastSignal[DRIVER_EXTRUDERS], // when was the last signal
                        encLastChangeAt[DRIVER_EXTRUDERS],
                        encErrorSteps[DRIVER_EXTRUDERS];
      #endif

      #if ENABLED(PID_ADD_EXTRUSION_RATE)
        static int lpq_len;
      #endif

    public: /** Public Function */

      static void cut_fiber();

      static void change(const uint8_t tmp_extruder, const float fr_mm_s=0.0, bool no_move=false, bool force=false, bool clean=false);

      static bool extruder_driver_is_plastic(const AxisEnum driver_extruder);
      static int8_t extruder_driver_to_extruder(uint8_t extruder_driver);
      static int8_t  plastic_driver_of_extruder(uint8_t e);

      FORCE_INLINE static void refresh_e_factor(const uint8_t e) {
        e_factor[e] =  (flow_percentage[e] * 0.01
          #if ENABLED(VOLUMETRIC_EXTRUSION)
            * volumetric_multiplier[e]
          #endif
        );
      }

	#if ENABLED(EG6_EXTRUDER)
      static void park_to_wipe();
      static void unpark_from_wipe();
	#endif

      #if ENABLED(VOLUMETRIC_EXTRUSION)

        static void calculate_volumetric_multipliers();

        FORCE_INLINE static void set_filament_size(const uint8_t e, const float &v) {
          filament_size[e] = v;
          // make sure all extruders have some sane value for the filament size
          for (uint8_t i = 0; i < COUNT(filament_size); i++)
            if (!filament_size[i]) filament_size[i] = DEFAULT_NOMINAL_FILAMENT_DIA;
        }

      #endif

      #if ENABLED(EXT_SOLENOID)
        static void enable_solenoid(const uint8_t e);
        static void enable_solenoid_on_active_extruder();
        static void disable_all_solenoids();
      #endif

    private: /** Private Function */

      static void invalid_extruder_error(const uint8_t e);

      #if ENABLED(VOLUMETRIC_EXTRUSION)
        static float calculate_volumetric_multiplier(const float diameter);
      #endif

      #if HAS_MKMULTI_TOOLS
        static void MK_multi_tool_change(const uint8_t e);
      #endif

      #if HAS_DONDOLO
        static void move_extruder_servo(const uint8_t e);
      #endif

      #if ENABLED(COLOR_MIXING_EXTRUDER) && MIXING_VIRTUAL_TOOLS > 1
        static void mixing_tool_change(const uint8_t tmp_extruder);
      #endif

      #if ENABLED(DUAL_X_CARRIAGE)
        static void dualx_tool_change(const uint8_t tmp_extruder, bool &no_move);
      #endif

  };

  extern Tools tools;

#endif

#endif /* _TOOLS_H_ */
