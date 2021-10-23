/*********************************************************/
/* Author      : Muhammad Abdelmoneim  Ahmed             */
/* Date        : Aug 28, 2020                            */
/* Version     : 1.0.0                                   */
/*********************************************************/

/** @file dio.c
* @brief The implementation for the DIO.
*/


/**********************************************************************
* Includes
**********************************************************************/
#include <stdint.h>
#include "LIB/Exceptions.h"
#include "Dio.h" /* For this modules definitions */
#include "Dio_Register.h" /* For Hardware definitions */

/**********************************************************************
* Module Preprocessor Constants
**********************************************************************/

/*********************************************************************
* Module Preprocessor Macros
**********************************************************************/

/**********************************************************************
* Module Typedefs
**********************************************************************/

/**********************************************************************
* Module Variable Definitions
**********************************************************************/

/**
* Defines a table of pointers to the peripheral mode register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrMode[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_MODE_R, (volatile uint32_t*)GPIOB_MODE_R,
		(volatile uint32_t*)GPIOC_MODE_R, (volatile uint32_t*)GPIOD_MODE_R,
		(volatile uint32_t*)GPIOD_MODE_R, (volatile uint32_t*)GPIOF_MODE_R
};

/**
* Defines a table of pointers to the peripheral OTYPE_R register on the
* microcontroller.
*/

static volatile uint32_t * const Dio_arrOutType[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_OTYPE_R, (volatile uint32_t*)GPIOB_OTYPE_R,
		(volatile uint32_t*)GPIOC_OTYPE_R, (volatile uint32_t*)GPIOD_OTYPE_R,
		(volatile uint32_t*)GPIOE_OTYPE_R, (volatile uint32_t*)GPIOF_OTYPE_R
};

/**
* Defines a table of pointers to the peripheral OutSpeed register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrOutSpeed[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_OSPEED_R, (volatile uint32_t*)GPIOB_OSPEED_R,
		(volatile uint32_t*)GPIOC_OSPEED_R, (volatile uint32_t*)GPIOD_OSPEED_R,
		(volatile uint32_t*)GPIOE_OSPEED_R, (volatile uint32_t*)GPIOF_OSPEED_R
};



/**
* Defines a table of pointers to the peripheral OutSpeed register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrPupPd[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_PUPD_R, (volatile uint32_t*)GPIOA_PUPD_R,
		(volatile uint32_t*)GPIOC_PUPD_R, (volatile uint32_t*)GPIOD_PUPD_R,
		(volatile uint32_t*)GPIOE_PUPD_R, (volatile uint32_t*)GPIOF_PUPD_R,
};


/**
* Defines a table of pointers to the peripheral InData register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrInData[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_ID_R, (volatile uint32_t*)GPIOB_ID_R,
		(volatile uint32_t*)GPIOC_ID_R, (volatile uint32_t*)GPIOD_ID_R,
		(volatile uint32_t*)GPIOE_ID_R, (volatile uint32_t*)GPIOF_ID_R,
};

/**
* Defines a table of pointers to the peripheral OutData register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrOutData[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_OD_R, (volatile uint32_t*)GPIOB_OD_R,
		(volatile uint32_t*)GPIOC_OD_R, (volatile uint32_t*)GPIOD_OD_R,
		(volatile uint32_t*)GPIOE_OD_R, (volatile uint32_t*)GPIOF_OD_R,
};


/**
* Defines a table of pointers to the peripheral Bit-Set-Reset  register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrBSR[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_BSR_R, (volatile uint32_t*)GPIOB_BSR_R,
		(volatile uint32_t*)GPIOC_BSR_R, (volatile uint32_t*)GPIOD_BSR_R,
		(volatile uint32_t*)GPIOE_BSR_R, (volatile uint32_t*)GPIOF_BSR_R,
};

/**
* Defines a table of pointers to the peripheral Lock  register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrLock[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_LCK_R, (volatile uint32_t*)GPIOB_LCK_R,
		(volatile uint32_t*)GPIOC_LCK_R, (volatile uint32_t*)GPIOD_LCK_R,
		(volatile uint32_t*)GPIOE_LCK_R, (volatile uint32_t*)GPIOF_LCK_R,
};

/**
* Defines a table of pointers to the peripheral Alternate function Low register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrAFL[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_AFNL_R, (volatile uint32_t*)GPIOB_AFNL_R,
		(volatile uint32_t*)GPIOC_AFNL_R, (volatile uint32_t*)GPIOD_AFNL_R,
		(volatile uint32_t*)GPIOE_AFNL_R, (volatile uint32_t*)GPIOF_AFNL_R,
};

/**
* Defines a table of pointers to the peripheral Alternate function High register on the
* microcontroller.
*/
static volatile uint32_t * const Dio_arrAFH[DIO_NUMBER_OF_PORTS] =
{
		(volatile uint32_t*)GPIOA_AFNH_R, (volatile uint32_t*)GPIOB_AFNH_R,
		(volatile uint32_t*)GPIOC_AFNH_R, (volatile uint32_t*)GPIOD_AFNH_R,
		(volatile uint32_t*)GPIOE_AFNH_R, (volatile uint32_t*)GPIOF_AFNH_R,
};

/**********************************************************************
* Function Prototypes
**********************************************************************/
/**********************************************************************
* Function Definitions
**********************************************************************/

/*********************************************************************
* Function : Dio_vidInit()
*//**
* \b Description:
*
* This function is used to initialize the Dio based on the configuration
* table defined in Dio_Config.c module.
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_CHANNELS_PER_PORT > 0 <br>
* PRE-CONDITION: NUMBER_OF_PORTS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The DIO peripheral is set up with the configuration
* settings.
*
* @param Config is a pointer to the configuration table that
* contains the initialization for the peripheral.
*
* @return void
*
* \b Example:
* @code
* const DioConfig_t *DioConfig = Dio_vidConfigGet();
*
* Dio_vidInit(DioConfig);
* @endcode
**********************************************************************/
void Dio_vidInit(const DioConfig_t * Config)
{
	uint8_t i = 0U; // Loop counter variable
	uint8_t u8PortNumber = 0U; // Port Number
	uint8_t u8PinNumber = 0U; // Pin Number

	/* Loop through all pins, set the data register bit and the data-direction */
	/* register bit according to the Dio configuration table values */
	for (i = 0; i < DIO_NUM_OF_PINS; i++)
	{
		/* Get Port number from configurations table */
		u8PortNumber = Config[i].Channel / DIO_CHANNELS_NUMBER_PER_PORT;
		/* Get Pin number from configurations table */
		u8PinNumber = Config[i].Channel % DIO_CHANNELS_NUMBER_PER_PORT;
		if(Config[i].Function == DIO_OUTPUT)
		{
			/* Set pin direction */
			*Dio_arrMode[u8PortNumber] |=   (uint32_t)Config[i].Function << (u8PinNumber * 2UL);
			/* Set output type */
			*Dio_arrOutType[u8PortNumber] |= (uint32_t)Config[i].OutType << u8PinNumber;
			/* Set output speed */
			*Dio_arrOutSpeed[u8PortNumber] |= (uint32_t)Config[i].Speed << (u8PinNumber * 2UL);
			/* Set Output Data Register */
			*Dio_arrOutData[u8PortNumber] |= (uint32_t)Config[i].Data << u8PinNumber;
		}
		else if(Config[i].Function == DIO_INPUT)
		{
			*Dio_arrMode[u8PortNumber] &= ~(0b11 << (u8PinNumber * 2UL));
			/* Set resistor */
			if(Config[i].Resistor == DIO_RESISTOR_DISABLED)
			{
				*Dio_arrPupPd[u8PortNumber] &= ~(0b11 << (u8PinNumber * 2UL));
			}
			else
			{
				*Dio_arrPupPd[u8PortNumber] |= (uint32_t)Config[i].Resistor << (u8PinNumber * 2UL);
			}
		}
		else if(Config[i].Function == DIO_ALT_FUN)
		{

		}
		else if(Config[i].Function == DIO_ANALOG_FUN)
		{

		}
		else
		{
			/* Error Code */
		}
	}
}

/**********************************************************************
* Function : Dio_ChannelRead()
*//**
* \b Description:
* This function is used to read the state of a dio channel (pin)
*
* PRE-CONDITION: The channel is configured as INPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t
* definition
*
* POST-CONDITION: The channel state is returned.
*
* @param Channel is the DioChannel_t that represents a pin
*
* @return The state of the channel as HIGH or LOW
*
* \b Example:
* @code
* uint8_t pin = Dio_ReadChannel(PORT1_0);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
*
**********************************************************************/
DioPinState_t Dio_udtChannelRead(DioChannel_t Channel)
{
	uint8_t u8PortNumber = 0;
	uint8_t u8PinNumber = 0;
	/* Get Port number from configurations table */
	u8PortNumber = Channel / DIO_CHANNELS_NUMBER_PER_PORT;
	/* Get Pin number from configurations table */
	u8PinNumber = Channel % DIO_CHANNELS_NUMBER_PER_PORT;
	return *Dio_arrInData[u8PortNumber] & (1<< u8PinNumber) ? DIO_HIGH : DIO_LOW;
}
/**********************************************************************
* Function : Dio_ChannelWrite()
*//**
* \b Description:
* *
This function is used to write the state of a channel (pin) as either
* logic high or low through the use of the DioChannel_t enum to select
* the channel and the DioPinState_t to define the desired state.
*
* PRE-CONDITION: The channel is configured as OUTPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition
*
* POST-CONDITION: The channel state will be State
*
* @param Channel is the pin to write using the DioChannel_t
* enum definition
* @param State is HIGH or LOW as defined in the
* DioPinState_t enum
*
* @return void
*
* \b Example:
* @code
* Dio_WriteChannel(PORT1_0, LOW); // Set the PORT1_0 pin low
* Dio_WriteChannel(PORT1_0, HIGH); // Set the PORT1_0 pin high
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
*
**********************************************************************/
void Dio_vidChannelWrite(DioChannel_t Channel, DioPinState_t State)
{
	uint8_t u8PortNumber = 0U;
	uint8_t u8PinNumber = 0U;
	u8PortNumber = Channel / DIO_CHANNELS_NUMBER_PER_PORT;
	u8PinNumber = Channel % DIO_CHANNELS_NUMBER_PER_PORT;
	if(State == DIO_HIGH)
		*Dio_arrOutData[u8PortNumber] |= 1U << u8PinNumber;
	else
		*Dio_arrOutData[u8PortNumber] &= ~(1U << u8PinNumber);
}
/**************************************************************************
* Function : Dio_ChannelToggle()
*//**
* \b Description:
* *
This function is used to toggle the current state of a channel (pin).
*
* PRE-CONDITION: The channel is configured as OUTPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition
*
* POST-CONDITION:
*
* @param Channel is the pin from the DioChannel_t that is
* to be modified.
*
* @return void
*
* \b Example:
* @code
* Dio_ChannelToggle(PORTA_1);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*
**********************************************************************/
void Dio_vidChannelToggle(DioChannel_t Channel)
{
	uint8_t u8PortNumber = 0;
	uint8_t u8PinNumber = 0;
	/* Get Port number from configurations table */
	u8PortNumber = Channel / DIO_CHANNELS_NUMBER_PER_PORT;
	/* Get Pin number from configurations table */
	u8PinNumber = Channel % DIO_CHANNELS_NUMBER_PER_PORT;
	*Dio_arrOutData[u8PortNumber] ^= 1U << u8PinNumber;
}
/**************************************************************************
* Function : Dio_RegisterWrite()
*//**
* \b Description:
* *
This function is used to directly address and modify a Dio register.
* The function should be used to access specialied functionality in the
* Dio peripheral that is not exposed by any other function of the
* interface.
*
* PRE-CONDITION: Address is within the boundaries of the Dio register
* addresss space
*
* POST-CONDITION: The register located at Address with be updated
* with Value
*
* @param Address is a register address within the Dio
* peripheral map
* @param Value is the value to set the Dio register to
*
* @return void
*
* \b Example:
* @code
* Dio_RegisterWrite(0x1000, 0x15);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
*
**********************************************************************/
void Dio_vidRegisterWrite(uint32_t Address, uint32_t Value)
{
	*(volatile uint32_t * const)Address = Value;
}
/**********************************************************************
* Function : Dio_RegisterRead()
*//**
* \b Description:
* *
This function is used to directly address a Dio register. The function
* should be used to access specialied functionality in the Dio peripheral
* that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Dio register
* addresss space
*
* POST-CONDITION: The value stored in the register is returned to the
* caller
*
* @param Address is the address of the Dio register to read
*
* @return The current value of the Dio register.
*
* \b Example:
* @code
* DioValue = Dio_RegisterRead(0x1000);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
* *
**********************************************************************/
uint32_t Dio_u32RegisterRead(uint32_t Address)
{
	return *(volatile const uint32_t * const)Address;
}
/**********************************************************************
* Function : Dio_CallbackRegister()
*//**
* \b Description:
*
* This function is used to set the callback functions of the dio driver. By
* default, the callbacks are initialized to a NULL pointer. The driver may
* contain more than one possible callback, so the function will take a
* parameter to configure the specified callback.
*
* PRE-CONDITION: The DioCallback_t has been populated
* PRE-CONDITION: The callback function exists within memory.
*
* POST-CONDITION: The specified callback function will be registered
* with the driver.
*
* @param Function is the callback function that will be registered
* @param CallbackFunction is a function pointer to the desired
* function
*
* @return None.
*
* \b Example:
* @code
* DioCallback_t Dio_Function = DIO_SAMPLE_COMPLETE;
* *
Dio_CallbackRegister(Dio_Function, Dio_SampleAverage);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
*
**********************************************************************/
//void Dio_CallbackRegister(DioCallback_t Function,
//TYPE (*CallbackFunction)(type))
//{
//
//}
/**************** END OF FUNCTIONS ********************************/











