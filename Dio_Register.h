/*********************************************************/
/* Author      : Muhammad Abdelmoneim Ahmed              */
/* Date        : Aug 28, 2020                            */
/* Version     : 1.0.0                                   */
/* Description :                                         */
/*********************************************************/

#ifndef DIO_DIO_REGISTER_H_
#define DIO_DIO_REGISTER_H_




/** @file Dio_Register.h
* @brief The Definitions of the DIO HW Registers .
*/

#define GPIOA_BASE_ADD		  0x40020000UL
#define GPIOA_MODE_R		  (GPIOA_BASE_ADD + 0x00)
#define GPIOA_OTYPE_R		  (GPIOA_BASE_ADD + 0x04)
#define GPIOA_OSPEED_R		  (GPIOA_BASE_ADD + 0x08)
#define GPIOA_PUPD_R		  (GPIOA_BASE_ADD + 0x0C)
#define GPIOA_ID_R			  (GPIOA_BASE_ADD + 0x10)
#define GPIOA_OD_R            (GPIOA_BASE_ADD + 0x14)
#define GPIOA_BSR_R			  (GPIOA_BASE_ADD + 0x18)
#define GPIOA_LCK_R			  (GPIOA_BASE_ADD + 0x1C)
#define GPIOA_AFNL_R		  (GPIOA_BASE_ADD + 0x20)
#define GPIOA_AFNH_R		  (GPIOA_BASE_ADD + 0x24)

#define GPIOB_BASE_ADD		  0x40020400UL
#define GPIOB_MODE_R		  (GPIOB_BASE_ADD + 0x00)
#define GPIOB_OTYPE_R		  (GPIOB_BASE_ADD + 0x04)
#define GPIOB_OSPEED_R		  (GPIOB_BASE_ADD + 0x08)
#define GPIOB_PUPD_R		  (GPIOB_BASE_ADD + 0x0C)
#define GPIOB_ID_R			  (GPIOB_BASE_ADD + 0x10)
#define GPIOB_OD_R            (GPIOB_BASE_ADD + 0x14)
#define GPIOB_BSR_R			  (GPIOB_BASE_ADD + 0x18)
#define GPIOB_LCK_R			  (GPIOB_BASE_ADD + 0x1C)
#define GPIOB_AFNL_R		  (GPIOB_BASE_ADD + 0x20)
#define GPIOB_AFNH_R		  (GPIOB_BASE_ADD + 0x24)

#define GPIOC_BASE_ADD		  0x40020800UL
#define GPIOC_MODE_R		  (GPIOC_BASE_ADD + 0x00)
#define GPIOC_OTYPE_R		  (GPIOC_BASE_ADD + 0x04)
#define GPIOC_OSPEED_R		  (GPIOC_BASE_ADD + 0x08)
#define GPIOC_PUPD_R		  (GPIOC_BASE_ADD + 0x0C)
#define GPIOC_ID_R			  (GPIOC_BASE_ADD + 0x10)
#define GPIOC_OD_R            (GPIOC_BASE_ADD + 0x14)
#define GPIOC_BSR_R			  (GPIOC_BASE_ADD + 0x18)
#define GPIOC_LCK_R			  (GPIOC_BASE_ADD + 0x1C)
#define GPIOC_AFNL_R		  (GPIOC_BASE_ADD + 0x20)
#define GPIOC_AFNH_R		  (GPIOC_BASE_ADD + 0x24)

#define GPIOD_BASE_ADD		  0x40020C00UL
#define GPIOD_MODE_R		  (GPIOD_BASE_ADD + 0x00)
#define GPIOD_OTYPE_R		  (GPIOD_BASE_ADD + 0x04)
#define GPIOD_OSPEED_R		  (GPIOD_BASE_ADD + 0x08)
#define GPIOD_PUPD_R		  (GPIOD_BASE_ADD + 0x0C)
#define GPIOD_ID_R			  (GPIOD_BASE_ADD + 0x10)
#define GPIOD_OD_R            (GPIOD_BASE_ADD + 0x14)
#define GPIOD_BSR_R			  (GPIOD_BASE_ADD + 0x18)
#define GPIOD_LCK_R			  (GPIOD_BASE_ADD + 0x1C)
#define GPIOD_AFNL_R		  (GPIOD_BASE_ADD + 0x20)
#define GPIOD_AFNH_R		  (GPIOD_BASE_ADD + 0x24)

#define GPIOE_BASE_ADD		  0x40021000UL
#define GPIOE_MODE_R		  (GPIOE_BASE_ADD + 0x00)
#define GPIOE_OTYPE_R		  (GPIOE_BASE_ADD + 0x04)
#define GPIOE_OSPEED_R		  (GPIOE_BASE_ADD + 0x08)
#define GPIOE_PUPD_R		  (GPIOE_BASE_ADD + 0x0C)
#define GPIOE_ID_R			  (GPIOE_BASE_ADD + 0x10)
#define GPIOE_OD_R            (GPIOE_BASE_ADD + 0x14)
#define GPIOE_BSR_R			  (GPIOE_BASE_ADD + 0x18)
#define GPIOE_LCK_R			  (GPIOE_BASE_ADD + 0x1C)
#define GPIOE_AFNL_R		  (GPIOE_BASE_ADD + 0x20)
#define GPIOE_AFNH_R		  (GPIOE_BASE_ADD + 0x24)

#define GPIOF_BASE_ADD		  0x40021400UL
#define GPIOF_MODE_R		  (GPIOF_BASE_ADD + 0x00)
#define GPIOF_OTYPE_R		  (GPIOF_BASE_ADD + 0x04)
#define GPIOF_OSPEED_R		  (GPIOF_BASE_ADD + 0x08)
#define GPIOF_PUPD_R		  (GPIOF_BASE_ADD + 0x0C)
#define GPIOF_ID_R			  (GPIOF_BASE_ADD + 0x10)
#define GPIOF_OD_R            (GPIOF_BASE_ADD + 0x14)
#define GPIOF_BSR_R			  (GPIOF_BASE_ADD + 0x18)
#define GPIOF_LCK_R			  (GPIOF_BASE_ADD + 0x1C)
#define GPIOF_AFNL_R		  (GPIOF_BASE_ADD + 0x20)
#define GPIOF_AFNH_R		  (GPIOF_BASE_ADD + 0x24)


#endif /* DIO_DIO_REGISTER_H_ */










