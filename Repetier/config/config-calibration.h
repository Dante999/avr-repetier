#ifndef CONFIG_CALIBRATION_H
#define CONFIG_CALIBRATION_H


// ##########################################################################################
// ##                               Calibration                                            ##
// ##########################################################################################

/** 
 * Drive settings for the Delta printers
 */
#if DRIVE_SYSTEM == DELTA
	
	/**
	 * Delta drive type: 
	 * 0 = belts and pulleys, 
	 * 1 = filament drive 
	 */
	#define DELTA_DRIVE_TYPE 0

	#if DELTA_DRIVE_TYPE == 0

		/** 
		 * Pitch in mm of drive belt. GT2 = 2mm 
		 * */
		#define BELT_PITCH 2
		
		/** 
		 * Number of teeth on X, Y and Z tower pulleys 
		 */
		#define PULLEY_TEETH 20
		
		/**
		 * calculations - do not change
		 */
		#define PULLEY_CIRCUMFERENCE (BELT_PITCH * PULLEY_TEETH)

		
	#elif DELTA_DRIVE_TYPE == 1
	
		/**
		 * Filament pulley diameter in millimeters 
		 */
		#define PULLEY_DIAMETER 10
		
		/**
		 * calculations - do not change
		 */
		#define PULLEY_CIRCUMFERENCE (PULLEY_DIAMETER * 3.1415927)
		
	#endif // DELTA_DRIVE_TYPE

	/**
	 * Steps per rotation of stepper motor 
	 */
	#define STEPS_PER_ROTATION 200

	/** 
	 * Micro stepping rate of X, Y and Y tower stepper drivers 
	 */
	#define MICRO_STEPS 16

	/**
	 * Calculations - do not change
	 */
	#define AXIS_STEPS_PER_MM ((float)(MICRO_STEPS * STEPS_PER_ROTATION) / PULLEY_CIRCUMFERENCE)
	#define XAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM
	#define YAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM
	#define ZAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM

/** Drive settings for printers with cartesian drive systems */	
#else // DRIVE_SYSTEM

	
	/** 
	 * Number of steps for a 1mm move in x direction.
	 * For xy gantry use 2*belt moved!
	 * 
	 * Overridden if EEPROM activated. 
	 */
	#define XAXIS_STEPS_PER_MM 203
	
	/** 
	 * Number of steps for a 1mm move in y direction.
	 * For xy gantry use 2*belt moved!
	 * 
	 * Overridden if EEPROM activated.
	 */
	#define YAXIS_STEPS_PER_MM 203
	
	/** 
	 * Number of steps for a 1mm move in z direction  
	 * 
	 * Overridden if EEPROM activated.
	 */
	#define ZAXIS_STEPS_PER_MM 805
	
	
#endif


#endif
