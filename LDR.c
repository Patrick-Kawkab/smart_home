/*
 * LDR.c
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */
#include"LDR.h"
#include "ADC.h"
uint16 LDR_getLightIntensity(void)
{
	uint8 LDR_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(LDR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	LDR_value = (uint8)(((uint32)adc_value*LDR_MAX_LIGHT*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_MAX_VOLT_VALUE));
 return LDR_value;
}
