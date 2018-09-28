

#include "F94_LCD.h"
#include "../MCAL/F94_DIO.h"
#include "../Service_Layer/Services.h"
#include <util/delay.h>


static void F94_void_Send_Data_4bit(unsigned char data)
{

	F94_void_DIO_Write_pin(LCD_RS_PORT , LCD_RS_PIN , HIGH);

	F94_void_DIO_Write_Port(LCD_DATA_PORT , WRITE_MOST(data));
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(2);
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(2);

	F94_void_DIO_Write_Port(LCD_DATA_PORT , WRITE_LEST(data));
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(2);
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(2);

}











static void F94_void_Send_Command_4bit(unsigned char command)
{
	F94_void_DIO_Write_pin(LCD_RS_PORT , LCD_RS_PIN , LOW);

	F94_void_DIO_Write_Port(LCD_DATA_PORT , WRITE_MOST(command));
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(2);
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(2);

	F94_void_DIO_Write_Port(LCD_DATA_PORT , WRITE_LEST(command));
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(2);
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(2);
}


static void F94_void_Send_Refresh_8bit(unsigned char command)
{
	F94_void_DIO_Write_pin(LCD_RS_PORT , LCD_RS_PIN , LOW);

	F94_void_DIO_Write_Port(LCD_DATA_PORT , WRITE_MOST(command));
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(2);
	F94_void_DIO_Write_pin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(2);

}

void F94_void_LCD_Init()
{
	F94_void_DIO_init_pin(LCD_DATA_PORT , LCD_DATA_PIN1 , OUTPUT);
	F94_void_DIO_init_pin(LCD_DATA_PORT , LCD_DATA_PIN2 , OUTPUT);
	F94_void_DIO_init_pin(LCD_DATA_PORT , LCD_DATA_PIN3 , OUTPUT);
	F94_void_DIO_init_pin(LCD_DATA_PORT , LCD_DATA_PIN4 , OUTPUT);
	F94_void_DIO_init_pin(LCD_RS_PORT , LCD_RS_PIN , OUTPUT);
	F94_void_DIO_init_pin(LCD_EN_PORT , LCD_EN_PIN , OUTPUT);

	F94_void_Send_Refresh_8bit(0x30);
	_delay_ms(10);
	F94_void_Send_Refresh_8bit(0x30);
	_delay_ms(10);
	F94_void_Send_Refresh_8bit(0x30);
	_delay_ms(10);
	F94_void_Send_Refresh_8bit(0x20);
	_delay_ms(10);
	F94_void_Send_Command_4bit(0x28);
	F94_void_Send_Command_4bit(0x0C);
	F94_void_Send_Command_4bit(0x06);
	F94_void_Send_Command_4bit(0x80);
	_delay_ms(20);

}


void F94_void_LCD_ClearScreen()
{
	F94_void_Send_Command_4bit(0x01);

}

void F94_void_LCD_Print_String(char *Arr)
{
	int index = 0;

	// '\0' = 0
	while(Arr[index] != 0)
	{

		F94_void_Send_Data_4bit(Arr[index]);
		index ++;
	}
}


void F94_void_LCD_goto(char y, char x)
{
	char firstAddress[] = {0x80,0xC0};

	F94_void_Send_Command_4bit(firstAddress[y-1] + x-1);
	_delay_ms(20);
}
