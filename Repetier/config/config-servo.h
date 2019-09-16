#ifndef CONFIG_SERVO_H
#define CONFIG_SERVO_H

/* Servos
 * 
 * If you need to control servos, enable this feature. You can control up to 4 servos.
 * Control the servos with
 *
 *    M340 P<servoId> S<pulseInUS>
 *
 * servoID = 0..3
 * Servos are controlled by a pulse width normally between 500 and 2500 with
 * 1500ms in center position. 0 turns servo off.
 * 
 * WARNING: Servos can draw a considerable amount of current. Make sure your
 * system can handle this or you may risk your hardware!
 */

/**
 * enable disable the feature 
 *
 * 0 = disable (default) 
 * 1 = enable
 */
#define FEATURE_SERVO 0


// Servo pins on a RAMPS board are 11,6,5,4
#define SERVO0_PIN 11
#define SERVO1_PIN 6
#define SERVO2_PIN 5
#define SERVO3_PIN 4

/* 
 * for set servo(s) at designed neutral position at power-up. Values < 500 mean
 * no start position 
 */
#define SERVO0_NEUTRAL_POS  -1
#define SERVO1_NEUTRAL_POS  -1
#define SERVO2_NEUTRAL_POS  -1
#define SERVO3_NEUTRAL_POS  -1

/** 
 * Set to servo number +1 to control that servo in ui menu. 0 disables ui
 * control. 
 */
#define UI_SERVO_CONTROL 0



#endif // CONFIG_SERVO_H
