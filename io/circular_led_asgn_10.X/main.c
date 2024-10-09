/*
 
 * this program shows circular tracing of an led
 * assuming each port is connected to led board
 * and they all are adjacent
 
 * by design this program uses individual pins
 * not ports
 */

#include <xc.h>
#include "config.h"

#define TRUE  1  // using TRUE instead  of 1
#define FALSE 0  // using FALSE instead of 0

#define _XTAL_FREQ 8000000 // time = 12.5 micro sec
#define FOSC 8000000L      // L is long integer size:4-bytes)
                           // ranges upto 4x10^9

void main(void) {

    unsigned char initial_state;
    OSCCON = 0b00000000;  // 8 MHz internal oscillator (matches to FOSC)
    ANSEL = 0b00000000;   // Pin select is digital (LED require digital input)
    ANSELH = 0b00000000;  // pin select is digital (LEDs are digital)
    
    // comparator is off (they are used to compare two analog and produce a
    // digital output based on difference between analog voltages)
    // as analog circuits are not used comparators are off
    C1ON = 0b00000000;
    C2ON = 0b00000000;    
    
    // make all ports output
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 0b00000000;
    // make all ports as low initial
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    PORTD = 0b00000000;
    PORTE = 0b00000000;
    
    while(TRUE){
        
        RA0=1;__delay_ms(90);
        RA1=1;__delay_ms(90);
        RA2=1;__delay_ms(90);
        RA3=1;__delay_ms(90);
        RA4=1;__delay_ms(90);
        RA5=1;__delay_ms(90);
        RE0=1;__delay_ms(90);
        RE1=1;__delay_ms(90);
        RE2=1;__delay_ms(90);
        RA7=1;__delay_ms(90);
        RA6=1;__delay_ms(90);
        RC0=1;__delay_ms(90);
        RC1=1;__delay_ms(90);
        RC2=1;__delay_ms(90);
        RC3=1;__delay_ms(90);
        RD0=1;__delay_ms(90);
        RD1=1;__delay_ms(90);
        RD2=1;__delay_ms(90);
        RD3=1;__delay_ms(90);
        RC4=1;__delay_ms(90);
        RC5=1;__delay_ms(90);
        RC6=1;__delay_ms(90);
        RC7=1;__delay_ms(90);
        RD4=1;__delay_ms(90);
        RD5=1;__delay_ms(90);
        RD6=1;__delay_ms(90);
        RD7=1;__delay_ms(90);
        RB0=1;__delay_ms(90);
        RB1=1;__delay_ms(90);
        RB2=1;__delay_ms(90);
        RB3=1;__delay_ms(90);
        RB4=1;__delay_ms(90);
        RB5=1;__delay_ms(90);
        RB6=1;__delay_ms(90);
        RB7=1;__delay_ms(90);
    }
}