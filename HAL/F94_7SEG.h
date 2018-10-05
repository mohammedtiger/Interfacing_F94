/*
 * F94_7SEG.h
 *
 *  Created on: Oct 5, 2018
 *      Author: root
 */

#ifndef F94_7SEG_H_
#define F94_7SEG_H_


enum
{
	SEVENSEG_1 = 1,
	SEVENSEG_2,
	SEVENSEG_3,
	SEVENSEG_4,
};
enum
{
	_7SEG_DATA_PINS 	= 0x0F,

	_7SEG_EN_PIN1 		= 4,
	_7SEG_EN_PIN2 		= 3,
	_7SEG_EN_PIN3 		= 4,
	_7SEG_EN_PIN4 		= 4,

	_7SEG_EN_PORT1 		= 'A',
	_7SEG_EN_PORT2 		= 'A',
	_7SEG_EN_PORT3 		= 'B',
	_7SEG_EN_PORT4 		= 'C',

	_7SEG_DATA_PORT 	= 'B',
};

void F94_void_7SEG_Init();
void F94_void_7SEG_Write(char SevenNumber , char data);



#endif /* F94_7SEG_H_ */
