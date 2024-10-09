/*
 
 * This program turns on rightmost led
 * then it turns it off
 * then it turns on adjacent left led
 * and turns it off
 * this happens until left most led is
 * reached and then it
 * repeats from rightmost led again
 * 
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
    
    // initialize PORTC to 0
    TRISC = 0b00000000;
    PORTC = 0b00000000;
    
    PORTC = 0b00000001;
    
    while(TRUE){
        
        if (PORTC == 0b00000000){ // check if PORTC is zero
            PORTC = 0b00000001;   // if True then reassign its value
        }
        
        PORTC=PORTC<<1;           // apply left shiting
        __delay_ms(500);          // call delay so user can see 
                                  // led glow and off  
    }
    
}