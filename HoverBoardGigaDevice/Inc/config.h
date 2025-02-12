#ifndef CONFIG_H
#define CONFIG_H

// ################################################################################
// select one of the supported circuit boards and whether to compile the slave- or master board
// only the master has a buzzer :-)

// LAYOUT_2_X is used in defines.h
#ifdef GD32E230
	//LAYOUT_2_7	// https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/16
	#define LAYOUT 7
#else
	/*
	LAYOUT_2_0	// 100% ready.. https://github.com/flo199213/Hoverboard-Firmware-Hack-Gen2
	LAYOUT_2_1	// https://github.com/krisstakos/Hoverboard-Firmware-Hack-Gen2.1
	LAYOUT_2_2	// 90% ready. battery voltage and currentDC missing. motor spinning.
	LAYOUT_2_3	// 99% ready.. https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/20
	LAYOUT_2_4	// NOT READY !!! https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/3
	LAYOUT_2_11	// NOT READY !!! https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/27
	*/
	#define LAYOUT 17
#endif

//#define MASTER		// uncomment for MASTER firmware. Choose USART0_MASTERSLAVE or USART1_MASTERSLAVE in your defines_2-?.h file
//#define SLAVE			// uncomment for SLAVE firmware. Choose USART0_MASTERSLAVE or USART1_MASTERSLAVE in your defines_2-?.h file
#define SINGLE			// uncomment if firmware is for single board and no master-slave dual board setup

#define BAT_CELLS         	6        // battery number of cells. Normal Hoverboard battery: 10s

#if defined(MASTER) || defined(SINGLE)
	#define MASTER_OR_SINGLE
	
	#define REMOTE_DUMMY
	//#define REMOTE_UART
	//#define REMOTE_UARTBUS	// ESP32 as master and multiple boards as multiple slaves ESP.tx-Hovers.rx and ESP.rx-Hovers.tx
	//#define REMOTE_CRSF		// https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/26

	#ifdef REMOTE_UARTBUS
		#define SLAVE_ID	0		// must be unique for all hoverboards connected to the bus
	#endif

#define TEST_HALL2LED	// led the 3-led panel blink according to the hall sensors
//#define DEBUG_LED		// uncomment to activate DEBUG_LedSet(bSet,iColor) macro. iCol: 0=green, 1=organge, 2=red

	#define SPEED_COEFFICIENT   -1
	#define STEER_COEFFICIENT   1
	
	#define CHECK_BUTTON		// disable = add '//' if you use a slave board as master
#endif


// ################################################################################


#define PWM_FREQ         		16000     // PWM frequency in Hz
#define DEAD_TIME        		60        // PWM deadtime (60 = 1�s, measured by oscilloscope)

#define DC_CUR_LIMIT     		15        // Motor DC current limit in amps


//#define BLDC_WEAKENING		// some kind of field weaking added by HarleyBob for his gen2.2 firmware ?

// ################################################################################

#define DELAY_IN_MAIN_LOOP 	5         // Delay in ms

#define TIMEOUT_MS          2000      // Time in milliseconds without steering commands before pwm emergency off

#ifdef MASTER_OR_SINGLE
	#define INACTIVITY_TIMEOUT 	8        	// Minutes of not driving until poweroff (not very precise)

	// ################################################################################


	#define CELL_LOW_LVL1     3.5       // Gently beeps, show green battery symbol above this Level.
	#define CELL_LOW_LVL2     3.3       // Battery almost empty, show orange battery symbol above this Level. Charge now! 
	#define CELL_LOW_DEAD     3.1       // Undervoltage lockout, show red battery symbol above this Level.

	#define BAT_LOW_LVL1     BAT_CELLS * CELL_LOW_LVL1
	#define BAT_LOW_LVL2     BAT_CELLS * CELL_LOW_LVL2
	#define BAT_LOW_DEAD     BAT_CELLS * CELL_LOW_DEAD

	/*
	#define BAT_LOW_LVL1     35.0       // Gently beeps, show green battery symbol above this Level.
	#define BAT_LOW_LVL2     33.0       // Battery almost empty, show orange battery symbol above this Level. Charge now! 
	#define BAT_LOW_DEAD     31.0       // Undervoltage lockout, show red battery symbol above this Level.
	// ONLY DEBUG-LEVEL!!!
	//#define BAT_LOW_LVL1     29.0
	//#define BAT_LOW_LVL2     28.0
	//#define BAT_LOW_DEAD     27.0
	*/

	// ################################################################################
#endif

#if defined(MASTER) || defined(SLAVE)
	#define MASTER_OR_SLAVE
#endif

// ###### ARMCHAIR ######
#define FILTER_SHIFT 12 						// Low-pass filter for pwm, rank k=12


#endif
