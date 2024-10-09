
#include <xc.h>
#include "config.h"

#define TRUE 1
#define FALSE 0

#define _XTAL_FREQ 8000000
#define FOSC       8000000L

void main(void) {

    unsigned int count;
    
    ANSEL = 0b00000000;
    ANSELH = 0b00000000;
    C1ON = 0b00000000;
    C2ON = 0b00000000;
    OSCCON = 0b01110110;
    
    TRISC = 0b00000000;
    PORTC = 0b00000000;
    
    OPTION_REG = 0b00000010; // select the timer mode for timer0
    TMR0 = 0;   //for interval of 1ms c=
    TMR0IF = 0; 
    
    
    while(TRUE){
        
        if (TMR0IF==1){
            
            TMR0IF = 0;
            TMR0 = 6;
            RC0 =! RC0;
            count++;
            if (count == 500){
                count = 0;
                RC1 =! RC1;
            }
        
    }
        
    }
}