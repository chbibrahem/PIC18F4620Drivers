/* 
 * File:   ecu_button.h
 * Author: chbib
 *
 * Created on May 24, 2023, 5:05 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H
/* Section : Includes */
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "../BUTTON/ecu_button_cfg.h"

/* Section : Macros Declarations */

/* Section : Macros Functions Declarations */

/* Section : Data Types Declarations */
typedef enum {
    BUTTON_PRESSED =0,
    BUTTON_RELEASED
}button_status_t;

typedef enum {
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct {
    pin_config_t button_pin;
    button_status_t button_state;
    button_active_t button_connection;
    
}button_t;

/* Section : Functions Declarations */

Std_ReturnType button_initialize (const button_t *btn);
Std_ReturnType button_read_state (const button_t *btn , button_status_t *btn_state);
        
#endif	/* ECU_BUTTON_H */

