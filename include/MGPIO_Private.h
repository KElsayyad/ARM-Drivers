/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	18 / 1 / 20232                                                    */
/* Description     :	MGPIO_Private.h -> Register Definition Macros                      */
/******************************************************************************************/
#ifndef MGPIO_PRIVATE_H
#define MGPIO_PRIVATE_H

/******************************************************************************************/
/*-------------------------------- Structure ---------------------------------------------*/
/******************************************************************************************/
typedef struct
{
	volatile u32 MODER		;
	volatile u32 OTYPER		;
	volatile u32 OSPEEDR	;
	volatile u32 PUPDR		;
	volatile u32 IDR		;
	volatile u32 ODR		;
	volatile u32 BSRR		;
	volatile u32 LCKR		;
	volatile u32 AFRL		;
	volatile u32 AFRH		;
}MGPIO_t;

/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/
#define MGPIOA_BASE_ADDRESS		0x40020000
#define MGPIOB_BASE_ADDRESS		0x40020400
#define MGPIOC_BASE_ADDRESS		0x40020800
#define MGPIOA					((MGPIO_t*)(MGPIOA_BASE_ADDRESS))
#define MGPIOB					((MGPIO_t*)(MGPIOB_BASE_ADDRESS))
#define MGPIOC					((MGPIO_t*)(MGPIOC_BASE_ADDRESS))

/******************************************************************************************/
/*						          User Configuration                                       */
/******************************************************************************************/

#endif /* MGPIO_PRIVATE_H */
