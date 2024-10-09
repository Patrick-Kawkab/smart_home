/*
 * flame_sensor.c
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */
#include"flame_sensor.h"
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_PORT_ID,FLAME_PIN_ID,PIN_INPUT);
}
uint8 FlameSensor_getValue(void)
{
    return GPIO_readPin(FLAME_PORT_ID,FLAME_PIN_ID);
}


