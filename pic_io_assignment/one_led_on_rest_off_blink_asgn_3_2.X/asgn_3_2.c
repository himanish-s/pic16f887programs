/*
 * This program blinks 
 * alternate led pattern
 * delay is 500ms
 */

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

    // initialize trisc to 0
    TRISC = 0b00000000;
    // initialize portc to 0
    PORTC = 0b00000000;

    // keep repeating the pattern
    while(TRUE){
        
        PORTC = 0b01010101;     // alternate pins glow from pin0
        __delay_ms(500);      // delay for 500ms
        
        PORTC = 0b10101010;     // alternate pins glow from pin1
        __delay_ms(500);      // delay for 500ms
        
        
    }
}