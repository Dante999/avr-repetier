#ifndef CONFIG_EXTRUDER_H
#define CONFIG_EXTRUDER_H


// ##########################################################################################
// ##                           Extruder configuration                                     ##
// ##########################################################################################

/** 
 * You can use either PWM (pulse width modulation) or PDM (pulse density
 * modulation) for extruders or coolers. PDM will give more signal changes per
 * second, so on average it gives the cleaner signal. The only advantage of PWM
 * is giving signals at a fixed rate and never more then PWM.
 */
#define PDM_FOR_EXTRUDER  1
#define PDM_FOR_COOLER    1

/**
 * #############################################################################
 * # Security Checks
 * #############################################################################
 *
 * The firmware checks if the heater and sensor got decoupled, which is
 * dangerous. Since it will never reach target temperature, the heater will stay
 * on for every which can burn your printer or house.  As an additional barrier
 * to your smoke detectors (I hope you have one above your printer) we now do
 * some more checks to detect if something got wrong.
 */

/** 
 * If the temp. is on hold target, it may not sway more then this degrees
 * celsius, or we mark sensor as defect.
 */
#define DECOUPLING_TEST_MAX_HOLD_VARIANCE 20

/** 
 * Minimum temp. rise we expect after the set duration of full heating is over.
 * Always keep a good safety margin to get no false positives. If your period is
 * e.g. 10 seconds because at startup you already need 7 seconds until heater
 * starts to rise temp. for sensor then you have 3 seconds of increased heating
 * to reach 1°C.
 */
#define DECOUPLING_TEST_MIN_TEMP_RISE 1

/**
 *  Set to 1 if you want firmware to kill print on decouple
 */
#define KILL_IF_SENSOR_DEFECT 0


/*
 * #############################################################################
 */



/**
 * for each extruder, fan will stay on until extruder temperature is below this
 * value
 */ 
#define EXTRUDER_FAN_COOL_TEMP 50

/**
 *  Retraction for sd pause over lcd
 */
#define RETRACT_ON_PAUSE 2

/**
 *  These commands get executed after storing position and going to park position.
 */
#define PAUSE_START_COMMANDS ""

/**
 *  These commands get executed before we go to stored position.
 */
#define PAUSE_END_COMMANDS ""

/**
 * Set to 1 if all extruders use the same heater block. Temp. control is then 
 * always controlled by settings in extruder 0 definition. 
 */
#define SHARED_EXTRUDER_HEATER 0

/** 
 * Speed in mm/s for extruder moves fom internal commands, e.g. switching
 * extruder. 
 */
#define EXTRUDER_SWITCH_XY_SPEED 100

/** 
 * Extruder offsets in steps not mm!
 */
#define EXT0_X_OFFSET 0
#define EXT0_Y_OFFSET 0
#define EXT0_Z_OFFSET 0

#define EXT1_X_OFFSET 0
#define EXT1_Y_OFFSET 0
#define EXT1_Z_OFFSET 0

/**
 * for skeinforge 40 and later, steps to pull the plastic 1 mm inside the 
 * extruder, not out.  
 * 
 * Overridden if EEPROM activated.
 */
#define EXT0_STEPS_PER_MM 413
#define EXT1_STEPS_PER_MM 373

/**
 * What type of sensor is used?
 *
 *   0 = no thermistor/temperature control
 *   1 = 100k thermistor (Epcos B57560G0107F000 - RepRap-Fab.org and many other)
 *   2 = 200k thermistor
 *   3 = mendel-parts thermistor (EPCOS G550)
 *   4 = 10k thermistor
 *   5 = userdefined thermistor table 0
 *   6 = userdefined thermistor table 1
 *   7 = userdefined thermistor table 2
 *   8 = ATC Semitec 104GT-2
 *  12 = 100k RS thermistor 198-961
 *  13 = PT100 for E3D/Ultimaker
 *  14 = 100K NTC 3950
 *  15 = DYZE DESIGN 500°C Thermistor
 *  16 = B3 innovations 500°C sensor
 *  50 = userdefined thermistor table 0 for PTC thermistors
 *  51 = userdefined thermistor table 0 for PTC thermistors
 *  52 = userdefined thermistor table 0 for PTC thermistors
 *  60 = AD8494, AD8495, AD8496 or AD8497 (5mV/degC and 1/4 the price of AD595 
 *       but only MSOT_08 package)
 *  61 = AD8494, AD8495, AD8496 or AD8497 (5mV/degC and 1.25 Vref offset like 
 *       adafruit breakout)
 *  97 = Generic thermistor table 1
 *  98 = Generic thermistor table 2
 *  99 = Generic thermistor table 3
 * 100 = AD595
 * 101 = MAX6675
 * 102 = MAX31855
 */
#define EXT0_TEMPSENSOR_TYPE 1
#define EXT1_TEMPSENSOR_TYPE 3

/** 
 * Analog input pin for reading temperatures or pin enabling SS for MAX6675
 */
#define EXT0_TEMPSENSOR_PIN   TEMP_0_PIN
#define EXT1_TEMPSENSOR_PIN   TEMP_2_PIN

/**
 * Which pin enables the heater
 */
#define EXT0_HEATER_PIN   HEATER_0_PIN
#define EXT0_STEP_PIN     E0_STEP_PIN
#define EXT0_DIR_PIN      E0_DIR_PIN

#define EXT1_HEATER_PIN   HEATER_2_PIN
#define EXT1_STEP_PIN     E1_STEP_PIN
#define EXT1_DIR_PIN      E1_DIR_PIN


/**
 * set to false/true for normal / inverse direction
 */
#define EXT0_INVERSE      true
#define EXT1_INVERSE      false

#define EXT0_ENABLE_PIN   E0_ENABLE_PIN
#define EXT1_ENABLE_PIN   E1_ENABLE_PIN

/**
 * For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active
 * High) use 1
 */
#define EXT0_ENABLE_ON   0
#define EXT1_ENABLE_ON   0

/* 
 * Set to 1 to mirror motor. Pins for mirrored motor are below 
 */
#define EXT0_MIRROR_STEPPER   0
#define EXT0_STEP2_PIN        E0_STEP_PIN
#define EXT0_DIR2_PIN         E0_DIR_PIN
#define EXT0_INVERSE2         false
#define EXT0_ENABLE2_PIN      E0_ENABLE_PIN

#define EXT1_MIRROR_STEPPER   0
#define EXT1_STEP2_PIN        E0_STEP_PIN
#define EXT1_DIR2_PIN         E0_DIR_PIN
#define EXT1_INVERSE2         false
#define EXT1_ENABLE2_PIN      E0_ENABLE_PIN


/**
 * The following speed settings are for skeinforge 40+ where e is the length of
 * filament pulled inside the heater. For repsnap or older skeinforge use higher
 * values.
 *
 * Overridden if EEPROM activated.
 */
#define EXT0_MAX_FEEDRATE 30
#define EXT1_MAX_FEEDRATE 25

/**
 * Feedrate from halted extruder in mm/s
 * Overridden if EEPROM activated.
 */
#define EXT0_MAX_START_FEEDRATE 10
#define EXT1_MAX_START_FEEDRATE 12

/**
 * Acceleration in mm/s^2
 * 
 * Overridden if EEPROM activated.
 */
#define EXT0_MAX_ACCELERATION 4000
#define EXT1_MAX_ACCELERATION 10000

/** 
 * Type of heat manager for this extruder.
 *
 * 0 = Simply switch on/off if temperature is reached. Works always.
 * 1 = PID Temperature control. Is better but needs good PID values. Defaults
 *     are a good start for most extruder.
 * 3 = Dead-time control. PID_P becomes dead-time in seconds.
 * 
 * Overridden if EEPROM activated.
*/
#define EXT0_HEAT_MANAGER 1
#define EXT1_HEAT_MANAGER 1

/** 
 * Wait x seconds, after reaching target temperature. Only used for M109.  
 *
 * Overridden if EEPROM activated. 
 */
#define EXT0_WATCHPERIOD 1
#define EXT1_WATCHPERIOD 1






/**
 * lower value for integral part
 *
 * The I state should converge to the exact heater output needed for the target
 * temperature.  To prevent a long deviation from the target zone, this value
 * limits the lower value.  A good start is 30 lower then the optimal value. You
 * need to leave room for cooling.
 * 
 * Overridden if EEPROM activated.
 */
#define EXT0_PID_INTEGRAL_DRIVE_MIN 60
#define EXT1_PID_INTEGRAL_DRIVE_MIN 60

/** 
 * The maximum value, I-gain can contribute to the output.
 * 
 * A good value is slightly higher then the output needed for your temperature.
 * Values for starts:
 *
 * 130 => PLA for temperatures from 170-180 deg C
 * 180 => ABS for temperatures around 240 deg C
 * 
 * The precise values may differ for different nozzle/resistor combination.
 * 
 * Overridden if EEPROM activated.
 */
#define EXT0_PID_INTEGRAL_DRIVE_MAX 140
#define EXT1_PID_INTEGRAL_DRIVE_MAX 130

/** 
 * P-gain.
 * 
 * Overridden if EEPROM activated. 
 */
#define EXT0_PID_PGAIN_OR_DEAD_TIME   24
#define EXT1_PID_PGAIN_OR_DEAD_TIME   24

/** 
 * I-gain.
 *
 * Overridden if EEPROM activated.
 */
#define EXT0_PID_I   0.88
#define EXT1_PID_I   0.88

/** 
 * Dgain.  
 *
 * Overridden if EEPROM activated.
 */
#define EXT0_PID_D 80
#define EXT1_PID_D 200

/**
 * [0-255] Determines maximum power for the heater.
 *
 * Overridden if EEPROM activated.
 */
#define EXT0_PID_MAX 255
#define EXT1_PID_MAX 255

/** 
 * Faktor for the advance algorithm. 0 disables the algorithm. 
 * 
 * K is the factor for the quadratic term, which is normally disabled in newer
 * versions. If you want to use the quadratic factor make sure
 * ENABLE_QUADRATIC_ADVANCE is defined.
 * 
 * L is the linear factor and seems to be working better then the quadratic
 * dependency.
 *
 * Overridden if EEPROM activated.
 */
#define EXT0_ADVANCE_K 0.0f
#define EXT0_ADVANCE_L 0.0f
#define EXT1_ADVANCE_K 0.0f
#define EXT1_ADVANCE_L 0.0f



/* 
 * Motor steps to remove backlash for advance algorithm. These are the steps
 * needed to move the motor cog in reverse direction until it hits the driving
 * cog. Direct drive extruder need 0. 
 */
#define EXT0_ADVANCE_BACKLASH_STEPS 0
#define EXT1_ADVANCE_BACKLASH_STEPS 0

/** 
 * Temperature to retract filament when extruder is heating up. 
 *
 * Overridden if EEPROM activated.
 */
#define EXT0_WAIT_RETRACT_TEMP 150
#define EXT1_WAIT_RETRACT_TEMP 150

/** 
 * Units (mm/inches) to retract filament when extruder is heating up. 
 *
 * Set to 0 to disable.
 *
 * Overridden if EEPROM activated.
 */
#define EXT0_WAIT_RETRACT_UNITS 0
#define EXT1_WAIT_RETRACT_UNITS 0


/** 
 * You can run any GCODE command on extruder deselect/select. Separate multiple
 * commands with a new line \n. That way you can execute some mechanical
 * components needed for extruder selection or retract filament or whatever you
 * need. The codes are only executed for multiple extruder when changing the
 * extruder. 
 */
#define EXT0_SELECT_COMMANDS "M117 Extruder 1"
#define EXT1_SELECT_COMMANDS "M117 Extruder 2"
#define EXT0_DESELECT_COMMANDS ""
#define EXT1_DESELECT_COMMANDS ""




/** 
 * #############################################################################
 * # Extruder Cooler
 * #############################################################################
 *
 * The extruder cooler is a fan to cool the extruder when it is heating. If you
 * turn the extruder on, the fan goes on. 
 */
#define EXT0_EXTRUDER_COOLER_PIN -1
#define EXT1_EXTRUDER_COOLER_PIN -1

/** 
 * PWM speed for the cooler fan. 
 *
 * 0=off 255=full speed 
 * */
#define EXT0_EXTRUDER_COOLER_SPEED 255
#define EXT1_EXTRUDER_COOLER_SPEED 255

//##############################################################################




/** 
 * Time in ms between a heater action and test of success. Must be more then
 * time between turning heater on and first temp. rise!  0 will disable
 * decoupling test 
 */
#define EXT0_DECOUPLE_TEST_PERIOD 18000
#define EXT1_DECOUPLE_TEST_PERIOD 18000

/** 
 * #############################################################################
 * # Filament Jam detection 
 * #############################################################################
 */

/** 
 * Pin which toggles regularly during extrusion allowing jam control. 
 *
 * -1 = disabled 
 */
#define EXT0_JAM_PIN -1
#define EXT1_JAM_PIN -1

/** 
 * Pull-up resistor for jam pin? 
 */
#define EXT0_JAM_PULLUP false
#define EXT1_JAM_PULLUP false

/* Define how we detect jam/out of filament
 *
 * 1 = Distance between signal changes increase
 * 2 = signal gets high
 * 3 = signal gets low
 * 
 * 2 and 3 are not jam detections, but only out of filament detection by a
 * switch that changes the signal! 
 */
#define JAM_METHOD 1

/**
 * Steps normally needed for a full signal cycle.
 */
#define JAM_STEPS 220

/** 
 * Steps for reducing speed. Must be higher then JAM_STEPS
 */
#define JAM_SLOWDOWN_STEPS 380

/** 
 * New speed multiplier which gets set when slowdown is reached.
 */
#define JAM_SLOWDOWN_TO 70

/**
 * Last fallback. If we slip this much, we want to pause.
 */
#define JAM_ERROR_STEPS 430

/** 
 * To prevent signal bouncing, only consider changes if we are this much steps
 * away from last signal change. 
 */
#define JAM_MIN_STEPS 10

/**
 * Determine what should be done if a jam is detected
 *
 * 0 = Nothing, just mark extruder as jammed.
 * 1 = Jam/out of filament dialog and block communication.
 * 2 = Message to host/server otherwise continue and mark extruder jammed
 */
#define JAM_ACTION 1

//##############################################################################







/**
 * Temperature when using preheat 
 */
#define EXT0_PREHEAT_TEMP 190
#define EXT1_PREHEAT_TEMP 190




/** 
 * If enabled you can select the distance your filament gets retracted during a
 * M140 command, after a given temperature is reached. 
 */
#define RETRACT_DURING_HEATUP 1

/** 
 * Allow retraction with G10/G11 removing requirement for retraction setting in
 * slicer. Also allows filament change if lcd is configured. 
 */
#define FEATURE_RETRACTION 1

/** 
 * auto-retract converts pure extrusion moves into retractions. Beware that
 * simple extrusion e.g. over Repetier-Host will then not work! 
 */
#define AUTORETRACT_ENABLED 0
#define RETRACTION_LENGTH 3
#define RETRACTION_LONG_LENGTH 13
#define RETRACTION_SPEED 40
#define RETRACTION_Z_LIFT 0
#define RETRACTION_UNDO_EXTRA_LENGTH 0
#define RETRACTION_UNDO_EXTRA_LONG_LENGTH 0
#define RETRACTION_UNDO_SPEED 20


/**
 * #############################################################################
 * # Filament Change
 * #############################################################################
 */

/**
 * If you have a lcd display, you can do a filament switch with M600.  It will
 * change the current extruders filament and temperature must already be high
 * enough.
 */
#define FILAMENTCHANGE_X_POS 0
#define FILAMENTCHANGE_Y_POS 0
#define FILAMENTCHANGE_Z_ADD 1

/** 
 * Does a homing procedure after a filament change. This is good in case
 * you moved the extruder while changing filament during print.
 *
 * 0 = no homing
 * 1 = xy homing
 * 2 = xyz homing
 */
#define FILAMENTCHANGE_REHOME 1

/** 
 * Will first retract short distance, go to change position and then retract longretract.
 * Retractions speeds are taken from RETRACTION_SPEED and RETRACTION_UNDO_SPEED
 */
#define FILAMENTCHANGE_SHORTRETRACT 30
#define FILAMENTCHANGE_LONGRETRACT 30

//##############################################################################


/** 
 * PID control only works target temperature +/- PID_CONTROL_RANGE.  If you get
 * much overshoot at the first temperature set, because the heater is going full
 * power too long, you need to increase this value. For one 6.8 Ohm heater 10 is
 * ok. With two 6.8 Ohm heater use 15.
 */
#define PID_CONTROL_RANGE 20

/** 
 * Prevent extrusions longer then x mm for one command. This is especially
 * important if you abort a print. Then the extrusion position might be at any
 * value like 23344. If you then have an G1 E-2 it will roll back 23 meter! 
 */
#define EXTRUDE_MAXLENGTH 100

/** 
 * Skip wait, if the extruder temperature is already within x degrees. Only
 * fixed numbers, 
 *
 * 0 = off 
 */
#define SKIP_M109_IF_WITHIN 2

/**
 * Set PID scaling
 * 
 * PID values assume a usable range from 0-255. This can be further limited to
 * EXT0_PID_MAX by to methods. 
 *
 * 0 = Normal computation, just  clip output to EXT0_PID_MAX if computed value 
 *     is too high. 
 * 1 = Scale PID by EXT0_PID_MAX/256 and then clip to EXT0_PID_MAX. If your
 *     EXT0_PID_MAX is low, you should prefer the second method.
 */
#define SCALE_PID_TO_MAX 0

/**
 * PWM Frequency
 *
 * 0 = 15.25Hz
 * 1 = 30.51Hz
 * 2 = 61.03Hz
 * 3 = 122.06Hz
 */
#define HEATER_PWM_SPEED 1 
















/** Temperature range for target temperature to hold in M109 command. 5 means +/-5 degC

Uncomment define to force the temperature into the range for given watch period.
*/
//#define TEMP_HYSTERESIS 5

/** Userdefined thermistor table

There are many different thermistors, which can be combined with different resistors. This result
in unpredictable number of tables. As a resolution, the user can define one table here, that can
be used as type 5 for thermistor type in extruder/heated bed definition. Make sure, the number of entries
matches the value in NUM_TEMPS_USERTHERMISTOR0. If you span definition over multiple lines, make sure to end
each line, except the last, with a backslash. The table format is {{adc1,temp1},{adc2,temp2}...} with
increasing adc values. For more informations, read
http://hydraraptor.blogspot.com/2007/10/measuring-temperature-easy-way.html

If you have a sprinter temperature table, you have to multiply the first value with 4 and the second with 8.
This firmware works with increased precision, so the value reads go from 0 to 4095 and the temperature is
temperature*8.

If you have a PTC thermistor instead of a NTC thermistor, keep the adc values increasing and use thermistor types 50-52 instead of 5-7!
*/
/** Number of entries in the user thermistor table 0. Set to 0 to disable it. */
#define NUM_TEMPS_USERTHERMISTOR0 28
#define USER_THERMISTORTABLE0  {\
  {1*4,864*8},{21*4,300*8},{25*4,290*8},{29*4,280*8},{33*4,270*8},{39*4,260*8},{46*4,250*8},{54*4,240*8},{64*4,230*8},{75*4,220*8},\
  {90*4,210*8},{107*4,200*8},{128*4,190*8},{154*4,180*8},{184*4,170*8},{221*4,160*8},{265*4,150*8},{316*4,140*8},{375*4,130*8},\
  {441*4,120*8},{513*4,110*8},{588*4,100*8},{734*4,80*8},{856*4,60*8},{938*4,40*8},{986*4,20*8},{1008*4,0*8},{1018*4,-20*8}	}

/** Number of entries in the user thermistor table 1. Set to 0 to disable it. */
#define NUM_TEMPS_USERTHERMISTOR1 0
#define USER_THERMISTORTABLE1  {}
/** Number of entries in the user thermistor table 2. Set to 0 to disable it. */
#define NUM_TEMPS_USERTHERMISTOR2 0
#define USER_THERMISTORTABLE2  {}

/** If defined, creates a thermistor table at startup.

If you don't feel like computing the table on your own, you can use this generic method. It is
a simple approximation which may be not as accurate as a good table computed from the reference
values in the datasheet. You can increase precision if you use a temperature/resistance for
R0/T0, which is near your operating temperature. This will reduce precision for lower temperatures,
which are not really important. The resistors must fit the following schematic:
@code
VREF ---- R2 ---+--- Termistor ---+-- GND
                |                 |
                +------ R1 -------+
                |                 |
                +---- Capacitor --+
                |
                V measured
@endcode

If you don't have R1, set it to 0.
The capacitor is for reducing noise from long thermistor cable. If you don't have one, it's OK.

If you need the generic table, uncomment the following define.
*/
//#define USE_GENERIC_THERMISTORTABLE_1

/**
 * Some examples for different thermistors:
 *
 * ------------------------------------
 * EPCOS B57560G104+
 * -> T0   = 25  
 * -> R0   = 100000  
 * -> Beta = 4036
 *
 * ------------------------------------
 * EPCOS 100K Thermistor (B57560G1104F)
 * -> T0   = 25  
 * -> R0   = 100000  
 * -> Beta = 4092
 *
 * ------------------------------------
 * ATC Semitec 104GT-2
 * -> T0   = 25 
 * -> R0   = 100000  
 * -> Beta = 4267
 *
 * ------------------------------------
 * Honeywell 100K Thermistor (135-104LAG-J01)
 * -> T0   = 25
 * -> R0   = 100000  
 * -> Beta = 3974
 *
 */

/** 
 * Reference Temperature [°C]
 */
#define GENERIC_THERM1_T0 25

/** 
 * Resistance at reference temperature [Ohm]
 */
#define GENERIC_THERM1_R0 100000

/**
 * Beta value of thermistor
 *
 * You can use the beta from the datasheet or compute it yourself.
 * See http://reprap.org/wiki/MeasuringThermistorBeta for more details.
 */
#define GENERIC_THERM1_BETA 4036

/** 
 * Start temperature for generated thermistor table [°C]
 */
#define GENERIC_THERM1_MIN_TEMP -20

/** 
 * End Temperature for generated thermistor table [°C]
 */
#define GENERIC_THERM1_MAX_TEMP 300
#define GENERIC_THERM1_R1 0
#define GENERIC_THERM1_R2 4700

// The same for table 2 and 3 if needed

//#define USE_GENERIC_THERMISTORTABLE_2
#define GENERIC_THERM2_T0 170
#define GENERIC_THERM2_R0 1042.7
#define GENERIC_THERM2_BETA 4036
#define GENERIC_THERM2_MIN_TEMP -20
#define GENERIC_THERM2_MAX_TEMP 300
#define GENERIC_THERM2_R1 0
#define GENERIC_THERM2_R2 4700

//#define USE_GENERIC_THERMISTORTABLE_3
#define GENERIC_THERM3_T0 170
#define GENERIC_THERM3_R0 1042.7
#define GENERIC_THERM3_BETA 4036
#define GENERIC_THERM3_MIN_TEMP -20
#define GENERIC_THERM3_MAX_TEMP 300
#define GENERIC_THERM3_R1 0
#define GENERIC_THERM3_R2 4700

/** Supply voltage to ADC, can be changed by setting ANALOG_REF below to different value. */
#define GENERIC_THERM_VREF 5
/** Number of entries in generated table. One entry takes 4 bytes. Higher number of entries increase computation time too.
Value is used for all generic tables created. */
#define GENERIC_THERM_NUM_ENTRIES 33

// uncomment the following line for MAX6675 support.
//#define SUPPORT_MAX6675
// uncomment the following line for MAX31855 support.
//#define SUPPORT_MAX31855

#endif
