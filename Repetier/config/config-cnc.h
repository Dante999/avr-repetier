#ifndef CONFIG_CNC_H
#define CONFIG_CNC_H

// ##########################################################################################
// ##                              CNC configuration                                       ##
// ##########################################################################################

/*
If the firmware is in CNC mode, it can control a mill with M3/M4/M5. It works 
similar to laser mode, but mill keeps enabled during G0 moves and it allows
setting rpm (only with event extension that supports this) and milling direction.
It also can add a delay to wait for spindle to run on full speed.
*/

#define SUPPORT_CNC 0 // Set 1 for CNC support
#define CNC_WAIT_ON_ENABLE 300 // wait x milliseconds after enabling
#define CNC_WAIT_ON_DISABLE 0 // delay in milliseconds after disabling spindle. May be required for direction changes.
#define CNC_ENABLE_PIN -1 // Pin to enable mill
#define CNC_ENABLE_WITH 1 // Set 0 if low enables spindle
#define CNC_DIRECTION_PIN -1 // Set to pin if direction control is possible
#define CNC_DIRECTION_CW 1 // Set signal required for clockwise rotation
#define CNC_PWM_MAX 255  //255 8-bit PWM 4095 for 12Bit PWM
#define CNC_RPM_MAX 25000   //max spindle RPM
#define CNC_SAFE_Z 150  // Safe Z height so tool is outside object, used for pause

/* Select the default mode when the printer gets enables. Possible values are
PRINTER_MODE_FFF 0
PRINTER_MODE_LASER 1
PRINTER_MODE_CNC 2
*/
#define DEFAULT_PRINTER_MODE PRINTER_MODE_FFF

#endif
