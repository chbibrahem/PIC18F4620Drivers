/* 
 * File:   ecu_layer_init.h
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on February 7, 2021, 10:39 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

#include "LED/ecu_led.h"
#include "ecu_seven_seg/ecu_seven_seg.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "button/ecu_button.h"
#include "KeyPad/ecu_keypad.h"
#include "LCD/ecu_lcd.h"

void ecu_layer_intialize(void);

#endif	/* ECU_LAYER_INIT_H */

