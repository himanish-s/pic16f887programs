/*
 
 * This program turns LED
 * on one at each time 
 * and then proceeds to 
 * switch on the adjacent right
 * LED
 * 
 * When last LED glows and turns off
 * this pattern repeats again
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

    // initialize trisc to 0
    TRISC = 0b00000000;
    // initialize portc to 0
    PORTC = 0b00000000;

    // initialy left most led glows
    // then shifting occurs
    PORTC = 0b10000000;
    
    // repeat the pattern
    while(TRUE){
    /* In this loop due to shifting after
     * eight shifts PORTC becomes zero
     * 
     * In the last led is on PORTC is 00000001
     * after shifting at this value of PORTC
     * PORTC will be 00000000
     * 
     */    
       if (PORTC == 0b00000000){ // check if PORTC is completely zero
           
           PORTC = 0b10000000; // reassign PORTC value as 10000000
           
           /*
            the delay call below lets user 
            see first led glow again
            if delay is not called it appears as first
            LED is not glowing after PORTC reaches last 
            PIN
            */
           __delay_ms(500);    
           
           
       }else{                   // else shift and call delay
           
           /*
            PORTC>>1  moves only one bit towards rightside
            */
           PORTC = PORTC>>1;    
           
           __delay_ms(500); // delay lets user see the pattern
           
       }
        
    }
    
    
}

