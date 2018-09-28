/*
 * F94_LCD.h
 *
 *  Created on: Sep 28, 2018
 *      Author: root
 */

#ifndef F94_LCD_H_
#define F94_LCD_H_

#define WRITE_MOST(data)   ((data & 0xF0) >> 4)
#define WRITE_LEST(data)   (data & 0x0F)


enum
{
	//LCD PINS
	LCD_DATA_PIN1 ,
	LCD_DATA_PIN2 ,
	LCD_DATA_PIN3 ,
	LCD_DATA_PIN4 ,
	LCD_RS_PIN	= 3,
	LCD_EN_PIN	= 6,

	//LCD PORTS
	LCD_DATA_PORT = 'B',
	LCD_RS_PORT = 	'A',
	LCD_EN_PORT = 	'D',
};

void F94_void_LCD_Print_String(char *Arr);
void F94_void_LCD_ClearScreen();
void F94_void_LCD_Init();
void F94_void_LCD_goto(char y, char x);



#endif /* F94_LCD_H_ */
