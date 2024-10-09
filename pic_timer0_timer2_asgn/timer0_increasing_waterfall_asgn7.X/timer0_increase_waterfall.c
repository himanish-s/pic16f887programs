/*
 * this program shows an increasing 
 * waterfall effect by using LEDs and
 * timer used is timer0
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
    unsigned char s = 1; // used to shift
    unsigned char i = 0; // used to add 2 powers 
    unsigned char val; // port value holder

     // assign val as 0b10000000 initial
     // this is reassigned in the else-block and in switch-block
    val = 0b10000000;
    PORTC = 0b10000000;
    
    while (TRUE) {

        if (TMR0IF == 1) { // for every 1milli this condition is true

            TMR0IF = 0;
            TMR0 = 6;
            count++;

            if (count == 100) { // for every 100milli this is true

                if (PORTC > 0b00000000) { // initial PORTC is 0b100000000

                    // shift by s value it is incremented 
                    // when PORTC become zero
                    
                    PORTC = PORTC>>s;     

                } else {       // this is true when PORTC is zero
                    
                    // increment so we may shift more digits
                    s++;    
                    
                    // store in case of poweroff and lets repeat 
                    // from same no of led shifts
                    val = PORTC; 
                    
                    /* use switch to look s value and 
                       assign number of bits as s value to shift.
                       Taking s value corresponding to no of digits 
                       to reduce confusion while shifting */
                    switch (s) { // assign these values as per s value 
                        case 2:
                            PORTC = 0b11000000; 
                            break;
                        case 3:
                            PORTC = 0b11100000;
                            break;
                        case 4:
                            PORTC = 0b11110000;
                            break;
                        case 5:
                            PORTC = 0b11111000;
                            break;
                        case 6:
                            PORTC = 0b11111100;
                            break;
                        case 7:
                            PORTC = 0b11111110;
                            break;
                        case 8:    
                          /* when PORTC reaches max
                           * it shifting occurs and again PORTC will be
                           * equal to zero
                           * 
                           * keep s as 1 again 
                           * so it may work with newly
                           * assigned  zero value of PORTC
                           * and this process can repeat
                           */
                            PORTC = 0b11111111;
                            s = 1; // switch has to reset to start over
                            break;
                        default:
                            /* If any thing happens reload 
                             * the PORTC value from val
                             */
                            PORTC = val;
                            s = 1;
                            break;
                    }
                }
            }
        }
    }




}
