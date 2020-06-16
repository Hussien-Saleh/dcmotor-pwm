#include "mcu.h"
#include "timer.h"

void timer0_init_pwm(uint8_t val){ 
	
    TCNT0 = 0x00;
	OCR0  = val; 
	DDRB |= (1<<PB3); // OC0 as output pin	
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}