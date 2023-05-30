/* 
 * File:   ecu_led.c
 * Author: chbib
 *
 * Created on May 21, 2023, 11:04 PM
 */

#include "ecu_led.h"

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_intialized (const led_t * led){
        Std_ReturnType ret = E_OK;
        
    if (NULL == led){
        ret = E_NOT_OK;
    }
    else {
        pin_config_t pin_obj= {
            .port = led ->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT };
        gpio_pin_initialize(&pin_obj);
    }
    return ret; 
}


/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on (const led_t * led){
    Std_ReturnType ret = E_OK;
    if (NULL == led){
        ret = E_NOT_OK;
    }
    else {
        pin_config_t pin_obj= {
            .port = led ->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT };
        gpio_pin_write_logic(&pin_obj,GPIO_HIGH);
    }
    return ret; 
}


/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off (const led_t * led){
    Std_ReturnType ret = E_OK;
    if (NULL == led){
        ret = E_NOT_OK;
    }
    else {
        pin_config_t pin_obj= {
            .port = led ->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT };
        gpio_pin_write_logic(&pin_obj,GPIO_LOW);
    }
    return ret; 
}


/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_toggle (const led_t * led){
    Std_ReturnType ret = E_OK;
    if (NULL == led){
        ret = E_NOT_OK;
    }
    else {
        pin_config_t pin_obj= {
            .port = led ->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT };
        gpio_pin_toggle_logic(&pin_obj);
        
    }
    return ret; 
}