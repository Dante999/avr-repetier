/**
 * This file is part of Repetier-Firmware.
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
 * ##########################################################################################
 * ##                                        IMPORTANT                                     ##
 * ##########################################################################################
 * 
 * Some words on units:
 * From 0.80 onwards the units used are unified for easier configuration, watch out when transferring from older configs!
 * 
 * Speed is in mm/s
 * Acceleration in mm/s^2
 * Temperature is in degrees Celsius
 * 
 * For easy configuration, the default settings enable parameter storage in EEPROM.
 * This means, after the first upload many variables can only be changed using the special
 * M commands as described in the documentation. Changing these values in the configuration.h
 * file has no effect. Parameters overridden by EEPROM settings are calibration values, extruder
 * values except thermistor tables and some other parameter likely to change during usage
 * like advance steps or ops mode.
 * To override EEPROM settings with config settings, set EEPROM_MODE 0
 * 
 */


/**
 * Number of extruders. Maximum 6 extruders. 
 */
#define NUM_EXTRUDER 1

/** 
 * Set to 1 if all extruder motors go to 1 nozzle that mixes your colors. 
 */
#define MIXING_EXTRUDER 0

/**
 * The following define selects which electronics board you have. 
 * Please choose the one that matches your setup
 * 
 * Gen3 PLUS for RepRap Motherboard V1.2 = 21
 * MEGA/RAMPS up to 1.2       = 3
 * RAMPS 1.3/RAMPS 1.4        = 33
 * Azteeg X3                  = 34
 * Azteeg X3 Pro              = 35
 * MPX3  (mainly RAMPS compatible) = 38
 * Ultimaker Shield 1.5.7     = 37
 * Gen6                       = 5
 * Gen6 deluxe                = 51
 * Sanguinololu up to 1.1     = 6
 * Sanguinololu 1.2 and above = 62
 * 3Drag/Velleman K8200       = 66 (experimental)
 * Open Motion Controller     = 91
 * Melzi board                = 63  // Define REPRAPPRO_HUXLEY if you have one for correct HEATER_1_PIN assignment!
 * Azteeg X1                  = 65
 * 3Drag/Velleman K8200 (experimental) = 66
 * Gen7 1.1 till 1.3.x        = 7
 * Gen7 1.4.1 and later       = 71
 * Sethi 3D_1                 = 72
 * Teensylu (at90usb)         = 8 // requires Teensyduino
 * Printrboard (at90usb)      = 9 // requires Teensyduino
 * Printrboard Ref. F or newer= 92 // requires Teensyduino
 * Foltyn 3D Master           = 12
 * MegaTronics 1.0            = 70
 * Megatronics 2.0            = 701
 * Megatronics 3.0            = 703 // Thermistors predefined not thermocouples
 * Minitronics 1.0            = 702
 * RUMBA                      = 80  // Get it from reprapdiscount
 * FELIXprinters              = 101
 * Rambo                      = 301
 * Rambo EInsy                = 310
 * PiBot for Repetier V1.0-1.3= 314
 * PiBot for Repetier V1.4    = 315
 * PiBot Controller V2.0      = 316
 * Sanguish Beta              = 501
 * Unique One rev. A          = 88
 * SAV MK1                    = 89
 * MJRice Pica Rev B          = 183
 * MJRice Pica Rev C          = 184
 * Zonestar ZRIB 2.1          = 39
 * User layout defined in userpins.h = 999
 */
#define MOTHERBOARD 80

#include "pins.h"

/**
 * Override pin definitions from pins.h
 * 
 * Extruder 2 uses the default fan output, so move to an other pin
 */
//#define FAN_PIN   4

/**
 * Override pin definitions from pins.h
 * 
 * use Arduino serial library instead of build in. Requires more ram, 
 * has only 63 byte input buffer.
 */
//#define EXTERNALSERIAL

/**
 * 
 * We can connect BlueTooth to serial converter module directly to 
 * boards based on AtMega2560 or AtMega1280 and some boards based on 
 * AtMega2561, AtMega1281 or AtMega1284p
 * 
 * - On Melzi boards connect BT to TX1 and RX1 pins, then set 
 *   BLUETOOTH_SERIAL to 1
 * - On RUMBA boards connect BT to pin 11 and 12 of X3 connector, then 
 *   set BLUETOOTH_SERIAL to 3
 * - On RAMBO boards connect BT to pins 5,6 or 7,8 or 9,10 on Serial 
 *   connector, then accordingly set BLUETOOTH_SERIAL to 1,2 or 3
 * - On RAMPS we must remap Y_ENDSTOPS pins or Z_ENDSTOPZ pins or 
 *   LCD_ENABLE and LCD_RS pins to another pins, and connect BT to:
 *     a) signals of Y_MIN, Y_MAX, then set BLUETOOTH_SERIAL to 3 
 *        (RX from BT to Y_MIN, TX from BT to Y_MAX)
 *     b) signals of Z_MIN, Z_MAX, then set BLUETOOTH_SERIAL to 1 
 *        (RX from BT to Z_MIN, TX from BT to Z_MAX)
 *     c) pin 17 and 18 of AUX4 connector, then set BLUETOOTH_SERIAL 
 *        to 2 (RX from BT to AUX4 p18, TX from BT to AUX4 p17)
 * 
 * Comment out or set the BLUETOOTH_SERIAL to 0 or -1 to disable this 
 * feature.
 */
 
/**
 * Port number (1..3) - For RUMBA use 3
 */
#define BLUETOOTH_SERIAL   1

/**
 * communication speed
 */
#define BLUETOOTH_BAUD     115200


/** Uncomment the following line if you are using Arduino compatible 
 * firmware made for Arduino version earlier then 1.0
 * If it is incompatible you will get compiler errors about write 
 * functions not being compatible!
 */
//#define COMPAT_PRE1

/**
 * Define the type of axis movements needed for your printer. 
 * The typical case is a full cartesian system where x, y and z moves 
 * are handled by separate motors.
 * 
 * 0 = full cartesian system, xyz have separate motors.
 * 1 = z axis + xy H-gantry (x_motor = x+y, y_motor = x-y)
 * 2 = z axis + xy H-gantry (x_motor = x+y, y_motor = y-x)
 * 3 = Delta printers (Rostock, Kossel, RostockMax, Cerberus, etc)
 * 4 = Tuga printer (Scott-Russell mechanism)
 * 5 = Bipod system (not implemented)
 * 8 = y axis + xz H-gantry (x_motor = x+z, z_motor = x-z)
 * 9 = y axis + xz H-gantry (x_motor = x+z, z_motor = z-x)
 * 
 * Cases 1, 2, 8 and 9 cover all needed xy and xz H gantry systems. 
 * If you get results mirrored etc. you can swap motor connections for 
 * x and y. If a motor turns in the wrong direction change INVERT_X_DIR 
 * or INVERT_Y_DIR.
 */
#define DRIVE_SYSTEM 0

/**
 * Normal core xy implementation needs 2 virtual steps for a motor step 
 * to guarantee that every tiny move gets maximum one step regardless of 
 * direction. This can cost some speed, so alternatively you can 
 * activate the FAST_COREXYZ by uncommenting the define. This solves the 
 * core movements as nonlinear movements like done for deltas but without 
 * the complicated transformations. Since transformations are still 
 * linear you can reduce delta computations per second to 10 and also 
 * use 10 subsegments instead of 20 to reduce memory usage.
 */
//#define FAST_COREXYZ

/** 
 * You can write some GCODE to be executed on startup. Use this e.g. to 
 * set some pins. Separate multiple GCODEs with \n
 */
#define STARTUP_GCODE "M320"

// ##########################################################################################
// ##                               inclusion                                            ##
// ##########################################################################################

#include "config/config-calibration.h"
#include "config/config-extruder.h"
#include "config/config-heatbed.h"
#include "config/config-laser.h"
#include "config/config-cnc.h"
#include "config/config-endstop.h"
#include "config/config-movement.h"
#include "config/config-extruder-control.h"


// ##########################################################################################
// ##                           Communication configuration                                ##
// ##########################################################################################

//// AD595 THERMOCOUPLE SUPPORT UNTESTED... USE WITH CAUTION!!!!

/**
 * 
 * 
 * - 250000 = Fastest with error rate of 0% with 16 or 32 MHz - 
 *            update wiring_serial.c in your board files. See boards/readme.txt
 * - 115200 = Fast, but may produce communication errors on quite regular basis, 
 *            Error rate -3,5%
 * - 76800  = Best setting for Arduino with 16 MHz, Error rate 0,2% page 198 
 *            AVR1284 Manual. Result: Faster communication then 115200
 * - 57600  = Should produce nearly no errors, on my gen 6 it's faster than 
 *            115200 because there are no errors slowing down the connection
 * - 38600
 *
 * Overridden if EEPROM activated.
 */
//#define BAUDRATE 76800
#define BAUDRATE 115200
//#define BAUDRATE 250000

/**
Some boards like Gen7 have a power on pin, to enable the ATX power supply. If this is defined,
the power will be turned on without the need to call M80 if initially started.
*/
#define ENABLE_POWER_ON_STARTUP 1

/**
If you use an ATX power supply you need the power pin to work non inverting. For some special
boards you might need to make it inverting.
*/
#define POWER_INVERTING 0

/** Automatically enable power when temperatures or moves/homing is used. Set only to 1 if
 *you have a power unit controlled by PS_ON_PIN! */
#define AUTOMATIC_POWERUP 0

/** What shall the printer do, when it receives an M112 emergency stop signal?
 0 = Disable heaters/motors, wait forever until someone presses reset.
 1 = restart by resetting the AVR controller. The USB connection will not reset if managed by a different chip!
*/
#define KILL_METHOD 1

/** Appends the line number after every ok send, to acknowledge the received command. Uncomment for plain ok ACK if your host has problems with this */
#define ACK_WITH_LINENUMBER 1
/** Communication errors can swallow part of the ok, which tells the host software to send
the next command. Not receiving it will cause your printer to stop. Sending this string every
second, if our queue is empty should prevent this. Comment it, if you don't want this feature. */
#define WAITING_IDENTIFIER "wait"

/** \brief Sets time for echo debug

You can set M111 1 which enables ECHO of commands sent. This define specifies the position,
when it will be executed. In the original FiveD software, echo is done after receiving the
command. With checksum you know, how it looks from the sending string. With this define
uncommented, you will see the last command executed. To be more specific: It is written after
execution. This helps tracking errors, because there may be 8 or more commands in the queue
and it is elsewise difficult to know, what your reprap is currently doing.
*/
#define ECHO_ON_EXECUTE 1

/** \brief EEPROM storage mode

Set the EEPROM_MODE to 0 if you always want to use the settings in this configuration file. If not,
set it to a value not stored in the first EEPROM-byte used. If you later want to overwrite your current
EEPROM settings with configuration defaults, just select an other value. On the first call to epr_init()
it will detect a mismatch of the first byte and copy default values into EEPROM. If the first byte
matches, the stored values are used to overwrite the settings.

IMPORTANT: With mode <>0 some changes in Configuration.h are not set any more, as they are
           taken from the EEPROM.
*/
#define EEPROM_MODE 0


/**************** duplicate motor driver ***************

If you have unused extruder steppers free, you could use it to drive the second or third z motor
instead of driving them with a single stepper. The same works for the other axis if needed.
*/

#define FEATURE_TWO_XSTEPPER 0
#define X2_STEP_PIN   E1_STEP_PIN
#define X2_DIR_PIN    E1_DIR_PIN
#define X2_ENABLE_PIN E1_ENABLE_PIN

/* Dual x axis mean having a printer with x motors and each controls one
extruder position. In that case you can also have different resolutions for the
2 motors. */
#define DUAL_X_AXIS 0
#define DUAL_X_RESOLUTION 0
#define X2AXIS_STEPS_PER_MM 100


#define FEATURE_TWO_YSTEPPER 0
#define Y2_STEP_PIN   E1_STEP_PIN
#define Y2_DIR_PIN    E1_DIR_PIN
#define Y2_ENABLE_PIN E1_ENABLE_PIN

#define FEATURE_TWO_ZSTEPPER 0
#define Z2_STEP_PIN   E1_STEP_PIN
#define Z2_DIR_PIN    E1_DIR_PIN
#define Z2_ENABLE_PIN E1_ENABLE_PIN

#define FEATURE_THREE_ZSTEPPER 0
#define Z3_STEP_PIN   E2_STEP_PIN
#define Z3_DIR_PIN    E2_DIR_PIN
#define Z3_ENABLE_PIN E2_ENABLE_PIN

#define FEATURE_FOUR_ZSTEPPER 0
#define Z4_STEP_PIN   E2_STEP_PIN
#define Z4_DIR_PIN    E2_DIR_PIN
#define Z4_ENABLE_PIN E2_ENABLE_PIN

/* Ditto printing allows 2 extruders to do the same action. This effectively allows
to print an object two times at the speed of one. Works only with dual extruder setup.
*/
#define FEATURE_DITTO_PRINTING 0


// ##########################################################################################
// ##                        Trinamic TMC2130 driver configuration                         ##
// ##########################################################################################

/* If you want to use TMC2130 specific features uncomment next line and make sure all
following settings are correct. 
You need this library to compile:
https://github.com/teemuatlut/TMC2130Stepper

*/

// #define DRV_TMC2130

// Uncomment if you use the stall guard for homing. Only for cartesian printers and xy direction
// #define SENSORLESS_HOMING

// The drivers with set CS pin will be used, all others are normal step/dir/enable drivers
#ifndef TMC2130_X_CS_PIN
#define TMC2130_X_CS_PIN -1
#endif
#ifndef TMC2130_Y_CS_PIN
#define TMC2130_Y_CS_PIN -1
#endif
#ifndef TMC2130_Z_CS_PIN
#define TMC2130_Z_CS_PIN -1
#endif
#ifndef TMC2130_EXT0_CS_PIN
#define TMC2130_EXT0_CS_PIN -1
#endif
#ifndef TMC2130_EXT1_CS_PIN
#define TMC2130_EXT1_CS_PIN -1
#endif
#ifndef TMC2130_EXT2_CS_PIN
#define TMC2130_EXT2_CS_PIN -1
#endif

// Per-axis current setting in mA { X, Y, Z, E0, E1, E2}
#ifndef MOTOR_CURRENT
#define MOTOR_CURRENT {1000,1000,1000,1000,1000,1000}
#endif

/**  Global settings - these apply to all configured drivers
     Per-axis values will override these
*/
#define TMC2130_STEALTHCHOP         1  // Enable extremely quiet stepping
#define TMC2130_INTERPOLATE_256  true  // Enable internal driver microstep interpolation
#define TMC2130_STALLGUARD          0  // Sensorless homing sensitivity (between -63 and +64)

/** PWM values for chopper tuning
    only change if you know what you're doing
*/
#define TMC2130_PWM_AMPL          255
#define TMC2130_PWM_GRAD            1
#define TMC2130_PWM_AUTOSCALE    true
#define TMC2130_PWM_FREQ            2

/**  Per-axis parameters

  To define different values for certain parameters on each axis,
  append either _X, _Y, _Z, _EXT0, _EXT1 or _EXT2 
  to the name of the global parameter.

  Examples for the X axis:

  #define TMC2130_STEALTHCHOP_X         1
  #define TMC2130_INTERPOLATE_256_X  true
*/

/** Minimum speeds for stall detection.

  These values may need to be adjusted if SENSORLESS_HOMING is enabled,
  but endstops trigger prematurely or don't trigger at all. 
  The exact value is dependent on the duration of one microstep,
  but good approximations can be determined by experimentation.
*/
#define TMC2130_TCOOLTHRS_X 300
#define TMC2130_TCOOLTHRS_Y 300
#define TMC2130_TCOOLTHRS_Z 300

/* Servos

If you need to control servos, enable this feature. You can control up to 4 servos.
Control the servos with
M340 P<servoId> S<pulseInUS>
servoID = 0..3
Servos are controlled by a pulse width normally between 500 and 2500 with 1500ms in center position. 0 turns servo off.

WARNING: Servos can draw a considerable amount of current. Make sure your system can handle this or you may risk your hardware!
*/

#define FEATURE_SERVO 0
// Servo pins on a RAMPS board are 11,6,5,4
#define SERVO0_PIN 11
#define SERVO1_PIN 6
#define SERVO2_PIN 5
#define SERVO3_PIN 4
/* for set servo(s) at designed neutral position at power-up. Values < 500 mean no start position */
#define SERVO0_NEUTRAL_POS  -1
#define SERVO1_NEUTRAL_POS  -1
#define SERVO2_NEUTRAL_POS  -1
#define SERVO3_NEUTRAL_POS  -1
/** Set to servo number +1 to control that servo in ui menu. 0 disables ui control. */
#define UI_SERVO_CONTROL 0

/** Some fans won't start for low values, but would run if started with higher power at the beginning.
This defines the full power duration before returning to set value. Time is in milliseconds */
#define FAN_KICKSTART_TIME  200
/** Defines the max. fan speed for M106 controlled fans. Normally 255 to use full range, but for
 12V fans on 24V this might help preventing a defect. For all other fans there is a explicit maximum PWM value
 you can set, so this is not used for other fans! */
#define MAX_FAN_PWM 255

/* A watchdog resets the printer, if a signal is not send within predefined time limits. That way we can be sure that the board
is always running and is not hung up for some unknown reason. */
#define FEATURE_WATCHDOG 1

#include "config/config-z-probe.h"

/* If your printer is not exactly square but is more like a parallelogram, you can
use this to compensate the effect of printing squares like parallelograms. Set the
parameter to then tangents of the deviation from 90° when you print a square object.
E.g. if you angle is 91° enter tan(1) = 0.017. If error doubles you have the wrong sign.
Always hard to say since the other angle is 89° in this case!
*/
#define FEATURE_AXISCOMP 0
#define AXISCOMP_TANXY 0
#define AXISCOMP_TANYZ 0
#define AXISCOMP_TANXZ 0



/** \brief Experimental calibration utility for delta printers
 * Change 1 to 0 to disable
*/
#define FEATURE_SOFTWARE_LEVELING 0

/* Babystepping allows to change z height during print without changing official z height */
#define FEATURE_BABYSTEPPING 0
/* If you have a threaded rod, you want a higher multiplicator to see an effect. Limit value to 50 or you get easily overflows.*/
#define BABYSTEP_MULTIPLICATOR 1

/* Define a pin to turn light on/off */
#define CASE_LIGHTS_PIN -1
#define CASE_LIGHT_DEFAULT_ON 1

/** Set to false to disable SD support: */
#ifndef SDSUPPORT  // Some boards have SD support on board. These define the values already in pins.h
#define SDSUPPORT false
// Uncomment to enable or change card detection pin. With card detection the card is mounted on insertion.
#undef SDCARDDETECT
#define SDCARDDETECT -1
// Change to true if you get a inserted message on removal.
#undef SDCARDDETECTINVERTED
#define SDCARDDETECTINVERTED false
#endif
/** Show extended directory including file length. Don't use this with Pronterface! */
#define SD_EXTENDED_DIR 1
/** The GCODEs in this line get executed, when you stop a SD print before it was ended.
Separate commands by \n */
#define SD_RUN_ON_STOP ""
/** Disable motors and heaters when print was stopped. */
#define SD_STOP_HEATER_AND_MOTORS_ON_STOP 1

// If you want support for G2/G3 arc commands set to true, otherwise false.
#define ARC_SUPPORT 1

/** You can store the current position with M401 and go back to it with M402.
   This works only if feature is set to true. */
#define FEATURE_MEMORY_POSITION 1

/** If a checksum is sent, all future commands must also contain a checksum. Increases reliability especially for binary protocol. */
#define FEATURE_CHECKSUM_FORCED 0

/** Should support for fan control be compiled in. If you enable this make sure
the FAN pin is not the same as for your second extruder. RAMPS e.g. has FAN_PIN in 9 which
is also used for the heater if you have 2 extruders connected. */
#define FEATURE_FAN_CONTROL 1

/* You can have a second fan controlled by adding P1 to M106/M107 command. */
#define FEATURE_FAN2_CONTROL 0
//#define FAN2_PIN ORIG_FAN2_PIN

/* By setting FAN_BOARD_PIN to a pin number you get a board cooler. That fan 
goes on as soon as moves occur. Mainly to prevent overheating of stepper drivers. */
//#undef FAN_BOARD_PIN
//#define FAN_BOARD_PIN ORIG_FAN_PIN
/** Speed of board fan when on. 0 = off, 255 = max */
#define BOARD_FAN_SPEED 255
/* Speed when no cooling is required. Normally 0 but if you need slightly cooling
it can be set here */
#define BOARD_FAN_MIN_SPEED 0
/* You can have one additional fan controlled by a temperature. You can set
   set at which temperature it should turn on and at which it should reach max. speed.
*/
#define FAN_THERMO_PIN -1
#define FAN_THERMO_MIN_PWM 128
#define FAN_THERMO_MAX_PWM 255
#define FAN_THERMO_MIN_TEMP 45
#define FAN_THERMO_MAX_TEMP 60
// Analog pin number or channel for due boards
#define FAN_THERMO_THERMISTOR_PIN -1
#define FAN_THERMO_THERMISTOR_TYPE 1

/** The door pin is to detect a door opening. This will prevent new command
 from serial or sd card getting executed. It will not stop immediately. Instead
 it lets the move buffer run empty so closing the door allows continuing the print.
 The exact behavior might change in the future.
  */
 
#define DOOR_PIN -1
#define DOOR_PULLUP 1
#define DOOR_INVERTING 1

/** Adds support for ESP8266 Duet web interface, PanelDue and probably some other things. 
 * This essentially adds command M36/M408 and extends M20.
 * Since it requires some memory do not enable it unless you have such a display!
 *  */
#define FEATURE_JSON 0

#include "config/config-ui-lcd.h"

#endif
