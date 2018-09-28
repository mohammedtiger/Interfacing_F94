

#include "../MCAL/F94_DIO.h"
#include "F94_BUTTON.h"
#include "../Service_Layer/Services.h"


void F94_void_Button_init(char button_num)
{
	switch(button_num)
	{
	case BUTTON_1:
		F94_void_DIO_init_pin(BUTTON_1_PORT , BUTTON_1_PIN , INPUT);
		//Active (active low)
		F94_void_DIO_Write_pin(BUTTON_1_PORT , BUTTON_1_PIN , HIGH);
		break;
	case BUTTON_2:
		F94_void_DIO_init_pin(BUTTON_2_PORT , BUTTON_2_PIN , INPUT);
		//Active (active low)
		F94_void_DIO_Write_pin(BUTTON_2_PORT , BUTTON_2_PIN , HIGH);
		break;
	}
}

char F94_char_Button_Read(char button_num)
{

	switch(button_num)
	{
	case BUTTON_1:

		return F94_char_Read_Pin(BUTTON_1_PORT , BUTTON_1_PIN);
		break;
	case BUTTON_2:
		return F94_char_Read_Pin(BUTTON_2_PORT , BUTTON_2_PIN);
		break;
	}
	return ERROR;
}
