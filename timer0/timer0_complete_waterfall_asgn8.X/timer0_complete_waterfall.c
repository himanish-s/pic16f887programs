/*
 * this program shows complete 
 * waterfall effect by using LEDs and
 * timer used is timer0
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

    OPTION_REG = 0b00000010; // select the timer mode for timer0
    // in OPTION_REG 1:8 PRESCALER is selected last bits are 010    

    // when time period is 1milli and PRESCALER is 1:8 
    // c = 250 and TMR0 is 6
    TMR0 = 6;
    TMR0IF = 0;

    unsigned char count; // upto 255 range is enough

    // default keep PORTC as 0b11111110
    PORTC = 0b11111110;
    
    while (TRUE) {

        if (TMR0IF == 1) { // for every 1milli this condition is true

            TMR0IF = 0;
            TMR0 = 6;
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
