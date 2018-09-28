
#include <avr/io.h>
#include <util/delay.h>
#include "../Service_Layer/Services.h"
#include "../HAL/F94_LED.h"
#include "../HAL/F94_BUTTON.h"
#include "../HAL/F94_LCD.h"

int main()
{

	F94_void_LCD_Init();
	F94_void_LCD_ClearScreen();

	int i = 0;
	while (1)
	{


		F94_void_LCD_goto(1,i++);
		F94_void_LCD_Print_String("Hello world");

		i%=16;
		_delay_ms(100);

		F94_void_LCD_ClearScreen();


	}
	return 0;
}
