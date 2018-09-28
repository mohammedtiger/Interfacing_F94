

#include "../MCAL/F94_DIO.h"
#include "F94_LED.h"
#include "../Service_Layer/Services.h"

void F94_void_Led_init(char led_num)
{

	switch(led_num)
	{
	case LED_1:
		F94_void_DIO_init_pin(LED_1_PORT , LED_1_PIN , OUTPUT);
		break;
	case LED_2:
		F94_void_DIO_init_pin(LED_2_PORT , LED_2_PIN , OUTPUT);
		break;
	case LED_3:
		F94_void_DIO_init_pin(LED_3_PORT , LED_3_PIN , OUTPUT);
		break;
	case LED_4:
		F94_void_DIO_init_pin(LED_4_PORT , LED_4_PIN , OUTPUT);
		break;

	}
}


void F94_void_Led_write(char led_num , char dir)
{

	switch(led_num)
	{
	case LED_1:
		F94_void_DIO_Write_pin(LED_1_PORT , LED_1_PIN , dir);
		break;
	case LED_2:
		F94_void_DIO_Write_pin(LED_2_PORT , LED_2_PIN , dir);
		break;
	case LED_3:
		F94_void_DIO_Write_pin(LED_3_PORT , LED_3_PIN , dir);
		break;
	case LED_4:
		F94_void_DIO_Write_pin(LED_4_PORT , LED_4_PIN , dir);
		break;

	}
}
