#ifndef CONFIG_ENDSTOP_H
#define CONFIG_ENDSTOP_H

// ##########################################################################################
// ##                            Endstop configuration                                     ##
// ##########################################################################################

/** 
 * Set the values true where you have a hardware endstop. The Pin number is 
 * taken from pins.h.
 */
#define MIN_HARDWARE_ENDSTOP_X true
#define MIN_HARDWARE_ENDSTOP_Y true
#define MIN_HARDWARE_ENDSTOP_Z false
#define MAX_HARDWARE_ENDSTOP_X false
#define MAX_HARDWARE_ENDSTOP_Y false
#define MAX_HARDWARE_ENDSTOP_Z true


/** 
 * By default all endstops are pulled up to HIGH. You need a pull-up if you
 * use a mechanical endstop connected with GND. Set value to false for no 
 * pull-up nn this endstop.
 */
#define ENDSTOP_PULLUP_X_MIN false
#define ENDSTOP_PULLUP_Y_MIN false
#define ENDSTOP_PULLUP_Z_MIN false
#define ENDSTOP_PULLUP_X_MAX true
#define ENDSTOP_PULLUP_Y_MAX true
#define ENDSTOP_PULLUP_Z_MAX false


/**
 * set to true to invert the logic of the endstops
 */
#define ENDSTOP_X_MIN_INVERTING true
#define ENDSTOP_Y_MIN_INVERTING true
#define ENDSTOP_Z_MIN_INVERTING true
#define ENDSTOP_X_MAX_INVERTING false
#define ENDSTOP_Y_MAX_INVERTING false
#define ENDSTOP_Z_MAX_INVERTING true



// If you have a mirrored motor you can put a second endstop to that motor.
// On homing you would then need to trigge rboth endstops. Each endstop only 
// stopps one motor, so they are aligned after homing. After homing only the 
// first endstop gets used.

#define X2_MIN_PIN -1
#define X2_MAX_PIN -1
#define Y2_MIN_PIN -1
#define Y2_MAX_PIN -1
#define Z2_MINMAX_PIN -1

#define ENDSTOP_PULLUP_X2_MIN false
#define ENDSTOP_PULLUP_Y2_MIN false
#define ENDSTOP_PULLUP_Z2_MINMAX false
#define ENDSTOP_PULLUP_X2_MAX true
#define ENDSTOP_PULLUP_Y2_MAX true

#define ENDSTOP_X2_MIN_INVERTING true
#define ENDSTOP_Y2_MIN_INVERTING true
#define ENDSTOP_X2_MAX_INVERTING true
#define ENDSTOP_Y2_MAX_INVERTING true

#define MIN_HARDWARE_ENDSTOP_X2 false
#define MIN_HARDWARE_ENDSTOP_Y2 false
#define MAX_HARDWARE_ENDSTOP_X2 false
#define MAX_HARDWARE_ENDSTOP_Y2 false
#define MINMAX_HARDWARE_ENDSTOP_Z2 false



//If your axes are only moving in one direction, make sure the endstops are connected properly.
//If your axes move in one direction ONLY when the endstops are triggered, set ENDSTOPS_INVERTING to true here

// ##########################################################################################
// TWEAK SETTINGS
// ##########################################################################################

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0

// Disables axis when it's not being used.
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
#define DISABLE_E false

/* If you want to keep z motor running on stepper timeout, remove comments below.
  This may be useful if your z bed moves when motors are disabled. Will still
  turn z off when heaters get also disabled. 
*/
//#define PREVENT_Z_DISABLE_ON_STEPPER_TIMEOUT

/**
 * Inverting motor direction. Only in case of pure cartesian printers, this
 * is also the axis you invert!
 */
#define INVERT_X_DIR 1
#define INVERT_Y_DIR 1
#define INVERT_Z_DIR 0

#define INVERT_X2_DIR 0
#define INVERT_Y2_DIR 0
#define INVERT_Z2_DIR 0
#define INVERT_Z3_DIR 0
#define INVERT_Z4_DIR 0

//// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR 1



/** 
 * If during homing the endstop is reached, ho many mm should the printer move 
 * back for the second try
 */
#define ENDSTOP_X_BACK_MOVE 5
#define ENDSTOP_Y_BACK_MOVE 5
#define ENDSTOP_Z_BACK_MOVE 2

/** 
 * When you have several endstops in one circuit you need to disable it after 
 * homing by moving a small amount back. This is also the case with H-belt 
 * systems.
 */
#define ENDSTOP_X_BACK_ON_HOME 1
#define ENDSTOP_Y_BACK_ON_HOME 1
#define ENDSTOP_Z_BACK_ON_HOME 0

/**
 * For higher precision you can reduce the speed for the second test on the 
 * endstop during homing operation. The homing speed is divided by the value. 
 * 
 * 1 = same speed
 * 2 = half speed
 */
#define ENDSTOP_X_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_Y_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_Z_RETEST_REDUCTION_FACTOR 2


/** 
 * If you do z min homing, you might want to rise extruder a bit after homing 
 * so it does not heat touching your bed.
 */
#define Z_UP_AFTER_HOME 0

/**
 * You can disable endstop checking for print moves. This is needed, if you get
 * sometimes false signals from your endstops. If your endstops don't give false 
 * signals, you can set it on for safety.
 */
#define ALWAYS_CHECK_ENDSTOPS 1

/**
 * Delta robot radius endstop
 */
#define max_software_endstop_r true

/**
 * If true, axis won't move to coordinates less than zero.
 */
#define min_software_endstop_x false
#define min_software_endstop_y false
#define min_software_endstop_z false

/**
 * If true, axis won't move to coordinates greater than the defined lengths 
 * below.
 */
#define max_software_endstop_x true
#define max_software_endstop_y true
#define max_software_endstop_z false


/** 
 * Park position used when pausing from firmware side
 */
#if DRIVE_SYSTEM == DELTA
	#define PARK_POSITION_X (0)
	#define PARK_POSITION_Y (70)
#else 
	#define PARK_POSITION_X (X_MIN_POS)
	#define PARK_POSITION_Y (Y_MIN_POS + Y_MAX_LENGTH)
#endif

#define PARK_POSITION_Z_RAISE 10

#endif
