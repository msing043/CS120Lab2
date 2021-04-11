/*	Author: msing043
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
DDRA = 0x00; PORTA = 0xFF; 
DDRB = 0x00; PORTB = 0xFF;
DDRC = 0x00; PORTC = 0xFF;
DDRD = 0xFF; PORTD = 0x00;
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;
unsigned char tmpC = 0x00;
unsigned char tmpD = 0x00;
unsigned char tmpD0 =0x00;
unsigned long weight = 0x0000;

	while(1){
	tmpA=PINA;
	tmpB=PINB;
	tmpC=PINC;
	tmpD=0x00;
	tmpD0=0x00;
	weight=tmpA+tmpB+tmpC;
if(weight>0x008C){
tmpD=0x01;
}
else{
tmpD=0x00;
}
if((tmpA>tmpC)&&(tmpA-tmpC>0x50)){
tmpD0=0x02;
}
else if((tmpC-tmpA)>0x50){
tmpD0=0x02;
}
PORTD=(weight &0x00FC)|tmpD|tmpD0;
}
return 1;
}

