/*********************************************************/
/* Author      : Muhammad Abdelmoneim Ahmed              */
/* Date        : Aug 28, 2020                            */
/* Version     : 1.0.0                                   */
/* Description :                                         */
/*********************************************************/

/** @file Dio_Config.c
* @brief This module contains the implementation for the digital
* input/output peripheral configuration
*/


/**********************************************************************
* Includes
**********************************************************************/
#include "DIO/Dio_Config.h" /* For this modules definitions */

/**********************************************************************
* Module Preprocessor Constants
**********************************************************************/

/**********************************************************************
* Module Preprocessor Macros
**********************************************************************/

/**********************************************************************
* Module Typedefs
**********************************************************************/

/*********************************************************************
* Module Variable Definitions
**********************************************************************/

/**
* The following array contains the configuration data for each
* digital input/output peripheral channel (pin). Each row represents a
* single pin. Each column is representing a member of the DioConfig_t
* structure. This table is read in by Dio_Init, where each channel is then
* set up based on this table.
*/

const DioConfig_t DioConfig[DIO_NUM_OF_PINS] =
{
/*    Channel           Resistor             state     Direction      Pin speed        Output type */
   {PORTD_PIN12 ,  DIO_RESISTOR_DISABLED , DIO_LOW , DIO_OUTPUT , DIO_SPEED_25MHZ , DIO_OUT_TYPE_PP },
   {PORTD_PIN14 ,  DIO_RESISTOR_DISABLED , DIO_LOW , DIO_OUTPUT , DIO_SPEED_25MHZ , DIO_OUT_TYPE_PP },
   {PORTD_PIN13 ,  DIO_RESISTOR_DISABLED , DIO_LOW , DIO_OUTPUT , DIO_SPEED_25MHZ , DIO_OUT_TYPE_PP },
   {PORTD_PIN15 ,  DIO_RESISTOR_DISABLED , DIO_LOW , DIO_OUTPUT , DIO_SPEED_25MHZ , DIO_OUT_TYPE_PP },
   {PORTA_PIN0 ,   DIO_RESISTOR_DISABLED , 0        , DIO_INPUT  , 0               , 0 }
};

/*********************************************************************
* Module Functions Definitions
**********************************************************************/


const DioConfig_t * const  Dio_udtConfigGet(void)
{
	return (const DioConfig_t* const)&DioConfig[0];
}



/***End Of File********************************************************/
