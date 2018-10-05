
#include "F94_ADC.h"
#include <avr/io.h>
#include "../Service_Layer/Services.h"
#include "F94_DIO.h"

void F94_void_ADC_Init(unsigned char Mux)
{

	ADMUX = (1 << REFS0) | Mux;
	ADCSRA = (1 << ADPS2) | (1 << ADPS1);
}


int F94_int_ADC_Read()
{
	ADCSRA |= (1 << ADEN) | (1 << ADSC);

	while(!( ADCSRA & (1 << ADIF)));

	ADCSRA |= (1 << ADIF);       //Clear flag

	return ADC;
}

