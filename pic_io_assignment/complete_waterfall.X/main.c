


#include <xc.h>
#include "config.h"

#define TRUE  1  // using TRUE instead  of 1
#define FALSE 0  // using FALSE instead of 0

#define _XTAL_FREQ 8000000 // time = 12.5 micro sec
#define FOSC 8000000L      // L is long integer size:4-bytes)
                           // ranges upto 4x10^9

void main(void) {

    OSCCON = 0b00000000;  // 8 MHz internal oscillator (matches to FOSC)
    ANSEL = 0b00000000;   // Pin select is digital (LED require digital input)
    ANSELH = 0b00000000;  // pin select is digital (LEDs are digital)
    
    // comparator is off (they are used to compare two analog and produce a
    // digital output based on difference between analog voltages)
    // as analog circuits are not used comparators are off
    C1ON = 0b00000000;
    C2ON = 0b00000000;    
        
    TRISC = 0b00000000;
    PORTC = 0b00000000;
    
    while(TRUE){
        
        PORTC = 0b00000000;
        __delay_ms(50);
        PORTC = 0b10000000;
        __delay_ms(50);
        PORTC = 0b11000000;
        __delay_ms(50);
        PORTC = 0b11100000;
        __delay_ms(50);
        PORTC = 0b11110000;
        __delay_ms(50);
        PORTC = 0b11111000;
        __delay_ms(50);
        PORTC = 0b11111100;
        __delay_ms(50);
        PORTC = 0b11111110;
        __delay_ms(50);
        PORTC = 0b11111111;
        __delay_ms(50);
        for (int i=8;i<=8;i--){
            PORTC = PORTC>>1;
            __delay_ms(50);
        }
        
    }
    
}
