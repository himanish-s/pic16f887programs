/*
 * File:   program_test.c
 *
 * Created on May 11, 2023, 2:00 AM
 */


#include <xc.h>

void main(void) {
    
    TRISB = 0b11110000;
    PORTB = 0b11110000;
    
    while(1){
        PORTB = 0b11110001;
    }
}
