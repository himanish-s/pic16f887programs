

#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 8000000
#define FOSC       8000000L

#define TRUE  1
#define FALSE 0

void main(void) {
    
    OSCCON = 0b01110110;
    ANSEL  = 0b00000000;
    ANSELH = 0b00000000;
    C1ON=0b00000000;
    C2ON=0b00000000;
    
    TRISC = 0b00000000;
    PORTC = 0b00000000;
    
    while(1){
        
        PORTC = 0b10101010;
        
    }
}
