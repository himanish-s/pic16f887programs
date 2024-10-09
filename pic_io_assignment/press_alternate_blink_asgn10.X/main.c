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
        
    TRISC = 0b00000000;
    PORTC = 0b10000000;   // assume button at R7
    TRISB = 0b00000000;     // PORTB dedicated to output
    PORTB = 0b10100110;   // assume all pins will be outputting voltage for leds
    initial_state = PORTB;
    while(TRUE){
        if (RC7 == 0){
            __delay_ms(30);
            if (RC7 == 0){
                PORTB = ~PORTB;
            }
        }else{
            PORTB = initial_state;
        }
    }
}