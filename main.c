/*
 * main.c
 *
 *  Created on: Oct 4, 2024
 *      Author: kawka
 */
#include"lcd.h"
#include"led.h"
#include"LDR.h"
#include"BUZZER.h"
#include"DC_Motor.h"
#include"flame_sensor.h"
#include"lm35_sensor.h"
#include"ADC.h"
/*
 * Description :
 * Main function for the app
 */
int main(void)
{
	uint8 temp,light;//two variables to store the temperature and the light in
	LEDS_init();
	Buzzer_init();
	DcMotor_Init();
	FlameSensor_init();
	LCD_init();
	ADC_init();//enabling all components
	while(1)
	{
		if(FlameSensor_getValue()==LOGIC_HIGH)//using the polling technique for the flame sensor
		{
			Buzzer_on();
			LCD_sendCommand(LCD_CLEAR_COMMAND);
			LCD_displayStringRowColumn(0,0,"Critical alert!");
			while(FlameSensor_getValue()==LOGIC_HIGH);
			LCD_sendCommand(LCD_CLEAR_COMMAND);
			Buzzer_off();
		}

		light=LDR_getLightIntensity();
		temp=LM35_getTemperature();
		LCD_displayStringRowColumn(1,0,"Temp=");

		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else if (temp>=10)//display temperature value
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		LCD_displayStringRowColumn(1,8,"LDR=");

		if(light >= 100)//display light value
		{
			LCD_intgerToString(light);
			LCD_displayCharacter('%');
		}
		else
		{
			LCD_intgerToString(light);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
			LCD_displayCharacter('%');
			LCD_displayCharacter(' ');
		}
		/*
		 *displaying fan on or fan off depending on temp
		 */
		temp <25 ?LCD_displayStringRowColumn(0,3,"FAN is OFF"):LCD_displayStringRowColumn(0,3,"FAN is ON ");
		/*
		 *controlling the fan speed depending on temperature sensor reading
		 */
		if(temp<25){
			DcMotor_Rotate(MOTOR_OFF,0);
		}
		else if(temp>=25 && temp<30)
		{
			DcMotor_Rotate(MOTOR_CW,25);
		}
		else if(temp>=30 && temp<35)
		{
			DcMotor_Rotate(MOTOR_CW,50);
		}
		else if(temp>=35&& temp<40)
		{
			DcMotor_Rotate(MOTOR_CW,75);
		}
		else if(temp>=40)
		{
			DcMotor_Rotate(MOTOR_CW,100);
		}
		/*
		 *controlling the light intensity depending on LDR reading
		 */
		if(light>70)
		{
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if(light<=70 && light>50)
		{
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if(light<=50 && light>15)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if(light<=15)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
		}
	}
}
