#include<xc.h>
#include"config.h"

#define _XTAL_FREQ 8000000          // Frequency of 8MHz

// FOSC is internal crystal 8MHz
// L is for long byte which is 4-bytes
// range is 0 to 4x10^9
#define FOSC 8000000L

void main() {
    // keep portc for output only
    TRISC = 0b00000000;
    // set all pins low
    PORTC = 0b00000000;

    // 8 MHz Internal Oscillator
    OSCCON = 0b01110110;

    // ansel is anaog selector now it is off so digital inputs
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
    T2CON = 0b01001101; //postscale is 1:10 // timer2 is on //prescale is 4:1

    // the overflow of timer2 is now cleared
    TMR2IF = 0;

    // repeat forever or until microcontroller is on
    while (1) {
        // check if overflow occured at timer2
        if (TMR2IF == 1) {
            // clear the overflow of timer2
            TMR2IF = 0;
            // toggle the led at PIN15
            RC0 = !RC0;
        }

    }

}
