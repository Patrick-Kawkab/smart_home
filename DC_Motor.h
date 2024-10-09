/*
 * DC_Motor.h
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"gpio.h"
#include"std_types.h"
#include "PWM.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define H_bridge_PORT_ID    PORTB_ID
#define IN1_PIN_ID			PIN0_ID
#define IN2_PIN_ID			PIN1_ID
#define EN_PIN_ID			PIN3_ID
/* DC motor state Values */
enum DcMotor_state {
    MOTOR_OFF,
    MOTOR_CW,
    MOTOR_A_CW
};
/*
 * Description :
 * Initializes the DC motor by setting the direction for the motor pins and stopping the
 *	motor at the beginning
 */
void DcMotor_Init(void);
/*
 * Description :
 * Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based
 * on the input duty cycle
 */
void DcMotor_Rotate(enum DcMotor_state DcMotor_state, uint16 speed);


#endif /* DC_MOTOR_H_ */
