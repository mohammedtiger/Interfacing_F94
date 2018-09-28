/*
 * F94_LED.h
 *
 *  Created on: Sep 22, 2018
 *      Author: root
 */

#ifndef F94_LED_H_
#define F94_LED_H_


enum
{
	LED_1,
	LED_2,
	LED_3,
	LED_4
};

enum
{
	LED_1_PIN = 1,
	LED_2_PIN = 2,
	LED_3_PIN = 7,
	LED_4_PIN = 6

};
enum
{
	LED_1_PORT = 'A',
	LED_2_PORT = 'A',
	LED_3_PORT = 'C',
	LED_4_PORT = 'C'


};
void F94_void_Led_init(char led_num);
void F94_void_Led_write(char led_num , char dir);


#endif /* F94_LED_H_ */
