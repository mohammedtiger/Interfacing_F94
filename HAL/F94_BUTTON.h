/*
 * F94_BUTTON.h
 *
 *  Created on: Sep 22, 2018
 *      Author: root
 */

#ifndef F94_BUTTON_H_
#define F94_BUTTON_H_

enum
{
	BUTTON_1,
	BUTTON_2
};

enum
{
	BUTTON_1_PIN = 0,
	BUTTON_2_PIN = 2
};

enum
{
	BUTTON_1_PORT = 'A',
	BUTTON_2_PORT = 'D'
};

void F94_void_Button_init(char button_num);
char F94_char_Button_Read(char button_num);


#endif /* F94_BUTTON_H_ */
