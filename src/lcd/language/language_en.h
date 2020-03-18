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
 * English
 *
 * LCD Menu Messages
 *
 */
#ifndef LANGUAGE_EN_H
#define LANGUAGE_EN_H

#define en 1234
#if LCD_LANGUAGE == en
  #define NOT_EXTENDED_ISO10646_1_5X7
#endif
#undef en

#ifndef CHARSIZE
  #define CHARSIZE 1
#endif

#ifndef MSG_PRINTER_FULL_NAME
  #define MSG_PRINTER_FULL_NAME                   _UxGT("Anisoprint %s v%s")
#endif

#ifndef MSG_UPDATING_FIRMWARE
  #define MSG_UPDATING_FIRMWARE                   _UxGT("Updating firmware...")
#endif

#ifndef MSG_DO_NOT_TURN_OFF
  #define MSG_DO_NOT_TURN_OFF                     _UxGT("Please do not turn off your printer")
#endif



#ifndef MSG_YES
  #define MSG_YES                           	  _UxGT("Yes")
#endif

#ifndef MSG_NO
  #define MSG_NO                             	  _UxGT("No")
#endif

#ifndef MSG_OK
  #define MSG_OK                             	  _UxGT("OK")
#endif

#ifndef MSG_CANCEL
  #define MSG_CANCEL                              _UxGT("Cancel")
#endif

#ifndef MSG_REPEAT
  #define MSG_REPEAT                              _UxGT("Repeat")
#endif

#ifndef MSG_RETRY
  #define MSG_RETRY                               _UxGT("Retry")
#endif

#ifndef MSG_NEXT
  #define MSG_NEXT                                _UxGT("Next")
#endif

#ifndef MSG_FINISH
  #define MSG_FINISH                              _UxGT("Finish")
#endif

#ifndef MSG_COMPOSITE
  #define MSG_COMPOSITE                           _UxGT("Composite")
#endif

#ifndef MSG_PLASTIC
  #define MSG_PLASTIC                             _UxGT("Plastic")
#endif

#ifndef MSG_PLEASE_WAIT
  #define MSG_PLEASE_WAIT                         _UxGT("Please wait...")
#endif


#ifndef MSG_COMPOSITE_EXTRUDER_TEMP
  #define MSG_COMPOSITE_EXTRUDER_TEMP             _UxGT("Composite extruder temperature")
#endif

#ifndef MSG_PLASTIC_EXTRUDER_TEMP
  #define MSG_PLASTIC_EXTRUDER_TEMP               _UxGT("Plastic extruder temperature")
#endif

#ifndef MSG_BUILDPLATE_TEMP
  #define MSG_BUILDPLATE_TEMP                     _UxGT("Build plate temperature")
#endif

#ifndef MSG_BUILDPLATE_HEATING
  #define MSG_BUILDPLATE_HEATING                    _UxGT("Build plate heating (%d/%d\370C)")
#endif

#ifndef MSG_COMPOSITE_EXTRUDER_HEATING
  #define MSG_COMPOSITE_EXTRUDER_HEATING            _UxGT("Composite extruder heating (%d/%d\370C)")
#endif

#ifndef MSG_PLASTIC_EXTRUDER_HEATING
  #define MSG_PLASTIC_EXTRUDER_HEATING              _UxGT("Plastic extruder heating (%d/%d\370C)")
#endif

#ifndef MSG_PRINTING_TIME
  #define MSG_PRINTING_TIME              			_UxGT("Time elapsed: %s\\rEst. time left: %s")
#endif

#ifndef MSG_LAYER_NUMBER
  #define MSG_LAYER_NUMBER              			_UxGT("Layer: %d/%d - %d%%")
#endif

#ifndef MSG_PLASTIC_FLOW_H
  #define MSG_PLASTIC_FLOW_H                 _UxGT("Plastic flow")
#endif

#ifndef MSG_PLASTIC_FLOW
  #define MSG_PLASTIC_FLOW              	_UxGT("Plastic flow (%)")
#endif

#ifndef MSG_COMP_PLASTIC_FLOW
  #define MSG_COMP_PLASTIC_FLOW              _UxGT("Composite plastic flow (%)")
#endif

#ifndef MSG_TEMPERATURE_CORRECTION_H
  #define MSG_TEMPERATURE_CORRECTION_H              _UxGT("Temperature correction")
#endif

#ifndef MSG_FAN_CORRECTION_H
  #define MSG_FAN_CORRECTION_H              		_UxGT("Fan correction")
#endif

#ifndef MSG_FANCOR_NOZZLE
  #define MSG_FANCOR_NOZZLE            				_UxGT("Part cooling correction (%)")
#endif

#ifndef MSG_TEMPCOR_PLASTIC
  #define MSG_TEMPCOR_PLASTIC            			_UxGT("Plastic temp. correction (\370C)")
#endif

#ifndef MSG_TEMPCOR_COMPOSITE
  #define MSG_TEMPCOR_COMPOSITE            			_UxGT("Composite temp. correction (\370C)")
#endif

#ifndef MSG_TEMPCOR_BP
  #define MSG_TEMPCOR_BP            				_UxGT("Buildplate temp. correction (\370C)")
#endif

#ifndef MSG_PRINTING
  #define MSG_PRINTING              				_UxGT("Printing...")
#endif

#ifndef MSG_PAUSED
  #define MSG_PAUSED              					_UxGT("Paused")
#endif

#ifndef MSG_CONFIRM_CANCEL_PRINTING
  #define MSG_CONFIRM_CANCEL_PRINTING              	_UxGT("Do you really want to cancel printing?")
#endif

#ifndef MSG_CANCEL_PRINTING
  #define MSG_CANCEL_PRINTING              			_UxGT("Cancel printing")
#endif

#ifndef MSG_READING_SD
  #define MSG_READING_SD              				_UxGT("Reading SD card...")
#endif

#ifndef MSG_NO_SD
  #define MSG_NO_SD              					_UxGT("No SD card found")
#endif

#ifndef MSG_LONG_FILENAME
  #define MSG_LONG_FILENAME              			_UxGT("File name is too long. Please use name which is shorter than 50 characters.")
#endif

#ifndef MSG_FILE_MODIFIED_DATE
  #define MSG_FILE_MODIFIED_DATE              		_UxGT("Modified: %.2i.%.2i.%.4i %.2i:%.2i")
#endif

#ifndef MSG_PLASTIC_CONS
  #define MSG_PLASTIC_CONS              			_UxGT("%s (%.1f g)")
#endif

#ifndef MSG_FIBER_CONS
  #define MSG_FIBER_CONS              				_UxGT("%s (%.1f m)")
#endif

#ifndef MSG_FILE_PRINT_TIME
  #define MSG_FILE_PRINT_TIME              			_UxGT("Print time: %s")
#endif

#ifndef MSG_DONE
  #define MSG_DONE             						_UxGT("DONE!")
#endif

#ifndef MSG_ERROR
  #define MSG_ERROR             					_UxGT("Error")
#endif

#ifndef MSG_WARNING
  #define MSG_WARNING             					_UxGT("Warning")
#endif

#ifndef MSG_FINISHED
  #define MSG_FINISHED             					_UxGT("Finished")
#endif

#ifndef MSG_PRINT_AGAIN
  #define MSG_PRINT_AGAIN                           _UxGT("Print again")
#endif

#ifndef MSG_PAUSE
  #define MSG_PAUSE                           		_UxGT("Pause")
#endif

#ifndef MSG_CANCEL_PAUSE
  #define MSG_CANCEL_PAUSE                    		_UxGT("Cancel pause")
#endif

#ifndef MSG_CANCELLING
  #define MSG_CANCELLING                    		_UxGT("Canceling...")
#endif

#ifndef MSG_RESUME
  #define MSG_RESUME                           		_UxGT("Resume")
#endif

#ifndef MSG_PAUSING
  #define MSG_PAUSING                           	_UxGT("Pausing...")
#endif

#ifndef MSG_RESUMING
  #define MSG_RESUMING                           	_UxGT("Resuming...")
#endif

#ifndef MSG_MAINTENANCE
  #define MSG_MAINTENANCE                           _UxGT("Maintenance")
#endif

#ifndef MSG_CONTROL
  #define MSG_CONTROL                           	_UxGT("Control")
#endif

#ifndef MSG_CALIBRATE
  #define MSG_CALIBRATE                     		_UxGT("Calibrate")
#endif

#ifndef MSG_CALIBRATE_PRINTHEAD
  #define MSG_CALIBRATE_PRINTHEAD                   _UxGT("Calibrate printhead")
#endif

#ifndef MSG_COMP_Z_OFFSET
  #define MSG_COMP_Z_OFFSET                   		_UxGT("Comp. Z-offset")
#endif

#ifndef MSG_MOVE
  #define MSG_MOVE                    				_UxGT("Move")
#endif

#ifndef MSG_TEMPERATURE
  #define MSG_TEMPERATURE                    		_UxGT("Temperature")
#endif

#ifndef MSG_MATERIALS
  #define MSG_MATERIALS                     		_UxGT("Materials")
#endif

#ifndef MSG_COMP_PLASTIC
  #define MSG_COMP_PLASTIC                     		_UxGT("Comp.plastic")
#endif

#ifndef MSG_COMP_FIBER
  #define MSG_COMP_FIBER                     		_UxGT("Comp.fiber")
#endif

#ifndef MSG_LOAD
  #define MSG_LOAD                   				_UxGT("Load")
#endif

#ifndef MSG_UNLOAD
  #define MSG_UNLOAD                   				_UxGT("Unload")
#endif

#ifndef MSG_BUILD_PLATE
  #define MSG_BUILD_PLATE                    		_UxGT("Buildplate")
#endif

#ifndef MSG_PRINTHEAD
  #define MSG_PRINTHEAD                   			_UxGT("Printhead")
#endif

#ifndef MSG_SETTINGS
  #define MSG_SETTINGS                     			_UxGT("Settings")
#endif

#ifndef MSG_DINFO
  #define MSG_DINFO                     			_UxGT("Debug info")
#endif

#ifndef MSG_ABOUT_PRINTER
  #define MSG_ABOUT_PRINTER                     	_UxGT("About printer")
#endif

#ifndef MSG_Z_AXIS
  #define MSG_Z_AXIS                    			_UxGT("Z axis")
#endif

#ifndef MSG_CANCEL_PRINT
  #define MSG_CANCEL_PRINT                    		_UxGT("Cancel print")
#endif

#ifndef MSG_TUNE
  #define MSG_TUNE                    				_UxGT("Tune")
#endif

#ifndef MSG_CORRECT_Z
  #define MSG_CORRECT_Z                    			_UxGT("Correct Z")
#endif

#ifndef RESTART_TO_CONTINUE
  #define RESTART_TO_CONTINUE                     	_UxGT("To reset printer please turn it off")
#endif

#ifndef MSG_HEADER_Z_OFFSET
  #define MSG_HEADER_Z_OFFSET                    	_UxGT("Z axis calibration")
#endif

#ifndef MSG_HEADER_COMP_Z_OFFSET
  #define MSG_HEADER_COMP_Z_OFFSET                    _UxGT("Composite Z offset calibration")
#endif

#ifndef MSG_HEADER_UNLOAD_MATERIAL
  #define MSG_HEADER_UNLOAD_MATERIAL                _UxGT(" unloading")
#endif

#ifndef MSG_UNLOAD_MATERIAL_ST1
  #define MSG_UNLOAD_MATERIAL_ST1                   _UxGT("To start the material unloading procedure,\\rplease press Next and set the printhead\\rtemperature, as the printhead should be\\rheated for material unloading.")
#endif

#ifndef MSG_UNLOAD_MATERIAL_ST2
  #define MSG_UNLOAD_MATERIAL_ST2                   _UxGT("Please wait while printhead is heating for\\rmaterial unloading (%d/%d\370C)\\rUnloading will be performed automatically\\rafter that.")
#endif

#ifndef MSG_UNLOAD_MATERIAL_ST2A
  #define MSG_UNLOAD_MATERIAL_ST2A                  _UxGT("The current printhead temperature is too low\\rto perform the material unloading procedure,\\rplease press Next and set new printhead\\rtemperature.\\r")
#endif

#ifndef MSG_UNLOAD_MATERIAL_ST3
  #define MSG_UNLOAD_MATERIAL_ST3               	_UxGT("Unloading material, please wait...")
#endif

#ifndef MSG_UNLOAD_MATERIAL_ST4
  #define MSG_UNLOAD_MATERIAL_ST4                   _UxGT("Material unloading complete. Please remove\\rthe excessive material from the nozzle with\\rtwizzers or pliers\\r")
#endif

#ifndef MSG_HEADER_LOAD_MATERIAL
  #define MSG_HEADER_LOAD_MATERIAL                  _UxGT(" loading")
#endif

#ifndef MSG_LOAD_MATERIAL_ST1
  #define MSG_LOAD_MATERIAL_ST1                    	_UxGT("To start the material loading procedure,\\rplease press Next and set the printhead\\rtemperature, as the printhead should be\\rheated for material loading.")
#endif

#ifndef MSG_LOAD_MATERIAL_ST2
  #define MSG_LOAD_MATERIAL_ST2                    	_UxGT("Please wait while printhead is heating for\\rmaterial loading (%d/%d\370C)")
#endif

#ifndef MSG_LOAD_MATERIAL_ST2A
  #define MSG_LOAD_MATERIAL_ST2A                    _UxGT("The current printhead temperature is too low\\rto perform the material loading procedure,\\rplease press Next and set new printhead\\rtemperature.\\r")
#endif

#ifndef MSG_LOAD_MATERIAL_ST3
  #define MSG_LOAD_MATERIAL_ST3                    	_UxGT("Push new material into the feeder on the\\rrear of your Composer and press Next.")
#endif

#ifndef MSG_LOAD_MATERIAL_ST3_TIMEOUT
  #define MSG_LOAD_MATERIAL_ST3_TIMEOUT             _UxGT("Printer was waiting for too long and\\rmaterial loading wizard was stopped.\\rTo restart the loading process please\\rpress Repeat.")
#endif

#ifndef MSG_LOAD_MATERIAL_ST4
  #define MSG_LOAD_MATERIAL_ST4                    	_UxGT("Loading material...")
#endif

#ifndef MSG_LOAD_MATERIAL_ST5
  #define MSG_LOAD_MATERIAL_ST5                    	_UxGT("When material exits from the nozzle press\\rNext")
#endif

#ifndef MSG_LOAD_MATERIAL_ST5_TIMEOUT
  #define MSG_LOAD_MATERIAL_ST5_TIMEOUT             _UxGT("Printer was waiting for too long and\\rmaterial loading wizard was stopped.\\rIf the material didn't come out of the\\rnozzle, please check that material passed\\rsuccessfully through the feeder and the\\rnozzle isn't clogged.")
#endif

#ifndef MSG_LOAD_MATERIAL_ST6
  #define MSG_LOAD_MATERIAL_ST6                    	_UxGT("Material loading complete. Please remove the\\rexcessive material from the nozzle with\\rtwizzers or pliers\\r")
#endif

#ifndef MSG_Z_OFFSET_ST1
  #define MSG_Z_OFFSET_ST1                    		_UxGT("To adjust Z axis zero you will need a sheet\\rof 80gsm paper.\\r\\rPlease be careful during the process. Do not\\rlift the build plate too much or too fast to\\ravoid collision with the printhead, which can\\rdamage your printer.")
#endif

#ifndef MSG_Z_OFFSET_ST2
  #define MSG_Z_OFFSET_ST2                    		_UxGT("Slide a paper between the buildplate and the\\rnozzle. Move the buildplate with the buttons\\rbelow until you feel some friction while\\rsliding the paper.")
#endif

#ifndef MSG_COMP_Z_OFFSET_ST1
  #define MSG_COMP_Z_OFFSET_ST1                    	_UxGT("To adjust composite nozzle Z-offset you will\\rneed a sheet of 80gsm paper.\\r\\rPlease be careful during the process. Do not\\rlift the build plate too much or too fast to\\ravoid collision with the printhead.")
#endif

#ifndef MSG_HEADER_BP_CALIBR
  #define MSG_HEADER_BP_CALIBR                    	_UxGT("Build plate calibration")
#endif

#ifndef MSG_BP_CALIBR_ST1
  #define MSG_BP_CALIBR_ST1                    		_UxGT("To calibrate the buildplate you will need a\\rsheet of 80gsm paper.\\r\\rPlease be careful during the process. Do not\\rlift the buildplate too much or too fast to\\ravoid collision with the printhead, which can\\rdamage your printer.")
#endif

#ifndef MSG_BP_CALIBR_ST2
  #define MSG_BP_CALIBR_ST2                    		_UxGT("If buildplate adjustment thumbscrews are in\\rmininum or maximum positions, please tighten\\ror loosen the screws, setting them to middle\\rpositions.\\r")
#endif

#ifndef MSG_BP_CALIBR_ST3
  #define MSG_BP_CALIBR_ST3                    		_UxGT("Move the buildplate with the buttons below\\runtil the nozzle is a millimeter away from\\rthe buildplate.")
#endif

#ifndef MSG_BP_CALIBR_ST4
  #define MSG_BP_CALIBR_ST4                    		_UxGT("Turn the left buildplate screw until the\\rnozzle is a millimeter away from the\\rbuildplate.")
#endif

#ifndef MSG_BP_CALIBR_ST5
  #define MSG_BP_CALIBR_ST5                    		_UxGT("Turn the right buildplate screw until the\\rnozzle is a millimeter away from the\\rbuildplate.")
#endif

#ifndef MSG_BP_CALIBR_ST6
  #define MSG_BP_CALIBR_ST6                    		_UxGT("Repeat the calibration process, but now use\\ra sheet of 80gsm paper to fine-tune the\\rbuildplate level.")
#endif

#ifndef MSG_BP_CALIBR_ST7
  #define MSG_BP_CALIBR_ST7                    		_UxGT("Slide a paper between the buildplate and the\\rnozzle. Turn the central screw or move the\\rbuildplate with the buttons below until you\\rfeel some friction while sliding the paper.")
#endif

#ifndef MSG_BP_CALIBR_ST8
  #define MSG_BP_CALIBR_ST8                    		_UxGT("Turn the left screw until you feel some\\rfriction while sliding the paper between\\rthe nozzle and the buildplate.")
#endif

#ifndef MSG_BP_CALIBR_ST9
  #define MSG_BP_CALIBR_ST9                    		_UxGT("Repeat this for the right corner.")
#endif

#ifndef MSG_HEADER_Z_BABYSTEP
  #define MSG_HEADER_Z_BABYSTEP                    	_UxGT("Z axis correction")
#endif

#ifndef MSG_Z_BABYSTEP
  #define MSG_Z_BABYSTEP                   			_UxGT("If your first layer appears to be too thick\\ror too thin you can move the buildplate with\\rthe buttons below to correct Z axis\\rcalibration (max. correction is 1 mm).")
#endif

#ifndef MSG_PAUSE_DURING_FIBER
  #define MSG_PAUSE_DURING_FIBER                    _UxGT("Print can't be paused during fiber\\rprinting. Pause will be made after the\\rcurrent fiber reinforced path.")
#endif

#ifndef MSG_WAITING_FOR_PAUSE
  #define MSG_WAITING_FOR_PAUSE                    _UxGT("Waiting for pause...")
#endif

#ifndef MSG_COLD_HOTEND
  #define MSG_COLD_HOTEND                    		_UxGT("Hotend is cold")
#endif

#ifndef MSG_COLD_HOTEND_TEXT
  #define MSG_COLD_HOTEND_TEXT                    	_UxGT("Please heat the hotend before extruding or\\rretracting the filament")
#endif

#ifndef MSG_INCORRECT_INPUT
  #define MSG_INCORRECT_INPUT                    	_UxGT("Incorrect input")
#endif

#ifndef MSG_INPUT_BOUNDS
  #define MSG_INPUT_BOUNDS                    	_UxGT("The value should be between %.2f and %.2f")
#endif

#ifndef MSG_DEBUG_INFO
  #define MSG_DEBUG_INFO                 		_UxGT("X:%.2f Y:%.2f Z:%.2f\\rE:%.2f U:%.2f V:%.2f T%d\\rT0:%.2f/%d T1:%.2f/%d\\rTB:%.2f/%d TC:%.2f\\rF0:%d F1:%d F2:%d\\rXe:%d Ye:%d Ze:%d")
#endif

//Settings
#ifndef MSG_COMP_EXTRUDER
  #define MSG_COMP_EXTRUDER                  _UxGT("Composite extruder offset")
#endif

#ifndef MSG_X_OFFSET
  #define MSG_X_OFFSET                  		_UxGT("X offset (mm)")
#endif

#ifndef MSG_Y_OFFSET
  #define MSG_Y_OFFSET                  		_UxGT("Y offset (mm)")
#endif

#ifndef MSG_Z_OFFSET
  #define MSG_Z_OFFSET                  		_UxGT("Z offset (mm)")
#endif

#ifndef MSG_FEEDERS_STEPS
  #define MSG_FEEDERS_STEPS                  _UxGT("Feeders steps per mm")
#endif

#ifndef MSG_PID_COEFFICIENTS
  #define MSG_PID_COEFFICIENTS               _UxGT("PID Coefficients")
#endif

#ifndef MSG_PLASTIC_P
  #define MSG_PLASTIC_P                  	 _UxGT("Plastic P")
#endif

#ifndef MSG_PLASTIC_I
  #define MSG_PLASTIC_I                  	 _UxGT("Plastic I")
#endif

#ifndef MSG_PLASTIC_D
  #define MSG_PLASTIC_D                  	 _UxGT("Plastic D")
#endif

#ifndef MSG_COMPOSITE_P
  #define MSG_COMPOSITE_P                  	 _UxGT("Composite P")
#endif

#ifndef MSG_COMPOSITE_I
  #define MSG_COMPOSITE_I                  	 _UxGT("Composite I")
#endif

#ifndef MSG_COMPOSITE_D
  #define MSG_COMPOSITE_D                  	 _UxGT("Composite D")
#endif

#ifndef MSG_BUILDPLATE_P
  #define MSG_BUILDPLATE_P                   _UxGT("Buildplate P")
#endif

#ifndef MSG_BUILDPLATE_I
  #define MSG_BUILDPLATE_I                   _UxGT("Buildplate I")
#endif

#ifndef MSG_BUILDPLATE_D
  #define MSG_BUILDPLATE_D                   _UxGT("Buildplate D")
#endif

#ifndef MSG_MOVEMENT_FEEDRATE
  #define MSG_MOVEMENT_FEEDRATE              _UxGT("Movement feedrate")
#endif

#ifndef MSG_FEEDRATE
  #define MSG_FEEDRATE              		_UxGT("Feedrate (%)")
#endif

// EEPROM ERRORS
#ifndef MSG_EEPROM_FAIL_READ_SYSTEM
  #define MSG_EEPROM_FAIL_READ_SYSTEM         "Failed to read System Config from EEPROM.\\rPlease try to update printer firmware.\\rIf the error persists, please contact\\rSupport"
#endif

#ifndef MSG_EEPROM_FAIL_WRITE_SYSTEM
  #define MSG_EEPROM_FAIL_WRITE_SYSTEM        "Failed to write System Config to EEPROM.\\rPlease try to update printer firmware.\\rIf the error persists, please contact\\rSupport"
#endif

#ifndef MSG_EEPROM_FAIL_READ_USER
  #define MSG_EEPROM_FAIL_READ_USER           "Failed to read User Config from EEPROM.\\rDefault settings were loaded. Buildpate and\\rprinthead re-calibration may be needed.\\rIf the error persists, please contact\\rSupport"
#endif

#ifndef MSG_EEPROM_FAIL_WRITE_USER
  #define MSG_EEPROM_FAIL_WRITE_USER          "Failed to save User Config to EEPROM.\\rPlease reset the printer and try again.\\rIf the error persists, please contact\\rSupport"
#endif





#ifndef WELCOME_MSG
  #define WELCOME_MSG                         MACHINE_NAME _UxGT(" ready")
#endif
#ifndef MSG_BACK
  #define MSG_BACK                            _UxGT("Back")
#endif
#ifndef MSG_SD_INSERTED
  #define MSG_SD_INSERTED                     _UxGT("Card inserted")
#endif
#ifndef MSG_SD_REMOVED
  #define MSG_SD_REMOVED                      _UxGT("Card removed")
#endif
#ifndef MSG_LCD_ENDSTOPS
  #define MSG_LCD_ENDSTOPS                    _UxGT("Endstops") // Max length 8 characters
#endif
#ifndef MSG_LCD_SOFT_ENDSTOPS
  #define MSG_LCD_SOFT_ENDSTOPS               _UxGT("Soft Endstops")
#endif
#ifndef MSG_MAIN
  #define MSG_MAIN                            _UxGT("Main")
#endif
#ifndef MSG_AUTOSTART
  #define MSG_AUTOSTART                       _UxGT("Autostart")
#endif
#ifndef MSG_DISABLE_STEPPERS
  #define MSG_DISABLE_STEPPERS                _UxGT("Disable steppers")
#endif
#ifndef MSG_DEBUG_MENU
  #define MSG_DEBUG_MENU                      _UxGT("Debug Menu")
#endif
#ifndef MSG_PROGRESS_BAR_TEST
  #define MSG_PROGRESS_BAR_TEST               _UxGT("Progress Bar Test")
#endif
#ifndef MSG_AUTO_HOME
  #define MSG_AUTO_HOME                       _UxGT("Auto home")
#endif
#ifndef MSG_AUTO_HOME_X
  #define MSG_AUTO_HOME_X                     _UxGT("Home X")
#endif
#ifndef MSG_AUTO_HOME_Y
  #define MSG_AUTO_HOME_Y                     _UxGT("Home Y")
#endif
#ifndef MSG_AUTO_HOME_Z
  #define MSG_AUTO_HOME_Z                     _UxGT("Home Z")
#endif
#ifndef MSG_LEVEL_BED_HOMING
  #define MSG_LEVEL_BED_HOMING                _UxGT("Homing XYZ")
#endif
#ifndef MSG_LEVEL_BED_WAITING
  #define MSG_LEVEL_BED_WAITING               _UxGT("Click to Begin")
#endif
#ifndef MSG_LEVEL_BED_NEXT_POINT
  #define MSG_LEVEL_BED_NEXT_POINT            _UxGT("Next Point")
#endif
#ifndef MSG_LEVEL_BED_DONE
  #define MSG_LEVEL_BED_DONE                  _UxGT("Leveling Done!")
#endif
#ifndef MSG_Z_FADE_HEIGHT
  #define MSG_Z_FADE_HEIGHT                   _UxGT("Fade Height")
#endif
#ifndef MSG_SET_HOME_OFFSETS
  #define MSG_SET_HOME_OFFSETS                _UxGT("Set home offsets")
#endif
#ifndef MSG_HOME_OFFSETS_APPLIED
  #define MSG_HOME_OFFSETS_APPLIED            _UxGT("Offsets applied")
#endif
#ifndef MSG_SET_ORIGIN
  #define MSG_SET_ORIGIN                      _UxGT("Set origin")
#endif
#ifndef MSG_PREHEAT_1
  #define MSG_PREHEAT_1                       _UxGT("Preheat PLA")
#endif
#ifndef MSG_PREHEAT_1_N
  #define MSG_PREHEAT_1_N                     MSG_PREHEAT_1 _UxGT(" ")
#endif
#ifndef MSG_PREHEAT_1_ALL
  #define MSG_PREHEAT_1_ALL                   MSG_PREHEAT_1 _UxGT(" All")
#endif
#ifndef MSG_PREHEAT_1_END
  #define MSG_PREHEAT_1_END                   MSG_PREHEAT_1 _UxGT(" End")
#endif
#ifndef MSG_PREHEAT_1_BEDONLY
  #define MSG_PREHEAT_1_BEDONLY               MSG_PREHEAT_1 _UxGT(" Bed")
#endif
#ifndef MSG_PREHEAT_1_SETTINGS
  #define MSG_PREHEAT_1_SETTINGS              MSG_PREHEAT_1 _UxGT(" conf")
#endif
#ifndef MSG_PREHEAT_2
  #define MSG_PREHEAT_2                       _UxGT("Preheat ABS")
#endif
#ifndef MSG_PREHEAT_2_N
  #define MSG_PREHEAT_2_N                     MSG_PREHEAT_2 _UxGT(" ")
#endif
#ifndef MSG_PREHEAT_2_ALL
  #define MSG_PREHEAT_2_ALL                   MSG_PREHEAT_2 _UxGT(" All")
#endif
#ifndef MSG_PREHEAT_2_END
  #define MSG_PREHEAT_2_END                   MSG_PREHEAT_2 _UxGT(" End")
#endif
#ifndef MSG_PREHEAT_2_BEDONLY
  #define MSG_PREHEAT_2_BEDONLY               MSG_PREHEAT_2 _UxGT(" Bed")
#endif
#ifndef MSG_PREHEAT_2_SETTINGS
  #define MSG_PREHEAT_2_SETTINGS              MSG_PREHEAT_2 _UxGT(" conf")
#endif
#ifndef MSG_PREHEAT_3
  #define MSG_PREHEAT_3                       _UxGT("Preheat GUM")
#endif
#ifndef MSG_PREHEAT_3_N
  #define MSG_PREHEAT_3_N                     MSG_PREHEAT_3 _UxGT(" ")
#endif
#ifndef MSG_PREHEAT_3_ALL
  #define MSG_PREHEAT_3_ALL                   MSG_PREHEAT_3 _UxGT(" All")
#endif
#ifndef MSG_PREHEAT_3_END
  #define MSG_PREHEAT_3_END                   MSG_PREHEAT_3 _UxGT(" End")
#endif
#ifndef MSG_PREHEAT_3_BEDONLY
  #define MSG_PREHEAT_3_BEDONLY               MSG_PREHEAT_3 _UxGT(" Bed")
#endif
#ifndef MSG_PREHEAT_3_SETTINGS
  #define MSG_PREHEAT_3_SETTINGS              MSG_PREHEAT_3 _UxGT(" conf")
#endif
#ifndef MSG_COOLDOWN
  #define MSG_COOLDOWN                        _UxGT("Cooldown")
#endif
#ifndef MSG_SWITCH_PS_ON
  #define MSG_SWITCH_PS_ON                    _UxGT("Switch power on")
#endif
#ifndef MSG_SWITCH_PS_OFF
  #define MSG_SWITCH_PS_OFF                   _UxGT("Switch power off")
#endif
#ifndef MSG_PRINT_TIME
  #define MSG_PRINT_TIME              		_UxGT("Print time: %d:%.2i")
#endif
#ifndef MSG_EXTRUDE
  #define MSG_EXTRUDE                         _UxGT("Extrude")
#endif
#ifndef MSG_RETRACT
  #define MSG_RETRACT                         _UxGT("Retract")
#endif
#ifndef MSG_MOVE_AXIS
  #define MSG_MOVE_AXIS                       _UxGT("Move axis")
#endif
#ifndef MSG_BED_LEVELING
  #define MSG_BED_LEVELING                    _UxGT("Bed Leveling")
#endif
#ifndef MSG_LEVEL_BED
  #define MSG_LEVEL_BED                       _UxGT("Level bed")
#endif
#ifndef MSG_LEVEL_CORNERS
  #define MSG_LEVEL_CORNERS                   _UxGT("Level corners")
#endif
#ifndef MSG_NEXT_CORNER
  #define MSG_NEXT_CORNER                     _UxGT("Next corner")
#endif
#ifndef MSG_EDITING_STOPPED
  #define MSG_EDITING_STOPPED                 _UxGT("Mesh Editing Stopped")
#endif
#ifndef MSG_USER_MENU
  #define MSG_USER_MENU                       _UxGT("Custom Commands")
#endif
#ifndef MSG_UBL_DOING_G29
  #define MSG_UBL_DOING_G29                   _UxGT("Doing G29")
#endif
#ifndef MSG_UBL_UNHOMED
  #define MSG_UBL_UNHOMED                     _UxGT("Home XYZ first")
#endif
#ifndef MSG_UBL_TOOLS
  #define MSG_UBL_TOOLS                       _UxGT("UBL Tools")
#endif
#ifndef MSG_UBL_LEVEL_BED
  #define MSG_UBL_LEVEL_BED                   _UxGT("Unified Bed Leveling")
#endif
#ifndef MSG_UBL_MANUAL_MESH
  #define MSG_UBL_MANUAL_MESH                 _UxGT("Manually Build Mesh")
#endif
#ifndef MSG_UBL_BC_INSERT
  #define MSG_UBL_BC_INSERT                   _UxGT("Place shim & measure")
#endif
#ifndef MSG_UBL_BC_INSERT2
  #define MSG_UBL_BC_INSERT2                  _UxGT("Measure")
#endif
#ifndef MSG_UBL_BC_REMOVE
  #define MSG_UBL_BC_REMOVE                   _UxGT("Remove & measure bed")
#endif
#ifndef MSG_UBL_MOVING_TO_NEXT
  #define MSG_UBL_MOVING_TO_NEXT              _UxGT("Moving to next")
#endif
#ifndef MSG_UBL_ACTIVATE_MESH
  #define MSG_UBL_ACTIVATE_MESH               _UxGT("Activate UBL")
#endif
#ifndef MSG_UBL_DEACTIVATE_MESH
  #define MSG_UBL_DEACTIVATE_MESH             _UxGT("Deactivate UBL")
#endif
#ifndef MSG_UBL_SET_BED_TEMP
  #define MSG_UBL_SET_BED_TEMP                _UxGT("Bed Temp")
#endif
#ifndef MSG_UBL_CUSTOM_BED_TEMP
  #define MSG_UBL_CUSTOM_BED_TEMP             MSG_UBL_SET_BED_TEMP
#endif
#ifndef MSG_UBL_SET_HOTEND_TEMP
  #define MSG_UBL_SET_HOTEND_TEMP             _UxGT("Hotend Temp")
#endif
#ifndef MSG_UBL_CUSTOM_HOTEND_TEMP
  #define MSG_UBL_CUSTOM_HOTEND_TEMP          MSG_UBL_SET_HOTEND_TEMP
#endif
#ifndef MSG_UBL_MESH_EDIT
  #define MSG_UBL_MESH_EDIT                   _UxGT("Mesh Edit")
#endif
#ifndef MSG_UBL_EDIT_CUSTOM_MESH
  #define MSG_UBL_EDIT_CUSTOM_MESH            _UxGT("Edit Custom Mesh")
#endif
#ifndef MSG_UBL_FINE_TUNE_MESH
  #define MSG_UBL_FINE_TUNE_MESH              _UxGT("Fine Tuning Mesh")
#endif
#ifndef MSG_UBL_DONE_EDITING_MESH
  #define MSG_UBL_DONE_EDITING_MESH           _UxGT("Done Editing Mesh")
#endif
#ifndef MSG_UBL_BUILD_CUSTOM_MESH
  #define MSG_UBL_BUILD_CUSTOM_MESH           _UxGT("Build Custom Mesh")
#endif
#ifndef MSG_UBL_BUILD_MESH_MENU
  #define MSG_UBL_BUILD_MESH_MENU             _UxGT("Build Mesh")
#endif
#ifndef MSG_UBL_BUILD_PLA_MESH
  #define MSG_UBL_BUILD_PLA_MESH              _UxGT("Build PLA Mesh")
#endif
#ifndef MSG_UBL_BUILD_ABS_MESH
  #define MSG_UBL_BUILD_ABS_MESH              _UxGT("Build ABS Mesh")
#endif
#ifndef MSG_UBL_BUILD_COLD_MESH
  #define MSG_UBL_BUILD_COLD_MESH             _UxGT("Build Cold Mesh")
#endif
#ifndef MSG_UBL_MESH_HEIGHT_ADJUST
  #define MSG_UBL_MESH_HEIGHT_ADJUST          _UxGT("Adjust Mesh Height")
#endif
#ifndef MSG_UBL_MESH_HEIGHT_AMOUNT
  #define MSG_UBL_MESH_HEIGHT_AMOUNT          _UxGT("Height Amount")
#endif
#ifndef MSG_UBL_VALIDATE_MESH_MENU
  #define MSG_UBL_VALIDATE_MESH_MENU          _UxGT("Validate Mesh")
#endif
#ifndef MSG_UBL_VALIDATE_PLA_MESH
  #define MSG_UBL_VALIDATE_PLA_MESH           _UxGT("Validate PLA Mesh")
#endif
#ifndef MSG_UBL_VALIDATE_ABS_MESH
  #define MSG_UBL_VALIDATE_ABS_MESH           _UxGT("Validate ABS Mesh")
#endif
#ifndef MSG_UBL_VALIDATE_CUSTOM_MESH
  #define MSG_UBL_VALIDATE_CUSTOM_MESH        _UxGT("Validate Custom Mesh")
#endif
#ifndef MSG_UBL_CONTINUE_MESH
  #define MSG_UBL_CONTINUE_MESH               _UxGT("Continue Bed Mesh")
#endif
#ifndef MSG_UBL_MESH_LEVELING
  #define MSG_UBL_MESH_LEVELING               _UxGT("Mesh Leveling")
#endif
#ifndef MSG_UBL_3POINT_MESH_LEVELING
  #define MSG_UBL_3POINT_MESH_LEVELING        _UxGT("3-Point Leveling")
#endif
#ifndef MSG_UBL_GRID_MESH_LEVELING
  #define MSG_UBL_GRID_MESH_LEVELING          _UxGT("Grid Mesh Leveling")
#endif
#ifndef MSG_UBL_MESH_LEVEL
  #define MSG_UBL_MESH_LEVEL                  _UxGT("Level Mesh")
#endif
#ifndef MSG_UBL_SIDE_POINTS
  #define MSG_UBL_SIDE_POINTS                 _UxGT("Side Points")
#endif
#ifndef MSG_UBL_MAP_TYPE
  #define MSG_UBL_MAP_TYPE                    _UxGT("Map Type")
#endif
#ifndef MSG_UBL_OUTPUT_MAP
  #define MSG_UBL_OUTPUT_MAP                  _UxGT("Output Mesh Map")
#endif
#ifndef MSG_UBL_OUTPUT_MAP_HOST
  #define MSG_UBL_OUTPUT_MAP_HOST             _UxGT("Output for Host")
#endif
#ifndef MSG_UBL_OUTPUT_MAP_CSV
  #define MSG_UBL_OUTPUT_MAP_CSV              _UxGT("Output for CSV")
#endif
#ifndef MSG_UBL_OUTPUT_MAP_BACKUP
  #define MSG_UBL_OUTPUT_MAP_BACKUP           _UxGT("Off Printer Backup")
#endif
#ifndef MSG_UBL_INFO_UBL
  #define MSG_UBL_INFO_UBL                    _UxGT("Output UBL Info")
#endif
#ifndef MSG_UBL_EDIT_MESH_MENU
  #define MSG_UBL_EDIT_MESH_MENU              _UxGT("Edit Mesh")
#endif
#ifndef MSG_UBL_FILLIN_AMOUNT
  #define MSG_UBL_FILLIN_AMOUNT               _UxGT("Fill-in Amount")
#endif
#ifndef MSG_UBL_MANUAL_FILLIN
  #define MSG_UBL_MANUAL_FILLIN               _UxGT("Manual Fill-in")
#endif
#ifndef MSG_UBL_SMART_FILLIN
  #define MSG_UBL_SMART_FILLIN                _UxGT("Smart Fill-in")
#endif
#ifndef MSG_UBL_FILLIN_MESH
  #define MSG_UBL_FILLIN_MESH                 _UxGT("Fill-in Mesh")
#endif
#ifndef MSG_UBL_INVALIDATE_ALL
  #define MSG_UBL_INVALIDATE_ALL              _UxGT("Invalidate All")
#endif
#ifndef MSG_UBL_INVALIDATE_CLOSEST
  #define MSG_UBL_INVALIDATE_CLOSEST          _UxGT("Invalidate Closest")
#endif
#ifndef MSG_UBL_FINE_TUNE_ALL
  #define MSG_UBL_FINE_TUNE_ALL               _UxGT("Fine Tune All")
#endif
#ifndef MSG_UBL_FINE_TUNE_CLOSEST
  #define MSG_UBL_FINE_TUNE_CLOSEST           _UxGT("Fine Tune Closest")
#endif
#ifndef MSG_UBL_STORAGE_MESH_MENU
  #define MSG_UBL_STORAGE_MESH_MENU           _UxGT("Mesh Storage")
#endif
#ifndef MSG_UBL_STORAGE_SLOT
  #define MSG_UBL_STORAGE_SLOT                _UxGT("Memory Slot")
#endif
#ifndef MSG_UBL_LOAD_MESH
  #define MSG_UBL_LOAD_MESH                   _UxGT("Load Bed Mesh")
#endif
#ifndef MSG_UBL_SAVE_MESH
  #define MSG_UBL_SAVE_MESH                   _UxGT("Save Bed Mesh")
#endif
#ifndef MSG_MESH_LOADED
  #define MSG_MESH_LOADED                     _UxGT("Mesh %i loaded")
#endif
#ifndef MSG_MESH_SAVED
  #define MSG_MESH_SAVED                      _UxGT("Mesh %i saved")
#endif
#ifndef MSG_NO_STORAGE
  #define MSG_NO_STORAGE                      _UxGT("No storage")
#endif
#ifndef MSG_UBL_SAVE_ERROR
  #define MSG_UBL_SAVE_ERROR                  _UxGT("Err: UBL Save")
#endif
#ifndef MSG_UBL_RESTORE_ERROR
  #define MSG_UBL_RESTORE_ERROR               _UxGT("Err: UBL Restore")
#endif
#ifndef MSG_UBL_Z_OFFSET_STOPPED
  #define MSG_UBL_Z_OFFSET_STOPPED            _UxGT("Z-Offset Stopped")
#endif
#ifndef MSG_UBL_STEP_BY_STEP_MENU
  #define MSG_UBL_STEP_BY_STEP_MENU           _UxGT("Step-By-Step UBL")
#endif

#ifndef MSG_LED_CONTROL
  #define MSG_LED_CONTROL                     _UxGT("LED Control")
#endif
#ifndef MSG_LEDS_ON
  #define MSG_LEDS_ON                         _UxGT("Lights On")
#endif
#ifndef MSG_LEDS_OFF
  #define MSG_LEDS_OFF                        _UxGT("Lights Off")
#endif
#ifndef MSG_LED_PRESETS
  #define MSG_LED_PRESETS                     _UxGT("Light Presets")
#endif
#ifndef MSG_SET_LEDS_RED
  #define MSG_SET_LEDS_RED                    _UxGT("Red")
#endif
#ifndef MSG_SET_LEDS_ORANGE
  #define MSG_SET_LEDS_ORANGE                 _UxGT("Orange")
#endif
#ifndef MSG_SET_LEDS_YELLOW
  #define MSG_SET_LEDS_YELLOW                 _UxGT("Yellow")
#endif
#ifndef MSG_SET_LEDS_GREEN
  #define MSG_SET_LEDS_GREEN                  _UxGT("Green")
#endif
#ifndef MSG_SET_LEDS_BLUE
  #define MSG_SET_LEDS_BLUE                   _UxGT("Blue")
#endif
#ifndef MSG_SET_LEDS_INDIGO
  #define MSG_SET_LEDS_INDIGO                 _UxGT("Indigo")
#endif
#ifndef MSG_SET_LEDS_VIOLET
  #define MSG_SET_LEDS_VIOLET                 _UxGT("Violet")
#endif
#ifndef MSG_SET_LEDS_WHITE
  #define MSG_SET_LEDS_WHITE                  _UxGT("White")
#endif
#ifndef MSG_SET_LEDS_DEFAULT
  #define MSG_SET_LEDS_DEFAULT                _UxGT("Default")
#endif
#ifndef MSG_CUSTOM_LEDS
  #define MSG_CUSTOM_LEDS                     _UxGT("Custom Lights")
#endif
#ifndef MSG_INTENSITY_R
  #define MSG_INTENSITY_R                     _UxGT("Red Intensity")
#endif
#ifndef MSG_INTENSITY_G
  #define MSG_INTENSITY_G                     _UxGT("Green Intensity")
#endif
#ifndef MSG_INTENSITY_B
  #define MSG_INTENSITY_B                     _UxGT("Blue Intensity")
#endif
#ifndef MSG_INTENSITY_W
  #define MSG_INTENSITY_W                     _UxGT("White Intensity")
#endif
#ifndef MSG_LED_BRIGHTNESS
  #define MSG_LED_BRIGHTNESS                  _UxGT("Brightness")
#endif

#ifndef MSG_MOVING
  #define MSG_MOVING                          _UxGT("Moving...")
#endif
#ifndef MSG_FREE_XY
  #define MSG_FREE_XY                         _UxGT("Free XY")
#endif
#ifndef MSG_MOVE_X
  #define MSG_MOVE_X                          _UxGT("Move X")
#endif
#ifndef MSG_MOVE_Y
  #define MSG_MOVE_Y                          _UxGT("Move Y")
#endif
#ifndef MSG_MOVE_Z
  #define MSG_MOVE_Z                          _UxGT("Move Z")
#endif
#ifndef MSG_MOVE_E
  #define MSG_MOVE_E                          _UxGT("Extruder")
#endif
#ifndef MSG_MOVE_01MM
  #define MSG_MOVE_01MM                       _UxGT("Move 0.1mm")
#endif
#ifndef MSG_MOVE_1MM
  #define MSG_MOVE_1MM                        _UxGT("Move 1mm")
#endif
#ifndef MSG_MOVE_10MM
  #define MSG_MOVE_10MM                       _UxGT("Move 10mm")
#endif
#ifndef MSG_SPEED
  #define MSG_SPEED                           _UxGT("Speed")
#endif
#ifndef MSG_BED_Z
  #define MSG_BED_Z                           _UxGT("Bed Z")
#endif
#ifndef MSG_NOZZLE
  #define MSG_NOZZLE                          _UxGT("Nozzle")
#endif
#ifndef MSG_BED
  #define MSG_BED                             _UxGT("Bed")
#endif
#ifndef MSG_CHAMBER
  #define MSG_CHAMBER                         _UxGT("Chamber")
#endif
#ifndef MSG_COOLER
  #define MSG_COOLER                          _UxGT("Cooler")
#endif
#ifndef MSG_FAN_SPEED
  #define MSG_FAN_SPEED                       _UxGT("Fan speed")
#endif
#ifndef MSG_EXTRA_FAN_SPEED
  #define MSG_EXTRA_FAN_SPEED                 _UxGT("Extra fan speed")
#endif
#ifndef MSG_FLOW
  #define MSG_FLOW                            _UxGT("Flow")
#endif
#ifndef MSG_CONTROL
  #define MSG_CONTROL                         _UxGT("Control")
#endif
#ifndef MSG_MIN
  #define MSG_MIN                             _UxGT(" ") LCD_STR_THERMOMETER _UxGT(" Min")
#endif
#ifndef MSG_MAX
  #define MSG_MAX                             _UxGT(" ") LCD_STR_THERMOMETER _UxGT(" Max")
#endif
#ifndef MSG_FACTOR
  #define MSG_FACTOR                          _UxGT(" ") LCD_STR_THERMOMETER _UxGT(" Fact")
#endif
#ifndef MSG_IDLEOOZING
  #define MSG_IDLEOOZING                      _UxGT("Anti oozing")
#endif
#ifndef MSG_AUTOTEMP
  #define MSG_AUTOTEMP                        _UxGT("Autotemp")
#endif
#ifndef MSG_ON
  #define MSG_ON                              _UxGT("On ")
#endif
#ifndef MSG_OFF
  #define MSG_OFF                             _UxGT("Switched Off")
#endif
#ifndef MSG_PID_P
  #define MSG_PID_P                           _UxGT("PID-P")
#endif
#ifndef MSG_PID_I
  #define MSG_PID_I                           _UxGT("PID-I")
#endif
#ifndef MSG_PID_D
  #define MSG_PID_D                           _UxGT("PID-D")
#endif
#ifndef MSG_PID_C
  #define MSG_PID_C                           _UxGT("PID-C")
#endif
#ifndef MSG_SELECT
  #define MSG_SELECT                          _UxGT("Select")
#endif
#ifndef MSG_ACC
  #define MSG_ACC                             _UxGT("Accel")
#endif
#ifndef MSG_JERK
  #define MSG_JERK                            _UxGT("Jerk")
#endif
#if IS_KINEMATIC
  #ifndef MSG_VA_JERK
    #define MSG_VA_JERK                       _UxGT("Va-jerk")
  #endif
  #ifndef MSG_VB_JERK
    #define MSG_VB_JERK                       _UxGT("Vb-jerk")
  #endif
  #ifndef MSG_VC_JERK
    #define MSG_VC_JERK                       _UxGT("Vc-jerk")
  #endif
#else
  #ifndef MSG_VA_JERK
    #define MSG_VA_JERK                       _UxGT("Vx-jerk")
  #endif
  #ifndef MSG_VB_JERK
    #define MSG_VB_JERK                       _UxGT("Vy-jerk")
  #endif
  #ifndef MSG_VC_JERK
    #define MSG_VC_JERK                       _UxGT("Vz-jerk")
  #endif
#endif
#ifndef MSG_VE_JERK
  #define MSG_VE_JERK                         _UxGT("Ve-jerk")
#endif
#ifndef MSG_VELOCITY
  #define MSG_VELOCITY                        _UxGT("Velocity")
#endif
#ifndef MSG_VMAX
  #define MSG_VMAX                            _UxGT("Vmax ")
#endif
#ifndef MSG_VMIN
  #define MSG_VMIN                            _UxGT("Vmin")
#endif
#ifndef MSG_VTRAV_MIN
  #define MSG_VTRAV_MIN                       _UxGT("VTrav min")
#endif
#ifndef MSG_ACCELERATION
  #define MSG_ACCELERATION                    _UxGT("Acceleration")
#endif
#ifndef MSG_AMAX
  #define MSG_AMAX                            _UxGT("Amax ")
#endif
#ifndef MSG_A_RETRACT
  #define MSG_A_RETRACT                       _UxGT("A-retract")
#endif
#ifndef MSG_A_TRAVEL
  #define MSG_A_TRAVEL                        _UxGT("A-travel")
#endif
#ifndef MSG_STEPS_PER_MM
  #define MSG_STEPS_PER_MM                    _UxGT("Steps/mm")
#endif
#if IS_KINEMATIC
  #ifndef MSG_ASTEPS
    #define MSG_ASTEPS                        _UxGT("Asteps/mm")
  #endif
  #ifndef MSG_BSTEPS
    #define MSG_BSTEPS                        _UxGT("Bsteps/mm")
  #endif
  #ifndef MSG_CSTEPS
    #define MSG_CSTEPS                        _UxGT("Csteps/mm")
  #endif
#else
  #ifndef MSG_ASTEPS
    #define MSG_ASTEPS                        _UxGT("Xsteps/mm")
  #endif
  #ifndef MSG_BSTEPS
    #define MSG_BSTEPS                        _UxGT("Ysteps/mm")
  #endif
  #ifndef MSG_CSTEPS
    #define MSG_CSTEPS                        _UxGT("Zsteps/mm")
  #endif
#endif
#ifndef MSG_ESTEPS
  #define MSG_ESTEPS                          _UxGT("Esteps/mm")
#endif
#ifndef MSG_E1STEPS
  #define MSG_E1STEPS                         _UxGT("E1steps/mm")
#endif
#ifndef MSG_E2STEPS
  #define MSG_E2STEPS                         _UxGT("E2steps/mm")
#endif
#ifndef MSG_E3STEPS
  #define MSG_E3STEPS                         _UxGT("E3steps/mm")
#endif
#ifndef MSG_E4STEPS
  #define MSG_E4STEPS                         _UxGT("E4steps/mm")
#endif
#ifndef MSG_E5STEPS
  #define MSG_E5STEPS                         _UxGT("E5steps/mm")
#endif
#ifndef MSG_E6STEPS
  #define MSG_E6STEPS                         _UxGT("E6steps/mm")
#endif
#ifndef MSG_TEMPERATURE
  #define MSG_TEMPERATURE                     _UxGT("Temperature")
#endif
#ifndef MSG_MOTION
  #define MSG_MOTION                          _UxGT("Motion")
#endif
#ifndef MSG_FILAMENT
  #define MSG_FILAMENT                        _UxGT("Filament")
#endif
#ifndef MSG_VOLUMETRIC_ENABLED
  #define MSG_VOLUMETRIC_ENABLED              _UxGT("E in mm3")
#endif
#ifndef MSG_FILAMENT_DIAM
  #define MSG_FILAMENT_DIAM                   _UxGT("Fil. Dia.")
#endif
#ifndef MSG_FILAMENT_UNLOAD
  #define MSG_FILAMENT_UNLOAD                 _UxGT("Unload mm")
#endif
#ifndef MSG_FILAMENT_LOAD
  #define MSG_FILAMENT_LOAD                   _UxGT("Load mm")
#endif
#ifndef MSG_ADVANCE_K
  #define MSG_ADVANCE_K                       _UxGT("Advance K")
#endif
#ifndef MSG_CONTRAST
  #define MSG_CONTRAST                        _UxGT("LCD contrast")
#endif
#ifndef MSG_STORE_EEPROM
  #define MSG_STORE_EEPROM                    _UxGT("Store settings")
#endif
#ifndef MSG_LOAD_EEPROM
  #define MSG_LOAD_EEPROM                     _UxGT("Load settings")
#endif
#ifndef MSG_RESTORE_FAILSAFE
  #define MSG_RESTORE_FAILSAFE                _UxGT("Restore failsafe")
#endif
#ifndef MSG_INIT_EEPROM
  #define MSG_INIT_EEPROM                     _UxGT("Initialize EEPROM")
#endif
#ifndef MSG_REFRESH
  #define MSG_REFRESH                         _UxGT("Refresh")
#endif
#ifndef MSG_WATCH
  #define MSG_WATCH                           _UxGT("Info screen")
#endif
#ifndef MSG_PREPARE
  #define MSG_PREPARE                         _UxGT("Prepare")
#endif
#ifndef MSG_TUNE
  #define MSG_TUNE                            _UxGT("Tune")
#endif
#ifndef MSG_PAUSE_PRINT
  #define MSG_PAUSE_PRINT                     _UxGT("Pause print")
#endif
#ifndef MSG_RESUME_PRINT
  #define MSG_RESUME_PRINT                    _UxGT("Resume print")
#endif
#ifndef MSG_STOP_PRINT
  #define MSG_STOP_PRINT                      _UxGT("Stop print")
#endif
#ifndef MSG_CARD_MENU
  #define MSG_CARD_MENU                       _UxGT("Print from SD")
#endif
#ifndef MSG_NO_CARD
  #define MSG_NO_CARD                         _UxGT("No SD card")
#endif
#ifndef MSG_DWELL
  #define MSG_DWELL                           _UxGT("Sleep...")
#endif
#ifndef MSG_USERWAIT
  #define MSG_USERWAIT                        _UxGT("Click to resume...")
#endif
#ifndef MSG_PRINT_PAUSED
  #define MSG_PRINT_PAUSED                    _UxGT("Print paused")
#endif
#ifndef MSG_RESUMING
  #define MSG_RESUMING                        _UxGT("Resuming print")
#endif
#ifndef MSG_PRINT_ABORTED
  #define MSG_PRINT_ABORTED                   _UxGT("Print aborted")
#endif
#ifndef MSG_NO_MOVE
  #define MSG_NO_MOVE                         _UxGT("No move.")
#endif
#ifndef MSG_KILLED
  #define MSG_KILLED                          _UxGT("KILLED. ")
#endif
#ifndef MSG_STOPPED
  #define MSG_STOPPED                         _UxGT("STOPPED. ")
#endif
#ifndef MSG_CONTROL_RETRACT
  #define MSG_CONTROL_RETRACT                 _UxGT("Retract mm")
#endif
#ifndef MSG_CONTROL_RETRACT_SWAP
  #define MSG_CONTROL_RETRACT_SWAP            _UxGT("Swap Re.mm")
#endif
#ifndef MSG_CONTROL_RETRACTF
  #define MSG_CONTROL_RETRACTF                _UxGT("Retract  V")
#endif
#ifndef MSG_CONTROL_RETRACT_ZLIFT
  #define MSG_CONTROL_RETRACT_ZLIFT           _UxGT("Hop mm")
#endif
#ifndef MSG_CONTROL_RETRACT_RECOVER
  #define MSG_CONTROL_RETRACT_RECOVER         _UxGT("UnRet mm")
#endif
#ifndef MSG_CONTROL_RETRACT_RECOVER_SWAP
  #define MSG_CONTROL_RETRACT_RECOVER_SWAP    _UxGT("S UnRet mm")
#endif
#ifndef MSG_CONTROL_RETRACT_RECOVERF
  #define MSG_CONTROL_RETRACT_RECOVERF        _UxGT("UnRet V")
#endif
#ifndef MSG_CONTROL_RETRACT_RECOVER_SWAPF
  #define MSG_CONTROL_RETRACT_RECOVER_SWAPF   _UxGT("S UnRet V")
#endif
#ifndef MSG_AUTORETRACT
  #define MSG_AUTORETRACT                     _UxGT("AutoRetr.")
#endif
#ifndef MSG_FILAMENTCHANGE
  #define MSG_FILAMENTCHANGE                  _UxGT("Change filament")
#endif
#ifndef MSG_FILAMENTLOAD
  #define MSG_FILAMENTLOAD                    _UxGT("Load filament")
#endif
#ifndef MSG_FILAMENTUNLOAD
  #define MSG_FILAMENTUNLOAD                  _UxGT("Unload filament")
#endif
#ifndef MSG_FILAMENTUNLOAD_ALL
  #define MSG_FILAMENTUNLOAD_ALL              _UxGT("Unload All")
#endif
#ifndef MSG_INIT_SDCARD
  #define MSG_INIT_SDCARD                     _UxGT("Init. SD card")
#endif
#ifndef MSG_CNG_SDCARD
  #define MSG_CNG_SDCARD                      _UxGT("Change SD card")
#endif
#ifndef MSG_ZPROBE_OUT
  #define MSG_ZPROBE_OUT                      _UxGT("Z probe out. bed")
#endif
#ifndef MSG_SKEW_FACTOR
  #define MSG_SKEW_FACTOR                     _UxGT("Skew Factor")
#endif
#ifndef MSG_BLTOUCH
  #define MSG_BLTOUCH                         _UxGT("BLTouch")
#endif
#ifndef MSG_BLTOUCH_SELFTEST
  #define MSG_BLTOUCH_SELFTEST                _UxGT("BLTouch Self-Test")
#endif
#ifndef MSG_BLTOUCH_RESET
  #define MSG_BLTOUCH_RESET                   _UxGT("Reset BLTouch")
#endif
#ifndef MSG_BLTOUCH_DEPLOY
  #define MSG_BLTOUCH_DEPLOY                  _UxGT("Deploy BLTouch")
#endif
#ifndef MSG_BLTOUCH_STOW
  #define MSG_BLTOUCH_STOW                    _UxGT("Stow BLTouch")
#endif
#ifndef MSG_HOME
  #define MSG_HOME                            _UxGT("Home") // Used as MSG_HOME " " MSG_X MSG_Y MSG_Z " " MSG_FIRST
#endif
#ifndef MSG_FIRST
  #define MSG_FIRST                           _UxGT("first")
#endif
#ifndef MSG_ZPROBE_ZOFFSET
  #define MSG_ZPROBE_ZOFFSET                  _UxGT("Z Offset")
#endif
#ifndef MSG_BABYSTEP_X
  #define MSG_BABYSTEP_X                      _UxGT("Babystep X")
#endif
#ifndef MSG_BABYSTEP_Y
  #define MSG_BABYSTEP_Y                      _UxGT("Babystep Y")
#endif
#ifndef MSG_BABYSTEP_Z
  #define MSG_BABYSTEP_Z                      _UxGT("Babystep Z")
#endif
#ifndef MSG_ENDSTOP_ABORT
  #define MSG_ENDSTOP_ABORT                   _UxGT("Endstop abort")
#endif
#ifndef MSG_HEATING_FAILED_LCD
  #define MSG_HEATING_FAILED_LCD              _UxGT("Heating failed")
#endif
#ifndef MSG_HEATING_FAILED_LCD_BED
  #define MSG_HEATING_FAILED_LCD_BED          _UxGT("Bed heating failed")
#endif
#ifndef MSG_ERR_REDUNDANT_TEMP
  #define MSG_ERR_REDUNDANT_TEMP              _UxGT("Err: REDUNDANT TEMP")
#endif
#ifndef MSG_THERMAL_RUNAWAY
  #define MSG_THERMAL_RUNAWAY                 _UxGT("THERMAL RUNAWAY")
#endif
#ifndef MSG_THERMAL_RUNAWAY_BED
  #define MSG_THERMAL_RUNAWAY_BED             _UxGT("BED THERMAL RUNAWAY")
#endif
#ifndef MSG_AD595
  #define MSG_AD595                           _UxGT("AD595 Offset & Gain")
#endif
#ifndef MSG_ERR_MAXTEMP
  #define MSG_ERR_MAXTEMP                     _UxGT("Error: MAXTEMP triggered")
#endif
#ifndef MSG_ERR_MINTEMP
  #define MSG_ERR_MINTEMP                     _UxGT("Error: MINTEMP triggered")
#endif
#ifndef MSG_ERR_MAXTEMP_BED
  #define MSG_ERR_MAXTEMP_BED                 _UxGT("Error: MAXTEMP BED triggered")
#endif
#ifndef MSG_ERR_MINTEMP_BED
  #define MSG_ERR_MINTEMP_BED                 _UxGT("Error: MINTEMP BED triggered")
#endif
#ifndef MSG_ERR_MAXTEMP_CHAMBER
  #define MSG_ERR_MAXTEMP_CHAMBER             _UxGT("Err: MAXTEMP CHAMBER")
#endif
#ifndef MSG_ERR_MINTEMP_CHAMBER
  #define MSG_ERR_MINTEMP_CHAMBER             _UxGT("Err: MINTEMP CHAMBER")
#endif
#ifndef MSG_ERR_MAXTEMP_COOLER
  #define MSG_ERR_MAXTEMP_COOLER              _UxGT("Err: MAXTEMP COOLER")
#endif
#ifndef MSG_ERR_MINTEMP_COOLER
  #define MSG_ERR_MINTEMP_COOLER              _UxGT("Err: MINTEMP COOLER")
#endif
#ifndef MSG_ERR_Z_HOMING
  #define MSG_ERR_Z_HOMING                    MSG_HOME _UxGT(" ") MSG_X MSG_Y _UxGT(" ") MSG_FIRST
#endif
#ifndef MSG_HALTED
  #define MSG_HALTED                          _UxGT("PRINTER HALTED")
#endif
#ifndef MSG_PLEASE_RESET
  #define MSG_PLEASE_RESET                    _UxGT("Please reset")
#endif
#ifndef MSG_SHORT_DAY
  #define MSG_SHORT_DAY                       _UxGT("d") // One character only
#endif
#ifndef MSG_SHORT_HOUR
  #define MSG_SHORT_HOUR                      _UxGT("h") // One character only
#endif
#ifndef MSG_SHORT_MINUTE
  #define MSG_SHORT_MINUTE                    _UxGT("m") // One character only
#endif
#ifndef MSG_LONG_DAY
  #define MSG_LONG_DAY                        _UxGT("days")
#endif
#ifndef MSG_LONG_HOUR
  #define MSG_LONG_HOUR                       _UxGT("hours")
#endif
#ifndef MSG_LONG_MINUTE
  #define MSG_LONG_MINUTE                     _UxGT("minutes")
#endif
#ifndef MSG_PRINT_TIME
  #define MSG_PRINT_TIME                      _UxGT("Print time ")
#endif
#ifndef MSG_HEATING
  #define MSG_HEATING                         _UxGT("Heating...")
#endif
#ifndef MSG_HEATING_COMPLETE
  #define MSG_HEATING_COMPLETE                _UxGT("Heating done.")
#endif
#ifndef MSG_COOLING
  #define MSG_COOLING                         _UxGT("Cooling...")
#endif
#ifndef MSG_COOLING_COMPLETE
  #define MSG_COOLING_COMPLETE                _UxGT("Cooling done.")
#endif
#ifndef MSG_BED_HEATING
  #define MSG_BED_HEATING                     _UxGT("Bed heating.")
#endif
#ifndef MSG_BED_COOLING
  #define MSG_BED_COOLING                     _UxGT("Bed cooling.")
#endif
#ifndef MSG_BED_DONE
  #define MSG_BED_DONE                        _UxGT("Bed done.")
#endif
#ifndef MSG_CHAMBER_HEATING
  #define MSG_CHAMBER_HEATING                 _UxGT("Chamber Heating.")
#endif
#ifndef MSG_CHAMBER_DONE
  #define MSG_CHAMBER_DONE                    _UxGT("Chamber done.")
#endif
#ifndef MSG_COOLER_COOLING
  #define MSG_COOLER_COOLING                  _UxGT("Cooler Cooling.")
#endif
#ifndef MSG_COOLER_DONE
  #define MSG_COOLER_DONE                     _UxGT("Cooler done.")
#endif
#ifndef MSG_DELTA_CALIBRATE
  #define MSG_DELTA_CALIBRATE                 _UxGT("Delta Calibration")
#endif
#ifndef MSG_DELTA_CALIBRATE_X
  #define MSG_DELTA_CALIBRATE_X               _UxGT("Calibrate X")
#endif
#ifndef MSG_DELTA_CALIBRATE_Y
  #define MSG_DELTA_CALIBRATE_Y               _UxGT("Calibrate Y")
#endif
#ifndef MSG_DELTA_CALIBRATE_Z
  #define MSG_DELTA_CALIBRATE_Z               _UxGT("Calibrate Z")
#endif
#ifndef MSG_DELTA_CALIBRATE_CENTER
  #define MSG_DELTA_CALIBRATE_CENTER          _UxGT("Calibrate Center")
#endif
#ifndef MSG_DELTA_SETTINGS
  #define MSG_DELTA_SETTINGS                  _UxGT("Delta Settings")
#endif
#ifndef MSG_DELTA_AUTO_CALIBRATE
  #define MSG_DELTA_AUTO_CALIBRATE            _UxGT("Auto Calibration")
#endif
#ifndef MSG_DELTA_HEIGHT_CALIBRATE
  #define MSG_DELTA_HEIGHT_CALIBRATE          _UxGT("Set Delta Height")
#endif
#ifndef MSG_DELTA_DIAG_ROD
  #define MSG_DELTA_DIAG_ROD                  _UxGT("Diag Rod")
#endif
#ifndef MSG_DELTA_HEIGHT
  #define MSG_DELTA_HEIGHT                    _UxGT("Height")
#endif
#ifndef MSG_DELTA_RADIUS
  #define MSG_DELTA_RADIUS                    _UxGT("Radius")
#endif
#ifndef MSG_DELTA_CHECKING
  #define MSG_DELTA_CHECKING                  _UxGT("Checking... AC")
#endif
#ifndef MSG_DELTA_AUTO_CALIBRATE_OK
  #define MSG_DELTA_AUTO_CALIBRATE_OK         _UxGT("Calibration OK")
#endif
#ifndef MSG_INFO_MENU
  #define MSG_INFO_MENU                       _UxGT("About Printer")
#endif
#ifndef MSG_INFO_FIRMWARE_MENU
  #define MSG_INFO_FIRMWARE_MENU              _UxGT("Firmware Info")
#endif
#ifndef MSG_INFO_PRINTER_MENU
  #define MSG_INFO_PRINTER_MENU               _UxGT("Printer Info")
#endif
#ifndef MSG_3POINT_LEVELING
  #define MSG_3POINT_LEVELING                 _UxGT("3-Point Leveling")
#endif
#ifndef MSG_LINEAR_LEVELING
  #define MSG_LINEAR_LEVELING                 _UxGT("Linear Leveling")
#endif
#ifndef MSG_BILINEAR_LEVELING
  #define MSG_BILINEAR_LEVELING               _UxGT("Bilinear Leveling")
#endif
#ifndef MSG_UBL_LEVELING
  #define MSG_UBL_LEVELING                    _UxGT("Unified Bed Leveling")
#endif
#ifndef MSG_MESH_LEVELING
  #define MSG_MESH_LEVELING                   _UxGT("Mesh Leveling")
#endif
#ifndef MSG_INFO_STATS_MENU
  #define MSG_INFO_STATS_MENU                 _UxGT("Printer Stats")
#endif
#ifndef MSG_INFO_BOARD_MENU
  #define MSG_INFO_BOARD_MENU                 _UxGT("Board Info")
#endif
#ifndef MSG_INFO_THERMISTOR_MENU
  #define MSG_INFO_THERMISTOR_MENU            _UxGT("Thermistors")
#endif
#ifndef MSG_INFO_EXTRUDERS
  #define MSG_INFO_EXTRUDERS                  _UxGT("Extruders")
#endif
#ifndef MSG_INFO_HOTENDS
  #define MSG_INFO_HOTENDS                    _UxGT("Hotends")
#endif
#ifndef MSG_INFO_BED
  #define MSG_INFO_BED                        _UxGT("Bed")
#endif
#ifndef MSG_INFO_CHAMBER
  #define MSG_INFO_CHAMBER                    _UxGT("Hot Chamber")
#endif
#ifndef MSG_INFO_COOLER
  #define MSG_INFO_COOLER                     _UxGT("Cooler")
#endif
#ifndef MSG_INFO_BAUDRATE
  #define MSG_INFO_BAUDRATE                   _UxGT("Baud")
#endif
#ifndef MSG_INFO_PROTOCOL
  #define MSG_INFO_PROTOCOL                   _UxGT("Protocol")
#endif
#ifndef MSG_CASE_LIGHT
  #define MSG_CASE_LIGHT                      _UxGT("Case light")
#endif
#ifndef MSG_CASE_LIGHT_BRIGHTNESS
  #define MSG_CASE_LIGHT_BRIGHTNESS           _UxGT("Light BRIGHTNESS")
#endif
#if LCD_WIDTH >= 20
  #ifndef MSG_INFO_PRINT_COUNT
    #define MSG_INFO_PRINT_COUNT              _UxGT("Print Count")
  #endif
  #ifndef MSG_INFO_COMPLETED_PRINTS
    #define MSG_INFO_COMPLETED_PRINTS         _UxGT("Completed")
  #endif
  #ifndef MSG_INFO_PRINT_LONGEST
    #define MSG_INFO_PRINT_LONGEST            _UxGT("Longest job time")
  #endif
  #ifndef MSG_INFO_PRINT_FILAMENT
    #define MSG_INFO_PRINT_FILAMENT           _UxGT("Extruded total")
  #endif
#else
  #ifndef MSG_INFO_PRINT_COUNT
    #define MSG_INFO_PRINT_COUNT              _UxGT("Prints")
  #endif
  #ifndef MSG_INFO_COMPLETED_PRINTS
    #define MSG_INFO_COMPLETED_PRINTS         _UxGT("Completed")
  #endif
  #ifndef MSG_INFO_PRINT_LONGEST
    #define MSG_INFO_PRINT_LONGEST            _UxGT("Longest")
  #endif
  #ifndef MSG_INFO_PRINT_FILAMENT
    #define MSG_INFO_PRINT_FILAMENT           _UxGT("Extruded")
  #endif
#endif

#ifndef MSG_INFO_TOTAL_PRINTS
  #define MSG_INFO_TOTAL_PRINTS               _UxGT("Total Prints")
#endif
#ifndef MSG_INFO_FINISHED_PRINTS
  #define MSG_INFO_FINISHED_PRINTS            _UxGT("Fin. Prints")
#endif
#ifndef MSG_INFO_ON_TIME
  #define MSG_INFO_ON_TIME                    _UxGT("On x")
#endif
#ifndef MSG_INFO_PRINT_TIME
  #define MSG_INFO_PRINT_TIME                 _UxGT("Pr x")
#endif
#ifndef MSG_INFO_FILAMENT_USAGE
  #define MSG_INFO_FILAMENT_USAGE             _UxGT("Fil")
#endif
#ifndef MSG_INFO_PWRCONSUMED
  #define MSG_INFO_PWRCONSUMED                _UxGT("PWR")
#endif
#ifndef MSG_INFO_MIN_TEMP
  #define MSG_INFO_MIN_TEMP                   _UxGT("Min Temp")
#endif
#ifndef MSG_INFO_MAX_TEMP
  #define MSG_INFO_MAX_TEMP                   _UxGT("Max Temp")
#endif
#ifndef MSG_INFO_PSU
  #define MSG_INFO_PSU                        _UxGT("PSU")
#endif
#ifndef MSG_DRIVE_STRENGTH
  #define MSG_DRIVE_STRENGTH                  _UxGT("Drive Strength")
#endif
#ifndef MSG_DAC_PERCENT
  #define MSG_DAC_PERCENT                     _UxGT("Driver %")
#endif
#ifndef MSG_DAC_EEPROM_WRITE
  #define MSG_DAC_EEPROM_WRITE                _UxGT("DAC EEPROM Write")
#endif
#ifndef MSG_FILAMENT_CHANGE_HEADER_PAUSE
  #define MSG_FILAMENT_CHANGE_HEADER_PAUSE    _UxGT("PRINT PAUSED")
#endif
#ifndef MSG_FILAMENT_CHANGE_HEADER_LOAD
  #define MSG_FILAMENT_CHANGE_HEADER_LOAD     _UxGT("LOAD FILAMENT")
#endif
#ifndef MSG_FILAMENT_CHANGE_HEADER_UNLOAD
  #define MSG_FILAMENT_CHANGE_HEADER_UNLOAD   _UxGT("UNLOAD FILAMENT")
#endif
#ifndef MSG_FILAMENT_CHANGE_OPTION_HEADER
  #define MSG_FILAMENT_CHANGE_OPTION_HEADER   _UxGT("RESUME OPTIONS:")
#endif
#ifndef MSG_FILAMENT_CHANGE_OPTION_PURGE
  #define MSG_FILAMENT_CHANGE_OPTION_PURGE    _UxGT("Purge more")
#endif
#ifndef MSG_FILAMENT_CHANGE_OPTION_RESUME
  #define MSG_FILAMENT_CHANGE_OPTION_RESUME   _UxGT("Continue")
#endif
#ifndef MSG_FILAMENT_CHANGE_NOZZLE
  #define MSG_FILAMENT_CHANGE_NOZZLE          _UxGT("  Nozzle: ")
#endif
#ifndef MSG_ERR_HOMING_FAILED
  #define MSG_ERR_HOMING_FAILED               _UxGT("Homing failed")
#endif
#ifndef MSG_ERR_PROBING_FAILED
  #define MSG_ERR_PROBING_FAILED              _UxGT("Probing failed")
#endif
#ifndef MSG_M600_TOO_COLD
  #define MSG_M600_TOO_COLD                   _UxGT("M600: Too cold")
#endif

//
// Filament Change screens show up to 3 lines on a 4-line display
//                        ...or up to 2 lines on a 3-line display
//
#if LCD_HEIGHT >= 4
  #ifndef MSG_FILAMENT_CHANGE_INIT_1
    #define MSG_FILAMENT_CHANGE_INIT_1          _UxGT("Wait for start")
    #define MSG_FILAMENT_CHANGE_INIT_2          _UxGT("of the filament")
    #define MSG_FILAMENT_CHANGE_INIT_3          _UxGT("change")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_UNLOAD_1
    #define MSG_FILAMENT_CHANGE_UNLOAD_1        _UxGT("Wait for")
    #define MSG_FILAMENT_CHANGE_UNLOAD_2        _UxGT("filament unload")
    #define MSG_FILAMENT_CHANGE_UNLOAD_3        _UxGT("")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_INSERT_1
    #define MSG_FILAMENT_CHANGE_INSERT_1        _UxGT("Insert filament")
    #define MSG_FILAMENT_CHANGE_INSERT_2        _UxGT("and press button")
    #define MSG_FILAMENT_CHANGE_INSERT_3        _UxGT("to continue...")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_HEAT_1
    #define MSG_FILAMENT_CHANGE_HEAT_1          _UxGT("Press button to")
    #define MSG_FILAMENT_CHANGE_HEAT_2          _UxGT("heat nozzle.")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_ZZZ_1
    #define MSG_FILAMENT_CHANGE_ZZZ_1           _UxGT(" z   z   z")
    #define MSG_FILAMENT_CHANGE_ZZZ_2           _UxGT("Z   Z   Z")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_HEATING_1
    #define MSG_FILAMENT_CHANGE_HEATING_1       _UxGT("Heating nozzle")
    #define MSG_FILAMENT_CHANGE_HEATING_2       _UxGT("Please wait...")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_LOAD_1
    #define MSG_FILAMENT_CHANGE_LOAD_1          _UxGT("Wait for")
    #define MSG_FILAMENT_CHANGE_LOAD_2          _UxGT("filament load")
    #define MSG_FILAMENT_CHANGE_LOAD_3          _UxGT("")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_PURGE_1
    #define MSG_FILAMENT_CHANGE_PURGE_1         _UxGT("Wait for")
    #define MSG_FILAMENT_CHANGE_PURGE_2         _UxGT("filament purge")
    #define MSG_FILAMENT_CHANGE_PURGE_3         _UxGT("")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_RESUME_1
    #define MSG_FILAMENT_CHANGE_RESUME_1        _UxGT("Wait for print")
    #define MSG_FILAMENT_CHANGE_RESUME_2        _UxGT("to resume")
    #define MSG_FILAMENT_CHANGE_RESUME_3        _UxGT("")
  #endif
#else // LCD_HEIGHT < 4
  #ifndef MSG_FILAMENT_CHANGE_INIT_1
    #define MSG_FILAMENT_CHANGE_INIT_1          _UxGT("Please wait...")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_UNLOAD_1
    #define MSG_FILAMENT_CHANGE_UNLOAD_1        _UxGT("Ejecting...")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_INSERT_1
    #define MSG_FILAMENT_CHANGE_INSERT_1        _UxGT("Insert and Click")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_HEATING_1
    #define MSG_FILAMENT_CHANGE_HEATING_1       _UxGT("Heating...")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_LOAD_1
    #define MSG_FILAMENT_CHANGE_LOAD_1          _UxGT("Loading...")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_PURGE_1
    #define MSG_FILAMENT_CHANGE_PURGE_1         _UxGT("Purging...")
  #endif
  #ifndef MSG_FILAMENT_CHANGE_RESUME_1
    #define MSG_FILAMENT_CHANGE_RESUME_1        _UxGT("Resuming...")
  #endif
#endif // LCD_HEIGHT < 4

// Extra
#ifndef MSG_RESTART_PRINT
  #define MSG_RESTART_PRINT                   _UxGT("Restart print")
#endif
#ifndef MSG_FIX_LOSE_STEPS
  #define MSG_FIX_LOSE_STEPS                  _UxGT("Fix axis steps")
#endif
#ifndef MSG_LASER
  #define MSG_LASER                           _UxGT("Laser Preset")
#endif
#ifndef MSG_CONFIG
  #define MSG_CONFIG                          _UxGT("Configuration")
#endif
#ifndef MSG_SAVED_POS
  #define MSG_SAVED_POS                       _UxGT("Saved position")
#endif
#ifndef MSG_RESTORING_POS
  #define MSG_RESTORING_POS                   _UxGT("Restoring position")
#endif
#ifndef MSG_INVALID_POS_SLOT
  #define MSG_INVALID_POS_SLOT                _UxGT("Invalid slot, total slots: ")
#endif
#ifndef MSG_NEED_TUNE_PID
  #define MSG_NEED_TUNE_PID                   _UxGT("Need Tune PID.")
#endif

// Rfid module
#ifndef MSG_RFID_SPOOL
  #define MSG_RFID_SPOOL                      _UxGT("Spool on E")
#endif
#ifndef MSG_RFID_BRAND
  #define MSG_RFID_BRAND                      _UxGT("Brand: ")
#endif
#ifndef MSG_RFID_TYPE
  #define MSG_RFID_TYPE                       _UxGT("Type: ")
#endif
#ifndef MSG_RFID_COLOR
  #define MSG_RFID_COLOR                      _UxGT("Color: ")
#endif
#ifndef MSG_RFID_SIZE
  #define MSG_RFID_SIZE                       _UxGT("Size: ")
#endif
#ifndef MSG_RFID_TEMP_HOTEND
  #define MSG_RFID_TEMP_HOTEND                _UxGT("Temperature Hotend: ")
#endif
#ifndef MSG_RFID_TEMP_BED
  #define MSG_RFID_TEMP_BED                   _UxGT("Temperature Bed: ")
#endif
#ifndef MSG_RFID_TEMP_USER_HOTEND
  #define MSG_RFID_TEMP_USER_HOTEND           _UxGT("User temperature Hotend: ")
#endif
#ifndef MSG_RFID_TEMP_USER_BED
  #define MSG_RFID_TEMP_USER_BED              _UxGT("User temperatura Bed: ")
#endif
#ifndef MSG_RFID_DENSITY
  #define MSG_RFID_DENSITY                    _UxGT("Density: ")
#endif
#ifndef MSG_RFID_SPOOL_LENGHT
  #define MSG_RFID_SPOOL_LENGHT               _UxGT("Spool Lenght: ")
#endif

// EEPROM Allert
#ifndef MSG_EEPROM_CHANGED_ALLERT_1
  #define MSG_EEPROM_CHANGED_ALLERT_1         _UxGT("ATTENTION...")
#endif
#ifndef MSG_EEPROM_CHANGED_ALLERT_2
  #define MSG_EEPROM_CHANGED_ALLERT_2         _UxGT("EEPROM Changed.")
#endif
#ifndef MSG_EEPROM_CHANGED_ALLERT_3
  #define MSG_EEPROM_CHANGED_ALLERT_3         _UxGT("Press button")
#endif
#ifndef MSG_EEPROM_CHANGED_ALLERT_4
  #define MSG_EEPROM_CHANGED_ALLERT_4         _UxGT("to continue...")
#endif

#endif // LANGUAGE_EN_H
