/* 
 * File:   ecu_led.h
 * Author: chbib
 *
 * Created on May 21, 2023, 11:04 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/* Section : Includes */
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"

/* Section : Macros Declarations */

/* Section : Macros Functions Declarations */

/* Section : Data Types Declarations */
typedef enum {
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct {
    uint8_t port_name :3;
    uint8_t pin:3;
    uint8_t led_status :1;
    uint8_t reserved :1;
}led_t;


/* Section : Functions Declarations */

Std_ReturnType led_intialized (const led_t * led);
Std_ReturnType led_turn_on (const led_t * led);
Std_ReturnType led_turn_off (const led_t * led);
Std_ReturnType led_toggle (const led_t * led);


#endif	/* ECU_LED_H */

