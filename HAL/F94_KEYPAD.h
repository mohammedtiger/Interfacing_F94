/*
 * F94_KEYPAD.h
 *
 *  Created on: Oct 5, 2018
 *      Author: root
 */

#ifndef F94_KEYPAD_H_
#define F94_KEYPAD_H_

enum
{
	KEYPAD_COLUMN_PIN1 	=	5,
	KEYPAD_COLUMN_PIN2 	,
	KEYPAD_COLUMN_PIN3 	,
	KEYPAD_COLUMN_PORT 	= 	'C',
	KEYPAD_ROW_PIN1 	=	2,
	KEYPAD_ROW_PIN2 	=   1,
	KEYPAD_ROW_PIN3 	=   0,
	KEYPAD_ROW_PORT 	= 	'A'
};

enum
{
	NUMBER_0,
	NUMBER_1,
	NUMBER_2,
	NUMBER_3,
	NUMBER_4,
	NUMBER_5,
	NUMBER_6,
	NUMBER_7,
	NUMBER_8,
	NUMBER_9,
};
void F94_void_KEYPAD_Init();

int F94_int_Read_KEYPAD();

#endif /* F94_KEYPAD_H_ */
