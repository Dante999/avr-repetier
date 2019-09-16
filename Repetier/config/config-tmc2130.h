#ifndef TMC2130_H
#define TMC2130_H


/** 
 * #############################################################################
 * #                        Trinamic TMC2130 driver configuration
 * #############################################################################
 *
 * If you want to use TMC2130 specific features uncomment next line and make
 * sure all following settings are correct. 
 *
 * You need this library to compile:
 * https://github.com/teemuatlut/TMC2130Stepper
 */
// #define DRV_TMC2130

/**
 * Uncomment if you use the stall guard for homing. Only for cartesian printers
 * and xy direction
 */
// #define SENSORLESS_HOMING


/**
 * The drivers with set CS pin will be used, all others are normal
 * step/dir/enable drivers
 */
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

/**
 * Per-axis current setting in mA { X, Y, Z, E0, E1, E2}
 */
#ifndef MOTOR_CURRENT
#define MOTOR_CURRENT {1000,1000,1000,1000,1000,1000} 
#endif

/** 
 * Global settings - these apply to all configured drivers
 * Per-axis values will override these
 */

/**
 * enable extremely quiet stepping
 *
 * 0 = off
 * 1 = on
 */
#define TMC2130_STEALTHCHOP 1

/**
 * Enable internal driver microstep interpolation
 */
#define TMC2130_INTERPOLATE_256 true

/**
 * Sensorless homing sensitivity (between -63 and +64)
 */
#define TMC2130_STALLGUARD 0

/** 
 * PWM values for chopper tuning only change if you know what you're doing
 */
#define TMC2130_PWM_AMPL          255
#define TMC2130_PWM_GRAD            1
#define TMC2130_PWM_AUTOSCALE    true
#define TMC2130_PWM_FREQ            2

/**  
 * Per-axis parameters
 *
 * To define different values for certain parameters on each axis, append
 * either _X, _Y, _Z, _EXT0, _EXT1 or _EXT2 to the name of the global
 * parameter.
 * 
 *   Examples for the X axis:
 * 
 *   #define TMC2130_STEALTHCHOP_X         1
 *   #define TMC2130_INTERPOLATE_256_X  true
 */

/** 
 * Minimum speeds for stall detection.
 * 
 *  These values may need to be adjusted if SENSORLESS_HOMING is enabled,
 *  but endstops trigger prematurely or don't trigger at all. 
 *  The exact value is dependent on the duration of one microstep,
 *  but good approximations can be determined by experimentation.
 */
#define TMC2130_TCOOLTHRS_X 300
#define TMC2130_TCOOLTHRS_Y 300
#define TMC2130_TCOOLTHRS_Z 300



#endif
