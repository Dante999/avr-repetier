#ifndef CONFIG_GENERAL_H
#define CONFIG_GENERAL_H


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

#include "../pins.h"

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
 *
 * M320 = Enable Autolevel
 */
#define STARTUP_GCODE "M320"


// ##########################################################################################
// ##                           Communication configuration                                ##
// ##########################################################################################

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
 * Some boards like Gen7 have a power on pin, to enable the ATX power supply. If
 * this is defined, the power will be turned on without the need to call M80 if
 * initially started.
 */
#define ENABLE_POWER_ON_STARTUP 1

/**
 * If you use an ATX power supply you need the power pin to work non inverting.
 * For some special boards you might need to make it inverting.
 */
#define POWER_INVERTING 0

/** 
 * Automatically enable power when temperatures or moves/homing is used. Set
 * only to 1 if you have a power unit controlled by PS_ON_PIN! 
 */
#define AUTOMATIC_POWERUP 0

/** 
 * What shall the printer do, when it receives an M112 emergency stop signal?
 *
 * 0 = Disable heaters/motors, wait forever until someone presses reset.  
 * 1 = restart by resetting the AVR controller. The USB connection will not 
 *     reset if managed by a different chip!
 */
#define KILL_METHOD 1

/** 
 * Appends the line number after every ok send, to acknowledge the received
 * command. Uncomment for plain ok ACK if your host has problems with this 
 */
#define ACK_WITH_LINENUMBER 1

/** 
 * Communication errors can swallow part of the ok, which tells the host
 * software to send the next command. Not receiving it will cause your printer
 * to stop. Sending this string every second, if our queue is empty should
 * prevent this. Comment it, if you don't want this feature. 
 */
#define WAITING_IDENTIFIER "wait"

/** 
 * Sets time for echo debug
 *
 * You can set M111 1 which enables ECHO of commands sent. This define specifies the position,
 * when it will be executed. In the original FiveD software, echo is done after receiving the
 * command. With checksum you know, how it looks from the sending string. With this define
 * uncommented, you will see the last command executed. To be more specific: It is written after
 * execution. This helps tracking errors, because there may be 8 or more commands in the queue
 * and it is elsewise difficult to know, what your reprap is currently doing.
 */
#define ECHO_ON_EXECUTE 1

/** 
 * EEPROM storage mode
 * 
 * Set the EEPROM_MODE to 0 if you always want to use the settings in this
 * configuration file. If not, set it to a value not stored in the first
 * EEPROM-byte used. If you later want to overwrite your current EEPROM settings
 * with configuration defaults, just select an other value. On the first call to
 * epr_init() it will detect a mismatch of the first byte and copy default
 * values into EEPROM. If the first byte matches, the stored values are used to
 * overwrite the settings.
 * 
 * IMPORTANT: With mode <>0 some changes in Configuration.h are not set any
 * more, as they are taken from the EEPROM.
 */
#define EEPROM_MODE 0


/**
 * maximum positions in mm - only fixed numbers!
 *
 * For delta robot Z_MAX_LENGTH is the maximum travel of the towers and should
 * be set to the distance between the hotend and the platform when the printer
 * is at its home position.
 * 
 * If EEPROM is enabled these values will be overridden with the values in the
 * EEPROM
 */
#define X_MAX_LENGTH 230
#define Y_MAX_LENGTH 205
#define Z_MAX_LENGTH 180

/**
 * Coordinates for the minimum axis. Can also be negative if you want to have
 * the bed start at 0 and the printer can go to the left side of the bed.
 * Maximum coordinate is given by adding the above X_MAX_LENGTH values.
 */
#define X_MIN_POS -40
#define Y_MIN_POS -15
#define Z_MIN_POS 0


#endif




