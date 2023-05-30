/* 
 * File:   application.h
 * Author: chbib
 *
 * Created on May 21, 2023, 11:09 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
/* Section : Includes */
#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/BUTTON/ecu_button.h"
#include "ECU_Layer/ecu_seven_seg/ecu_seven_seg.h"
#include "ECU_Layer/DC_MOTOR/ecu_dc_motor.h"
#include "ECU_Layer/KEYPAD/ecu_keypad.h"
/* Section : Macros Declarations */

/* Section : Macros Functions Declarations */

/* Section : Data Types Declarations */

/* Section : Functions Declarations */
void application_initialize (void);

#endif	/* APPLICATION_H */

