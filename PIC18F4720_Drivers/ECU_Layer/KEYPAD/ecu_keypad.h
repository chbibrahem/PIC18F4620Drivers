/* 
 * File:   ecu_keypad.h
 * Author: chbib
 *
 * Created on May 26, 2023, 10:33 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section : Includes */
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_keypad_cfg.h"
/* Section : Macros Declarations */
#define ECU_KEYPAD_ROW 4
#define ECU_KEYPAD_COLUMNS 4
/* Section : Macros Functions Declarations */

/* Section : Data Types Declarations */
typedef struct {
    pin_config_t keypad_row_pins [ECU_KEYPAD_ROW] ;
    pin_config_t keypad_columns_pins [ECU_KEYPAD_COLUMNS];
}keypad_t;
    
/* Section : Functions Declarations */
Std_ReturnType Keypad_initialize (const keypad_t * _keypad_obj);
Std_ReturnType Keypad_get_value (const keypad_t * _keypad_obj , uint8_t *value);



#endif	/* ECU_KEYPAD_H */

