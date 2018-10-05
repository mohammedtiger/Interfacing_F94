
#include "F94_7SEG.h"
#include "../MCAL/F94_DIO.h"
#include "../Service_Layer/Services.h"
#include "F94_LCD.h"


void F94_void_7SEG_Init()
{
	F94_void_DIO_init_Port(_7SEG_DATA_PORT , _7SEG_DATA_PINS);

	F94_void_DIO_init_pin(_7SEG_EN_PORT1 , _7SEG_EN_PIN1 , OUTPUT);
	F94_void_DIO_init_pin(_7SEG_EN_PORT2 , _7SEG_EN_PIN2 , OUTPUT);
	F94_void_DIO_init_pin(_7SEG_EN_PORT3 , _7SEG_EN_PIN3 , OUTPUT);
	F94_void_DIO_init_pin(_7SEG_EN_PORT4 , _7SEG_EN_PIN4 , OUTPUT);

}

void F94_void_7SEG_Write(char SevenNumber , char data)
{

	F94_void_DIO_Write_pin(_7SEG_EN_PORT1 , _7SEG_EN_PIN1 ,HIGH);
	F94_void_DIO_Write_pin(_7SEG_EN_PORT2 , _7SEG_EN_PIN2 ,HIGH);
	F94_void_DIO_Write_pin(_7SEG_EN_PORT3 , _7SEG_EN_PIN3 ,HIGH);
	F94_void_DIO_Write_pin(_7SEG_EN_PORT4 , _7SEG_EN_PIN4 ,HIGH);

	switch(SevenNumber)
	{
	case SEVENSEG_1 :
		F94_void_DIO_Write_pin(_7SEG_EN_PORT1 , _7SEG_EN_PIN1 ,LOW);
		F94_void_DIO_Write_Port(_7SEG_DATA_PORT , data|0x10);
		break;
	case SEVENSEG_2 :
		F94_void_DIO_Write_pin(_7SEG_EN_PORT2 , _7SEG_EN_PIN2 ,LOW);
		F94_void_DIO_Write_Port(_7SEG_DATA_PORT , data|0x10);
		break;
	case SEVENSEG_3 :
		F94_void_DIO_Write_pin(_7SEG_EN_PORT3 , _7SEG_EN_PIN3 ,LOW);
		F94_void_DIO_Write_Port(_7SEG_DATA_PORT , data);

		break;
	case SEVENSEG_4 :
		F94_void_DIO_Write_pin(_7SEG_EN_PORT4 , _7SEG_EN_PIN4 ,LOW);
		F94_void_DIO_Write_Port(_7SEG_DATA_PORT , data|0x10);
		break;
	}

}
