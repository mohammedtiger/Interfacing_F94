
#include "F94_KEYPAD.h"
#include "../Service_Layer/Services.h"
#include "../MCAL/F94_DIO.h"


void F94_void_KEYPAD_Init()
{
	F94_void_DIO_init_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , OUTPUT);
	F94_void_DIO_init_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , OUTPUT);
	F94_void_DIO_init_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , OUTPUT);

	F94_void_DIO_init_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1 , INPUT);
	F94_void_DIO_init_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2 , INPUT);
	F94_void_DIO_init_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3 , INPUT);

	F94_void_DIO_Write_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1 , HIGH);
	F94_void_DIO_Write_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2 , HIGH);
	F94_void_DIO_Write_pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3 , HIGH);
}

int F94_int_KEYPAD_COLUMN_1_Read()
{
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , LOW);
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , HIGH);
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , HIGH);

	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW)
	{
		return NUMBER_1;
	}
	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW)
	{
		return NUMBER_4;
	}
	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW)
	{
		return NUMBER_7;
	}

	return ERROR;
}

int F94_int_KEYPAD_COLUMN_2_Read()
{
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , HIGH);
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , LOW);
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , HIGH);

	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW)
	{
		return NUMBER_2;
	}
	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW)
	{
		return NUMBER_5;
	}
	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW)
	{
		return NUMBER_8;
	}

	return ERROR;
}

int F94_int_KEYPAD_COLUMN_3_Read()
{
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN1 , HIGH);
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN2 , HIGH);
	F94_void_DIO_Write_pin(KEYPAD_COLUMN_PORT , KEYPAD_COLUMN_PIN3 , LOW);

	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN1) == LOW)
	{
		return NUMBER_3;
	}
	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN2) == LOW)
	{
		return NUMBER_6;
	}
	if(F94_char_Read_Pin(KEYPAD_ROW_PORT , KEYPAD_ROW_PIN3) == LOW)
	{
		return NUMBER_9;
	}

	return ERROR;
}


int F94_int_Read_KEYPAD()
{
	return F94_int_KEYPAD_COLUMN_1_Read() ^ F94_int_KEYPAD_COLUMN_2_Read() ^ F94_int_KEYPAD_COLUMN_3_Read();
}
