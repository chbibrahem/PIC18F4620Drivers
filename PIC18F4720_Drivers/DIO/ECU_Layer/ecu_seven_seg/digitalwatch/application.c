/* 
 * File:   application.c
 * Author: chbrahem
 *
 * Created on May 21, 2023, 10:02 PM
 */


#include "application.h"
#define _XTAL_FREQ 8000000
uint8_t hours  = 1 , minuts = 13 , seconds = 55;
Std_ReturnType ret = E_NOT_OK;

int main() {
    
    application_initialize();

    
    while (1){ 
        for (int counter = 0; counter <50 ; counter ++){
            
            ret = gpio_port_direction_initialize(PORTD_INDEX , 0x3E);
            ret = gpio_port_direction_initialize(PORTC_INDEX ,(uint8_t)( hours/10));
            __delay_us (3333);
            
            ret = gpio_port_direction_initialize(PORTD_INDEX , 0x3D);
            ret = gpio_port_direction_initialize(PORTC_INDEX , (uint8_t)(hours%10));
            __delay_us (3333);
            
            ret = gpio_port_direction_initialize(PORTD_INDEX , 0x3B);
            ret = gpio_port_direction_initialize(PORTC_INDEX , (uint8_t)(minuts/10));
            __delay_us (3333);
            
            ret = gpio_port_direction_initialize(PORTD_INDEX , 0x37);
            ret = gpio_port_direction_initialize(PORTC_INDEX , (uint8_t)(minuts%10));
            __delay_us (3333);
            
            ret = gpio_port_direction_initialize(PORTD_INDEX , 0x2F);
            ret = gpio_port_direction_initialize(PORTC_INDEX , (uint8_t)(seconds/10));
            __delay_us (3333);
            
            ret = gpio_port_direction_initialize(PORTD_INDEX , 0x1F);
            ret = gpio_port_direction_initialize(PORTC_INDEX , (uint8_t)(seconds%10));
            __delay_us (3333);
        }
        seconds++;
        
        if (seconds == 60){
            minuts ++;
            seconds =0;
        }
        if (minuts == 60){
            hours++;
            minuts = 0;
        }
        if (hours == 12){
            hours = 0;
        }
    
    
}

    

    return (EXIT_SUCCESS);
}
    
void application_initialize (void){
    ret = gpio_port_direction_initialize(PORTC_INDEX , 0xF0);
    ret = gpio_port_direction_initialize(PORTD_INDEX , 0xC0);
    

    
}