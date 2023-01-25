/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	18 / 1 / 20232                                                    */
/* Description     :	MRCC_Private.h -> Register Definition Macros                      */
/******************************************************************************************/
#ifndef MSTK_PRIVATE_H
#define MSTK_PRIVATE_H

/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/
#define MSTK_BASE_ADDRESS		0xE000E010
#define MSTK					((MSTK_t*)(MSTK_BASE_ADDRESS))
/******************************************************************************************/
/*							    Sys Tick Register Addresses                               */
/******************************************************************************************/
typedef struct
{
	volatile u32 CTRL		;
	volatile u32 LOAD		;
	volatile u32 VAL		;
	volatile u32 CALIB		;
}MSTK_t;


/******************************************************************************************/
/*							RCC Control Register (RCC_CR)                                 */
/******************************************************************************************/
#define MSTK_CTRL_ENABLE				   0u
#define MSTK_CTRL_TICK_INT				   1u
#define MSTK_CTRL_CLK_SOURCE			   2u
#define MSTK_CTRL_COUNT_FLAG			   16u


/******************************************************************************************/
/*						           User Configuration                                     */
/******************************************************************************************/

#endif /* MSTK_PRIVATE_H */
