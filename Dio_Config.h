/*********************************************************/
/* Author      : Muhammad Abdelmoneim Ahmed              */
/* Date        : Aug 28, 2020                            */
/* Version     : 1.0.0                                   */
/* Description :                                         */
/*********************************************************/

/** @file dio_cfg.h
* @brief This module contains interface definitions for the
* Dio configuration. This is the header file for the definition of the
* interface for retrieving the digital input/output configuration table.
*/

#ifndef DIO_DIO_CONFIG_H_
#define DIO_DIO_CONFIG_H_

/**********************************************************************
*							 Includes
**********************************************************************/


/**********************************************************************
*							 Preprocessor Constants
**********************************************************************/

/* Defines the number of pins on each processor port. */
#define DIO_CHANNELS_NUMBER_PER_PORT 				16U

/* Defines the number of ports on the processor.*/
#define DIO_NUMBER_OF_PORTS 						6U

/* Defines the number of used pins that will be configured  */
#define DIO_NUM_OF_PINS								5U

/**********************************************************************
* 							Typedefs
**********************************************************************/

/**
* Defines the possible states for a digital output pin.
*/
typedef enum
{
	DIO_LOW = 0U, /* Defines digital state ground */
	DIO_HIGH = 1U, /* Defines digital state power */
	DIO_PIN_STATE_MAX /* Defines the maximum digital state */ //for error checking
}DioPinState_t;

/**
* Defines an enumerated list of all the channels (pins) on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
*/
typedef enum
{
	PORTA_PIN0,PORTA_PIN1,PORTA_PIN2,PORTA_PIN3,PORTA_PIN4,PORTA_PIN5,PORTA_PIN6,PORTA_PIN7,PORTA_PIN8,PORTA_PIN9,PORTA_PIN10,PORTA_PIN11,PORTA_PIN12,PORTA_PIN13,PORTA_PIN14,PORTA_PIN15,
	PORTB_PIN0,PORTB_PIN1,PORTB_PIN2,PORTB_PIN3,PORTB_PIN4,PORTB_PIN5,PORTB_PIN6,PORTB_PIN7,PORTB_PIN8,PORTB_PIN9,PORTB_PIN10,PORTB_PIN11,PORTB_PIN12,PORTB_PIN13,PORTB_PIN14,PORTB_PIN15,
	PORTC_PIN0,PORTC_PIN1,PORTC_PIN2,PORTC_PIN3,PORTC_PIN4,PORTC_PIN5,PORTC_PIN6,PORTC_PIN7,PORTC_PIN8,PORTC_PIN9,PORTC_PIN10,PORTC_PIN11,PORTC_PIN12,PORTC_PIN13,PORTC_PIN14,PORTC_PIN15,
	PORTD_PIN0,PORTD_PIN1,PORTD_PIN2,PORTD_PIN3,PORTD_PIN4,PORTD_PIN5,PORTD_PIN6,PORTD_PIN7,PORTD_PIN8,PORTD_PIN9,PORTD_PIN10,PORTD_PIN11,PORTD_PIN12,PORTD_PIN13,PORTD_PIN14,PORTD_PIN15,
	PORTE_PIN0,PORTE_PIN1,PORTE_PIN2,PORTE_PIN3,PORTE_PIN4,PORTE_PIN5,PORTE_PIN6,PORTE_PIN7,PORTE_PIN8,PORTE_PIN9,PORTE_PIN10,PORTE_PIN11,PORTE_PIN12,PORTE_PIN13,PORTE_PIN14,PORTE_PIN15,
	PORTF_PIN0,PORTF_PIN1,PORTF_PIN2,PORTF_PIN3,PORTF_PIN4,PORTF_PIN5,PORTF_PIN6,PORTF_PIN7,PORTF_PIN8,PORTF_PIN9,PORTF_PIN10,PORTF_PIN11,PORTF_PIN12,PORTF_PIN13,PORTF_PIN14,PORTF_PIN15,
	DIO_MAX_PIN_NUMBER
}DioChannel_t;


/**
* @brief Defines the possible DIO pin multiplexing values.
*/
typedef enum
{
	DIO_INPUT = 0x00, /* Defines input mode */
	DIO_OUTPUT = 0x01, /* Defines output mode */
	DIO_ALT_FUN = 0x10, /* Defines alternate function mode */
	DIO_ANALOG_FUN = 0x11, /* Defines analog function mode */
	DIO_MAX_MODE /* Defines maximum number of modes  */
}DioMode_t;

/**
  * @brief  GPIO Output type enumeration
  */
typedef enum
{
  DIO_OUT_TYPE_PP, /* Defines output push-pull type */
  DIO_OUT_TYPE_OD, /* Defines output open-drain type */
  DIO_MAX_OUT
}DioOutType_t;




/**
  * @brief  GPIO Output Maximum frequency enumeration
  */
typedef enum
{
  DIO_SPEED_2MHZ = 0x00, /*!< Low speed */
  DIO_SPEED_25MHZ = 0x01, /*!< Medium speed */
  DIO_SPEED_50MHZ = 0x10, /*!< Fast speed */
  DIO_SPEED_100MHZ = 0x11, /*!< High speed on 30 pF (80 MHz Output max speed on 15 pF) */
  DIO_MAX_SPEED
}DioSpeed_t;




/**
* @brief Defines the possible states of the channel pull-ups
*/
typedef enum
{
	DIO_RESISTOR_DISABLED = 0x00, /*< Used to disable the internal resistors */
	DIO_PULLUP_ENABLED = 0x01, /*< Used to enable the internal pull-ups */
	DIO_PULLDOWN_ENABLED = 0x10, /*< Used to disable the internal pull-downs */
	DIO_MAX_RESISTOR /*< Resistor states should be below this value */
}DioResistor_t;


/**
* @brief Defines the digital input/output configuration table’s elements that are used
* by Dio_Init to configure the DIO peripheral.
*/
typedef struct
{
	DioChannel_t Channel; /**< The I/O pin */
	DioResistor_t Resistor; /**< DISABLED ,PULLUP or PULLDOWN */
	DioPinState_t Data; /**<HIGH or LOW */
	DioMode_t Function; /**< Mux Function - Dio_Peri_Select*/
	DioSpeed_t Speed; /**< DIO channel speed */
	DioOutType_t OutType; /**< DIO output type */
}DioConfig_t;

/**********************************************************************
* Function Prototypes
**********************************************************************/

const DioConfig_t * const Dio_udtConfigGet(void);






#endif /* DIO_DIO_CONFIG_H_ */

/***End of File****************************************************/
