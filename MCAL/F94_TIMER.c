
#include <avr/interrupt.h>
#include <avr/io.h>
#include "F94_TIMER.h"

volatile unsigned long Timer_counter[10] ;

void F94_void_TIMER_Init()
{
	TCCR0 = (1 << CS00) | (1 << CS01);
	TIMSK = (1 << TOIE0);
	sei();
}


ISR(TIMER0_OVF_vect)
{

	for(int index = 0 ; index < 10 ; index ++)
		Timer_counter[index]++;

}



