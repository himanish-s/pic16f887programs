
#include <xc.h>
#include "config.h"

#define TRUE  1  // using TRUE instead  of 1
#define FALSE 0  // using FALSE instead of 0

#define _XTAL_FREQ 8000000 // time = 12.5 micro sec
#define FOSC 8000000L      // L is long integer size:4-bytes)
                           // ranges upto 4x10^9

void main(void) {

    unsigned char count;
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
                count++;    // increase or record button when pressed
                if (count%2 == 1){  // for odd times on LED
                    RC0  = 1;    //ON LED
                }else{          // for even times LED off
                    RC0  = 0;   // OFF LED
                }
            }
        }
        if (RC5 == 0) {     // 0 means button is pressed
            __delay_ms(50);     // button settling time
            if (RC5 == 0){  // check if button is still pressed
                count++;    // increase or record button count pressed
                if (count%2 == 1){  // for odd times on LED
                    RC1  = 1;    //ON LED
                }else{          // for even times LED off
                    RC1  = 0;   // OFF LED
                }
            }
        }
        if (RC6 == 0) {     // 0 means button is pressed
            __delay_ms(50);     // button settling time
            if (RC6 == 0){  // check if button is still pressed
                count++;    // increase or record button count when pressed
                if (count%2 == 1){  // for odd times on LED
                    RC2  = 1;    //ON LED
                }else{          // for even times LED off
                    RC2  = 0;   // OFF LED
                }
            }
        }
        if (RC7 == 0) {     // 0 means button is pressed
            __delay_ms(50);     // button settling time
            if (RC7 == 0){  // check if button is still pressed
                count++;    // increase or record button count when pressed
                if (count%2 == 1){  // for odd times on LED
                    RC3  = 1;    //ON LED
                }else{          // for even times LED off
                    RC3  = 0;   // OFF LED
                }
            }
        }
    }
}
