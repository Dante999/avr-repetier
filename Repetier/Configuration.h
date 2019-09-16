/**

 * 
 * Repetier-Firmware is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Repetier-Firmware is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H


/**
 * #############################################################################
 * ##                                        IMPORTANT                          
 * #############################################################################
 * 
 * Some words on units: From 0.80 onwards the units used are unified for easier
 * configuration, watch out when transferring from older configs!
 * 
 * Speed is in mm/s
 * Acceleration in mm/s^2
 * Temperature is in degrees Celsius
 * 
 * For easy configuration, the default settings enable parameter storage in
 * EEPROM.  This means, after the first upload many variables can only be
 * changed using the special M commands as described in the documentation.
 * Changing these values in the configuration.h file has no effect. Parameters
 * overridden by EEPROM settings are calibration values, extruder values except
 * thermistor tables and some other parameter likely to change during usage like
 * advance steps or ops mode.
 *
 * To override EEPROM settings with config settings, set EEPROM_MODE 0
 * 
 */


/**
 * #############################################################################
 * # inclusions
 * #############################################################################
 */

#include "config/config-general.h"
#include "config/config-calibration.h"
#include "config/config-extruder.h"
#include "config/config-heatbed.h"
#include "config/config-laser.h"
#include "config/config-cnc.h"
#include "config/config-endstop.h"
#include "config/config-movement.h"
#include "config/config-extruder-control.h"
#include "config/config-sdcard.h"
#include "config/config-servo.h"
#include "config/config-z-probe.h"
#include "config/config-ui-lcd.h"



/*
 * #############################################################################
 * # duplicate motor driver
 * #############################################################################
 * 
 * If you have unused extruder steppers free, you could use it to drive the
 * second or third z motor instead of driving them with a single stepper. The
 * same works for the other axis if needed.
 */

#define FEATURE_TWO_XSTEPPER 0
#define X2_STEP_PIN     E1_STEP_PIN
#define X2_DIR_PIN      E1_DIR_PIN
#define X2_ENABLE_PIN   E1_ENABLE_PIN

/* 
 * Dual x axis mean having a printer with x motors and each controls one
 * extruder position. In that case you can also have different resolutions for
 * the 2 motors. 
 */
#define DUAL_X_AXIS 0
#define DUAL_X_RESOLUTION 0
#define X2AXIS_STEPS_PER_MM 100


#define FEATURE_TWO_YSTEPPER 0
#define Y2_STEP_PIN     E1_STEP_PIN
#define Y2_DIR_PIN      E1_DIR_PIN
#define Y2_ENABLE_PIN   E1_ENABLE_PIN

#define FEATURE_TWO_ZSTEPPER 0
#define Z2_STEP_PIN     E1_STEP_PIN
#define Z2_DIR_PIN      E1_DIR_PIN
#define Z2_ENABLE_PIN   E1_ENABLE_PIN

#define FEATURE_THREE_ZSTEPPER 0
#define Z3_STEP_PIN     E2_STEP_PIN
#define Z3_DIR_PIN      E2_DIR_PIN
#define Z3_ENABLE_PIN   E2_ENABLE_PIN

#define FEATURE_FOUR_ZSTEPPER 0
#define Z4_STEP_PIN     E2_STEP_PIN
#define Z4_DIR_PIN      E2_DIR_PIN
#define Z4_ENABLE_PIN   E2_ENABLE_PIN


/*
 * Ditto printing allows 2 extruders to do the same action. This effectively
 * allows to print an object two times at the speed of one. Works only with dual
 * extruder setup.
 */
#define FEATURE_DITTO_PRINTING 0





/**
 * #############################################################################
 * # Feature: Watchdog
 * #############################################################################
 *
 * A watchdog resets the printer, if a signal is not send within predefined time
 * limits. That way we can be sure that the board is always running and is not
 * hung up for some unknown reason. 
 *
 * 0 = disable
 * 1 = enable (default)
 */
#define FEATURE_WATCHDOG 1


/** 
 * #############################################################################
 * # Feature: Axis Compensation
 * #############################################################################
 *
 * If your printer is not exactly square but is more like a parallelogram, you
 * can use this to compensate the effect of printing squares like
 * parallelograms. Set the parameter to then tangents of the deviation from 90°
 * when you print a square object.  E.g. if you angle is 91° enter tan(1) =
 * 0.017. If error doubles you have the wrong sign.  Always hard to say since
 * the other angle is 89° in this case!
 */
#define FEATURE_AXISCOMP 0
#define AXISCOMP_TANXY 0
#define AXISCOMP_TANYZ 0
#define AXISCOMP_TANXZ 0



/**
 * Experimental calibration utility for delta printers
 */
#define FEATURE_SOFTWARE_LEVELING 0

/** 
 * #############################################################################
 * # Feature: Baby Stepping
 * #############################################################################
 * 
 * Babystepping allows to change z height during print without changing official
 * z height 
 */
#define FEATURE_BABYSTEPPING 0

/**
 * If you have a threaded rod, you want a higher multiplicator to see an effect.
 * Limit value to 50 or you get easily overflows.
 */
#define BABYSTEP_MULTIPLICATOR 1


/** 
 * #############################################################################
 * # Feature: Case Light
 * #############################################################################
 */
#define CASE_LIGHTS_PIN -1
#define CASE_LIGHT_DEFAULT_ON 1











/**
 * If you want support for G2/G3 arc commands set to true, otherwise false.
 */
#define ARC_SUPPORT 1



/** 
 * #############################################################################
 * # Feature: Memory Position
 * #############################################################################
 *
 * You can store the current position with M401 and go back to it with M402.
 * This works only if feature is set to true. 
 */
#define FEATURE_MEMORY_POSITION 1



/** 
 * #############################################################################
 * # Feature: Checksum Forced
 * #############################################################################
 *
 * If a checksum is sent, all future commands must also contain a checksum. 
 * Increases reliability especially for binary protocol. 
 */
#define FEATURE_CHECKSUM_FORCED 0

/**
 * #############################################################################
 * # Feature: Filament Fan
 * #############################################################################
 */

/**
 *
 * Enable fan control (M106/M107) for filament cooling.
 *
 * Should support for fan control be compiled in. If you enable this make sure
 * the FAN pin is not the same as for your second extruder. RAMPS e.g. has
 * FAN_PIN in 9 which is also used for the heater if you have 2 extruders
 * connected. 
 */
#define FEATURE_FAN_CONTROL 1

/**
 * You can have a second fan controlled by adding P1 to M106/M107 command. 
 */
#define FEATURE_FAN2_CONTROL 0
//#define FAN2_PIN ORIG_FAN2_PIN

/** 
 * Some fans won't start for low values, but would run if started with higher
 * power at the beginning.  This defines the full power duration before
 * returning to set value. Time is in milliseconds 
 */
#define FAN_KICKSTART_TIME  200

/** 
 * Defines the max. fan speed for M106 controlled fans. Normally 255 to use full
 * range, but for 12V fans on 24V this might help preventing a defect. For all
 * other fans there is a explicit maximum PWM value you can set, so this is not
 * used for other fans! 
 */
#define MAX_FAN_PWM 255





/* 
 * By setting FAN_BOARD_PIN to a pin number you get a board cooler. That fan
 * goes on as soon as moves occur. Mainly to prevent overheating of stepper
 * drivers. 
 */
//#undef FAN_BOARD_PIN
//#define FAN_BOARD_PIN ORIG_FAN_PIN

/** 
 * Speed of board fan when on.
 *
 * 0   = off 
 * 255 = max 
 */
#define BOARD_FAN_SPEED 255

/** 
 * Speed when no cooling is required. Normally 0 but if you need slightly cooling
 * it can be set here 
 */
#define BOARD_FAN_MIN_SPEED 0




/**
 * #############################################################################
 * # Feature: Additional Temperature Controlled Fan
 * #############################################################################
 *
 * You can have one additional fan controlled by a temperature. You can set
 * set at which temperature it should turn on and at which it should reach max. speed.
 */
#define FAN_THERMO_PIN -1
#define FAN_THERMO_MIN_PWM 128
#define FAN_THERMO_MAX_PWM 255
#define FAN_THERMO_MIN_TEMP 45
#define FAN_THERMO_MAX_TEMP 60

// Analog pin number or channel for due boards
#define FAN_THERMO_THERMISTOR_PIN -1
#define FAN_THERMO_THERMISTOR_TYPE 1




/**
 * #############################################################################
 * # Feature: Open Door Detection
 * #############################################################################
 * 
 * The door pin is to detect a door opening. This will prevent new command from
 * serial or sd card getting executed. It will not stop immediately. Instead it
 * lets the move buffer run empty so closing the door allows continuing the
 * print. The exact behavior might change in the future.
 */
#define DOOR_PIN -1
#define DOOR_PULLUP 1
#define DOOR_INVERTING 1




/**
 * #############################################################################
 * # Feature: JSON Support
 * ############################################################################# 
 *
 * Adds support for ESP8266 Duet web interface, PanelDue and probably some other
 * things. This essentially adds command M36/M408 and extends M20.  Since it
 * requires some memory do not enable it unless you have such a display!
 */
#define FEATURE_JSON 0


#endif
