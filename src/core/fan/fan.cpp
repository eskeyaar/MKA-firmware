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
 * fan.cpp
 *
 * Copyright (C) 2017 Alberto Cotronei @MagoKimbra
 */

#include "../../../MK4duo.h"

#if FAN_COUNT > 0

  Fan fans[FAN_COUNT];

  /**
   * Initialize Fans
   */
  void Fan::init() {

    Speed               = 0;
    speed_nocorr		= 0;
    speed_correction 	= 0;
    paused_Speed        = 0;
    Kickstart           = 0;
    pwm_pos             = 0;
    lastpwm             = -1;
    triggerTemperatures = (HOTEND_AUTO_FAN_TEMPERATURE);

    setIdle(false);

    if (printer.isRunning()) return; // All running not reinitialize

    if (pin > 0) HAL::pinMode(pin, isHWInverted() ? OUTPUT_HIGH : OUTPUT_LOW);

  }

  void Fan::SetAutoMonitored(const int8_t h) {
    if (WITHIN(h, 0, HOTENDS - 1) || h == 7 || h == 8 || h == 9)
      autoMonitored = h;
    else      
      autoMonitored = -1;
    spin();
  }

  void Fan::spin() {

    static watch_t controller_fan_watch(CONTROLLERFAN_SECS * 1000UL);

    if (autoMonitored == -1) return;

    // Check for Hotend temperature
    LOOP_HOTEND() {
      if (autoMonitored==h) {
        if (heaters[h].current_temperature > triggerTemperatures) {
          Speed = HOTEND_AUTO_FAN_SPEED;
          break;
        }
        else
          Speed = HOTEND_AUTO_FAN_MIN_SPEED;
      }
    }

    // Check for Controller fan
    if (autoMonitored==7) {

      // Check Heaters
      if (thermalManager.heaters_isON()) controller_fan_watch.start();

      // Check Motors
      if (X_ENABLE_READ == X_ENABLE_ON || Y_ENABLE_READ == Y_ENABLE_ON || Z_ENABLE_READ == Z_ENABLE_ON
        || E0_ENABLE_READ == E_ENABLE_ON // If any of the drivers are enabled...
        #if DRIVER_EXTRUDERS > 1
          || E1_ENABLE_READ == E_ENABLE_ON
          #if HAS_X2_ENABLE
            || X2_ENABLE_READ == X_ENABLE_ON
          #endif
          #if DRIVER_EXTRUDERS > 2
            || E2_ENABLE_READ == E_ENABLE_ON
            #if DRIVER_EXTRUDERS > 3
              || E3_ENABLE_READ == E_ENABLE_ON
              #if DRIVER_EXTRUDERS > 4
                || E4_ENABLE_READ == E_ENABLE_ON
                #if DRIVER_EXTRUDERS > 5
                  || E5_ENABLE_READ == E_ENABLE_ON
                #endif
              #endif
            #endif
          #endif
        #endif
      ) {
        controller_fan_watch.start();
      }

      // Fan off if no steppers or heaters have been enabled for CONTROLLERFAN_SECS seconds
      Speed = controller_fan_watch.elapsed() ? CONTROLLERFAN_MIN_SPEED : CONTROLLERFAN_SPEED;
    }

    // Check for any hotend
    if (autoMonitored==8) {
    	Speed = HOTEND_AUTO_FAN_MIN_SPEED;
    	LOOP_HOTEND() {
            if (heaters[h].current_temperature > triggerTemperatures) {
              Speed = HOTEND_AUTO_FAN_SPEED;
              break;
            }
    	}
    }

    // Check for chamber
	#if HAS_HEATER_CHAMBER
		if (autoMonitored==9) {
			//Turned off
			if (Speed == CHAMBERFAN_MIN_SPEED)
			{
				if (heaters[CHAMBER_INDEX].current_temperature > CHAMBERFAN_TEMP3) Speed = CHAMBERFAN_SPEED3;
				else if (heaters[CHAMBER_INDEX].current_temperature > CHAMBERFAN_TEMP2) Speed = CHAMBERFAN_SPEED2;
				else if (heaters[CHAMBER_INDEX].current_temperature > CHAMBERFAN_TEMP1) Speed = CHAMBERFAN_SPEED1;
			}
			else if (Speed == CHAMBERFAN_SPEED1)
			{
				if (heaters[CHAMBER_INDEX].current_temperature > CHAMBERFAN_TEMP3) Speed = CHAMBERFAN_SPEED3;
				else if (heaters[CHAMBER_INDEX].current_temperature > CHAMBERFAN_TEMP2) Speed = CHAMBERFAN_SPEED2;
				else if (heaters[CHAMBER_INDEX].current_temperature < CHAMBERFAN_TEMP1 - CHAMBERFAN_HYSTERESIS) Speed = CHAMBERFAN_MIN_SPEED;
			}
			else if (Speed == CHAMBERFAN_SPEED2)
			{
				if (heaters[CHAMBER_INDEX].current_temperature > CHAMBERFAN_TEMP3) Speed = CHAMBERFAN_SPEED3;
				else if (heaters[CHAMBER_INDEX].current_temperature < CHAMBERFAN_TEMP1 - CHAMBERFAN_HYSTERESIS) Speed = CHAMBERFAN_MIN_SPEED;
				else if (heaters[CHAMBER_INDEX].current_temperature < CHAMBERFAN_TEMP2 - CHAMBERFAN_HYSTERESIS) Speed = CHAMBERFAN_SPEED1;
			}
			else if (Speed == CHAMBERFAN_SPEED3)
			{
				if (heaters[CHAMBER_INDEX].current_temperature < CHAMBERFAN_TEMP1 - CHAMBERFAN_HYSTERESIS) Speed = CHAMBERFAN_MIN_SPEED;
				else if (heaters[CHAMBER_INDEX].current_temperature < CHAMBERFAN_TEMP2 - CHAMBERFAN_HYSTERESIS) Speed = CHAMBERFAN_SPEED1;
				else if (heaters[CHAMBER_INDEX].current_temperature < CHAMBERFAN_TEMP3 - CHAMBERFAN_HYSTERESIS) Speed = CHAMBERFAN_SPEED2;
			}
		}
	#endif

  }

  #if HARDWARE_PWM
    void Fan::SetHardwarePwm() {
      if (pin > NoPin) {
        if (isHWInverted())
          pwm_pos = 255 - Speed;
        else
          pwm_pos = Speed;

        if (pwm_pos != lastpwm) {
          lastpwm = pwm_pos;
          if (freq>0)
        	  HAL::analogWrite(pin, pwm_pos, freq);
          else
        	  HAL::digitalWrite(pin, pwm_pos>127);
        }
      }
    }
  #endif

#endif // FAN_COUNT > 0
