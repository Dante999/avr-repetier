#ifndef CONFIG_HEATBED_H
#define CONFIG_HEATBED_H


/** \brief Set true if you have a heated bed connected to your board, false if not */
#define HAVE_HEATED_BED 1

#define HEATED_BED_MAX_TEMP 115
/** Skip M190 wait, if heated bed is already within x degrees. Fixed numbers only, 0 = off. */
#define SKIP_M190_IF_WITHIN 3

// Select type of your heated bed. It's the same as for EXT0_TEMPSENSOR_TYPE
// set to 0 if you don't have a heated bed
#define HEATED_BED_SENSOR_TYPE 1
/** Analog pin of analog sensor to read temperature of heated bed.  */
#define HEATED_BED_SENSOR_PIN TEMP_1_PIN
/** \brief Pin to enable heater for bed. */
#define HEATED_BED_HEATER_PIN HEATER_1_PIN
// How often the temperature of the heated bed is set (msec)
#define HEATED_BED_SET_INTERVAL 5000

/**
Heat manager for heated bed:
0 = Bang Bang, fast update
1 = PID controlled
2 = Bang Bang, limited check every HEATED_BED_SET_INTERVAL. Use this with relay-driven beds to save life time
3 = dead time control
*/
#define HEATED_BED_HEAT_MANAGER 1
/** \brief The maximum value, I-gain can contribute to the output.
The precise values may differ for different nozzle/resistor combination.
 Overridden if EEPROM activated.
*/
#define HEATED_BED_PID_INTEGRAL_DRIVE_MAX 255
/** \brief lower value for integral part

The I state should converge to the exact heater output needed for the target temperature.
To prevent a long deviation from the target zone, this value limits the lower value.
A good start is 30 lower then the optimal value. You need to leave room for cooling.
 Overridden if EEPROM activated.
*/
#define HEATED_BED_PID_INTEGRAL_DRIVE_MIN 80
/** P-gain.  Overridden if EEPROM activated. */
#define HEATED_BED_PID_PGAIN_OR_DEAD_TIME   196
/** I-gain  Overridden if EEPROM activated.*/
#define HEATED_BED_PID_IGAIN   33.02
/** Dgain.  Overridden if EEPROM activated.*/
#define HEATED_BED_PID_DGAIN 290
// maximum time the heater can be switched on. Max = 255.  Overridden if EEPROM activated.
#define HEATED_BED_PID_MAX 255
// Time to see a temp. change when fully heating. Consider that beds at higher temp. need longer to rise and cold
// beds need some time to get the temp. to the sensor. Time is in milliseconds! Set 0 to disable
#define HEATED_BED_DECOUPLE_TEST_PERIOD 300000

// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
#define MAXTEMP 260

#define HEATED_BED_PREHEAT_TEMP 55

/** Extreme values to detect defect thermistors. */
#define MIN_DEFECT_TEMPERATURE -10
#define MAX_DEFECT_TEMPERATURE 300

//How many milliseconds a hot end will preheat before starting to check the
//temperature. This value should NOT be set to the time it takes the
//hot end to reach the target temperature, but should be set to the time it 
//takes to reach the minimum temperature your thermistor can read. The lower
//the better/safer, and shouldn't need to be more than 30 seconds (30000) 
#define MILLISECONDS_PREHEAT_TIME 30000


#endif
