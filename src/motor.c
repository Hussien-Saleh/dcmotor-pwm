#include "mcu.h"
#include "motor.h"

void motor_init(void){

    DDRC |= (0x03<<PC0);   
	PORTC &= ~((1<<PC0) | (1<<PC1));
}

void motor_rotate_cw(void){

    PORTC &= (~(1<<PC0));
	PORTC |=  (1<<PC1);
}

void motor_rotate_ccw(void){

    PORTC |= (1<<PC0);
	PORTC &= (~(1<<PC1));	
}

void motor_stop(void){
    
    PORTC &= (~(1<<PC0));
	PORTC &= (~(1<<PC1));
}