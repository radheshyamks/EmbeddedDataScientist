/**************************************************************************
 * File Name: ADC.h
 * Version: 1.0
 * 
 * Description:
 * This file contains the function prototypes and constants used in 
 * the sequencing successive Approximation ADC Component.
 *  
***************************************************************************/
#if !defined(CY_ADC_SAR_SEQ_ADC_H)
#define CY_ADC_SAR_SEQ_ADC_H
#ifdef CY_TYPES
#include "ctypes.h"
#endif

/* ADC_CY_LIB is not defined yet*/
#ifdef ADC_CY_LIB
#include "CyLib.h"
#endif
#include <stdint.h>
/********************************
 * Data Structure definition
 */
/*Sleep Mode API support*/
typedef struct{
    uint8_t enableState;
}ADC_BACKUP_STRUCT;

#endif