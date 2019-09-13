#ifndef CONFIG_SDCARD_H
#define CONFIG_SDCARD_H

/** 
 * 
 * Some boards have SD support on board. These define the values already 
 * in pins.h
 */
#ifndef SDSUPPORT

	/**
	 * Set to false to disable SD support
	 */
	#define SDSUPPORT false
	
	/**
	 * Uncomment to enable or change card detection pin. 
	 * With card detection the card is mounted on insertion.
	 */
	#undef SDCARDDETECT
	#define SDCARDDETECT -1
	
	/**
	 * Change to true if you get a inserted message on removal.
	 */
	#undef SDCARDDETECTINVERTED
	#define SDCARDDETECTINVERTED false
#endif

/** 
 * Show extended directory including file length. Don't use 
 * this with Pronterface! 
 */
#define SD_EXTENDED_DIR 1

/** 
 * The GCODEs in this line get executed, when you stop a SD print before it 
 * was ended. Separate commands by \n 
 */
#define SD_RUN_ON_STOP ""

/** 
 * Disable motors and heaters when print was stopped. 
 */
#define SD_STOP_HEATER_AND_MOTORS_ON_STOP 1


#endif
