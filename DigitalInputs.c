// DigitalInputs.c

// switch on PD2 (pin 4)
// LED on PC5 (pin 28), turns on/off based on switch press

#ifndef F_CPU					// if F_CPU was not defined in Project -> Properties
#define F_CPU 1000000UL			// define it now as 1 GHz unsigned long
#endif

#include <avr/io.h>				// this is always included in AVR programs

#define BIT_IS_SET(byte, bit) (byte & (1 << bit))
#define BIT_IS_CLEAR(byte, bit) (!(byte & (1 << bit)))

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
	
	DDRD &= ~(1 << PD2);		// clear DDRD bit 2, sets PD2 (pin 4) for input
	
	PORTD |= (1 << PD2);		// set PD2/INT0 (pin 4) internal pull-up resistor
	
	DDRC |= (1 << PC5);			// set Port C pin PC5 for output
	
	while (1) {					// begin infinite loop
		if(BIT_IS_CLEAR(PIND, PD2)) {
			PORTC |= (1 << PC5);
		} else if(BIT_IS_SET(PIND, PD2)) {
			PORTC &= ~(1 << PC5);
		} else {
			// ideally should never get here, but may occasionally due to timing
		}
	}
	return(0);					// should never get here, this is to prevent a compiler warning
}
