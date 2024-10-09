/*
 * PWM.h
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */

#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>
#include "std_types.h"
#include"gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_PORT_ID     	PORTB_ID
#define PWM_PIN_ID         	PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the PWM timer0 driver.
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
