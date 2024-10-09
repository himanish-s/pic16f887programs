/*
 * This program turns on
 * PIN15 which is RC0
 * first pin in PORTC
 */

#include <xc.h>

/*
 * watchdog-off, code protection-on
 * FOSC is internal oscillator
 * other settings in config.h
 */
#include "config.h"

#define TRUE  1  // using TRUE instead of 1
#define FALSE 0  // using TRUE instead of 1

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

    // TRIS are registers for PORTS
    // All TRIS registers are initialized to 0
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 0b00000000;
    
    // All PORTS are initialized to 0
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    PORTD = 0b00000000;
    PORTE = 0b00000000;
    
    // The LED will be always on
    while(TRUE){
        
        PORTC = 0b00000001; 
        // last bit is PIN15
        // only it is high LED will glow
   
    }
    
}
