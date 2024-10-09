/*
 * ADC.c
 *
 *  Created on: Oct 4, 2024
 *      Author: kawka
 */

#include "avr/io.h"
#include "adc.h"
#include "common_macros.h"

void ADC_init(void) {
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 11 to choose Internal reference voltage 2.56V
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
    ADMUX = 0xC0;

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC must operate in range 50-200Khz
	 */
    ADCSRA = 0x87;
}

uint16 ADC_readChannel(uint8 channel_num) {
    ADMUX =( ADMUX & 0xE0)|(channel_num & 0x07);// Set the desired channel
    SET_BIT(ADCSRA, ADSC);// Start ADC conversion
    while (BIT_IS_CLEAR(ADCSRA, ADIF));// Wait for conversion to complete
    SET_BIT(ADCSRA, ADIF);// Clear ADIF
    return ADC;  // Read and return the ADC result
}

