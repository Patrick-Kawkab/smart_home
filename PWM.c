/*
 * PWM.c
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */
#include"PWM.h"
/*
 * Description :
 * Function responsible for initialize the PWM timer0 driver.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; //Set Timer Initial value

	OCR0 =(duty_cycle * 255) / 100;

	GPIO_setupPinDirection(PWM_PORT_ID,PWM_PIN_ID,PIN_OUTPUT); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = 0x6D;
}


