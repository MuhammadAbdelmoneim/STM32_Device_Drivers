/*********************************************************/
/* Author      : Muhammad Abdelmoneim Ahmed              */
/* Date        : Aug 28, 2020                            */
/* Version     : 1.0.0                                   */
/*********************************************************/

#ifndef DIO_DIO_H_
#define DIO_DIO_H_

/** @file dio.h
* @brief The interface definition for the dio.
*
* This is the header file for the definition of the interface for a digital
* input/output peripheral on a standard microcontroller.
*/

/**********************************************************************
* Includes
**********************************************************************/
#include "LIB/std_types.h" /* For standard type definitions */
#include <stdint.h>
#include "Dio_Config.h" /* For dio configuration */


/**********************************************************************
* Functions Prototypes
**********************************************************************/
void Dio_vidInit(const DioConfig_t * const Config);
DioPinState_t Dio_udtChannelRead(DioChannel_t Channel);
void Dio_vidChannelWrite(DioChannel_t Channel, DioPinState_t State);
void Dio_vidChannelToggle(DioChannel_t Channel);
void Dio_vidRegisterWrite(uint32_t Address, uint32_t Value);
uint32_t Dio_u32RegisterRead(uint32_t Address);
//void Dio_vidCallbackRegister(DioCallback_t Function, void (*CallbackFunction)(void));


#endif /* DIO_DIO_H_ */







