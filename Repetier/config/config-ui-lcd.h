#ifndef CONFIG_UI_LCD_H
#define CONFIG_UI_LCD_H

/** For displays and keys there are too many permutations to handle them all in once.
For the most common available combinations you can set the controller type here, so
you don't need to configure uicong.h at all. Controller settings > 1 disable usage
of uiconfig.h

0 or NO_CONTROLLER = no display
1 or UICONFIG_CONTROLLER = Manual definition of display and keys parameter in uiconfig.h

The following settings override uiconfig.h!
2 or CONTROLLER_SMARTRAMPS = Smartcontroller from reprapdiscount on a RAMPS or RUMBA board
3 or CONTROLLER_ADAFRUIT = Adafruit RGB controller
4 or CONTROLLER_FOLTYN = Foltyn 3DMaster with display attached
5 or CONTROLLER_VIKI = ViKi LCD - Check pin configuration in ui.h for feature controller 5!!! sd card disabled by default!
6 or CONTROLLER_MEGATRONIC = ReprapWorld Keypad / LCD, predefined pins for Megatronics v2.0 and RAMPS 1.4. Please check if you have used the defined pin layout in ui.h.
7 or CONTROLLER_RADDS = RADDS Extension Port
8 or CONTROLLER_PIBOT20X4 = PiBot Display/Controller extension with 20x4 character display
9 or CONTROLLER_PIBOT16X2 = PiBot Display/Controller extension with 16x2 character display
10 or CONTROLLER_GADGETS3D_SHIELD = Gadgets3D shield on RAMPS 1.4, see http://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
11 or CONTROLLER_REPRAPDISCOUNT_GLCD = RepRapDiscount Full Graphic Smart Controller
12 or CONTROLLER_FELIX = FELIXPrinters Controller
13 or CONTROLLER_RAMBO = SeeMeCNC Display on Rambo (ORION)
14 or CONTROLLER_OPENHARDWARE_LCD2004 = OpenHardware.co.za LCD2004 V2014
15 or CONTROLLER_SANGUINOLOLU_PANELOLU2 = Sanguinololu + Panelolu2
16 or CONTROLLER_GAMEDUINO2 (in development)
17 or CONTROLLER_MIREGLI 17
18 or CONTROLLER_GATE_3NOVATICA Gate Controller from 3Novatica
21 or CONTROLLER_VIKI2 Panucatt VIKI2 graphic lcd
24 or CONTROLLER_ZONESTAR = Zonestar P802M with LCD 20x4 and 5 ADC button keypad
25 or CONTROLLER_ORCABOTXXLPRO2 
26 or CONTROLLER_AZSMZ_12864 
405 or CONTROLLER_FELIX_DUE Felix LCD für due based board
27 or CONTROLLER_REPRAPWORLD_GLCD = ReprapWorld Graphical LCD
*/

#define FEATURE_CONTROLLER CONTROLLER_REPRAPDISCOUNT_GLCD

/* You can have one keypad connected via single analog pin as seen on
 some printers with Melzi V2.0 board, 20x4 LCD and 5 buttons keypad. This must be
 the analog pin number! */
#define ADC_KEYPAD_PIN -1

/**
Select the languages to use. On first startup user can select
the language from a menu with activated languages. In Configuration->Language
the language can be switched any time. 
On 8 bit processors do not active all or you run out of text memory (64kb)
and strange errors occur. 8-9 languages normally work.
*/
#define LANGUAGE_EN_ACTIVE 1 // English
#define LANGUAGE_DE_ACTIVE 1 // German
#define LANGUAGE_NL_ACTIVE 0 // Dutch
#define LANGUAGE_PT_ACTIVE 0 // Brazilian Portuguese
#define LANGUAGE_IT_ACTIVE 0 // Italian
#define LANGUAGE_ES_ACTIVE 0 // Spanish
#define LANGUAGE_FI_ACTIVE 0 // Finnish
#define LANGUAGE_SE_ACTIVE 0 // Swedish
#define LANGUAGE_FR_ACTIVE 0 // French
#define LANGUAGE_CZ_ACTIVE 0 // Czech
#define LANGUAGE_PL_ACTIVE 0 // Polish
#define LANGUAGE_TR_ACTIVE 0 // Turkish

/* Some displays loose their settings from time to time. Try uncommenting the
auto-repair function if this is the case. It is not supported for all display
types. It creates a minimal flicker from time to time and also slows down
computations, so do not enable it if your display works stable!
*/
//#define TRY_AUTOREPAIR_LCD_ERRORS

// This is line 2 of the status display at startup. Change to your like.
#define UI_PRINTER_NAME "Werkstatt"
#define UI_PRINTER_COMPANY "Bier"


/** For graphic displays you can have a fixed top line. It can also contain
 * dynamic modifiers. Do not define it if you want full 6 rows of data */
//#define UI_HEAD "E1:%e0/%E0 E2:%e1/%E1 B:%eb/%Eb"

/** How many ms should a single page be shown, until it is switched to the next one.*/
#define UI_PAGES_DURATION 4000

/** Delay of start screen in milliseconds */
#define UI_START_SCREEN_DELAY 1000
/** Uncomment if you don't want automatic page switching. You can still switch the
info pages with next/previous button/click-encoder */
#define UI_DISABLE_AUTO_PAGESWITCH 1

/** Time to return to info menu if x milliseconds no key was pressed. Set to 0 to disable it. */
#define UI_AUTORETURN_TO_MENU_AFTER 30000

#define FEATURE_UI_KEYS 0

/* Normally cou want a next/previous actions with every click of your encoder.
Unfortunately, the encoder have a different count of phase changes between clicks.
Select an encoder speed from 0 = fastest to 2 = slowest that results in one menu move per click.
*/
#define UI_ENCODER_SPEED 2

// Set to 1 to reverse encoder direction
#define UI_REVERSE_ENCODER 0

/* There are 2 ways to change positions. You can move by increments of 1/0.1 mm resulting in more menu entries
and requiring many turns on your encode. The alternative is to enable speed dependent positioning. It will change
the move distance depending on the speed you turn the encoder. That way you can move very fast and very slow in the
same setting.

*/
#define UI_SPEEDDEPENDENT_POSITIONING 1

/** If set to 1 faster turning the wheel makes larger jumps. Helps for faster navigation. */
#define UI_DYNAMIC_ENCODER_SPEED 1          // enable dynamic rotary encoder speed


/** \brief bounce time of keys in milliseconds */
#define UI_KEY_BOUNCETIME 10

/** \brief First time in ms until repeat of action. */
#define UI_KEY_FIRST_REPEAT 500
/** \brief Reduction of repeat time until next execution. */
#define UI_KEY_REDUCE_REPEAT 50
/** \brief Lowest repeat time. */
#define UI_KEY_MIN_REPEAT 50

/**
 * Enable/Disable to onboard beeper
 * 
 * 0 = disable
 * 1 = enable
 */
#define FEATURE_BEEPER 0

/**
Beeper sound definitions for short beeps during key actions
and longer beeps for important actions.
Parameter is delay in microseconds and the second is the number of repetitions.
Values must be in range 1..255
*/
#define BEEPER_SHORT_SEQUENCE 2,2
#define BEEPER_LONG_SEQUENCE 8,8

// ###############################################################################
// ##                         Values for menu settings                          ##
// ###############################################################################

/*
If you have leveling with bed coating or fixed z min you can use this menu to adjust 
0 height with a simple bed coating menu which adds coating thickness.
*/
#define UI_BED_COATING 0
// Extreme values
#define UI_SET_MIN_HEATED_BED_TEMP  50
#define UI_SET_MAX_HEATED_BED_TEMP 120
#define UI_SET_MIN_EXTRUDER_TEMP   160
#define UI_SET_MAX_EXTRUDER_TEMP   270
#define UI_SET_EXTRUDER_FEEDRATE 2 // mm/sec
#define UI_SET_EXTRUDER_RETRACT_DISTANCE 3 // mm


/*
#define USER_KEY1_PIN     UI_DISPLAY_D5_PIN      // D5 to display (not used for graphics controller), change to other pin if you use character LCD !
#define USER_KEY1_ACTION  UI_ACTION_FAN_SUSPEND
#define USER_KEY2_PIN     UI_DISPLAY_D6_PIN      // D6 to display (not used for graphics controller)...
#define USER_KEY2_ACTION  UI_ACTION_SD_PRI_PAU_CONT
#define USER_KEY3_PIN     UI_DISPLAY_D7_PIN      // D7 to display (not used for graphics controller)...
#define USER_KEY3_ACTION  UI_ACTION_LIGHTS_ONOFF
#define USER_KEY4_PIN     -1
#define USER_KEY4_ACTION  UI_ACTION_DUMMY
*/


// ####### Advanced stuff for very special function #########

#define NUM_MOTOR_DRIVERS 0
// #define MOTOR_DRIVER_x StepperDriver<int stepPin, int dirPin, int enablePin,bool invertDir, bool invertEnable>(float stepsPerMM,float speed)
// #define MOTOR_DRIVER_x StepperDriverWithEndstop<int stepPin, int dirPin, int enablePin,bool invertDir, bool invertEnable,int endstop_pin,bool minEndstop,minEndstop, bool endstopPullup> var(300,10,50)
#define MOTOR_DRIVER_1(var) StepperDriver<E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, false, false> var(float stepsPerMM,float speed,float maxXPos)

/*
  You can expand firmware functionality with events and you own event handler.
  Read Events.h for more informations. To activate, uncomment the following define.
*/
//#define CUSTOM_EVENTS


#endif
