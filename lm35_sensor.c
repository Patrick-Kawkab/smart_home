/*
 * lm35_sensor.c
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */

#include "lm35_sensor.h"
#include "ADC.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(TEMP_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)((((uint32)(adc_value*TEMP_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE))/(ADC_MAXIMUM_VALUE*TEMP_MAX_VOLT_VALUE)));
	return temp_value;
}

