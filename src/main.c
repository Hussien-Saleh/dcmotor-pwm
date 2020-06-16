/*
 a program control the speed of the DC Motor 
  Requirements:
• Connect the OC0/PB3 Timer0 Clock Pin to the DC-Motor
  Enable Pin in the L293D H-Bridge.
 */
 
#include "mcu.h"


int main(void)
{ 
	timer0_init_pwm(64);    // 25% duty cycle
	DDRA &= (~(0x07<<PA0)); // buttons as input pins, pin 0,1 &2
	motor_init();
		 
    for(;;)
    {
		if(PINA & (1<<PA0))
			motor_rotate_cw();
		else if(PINA & (1<<PA1))
			motor_rotate_ccw();
		else if(PINA & (1<<PA2))
			motor_stop();				    
    }
	return 0;
}
