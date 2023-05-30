/* 
 * File:   ecu_keypad.c
 * Author: chbib
 *
 * Created on May 26, 2023, 10:33 AM
 */

#include "ecu_keypad.h"
static const uint8_t btn_value [ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMNS] = {{'7','8','9','/'},
                                                                       {'4','5','6','*'},
                                                                       {'1','2','3','-'},
                                                                       {'#','0','=','+'}};
/**
 * 
 * @param _keypad_obj
 * @return 
 */
Std_ReturnType Keypad_initialize (const keypad_t * _keypad_obj){
    Std_ReturnType ret = E_OK;
    uint8_t row_counter = 0; 
    uint8_t columns_counter = 0; 
    if(NULL == _keypad_obj){
        ret = E_NOT_OK;
    }
    else{    
        for (row_counter = 0 ; row_counter < ECU_KEYPAD_ROW ; row_counter++){
            
            ret = gpio_pin_initialize (&(_keypad_obj->keypad_row_pins[row_counter]));
        }
        for (columns_counter = 0 ; columns_counter < ECU_KEYPAD_COLUMNS ; columns_counter++){
            ret = gpio_pin_direction_initialize(&(_keypad_obj->keypad_columns_pins[columns_counter]));
            
        }
    }
    return ret;
}

/**
 * 
 * @param _keypad_obj
 * @param value
 * @return 
 */

Std_ReturnType Keypad_get_value (const keypad_t * _keypad_obj , uint8_t *value){
    Std_ReturnType ret = E_OK;
    uint8_t row_counter = 0 , columns_counter = 0 , counter = 0 , column_logic = 0 ; 
    
    if(NULL == _keypad_obj){
        ret = E_NOT_OK;
    }
    else{    
        for (row_counter = 0 ; row_counter < ECU_KEYPAD_ROW ; row_counter++){
            for (counter = 0 ; counter < ECU_KEYPAD_ROW ; counter++){
                gpio_pin_write_logic (&(_keypad_obj->keypad_row_pins[counter]),GPIO_LOW) ;
        }
            gpio_pin_write_logic (&(_keypad_obj->keypad_row_pins[row_counter]),GPIO_HIGH);
             for (columns_counter = 0 ; columns_counter < ECU_KEYPAD_COLUMNS ; columns_counter++){
            ret = gpio_pin_read_logic (&(_keypad_obj->keypad_columns_pins[columns_counter]), &column_logic);
            if (GPIO_HIGH == column_logic ) {
                *value = btn_value [row_counter][columns_counter];
            }
        }
    }
}
        
    return ret;
}

