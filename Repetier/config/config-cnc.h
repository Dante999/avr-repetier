#ifndef CONFIG_CNC_H
#define CONFIG_CNC_H

/**
 * #############################################################################
 * # CNC Configuration
 * #############################################################################
 *
 * If the firmware is in CNC mode, it can control a mill with M3/M4/M5. It works
 * similar to laser mode, but mill keeps enabled during G0 moves and it allows
 * setting rpm (only with event extension that supports this) and milling
 * direction.  It also can add a delay to wait for spindle to run on full speed.
 */

/**
 * Enable/Disable the CNC support
 *
 * 0 = disable
 * 1 = enable
 */
#define SUPPORT_CNC 0

/**
 * Wait x milliseconds after enabling
 */
#define CNC_WAIT_ON_ENABLE 300

/**
 * delay in milliseconds after disabling spindle. May be required for direction
 * changes.
 */
#define CNC_WAIT_ON_DISABLE 0

/**
 * Pin to enable mill
 */
#define CNC_ENABLE_PIN -1

/**
 * Set 0 if low enables spindle
 */
#define CNC_ENABLE_WITH 1

/**
 * Set to pin if direction control is possible
 */
#define CNC_DIRECTION_PIN -1

/**
 * Set signal required for clockwise rotation
 */
#define CNC_DIRECTION_CW 1

/**
 * 255 8-bit PWM 4095 for 12Bit PWM
 */
#define CNC_PWM_MAX 255

/**
 * max spindle rpm
 */
#define CNC_RPM_MAX 25000

/**
 * Safe Z height so tool is outside object, used for pause
 */
#define CNC_SAFE_Z 150

/**
 * Select the default mode when the printer gets enables. Possible values are
 */
// PRINTER_MODE_FFF 0
// PRINTER_MODE_LASER 1
// PRINTER_MODE_CNC 2

#define DEFAULT_PRINTER_MODE PRINTER_MODE_FFF

#endif
