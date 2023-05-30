/* 
 * File:   Mcal_std_types.h
 * Author: chbib
 *
 * Created on May 21, 2023, 10:57 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section : Includes */
#include "std_libraries.h"
#include "compiler.h"


/* Section : Data Types Declarations */
typedef uint8_t Std_ReturnType;


/* Section : Macros Declarations */
#define STD_HIGH        0x01
#define STD_LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK           (Std_ReturnType)0x01
#define E_NOT_OK       (Std_ReturnType)0x00

/* Section : Macros Functions Declarations */


/* Section : Functions Declarations */



#endif	/* MCAL_STD_TYPES_H */

