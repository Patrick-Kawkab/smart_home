/*
 * lm35_sensor.h
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TEMP_CHANNEL_ID         1
#define TEMP_MAX_VOLT_VALUE     1.5
#define TEMP_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
