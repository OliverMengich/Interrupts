/*
 * interrupt12.c
 *
 * Created: 10/11/2019 15:18:59
 * Author : olive
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
 #include <avr/interrupt.h>
  #include <util/delay.h>

ISR(INT0_vect)
{
	PORTC ^= (1<<PC0);  /* Toggle PORTC PC0 */
	_delay_ms(50);
	
	
}

int main(void)
{
    /* Replace with your application code */
	
	DDRA = 0x07;
	DDRC = 1<<PC0;
	DDRD = 0;
	PORTD = 1<<PD2;
	GICR = 1<<INT0; /* Enable INT0*/
	 MCUCR = 1<<ISC01 | 1<<ISC00; /* Trigger INT0 on rising edge */ 
	 sei();
    while (1) 
    {
		PORTA = 1<<PA0;
		_delay_ms(200);
	    PORTA = 1<<PA1; 
		_delay_ms(200); 
		PORTA = 1<<PA2;
		 _delay_ms(200);
		 
		 
    }
	return 0;
}

