#ifndef CONFIG_LASER_H
#define CONFIG_LASER_H

// ##########################################################################################
// ##                             Laser configuration                                      ##
// ##########################################################################################

/*
If the firmware is in laser mode, it can control a laser output to cut or engrave materials.
Please use this feature only if you know about safety and required protection. Lasers are
dangerous and can hurt or make you blind!!!

The default laser driver only supports laser on and off. Here you control the intensity with
your feedrate. For exchangeable diode lasers this is normally enough. If you need more control
you can set the intensity in a range 0-255 with a custom extension to the driver. See driver.h
and comments on how to extend the functions non invasive with our event system.

If you have a laser - powder system you will like your E override. If moves contain a 
increasing extruder position it will laser that move. With this trick you can
use existing FDM slicers to laser the output. Laser width is extrusion width.

Other tools may use M3 and M5 to enable/disable laser. Here G1/G2/G3 moves have laser enabled
and G0 moves have it disables.

In any case, laser only enables while moving. At the end of a move it gets
automatically disabled. 
*/

#define SUPPORT_LASER 0 // set 1 to enable laser support
#define LASER_PIN -1    // set to pin enabling laser
#define LASER_ON_HIGH 1 // Set 0 if low signal enables laser
#define LASER_WARMUP_TIME 0// wait x milliseconds to start material burning before move
#define LASER_PWM_MAX 255 //255 8-bit PWM 4095 for 12Bit PWM
#define LASER_WATT 1.6  // Laser diode power

#endif
