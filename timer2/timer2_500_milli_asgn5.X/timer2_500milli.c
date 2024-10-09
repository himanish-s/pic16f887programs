/*
 * this program will toggle a pin/LED (assume pin is RC0 which is pin15)
 * at 500ms using TIMER2
 *
 * timer2 is an internal timer of 8bit like timer0
 */

#include<xc.h>
#include"config.h"

#define TRUE 1      // use TRUE instead of 1
#define FALSE 0     // use FALSE instead of 0

#define _XTAL_FREQ 8000000 // Frequency of 8MHz

// FOSC is internal crystal 8MHz
// L is for long byte which is 4-bytes
// range is 0 to 4x10^9
#define FOSC 8000000L

void main() {
    // use max range upto 65535
    unsigned int count;

    // keep portc for output only
    TRISC = 0b00000000;
    // set all pins low
    PORTC = 0b00000000;

    // 8 MHz Internal Oscillator
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

    // PR is period register
    // PR2 is for timer2
    // PR2 will trigger every 49 clock ticks
    PR2 = 49;

    // timer2 config register is T2CON
    // from 6 bit to 3 bit includes 6,5,4,3 bits
    // if they are 0000 1:1 postscale
    // if they are 0001 1:2 postscale
    // ....
    // if they are 1001 1:10 postscale
    // ....
    // if they are 1111 1:16 postscale
    // the 2 bit is timer2 on or off
    // the 1bit,0bit is prescaler
    // 00 is 1 prescale
    // 01 is 4 prescale
    // 11 or 10 is 16 prescale
    //postscale is 1:10 // timer2 is on //prescale is 4:1
    T2CON = 0b01001101;

    // the overflow of timer2 is now cleared
    TMR2IF = 0;

    // repeat forever
    while (TRUE) {

        // check for overflow at timer2
        if (TMR2IF == 1) {

            /* this is 1 micro-second block
             * each statement is executed at one to four micro second
             * based on complexity
             */

            // if overflow occurs clear it first
            TMR2IF = 0;
            // toggle pin assuming an LED is at
            RC0 = !RC0;
            // increase count every micro second
            count++;

            if (count == 500) {
                /* this is 500 milli second block
                 * any statement will take 500ms or
                 * 500000 micro second
                 */

                // reset count to start again
                count = 0;
                // toggle pin
                // this toggles at 500ms
                RC0 = !RC0;
            }
        }
    }


}

