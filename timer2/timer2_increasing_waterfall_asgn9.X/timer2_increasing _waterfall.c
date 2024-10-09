/*
 * this program shows increasing waterfall 
 * effect by using LEDs and timer2
 * PORTC is used
 */

#include<xc.h>
#include"config.h"

#define _XTAL_FREQ 8000000
#define FOSC       8000000L

#define TRUE  1
#define FALSE 0

void main(void){
    
    OSCCON = 0b01110110; // oscillator is set to 8MHz
    
    // disable analog and enable digital pins
    ANSEL  = 0b00000000;
    ANSELH = 0b00000000;
    
    // disable comparators
    C1ON = 0;
    C2ON = 0;
    
    // assign PORTC as output
    TRISC = 0b00000000;
    // keep PORTC as low initial
    PORTC = 0b00000000;
    
    // trigger at every 49 ticks
    PR2 = 49;
    
    //POSTSCALE is 1:10 // timer2 is on //PRESCALE is 4:1
    T2CON = 0b01001101; 
    
    //clear timer2 overflow
    TMR2IF = 0;
    
    // assign PORTC value as 0b10000000
    // we will shit this and in switch block other values 
    // are assigned
    PORTC = 0b10000000;
    
    unsigned char count;
    unsigned char s;
    unsigned char val;
    
    s=1;
    val=PORTC;
    
    while(TRUE){
        
        if(TMR2IF == 1){
            
            TMR2IF = 0;
            count++;
            
            if(count == 100){
                
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