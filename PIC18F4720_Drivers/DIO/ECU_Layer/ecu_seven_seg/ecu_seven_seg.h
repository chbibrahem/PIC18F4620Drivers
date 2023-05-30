/* 
 * File:   ecu_seven_seg.h
 * Author: chbib
 *
 * Created on May 25, 2023, 1:00 PM
 */

#ifndef ECU_SEVEN_SEG_H
#define	ECU_SEVEN_SEG_H

/* Section : Includes */
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_seven_seg_cfg.h"

/* Section : Macros Declarations */
#define SEGEMENT_PIN0 0
#define SEGEMENT_PIN1 1
#define SEGEMENT_PIN2 2
#define SEGEMENT_PIN3 3
/* Section : Macros Functions Declarations */

/* Section : Data Types Declarations */
typedef enum {
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct {
    pin_config_t segment_pins[4] ;
    segment_type_t segment_type;
    
}segment_t;
/* Section : Functions Declarations */
Std_ReturnType seven_segment_initialize(const segment_t * seg);
Std_ReturnType seven_segment_write_number(const segment_t * seg , uint8_t number);


#endif	/* ECU_SEVEN_SEG_H */
