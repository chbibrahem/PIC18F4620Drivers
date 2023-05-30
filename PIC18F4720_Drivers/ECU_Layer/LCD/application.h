/* 
 * File:   application.h
 * Author: chbib
 *
 * Created on May 21, 2023, 11:09 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
/* Section : Includes */
#include "ECU_Layer/ecu_layer_init.h"

/* Section : Macros Declarations */

/* Section : Macros Functions Declarations */

/* Section : Data Types Declarations */
extern keypad_t keypad1;
extern chr_lcd_8bit_t lcd8bit;
extern chr_lcd_4bit_t lcd4bit;
    
/* Section : Functions Declarations */
void application_initialize (void);
void  welcome_func (void);
void  loading_func (void);
#endif	/* APPLICATION_H */

