/*
 * flame_sensor.h
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_
#include "gpio.h"
#include"std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define FLAME_PORT_ID     PORTD_ID
#define FLAME_PIN_ID     PIN2_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialize the flame sensor:
 *  Setup the flame sensor pins directions by use the GPIO driver.
 */
void FlameSensor_init(void);
/*
 * Description :
 *	returns the bit from sensor with it's ID using GPIO driver which is logic one or logic zero
 */
uint8 FlameSensor_getValue(void);


#endif /* FLAME_SENSOR_H_ */
