
#include <avr/io.h>
#include <util/delay.h>
#include "../Service_Layer/Services.h"
#include "../HAL/F94_LED.h"
#include "../HAL/F94_BUTTON.h"
#include "../HAL/F94_KEYPAD.h"
#include "../HAL/F94_LCD.h"
#include "../MCAL/F94_ADC.h"
#include "stdio.h"
#include "../MCAL/F94_TIMER.h"
#include "../HAL/F94_7SEG.h"


int main()
{
	F94_void_KEYPAD_Init();
	F94_void_LCD_Init();
	F94_void_Button_init(BUTTON_1);
	F94_void_Led_init(LED_1);

	F94_void_7SEG_Init();

	char Deb_Flag = LOW;
	char Pre_Flag = LOW;
	while (1)
	{
		if(F94_char_Button_Read(BUTTON_1) == LOW && Pre_Flag == LOW)
		{
			Deb_Flag ^= HIGH;
			Pre_Flag = HIGH;
		}
		else if(F94_char_Button_Read(BUTTON_1) == HIGH && Pre_Flag == HIGH)
		{
			Pre_Flag = LOW;
		}


		if(Deb_Flag == HIGH)
			F94_void_Led_write(LED_1 , LOW);
		else
			F94_void_Led_write(LED_1 , HIGH);

		//		int data = F94_int_Read_KEYPAD();
		//		if(data > 0)
//		F94_void_7SEG_Write(SEVENSEG_1 , 5);
//		_delay_ms(5);
//		F94_void_7SEG_Write(SEVENSEG_2 , 5);
//		_delay_ms(5);
		F94_void_7SEG_Write(SEVENSEG_3 , 5);
		_delay_ms(5);
//		F94_void_7SEG_Write(SEVENSEG_4 , 5);
//		_delay_ms(5);

	}
	return 0;
}
