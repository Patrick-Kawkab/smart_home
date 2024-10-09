/*
 * led.h
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */

#ifndef LED_H_
#define LED_H_
#include "LDR.h"
#include "gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define RED_LED   PIN5_ID
#define GREEN_LED   PIN6_ID
#define BLUE_LED   PIN7_ID
#define LED_PORT   PORTB_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialize the LEDS:
 * 1. Setup the LEDS pins directions by use the GPIO driver.
 * 2. Setup the LEDS to be logic low at the first
 */
void LEDS_init(void);
/*
 * Description :
 * Turns on the required LED with it's ID using GPIO driver
 */
void LED_on(uint8 LED_ID);
/*
 * Description :
 * Turns off the required LED with it's ID using GPIO driver
 */
void LED_off(uint8 LED_ID);


#endif /* LED_H_ */
