/* 
 * File:   application.c
 * Author: chbrahem
 *
 * Created on May 21, 2023, 10:02 PM
 */


#include "application.h"

pin_config_t segment1_enable = {
    .port = PORTD_INDEX,
    .pin = GPIO_PIN0,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW
};
pin_config_t segment2_enable = {
    .port = PORTD_INDEX,
    .pin = GPIO_PIN1,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW
};

Std_ReturnType ret = E_NOT_OK;

segment_t seg1 = {.segment_pins[0].port = PORTC_INDEX,
                  .segment_pins[0].pin = GPIO_PIN0,
                  .segment_pins[0].logic = GPIO_LOW,
                  .segment_pins[0].direction = GPIO_DIRECTION_OUTPUT,
                  .segment_pins[1].port = PORTC_INDEX,
                  .segment_pins[1].pin = GPIO_PIN1,
                  .segment_pins[1].logic = GPIO_LOW,
                  .segment_pins[1].direction = GPIO_DIRECTION_OUTPUT,
                  .segment_pins[2].port = PORTC_INDEX,
                  .segment_pins[2].pin = GPIO_PIN2,
                  .segment_pins[2].logic = GPIO_LOW,
                  .segment_pins[2].direction = GPIO_DIRECTION_OUTPUT,
                  .segment_pins[3].port = PORTC_INDEX,
                  .segment_pins[3].pin = GPIO_PIN3,
                  .segment_pins[3].logic = GPIO_LOW,
                  .segment_pins[3].direction = GPIO_DIRECTION_OUTPUT,
                  .segment_type = SEGMENT_COMMON_ANODE };
uint8_t number = 45;

int main() {
    
    application_initialize();

    
    while (1){ 
        ret = seven_segment_write_number (&seg1,(uint8_t)(number/10));
        gpio_pin_write_logic(&segment1_enable,GPIO_HIGH);
        __delay_ms(5);
        gpio_pin_write_logic(&segment1_enable,GPIO_LOW);
        
        ret = seven_segment_write_number (&seg1,(uint8_t)(number%10));
        gpio_pin_write_logic(&segment2_enable,GPIO_HIGH);
        __delay_ms(5);
        gpio_pin_write_logic(&segment2_enable,GPIO_LOW);

        }
        
    

    return (EXIT_SUCCESS);
}
    
void application_initialize (void){
        ret = seven_segment_initialize (&seg1);
        ret = gpio_pin_direction_initialize (&segment1_enable);
        ret = gpio_pin_direction_initialize (&segment2_enable);
    
}