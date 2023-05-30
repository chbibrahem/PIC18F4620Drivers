
/* 
 * File:   ecu_button.c
 * Author: chbib
 *
 * Created on May 24, 2023, 5:05 PM
 */


#include "ecu_button.h"


/**
 * 
 * @param btn
 * @return 
 */
Std_ReturnType button_initialize (const button_t *btn){
    Std_ReturnType ret = E_OK;
    if (NULL == btn) {
        ret = E_NOT_OK;
    }
    else {
        ret = gpio_pin_direction_initialize(&(btn->button_pin));
    }
    
    return ret;
}
/**
 * 
 * @param btn
 * @param btn_status
 * @return 
 */    
Std_ReturnType button_read_state (const button_t *btn , button_status_t *btn_state){
    Std_ReturnType ret = E_NOT_OK;
    logic_t pin_logic_status = GPIO_LOW;
    
    if (NULL == btn || NULL == btn_state) {
        ret = E_NOT_OK;
    }
    else {
         gpio_pin_read_logic(&(btn->button_pin) , &pin_logic_status);
         if (BUTTON_ACTIVE_HIGH == btn->button_connection){
            if (GPIO_HIGH == pin_logic_status) {
                *btn_state = BUTTON_PRESSED;
         } 
            else {
                *btn_state = BUTTON_RELEASED;
            }
         }
         
        else if (BUTTON_ACTIVE_LOW == btn->button_connection){
            if (GPIO_HIGH == pin_logic_status) {
                *btn_state = BUTTON_RELEASED;
         } 
            else {
                *btn_state = BUTTON_PRESSED;
            }
         }
        else {}
         ret = E_OK;
    }
    
    return ret;
}
