#ifndef CONFIG_Z_PROBE_H
#define CONFIG_Z_PROBE_H

/* Z-Probing */

#define FEATURE_Z_PROBE true

/**
 * Especially if you have more then 1 extruder acting as z probe this is 
 * important!
 */
#define EXTRUDER_IS_Z_PROBE 0

/**
 * the pin where the Z-Probe is connected to
 */
#define Z_PROBE_PIN 33

/**
 * activate/deactivate the pullup 
 * 
 * 0 = no pullup
 * 1 = pullup
 */
#define Z_PROBE_PULLUP 1

/**
 * invert the signal of the Z-Probe. Normally the Z-Probe should return LOW if it 
 * has no contact to the surface. If it touches the surface ist should return 
 * HIGH. If you Z-Probe returns an inverted signal (LOW when contact), you can 
 * invert the signal here. 
 * 
 * Run the Command G31 to test the probe signal. 
 * 
 * 0 = not inverted
 * 1 = inverted
 */
#define Z_PROBE_ON_HIGH 0

/**
 * How is z min measured
 * 0 = trigger is height of real bed neglecting coating
 * 1 = trigger is current coating
 *
 * For mode 1 the current coating thickness is added to measured z probe distances.
 * That way the real bed is always the reference height. For inductive sensors
 * or z min endstops the coating has no effect on the result, so you should use mode 0.
 */
#define Z_PROBE_Z_OFFSET_MODE 0

/**
 * offset to coating form real bed level
 * 
 * After homing the z position is corrected to compensate
 * for a bed coating. Since you can change coatings the value is stored in
 * EEPROM if enabled, so you can switch between different coatings without 
 * needing to recalibrate z.
 */
#define Z_PROBE_Z_OFFSET 0
#define Z_PROBE_X_OFFSET -21.5
#define Z_PROBE_Y_OFFSET -17.7

/** 
 * Distance between nozzle and bed when probe triggers. 
 */
#define Z_PROBE_HEIGHT 0.35

/**
 * Distance to safely switch off probe after it was activated
 * how much is needed to go up to untrigger probe 
 */
#define Z_PROBE_SWITCHING_DISTANCE 2.5

/**
 * Higher than max bed level distance error in mm
 */
#define Z_PROBE_BED_DISTANCE 6.0 

/**
 * Disable all heaters before probing - required for inductive sensors
 */
#define Z_PROBE_DISABLE_HEATERS 0

/**
 * Waits for a signal to start. Valid signals are probe hit and ok button.
 * This is needful if you have the probe trigger by hand.
 */
#define Z_PROBE_WAIT_BEFORE_TEST 0

/** 
 * Speed of z-axis in mm/s when probing 
 */
#define Z_PROBE_SPEED 2

/**
 * Speed of x-axis and y-axis in mms/s when probing
 */
#define Z_PROBE_XY_SPEED 150

/** 
 * Delay before going down. Needed for piezo endstops to reload safely. 
 */
#define Z_PROBE_DELAY 0

/**
 * Repetitions for probing at one point.
 */
#define Z_PROBE_REPETITIONS 5

/**
 * 0 = use average of measurements
 * 1 = use middle value
 */
#define Z_PROBE_USE_MEDIAN 0 

/** 
 * These scripts are run before resp. after the z-probe is done. Add here code 
 * to activate/deactivate probe if needed. 
 */
#define Z_PROBE_START_SCRIPT ""
#define Z_PROBE_FINISHED_SCRIPT ""

/** 
 * Set 1 if you need a hot extruder for good probe results. 
 * Normally only required if nozzle is probe. 
 */
#define Z_PROBE_REQUIRES_HEATING 0

/** 
 * Minimum extruder temperature for probing. If it is lower, it will be 
 * increased to that value. 
 */
#define Z_PROBE_MIN_TEMPERATURE 150

/*
 * Define how we measure the bed rotation. 
 * All methods need at least 3 points to define the bed rotation correctly. The quality we get comes
 * from the selection of the right points and method.
 * 
 * BED_LEVELING_METHOD 0
 * This method measures at the 3 probe points and creates a plane through these points. If you have
 * a really planar bed this gives the optimum result. The 3 points must not be in one line and have
 * a long distance to increase numerical stability.
 * 
 * BED_LEVELING_METHOD 1
 * This measures a grid. Probe point 1 is the origin and points 2 and 3 span a grid. We measure
 * BED_LEVELING_GRID_SIZE points in each direction and compute a regression plane through all
 * points. This gives a good overall plane if you have small bumps measuring inaccuracies.

 * BED_LEVELING_METHOD 2
 * Bending correcting 4 point measurement. This is for cantilevered beds that have the rotation axis
 * not at the side but inside the bed. Here we can assume no bending on the axis and a symmetric
 * bending to both sides of the axis. So probe points 2 and 3 build the symmetric axis and
 * point 1 is mirrored to 1m across the axis. Using the symmetry we then remove the bending
 * from 1 and use that as plane.
*/
#define BED_LEVELING_METHOD 1

/**
 *  How to correct rotation.
 * 0 = software side
 * 1 = motorized modification of 2 from 3 fixture points.
 */
#define BED_CORRECTION_METHOD 0

/**
 * Grid size for grid based plane measurement
 */
#define BED_LEVELING_GRID_SIZE 4

/**
 * Repetitions for motorized bed leveling
 */
#define BED_LEVELING_REPETITIONS 5

/**
 * These are the motor positions relative to bed origin. Only needed for
 * motorized bed leveling 
 */
#define BED_MOTOR_1_X 0
#define BED_MOTOR_1_Y 0
#define BED_MOTOR_2_X 200
#define BED_MOTOR_2_Y 0
#define BED_MOTOR_3_X 100
#define BED_MOTOR_3_Y 200

/* Autoleveling allows it to z-probe 3 points to compute the inclination and compensates the error for the print.
   This feature requires a working z-probe and you should have z-endstop at the top not at the bottom.
   The same 3 points are used for the G29 command.
*/
#define FEATURE_AUTOLEVEL 1
#define Z_PROBE_X1 100
#define Z_PROBE_Y1 20
#define Z_PROBE_X2 160
#define Z_PROBE_Y2 170
#define Z_PROBE_X3 20
#define Z_PROBE_Y3 170
/* Bending correction adds a value to a measured z-probe value. This may be
  required when the z probe needs some force to trigger and this bends the
  bed down. Currently the correction values A/B/C correspond to z probe
  positions 1/2/3. In later versions a bending correction algorithm might be
  introduced to give it other meanings.*/
#define BENDING_CORRECTION_A 0
#define BENDING_CORRECTION_B 0
#define BENDING_CORRECTION_C 0

/* DISTORTION_CORRECTION compensates the distortion caused by mechanical imprecisions of nonlinear (i.e. DELTA) printers
 * assumes that the floor is plain (i.e. glass plate)
 *     and that it is perpendicular to the towers
 *     and that the (0,0) is in center
 * requires z-probe
 * G33 measures the Z offset in matrix NxN points (due to nature of the delta printer, the corners are extrapolated instead of measured)
 * and compensate the distortion
 * more points means better compensation, but consumes more memory and takes more time
 * DISTORTION_CORRECTION_R is the distance of last row or column from center
 */

#define DISTORTION_CORRECTION         1
#define DISTORTION_CORRECTION_POINTS  5
/** Max. distortion value to enter. Used to prevent dangerous errors with big values. */
#define DISTORTION_LIMIT_TO 2
/* For delta printers you simply define the measured radius around origin */
#define DISTORTION_CORRECTION_R       80
/* For all others you define the correction rectangle by setting the min/max coordinates. Make sure the the probe can reach all points! */
#define DISTORTION_XMIN 10
#define DISTORTION_YMIN 10
#define DISTORTION_XMAX 190
#define DISTORTION_YMAX 190

/** 
 * Uses EEPROM instead of ram. Allows bigger matrix (up to 22x22) without any ram cost.
 * Especially on arm based systems with cached EEPROM it is good, on AVR it has a small
 * performance penalty.
 */
#define DISTORTION_PERMANENT          1

/** 
 * Correction computation is not a cheap operation and changes are only small. So it
 * is not necessary to update it for every sub-line computed. For example lets take DELTA_SEGMENTS_PER_SECOND_PRINT = 150
 * and fastest print speed 100 mm/s. So we have a maximum segment length of 100/150 = 0.66 mm.
 * Now lats say our point field is 200 x 200 mm with 9 x 9 points. So between 2 points we have
 * 200 / (9-1) = 25 mm. So we need at least 25 / 0.66 = 37 lines to move to the next measuring
 * point. So updating correction every 15 calls gives us at least 2 updates between the
 * measured points.
 * 
 * NOTE: Explicit z changes will always trigger an update!
*/
#define DISTORTION_UPDATE_FREQUENCY   15

/** 
 * z distortion degrades to 0 from this height on. You should start after the 
 * first layer to get best bonding with surface. 
 */
#define DISTORTION_START_DEGRADE 0.5

/** 
 * z distortion correction gets down to 0 at this height. 
 */
#define DISTORTION_END_HEIGHT 1.5

/** 
 * If your corners measurement points are not measurable with given radius, you
 * can set this to 1. It then omits the outer measurement points allowing a 
 * larger correction area.
 */
#define DISTORTION_EXTRAPOLATE_CORNERS 0

#endif
