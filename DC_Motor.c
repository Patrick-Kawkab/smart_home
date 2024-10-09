/*
 * DC_Motor.c
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */
#include"DC_Motor.h"
/*
 * Description :
 * Initializes the DC motor by setting the direction for the motor pins and stopping the
 *	motor at the beginning
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(H_bridge_PORT_ID,IN1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(H_bridge_PORT_ID,IN2_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(H_bridge_PORT_ID,EN_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(H_bridge_PORT_ID,IN1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(H_bridge_PORT_ID,IN2_PIN_ID,LOGIC_LOW);
	GPIO_writePin(H_bridge_PORT_ID,EN_PIN_ID,LOGIC_LOW);
}
/*
 * Description :
 * Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based
 * on the input duty cycle
 */
void DcMotor_Rotate(enum DcMotor_state DcMotor_state, uint16 speed)
{
	if(DcMotor_state == MOTOR_OFF)
	{
		GPIO_writePin(H_bridge_PORT_ID,IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(H_bridge_PORT_ID,IN2_PIN_ID,LOGIC_LOW);
		GPIO_writePin(H_bridge_PORT_ID,EN_PIN_ID,LOGIC_LOW);
		PWM_Timer0_Start(speed);
	}
	else if(DcMotor_state == MOTOR_CW)
	{
		GPIO_writePin(H_bridge_PORT_ID,IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(H_bridge_PORT_ID,IN2_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(H_bridge_PORT_ID,EN_PIN_ID,LOGIC_HIGH);
		PWM_Timer0_Start(speed);
	}
	else if(DcMotor_state == MOTOR_A_CW)
	{
		GPIO_writePin(H_bridge_PORT_ID,IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(H_bridge_PORT_ID,IN2_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(H_bridge_PORT_ID,EN_PIN_ID,LOGIC_HIGH);
		PWM_Timer0_Start(speed);
	}
}


