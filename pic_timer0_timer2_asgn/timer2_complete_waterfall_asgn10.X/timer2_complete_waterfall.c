/*
 * this program shows complete 
 * waterfall effect by using LEDs and
 * timer used is timer2
 * 
 * assuming complete waterfall as 
 * 7 LEDs 
 * if 8 LEDs are used there
 * would be no recognition of pattern
 * formed
 */

#include <xc.h>
#include "config.h"

// using macro for 1,0
#define TRUE  1 
#define FALSE 0

// using external oscillator at 8MHz
#define _XTAL_FREQ 8000000

// using internal oscillator at 8MHz
#define FOSC 8000000L

void main(void) {

    // internal oscillatorat 8MHz
    OSCCON = 0b01110110;

    // ansel is analog selector now it is off so digital inputs
    // and outputs are taken
    ANSEL = 0b00000000;
    ANSELH = 0b00000000;


    // comparators are used when two analog signals shall be compared to give
    // a digital output by difference in between those analog signals
    // this is not needed so set off
    C1ON = 0;
    C2ON = 0;

    // lets use PORTC
    // set PORTC as OUTPUT only for LEDs using TRISC
    TRISC = 0b00000000;
    PORTC = 0b00000000;
    
    // trigger at every 49 ticks
    PR2=49; 
    
    //POSTSCALE is 1:10 //timer2 is on //PRESCALE is 4:1
    T2CON=0b01001101; 
   
    // clear timer2 overflow
    TMR2IF = 0;

    unsigned char count; // upto 255 range is enough

    // default keep PORTC as 0b11111110
    PORTC = 0b11111110;
    
    while (TRUE) {

        if (TMR2IF == 1) { // for every 1milli this condition is true

            TMR2IF = 0;
            count++;

            if (count == 100) { // for every 100milli this is true

                if (PORTC > 0b00000000) { // initial PORTC is 0b100000000

                    PORTC = PORTC>>1;     

                } else { 
                    
                    PORTC = 0b11111110;
                    
                }
            }
        }
    }




}
