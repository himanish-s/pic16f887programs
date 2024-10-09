
#include <xc.h>
#include "config.h"

#define TRUE  1  // using TRUE instead  of 1
#define FALSE 0  // using FALSE instead of 0

#define _XTAL_FREQ 8000000 // time = 12.5 micro sec
#define FOSC 8000000L      // L is long integer size:4-bytes)
                           // ranges upto 4x10^9

void main(void) {

    unsigned char count4,count5,count6,count7;
    OSCCON = 0b00000000;  // 8 MHz internal oscillator (matches to FOSC)
    ANSEL = 0b00000000;   // Pin select is digital (LED require digital input)
    ANSELH = 0b00000000;  // pin select is digital (LEDs are digital)
    
    // comparator is off (they are used to compare two analog and produce a
    // digital output based on difference between analog voltages)
    // as analog circuits are not used comparators are off
    C1ON = 0b00000000;
    C2ON = 0b00000000;    
 
    // initialize direction PORTC
    /*
     * RC7 to RC4 are inputs from buttons
     * RC3 to RC0 are outputs to LEDs
     */
    TRISC = 0b11110000;  
    PORTC = 0b11110000; // all LEDs off initial
    
    while(TRUE){
        
        if (RC4 == 0) {     // 0 means button is pressed
            __delay_ms(50);     // button settling time
            if (RC4 == 0){  // check if button is still pressed
                count4++;    // increase or record button when pressed
                if (count4%2 == 1){  // for odd times OFF LED
                    RC0  = 0;    //Off LED
                }else{          // for even times LED Off
                    RC0  = 1;   // On LED
                }
            }
        }
        if (RC5 == 0) {     // 0 means button is pressed
            __delay_ms(50);     // button settling time
            if (RC5 == 0){  // check if button is still pressed
                count5++;    // increase or record button when pressed
                if (count5%2 == 1){  // for odd times OFF LED
                    RC1  = 0;    //Off LED
                }else{          // for even times LED Off
                    RC1  = 1;   // On LED
                }
            }
        }
        if (RC6 == 0) {     // 0 means button is pressed
            __delay_ms(50);     // button settling time
            if (RC6 == 0){  // check if button is still pressed
                count6++;    // increase or record button when pressed
                if (count6%2 == 1){  // for odd times OFF LED
                    RC2  = 0;    //Off LED
                }else{          // for even times LED Off
                    RC2  = 1;   // On LED
                }
            }
        }
        if (RC7 == 0) {     // 0 means button is pressed
            __delay_ms(50);     // button settling time
            if (RC7 == 0){  // check if button is still pressed
                count7++;    // increase or record button when pressed
                if (count7%2 == 1){  // for odd times OFF LED
                    RC0  = 0;    //Off LED
                }else{          // for even times LED Off
                    RC0  = 1;   // On LED
                }
            }
        }
    }
}
