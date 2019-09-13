#ifndef CONFIG_MOVEMENT_H
#define CONFIG_MOVEMENT_H

// ##########################################################################################
// ##                           Movement settings                                          ##
// ##########################################################################################

// Microstep setting (Only functional when stepper driver microstep pins are connected to MCU. Currently only works for RAMBO boards
#define MICROSTEP_MODES {8,8,8,8,8} // [1,2,4,8,16]

// Motor Current setting (Only functional when motor driver current ref pins are connected to a digital trimpot on supported boards)
// Motor Current setting (Only functional when motor driver current ref pins are connected to a digital trimpot on supported boards)
#if MOTHERBOARD==301
//#define MOTOR_CURRENT {135,135,135,135,135} // Values 0-255 (RAMBO 135 = ~0.75A, 185 = ~1A)
#define MOTOR_CURRENT_PERCENT {53,53,53,53,53}
#elif MOTHERBOARD==12
//#define MOTOR_CURRENT {35713,35713,35713,35713,35713} // Values 0-65535 (3D Master 35713 = ~1A)
#define MOTOR_CURRENT_PERCENT {55,55,55,55,55}
#endif

/** \brief Number of segments to generate for delta conversions per second of move
*/
#define DELTA_SEGMENTS_PER_SECOND_PRINT 180 // Move accurate setting for print moves
#define DELTA_SEGMENTS_PER_SECOND_MOVE 70 // Less accurate setting for other moves

// Delta settings
#if DRIVE_SYSTEM==DELTA
/** \brief Delta rod length (mm)
*/
#define DELTA_DIAGONAL_ROD 345 // mm


/*  =========== Parameter essential for delta calibration ===================

            C, Y-Axis
            |                        |___| CARRIAGE_HORIZONTAL_OFFSET (recommend set it to 0)
            |                        |   \------------------------------------------
            |_________ X-axis        |    \                                        |
           / \                       |     \  DELTA_DIAGONAL_ROD (length)    Each move this Rod Height
          /   \                             \                                 is calculated
         /     \                             \    Carriage is at printer center!   |
         A      B                             \_____/--------------------------------
                                              |--| END_EFFECTOR_HORIZONTAL_OFFSET (recommend set it to 0)
                                         |----| ROD_RADIUS (Horizontal rod pivot to pivot measure)
                                     |-----------| PRINTER_RADIUS (recommend set it to ROD_RADIUS)

    Column angles are measured from X-axis counterclockwise
    "Standard" positions: alpha_A = 210, alpha_B = 330, alpha_C = 90
*/

/** \brief column positions - change only to correct build imperfections! */
#define DELTA_ALPHA_A 210
#define DELTA_ALPHA_B 330
#define DELTA_ALPHA_C 90

/** Correct radius by this value for each column. Perfect builds have 0 everywhere. */
#define DELTA_RADIUS_CORRECTION_A 0
#define DELTA_RADIUS_CORRECTION_B 0
#define DELTA_RADIUS_CORRECTION_C 0

/** Correction of the default diagonal size. Value gets added.*/
#define DELTA_DIAGONAL_CORRECTION_A 0
#define DELTA_DIAGONAL_CORRECTION_B 0
#define DELTA_DIAGONAL_CORRECTION_C 0

/** Max. radius (mm) the printer should be able to reach. */
#define DELTA_MAX_RADIUS 200

// Margin (mm) to avoid above tower minimum (xMin xMinsteps)
// If your printer can put its carriage low enough the rod is horizontal without hitting the floor
// set this to zero. Otherwise, measure how high the carriage is from horizontal rod
// Also, movement speeds are 10x to 20x cartesian speeds at tower bottom.
// You may need to leave a few mm for safety.
// Hitting floor at high speed can damage your printer (motors, drives, etc)
// THIS MAY NEED UPDATING IF THE HOT END HEIGHT CHANGES!
#define DELTA_FLOOR_SAFETY_MARGIN_MM 15

/** \brief Horizontal offset of the universal joints on the end effector (moving platform).
*/
#define END_EFFECTOR_HORIZONTAL_OFFSET 0

/** \brief Horizontal offset of the universal joints on the vertical carriages.
*/
#define CARRIAGE_HORIZONTAL_OFFSET 0

/** \brief Printer radius in mm,
  measured from the center of the print area to the vertical smooth tower.
  Alternately set this to the pivot to pivot horizontal rod distance, when head is at (0,0)
*/
#define PRINTER_RADIUS 124

/** 1 for more precise delta moves. 0 for faster computation.
Needs a bit more computation time. */
#define EXACT_DELTA_MOVES 1

/* ========== END Delta calibration data ==============*/

/** When true the delta will home to z max when reset/powered over cord. That way you start with well defined coordinates.
If you don't do it, make sure to home first before your first move.
*/
#define DELTA_HOME_ON_POWER 0

/** To allow software correction of misaligned endstops, you can set the correction in steps here. If you have EEPROM enabled
you can also change the values online and autoleveling will store the results here. */
#define DELTA_X_ENDSTOP_OFFSET_STEPS 0
#define DELTA_Y_ENDSTOP_OFFSET_STEPS 0
#define DELTA_Z_ENDSTOP_OFFSET_STEPS 0

#endif
#if DRIVE_SYSTEM==TUGA
// ========== Tuga special settings =============
/* Radius of the long arm in mm. */
#define DELTA_DIAGONAL_ROD 240
#endif

/** \brief Number of delta moves in each line. Moves that exceed this figure will be split into multiple lines.
Increasing this figure can use a lot of memory since 7 bytes * size of line buffer * MAX_SELTA_SEGMENTS_PER_LINE
will be allocated for the delta buffer.
PrintLine PrintLine::lines[PRINTLINE_CACHE_SIZE (default 16?)];
Printline is about 200 bytes + 7 * DELTASEGMENTS_PER_PRINTLINE
or 16 * (200 + (7*22=154) = 354) = 5664 bytes! !1
min is 5 * (200 + (7*10=70) =270) = 1350
 This leaves ~1K free RAM on an Arduino which has only 8k
Mega. Used only for nonlinear systems like delta or tuga. */
#define DELTASEGMENTS_PER_PRINTLINE 22

/** After x seconds of inactivity, the stepper motors are disabled.
    Set to 0 to leave them enabled.
    This helps cooling the Stepper motors between two print jobs.
    Overridden if EEPROM activated.
*/
#define STEPPER_INACTIVE_TIME 360
/** After x seconds of inactivity, the system will go down as far it can.
    It will at least disable all stepper motors and heaters. If the board has
    a power pin, it will be disabled, too.
    Set value to 0 for disabled.
    Overridden if EEPROM activated.
*/
#define MAX_INACTIVE_TIME 0L
/** Maximum feedrate, the system allows. Higher feedrates are reduced to these values.
    The axis order in all axis related arrays is X, Y, Z
     Overridden if EEPROM activated.
    */
#define MAX_FEEDRATE_X 200
#define MAX_FEEDRATE_Y 200
#define MAX_FEEDRATE_Z 5

/** Home position speed in mm/s. Overridden if EEPROM activated. */
#define HOMING_FEEDRATE_X 80
#define HOMING_FEEDRATE_Y 80
#define HOMING_FEEDRATE_Z 20

/** Set order of axis homing. Use HOME_ORDER_XYZ and replace XYZ with your order. 
 * If you measure Z with your extruder tip you need a hot extruder to get right measurement. In this
 * case set HOME_ORDER_ZXYTZ and also define ZHOME_HEAT_HEIGHT and ZHOME_MIN_TEMPERATURE. It will do
 * first a z home to get some reference, then raise to ZHOME_HEAT_HEIGHT do xy homing and then after
 * heating to minimum ZHOME_MIN_TEMPERATURE will z home again for correct height.   
 * */
#define HOMING_ORDER HOME_ORDER_ZXY
/*
  Raise Z before homing z axis
  0 = no
  1 = if z min is triggered
  2 = always
  This is for printers with z probe used as z min. For homing the probe must be
  at a minimum height for some endstop types, so raising it before will help
  to make sure this is guaranteed. 
*/
#define ZHOME_PRE_RAISE 0
// Distance in mm to raise if required
#define ZHOME_PRE_RAISE_DISTANCE 10

/*
 Raises Z before swapping extruder (tool change) and lowers it afterwards
 Unit is mm (INTEGER NUMBERS ONLY)
 */
#define RAISE_Z_ON_TOOLCHANGE 0

// Used for homing order HOME_ORDER_ZXYTZ
#define ZHOME_MIN_TEMPERATURE 0
// needs to heat all extruders (1) or only current extruder (0)
#define ZHOME_HEAT_ALL 1 
// Z-height for heating extruder during homing
#define ZHOME_HEAT_HEIGHT 20
// If your bed might bend while probing, because your sensor is the extruder tip
// you can define a predefined x,y position so bending is always the same and
// can be compensated. Set coordinate to 999999 to ignore positions and just
// use the position you are at.
#define ZHOME_X_POS IGNORE_COORDINATE
#define ZHOME_Y_POS IGNORE_COORDINATE

/* If you have a backlash in both z-directions, you can use this. For most printer, the bed will be pushed down by it's
own weight, so this is nearly never needed. */
#define ENABLE_BACKLASH_COMPENSATION 0
#define Z_BACKLASH 0
#define X_BACKLASH 0
#define Y_BACKLASH 0

/** Comment this to disable ramp acceleration */
#define RAMP_ACCELERATION 1

/** If your stepper needs a longer high signal then given, you can add a delay here.
The delay is realized as a simple loop wasting time, which is not available for other
computations. So make it as low as possible. For the most common drivers no delay is needed, as the
included delay is already enough.
*/
#define STEPPER_HIGH_DELAY 0

/** If your driver needs some additional delay between setting direction and first step signal,
 you can set this here. There are some commands between direction and signal, but some drivers
 might be even slower or you are using a fast Arduino board with slow driver. Normally 0 works.
 If you get skewed print, you might try 1 microsecond here.
 */
#define DIRECTION_DELAY 0
/** The firmware can only handle 16000Hz interrupt frequency cleanly. If you need higher speeds
a faster solution is needed, and this is to double/quadruple the steps in one interrupt call.
This is like reducing your 1/16th microstepping to 1/8 or 1/4. It is much cheaper then 1 or 3
additional stepper interrupts with all it's overhead. As a result you can go as high as
40000Hz.
*/
#define STEP_DOUBLER_FREQUENCY 12000
/** If you need frequencies off more then 30000 you definitely need to enable this. If you have only 1/8 stepping
enabling this may cause to stall your moves when 20000Hz is reached.
*/
#define ALLOW_QUADSTEPPING 1
/** If you reach STEP_DOUBLER_FREQUENCY the firmware will do 2 or 4 steps with nearly no delay. That can be too fast
for some printers causing an early stall.

*/
#define DOUBLE_STEP_DELAY 0 // time in microseconds

/** If the firmware is busy, it will send a busy signal to host signaling that
 everything is fine and it only takes a bit longer to finish. That way the 
 host can keep timeout short so in case of communication errors the resulting
 blobs are much smaller. Set to 0 to disable it. */
#define KEEP_ALIVE_INTERVAL 2000
//// Acceleration settings

/** \brief X, Y, Z max acceleration in mm/s^2 for printing moves or retracts. Make sure your printer can go that high!
 Overridden if EEPROM activated.
*/
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X 1000
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1000
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z 100

/** \brief X, Y, Z max acceleration in mm/s^2 for travel moves.  Overridden if EEPROM activated.*/
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X 2000
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y 2000
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z 100
/** If you print on a moving bed, it can become more shaky the higher and bigger
 your print gets. Therefore it might be helpfull to reduce acceleration with
 increasing print height. You can define here how acceleration should change.
 You set ACCELERATION_FACTOR_TOP to the factor in percent for the top position
 of your printer. Acceleration will then be modified linear over height.
 INTERPOLATE_ACCELERATION_WITH_Z sets, which accelerations get changed:
 0 = do not interpolate at all
 1 = interpolate x and y acceleration
 2 = interpolate z acceleration
 3 = interpolate x,y and z acceleration
  */
#define INTERPOLATE_ACCELERATION_WITH_Z 0
#define ACCELERATION_FACTOR_TOP 100

/** \brief Maximum allowable jerk.

Caution: This is no real jerk in a physical meaning.

The jerk determines your start speed and the maximum speed at the join of two segments.
Its unit is mm/s. If the printer is standing still, the start speed is jerk/2. At the
join of two segments, the speed difference is limited to the jerk value.

Examples:
For all examples jerk is assumed as 40.

Segment 1: vx = 50, vy = 0
Segment 2: vx = 0, vy = 50
v_diff = sqrt((50-0)^2+(0-50)^2) = 70.71
v_diff > jerk => vx_1 = vy_2 = jerk/v_diff*vx_1 = 40/70.71*50 = 28.3 mm/s at the join

Segment 1: vx = 50, vy = 0
Segment 2: vx = 35.36, vy = 35.36
v_diff = sqrt((50-35.36)^2+(0-35.36)^2) = 38.27 < jerk
Corner can be printed with full speed of 50 mm/s

Overridden if EEPROM activated.
*/
#define MAX_JERK 20.0
#define MAX_ZJERK 0.3

/** \brief Number of moves we can cache in advance.

This number of moves can be cached in advance. If you want to cache more, increase this. Especially on
many very short moves the cache may go empty. The minimum value is 5.
*/
#define PRINTLINE_CACHE_SIZE 16

/** \brief Low filled cache size.

If the cache contains less then MOVE_CACHE_LOW segments, the time per segment is limited to LOW_TICKS_PER_MOVE clock cycles.
If a move would be shorter, the feedrate will be reduced. This should prevent buffer underflows. Set this to 0 if you
don't care about empty buffers during print.
*/
#define MOVE_CACHE_LOW 10
/** \brief Cycles per move, if move cache is low.

This value must be high enough, that the buffer has time to fill up. The problem only occurs at the beginning of a print or
if you are printing many very short segments at high speed. Higher delays here allow higher values in PATH_PLANNER_CHECK_SEGMENTS.
*/
#define LOW_TICKS_PER_MOVE 250000


#endif
