/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	29 / 1 / 20232                                                    */
/* Description     :	MSPI_Interface.h -> Prototypes, Enumerators & Macros              */
/* Module Features :																	  */
/*				01- MSPI1_voidInit														  */
/*				02- MSPI1_voidMasterSendReceiveSynch       								  */
/*				03- MSPI1_voidSlaveSendReceiveSynch		   								  */
/*				04- MSPI1_voidSetCallBack       										  */
/* TODO:																				  */
/*				05- MSPI1_voidMasterSendReceiveAsynch									  */
/*				05- MSPI1_voidSlaveSendReceiveAsynch									  */
/******************************************************************************************/

/******************************************************************************************/
/*-------------------------------- Includes ----------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*                            Standard Types LIB                                          */
/******************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/******************************************************************************************/
/*                             Lower Level LIB                                            */
/******************************************************************************************/
#include "MGPIO_Interface.h"

/******************************************************************************************/
/*                              Module Headers                                            */
/******************************************************************************************/
#include "MSPI_Private.h"
#include "MSPI_Config.h"
#include "MSPI_Interface.h"

/* Pointer to Function used for CallBack */
void (*MSPI1_CallBack) (void);

/******************************************************************************************/
/*-------------------------------- Function Implementation -------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							01- MSPI1_voidInit			                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MUART_Init															  */
/* @brief 			This function is used to initialise UART							  */
/* @param[in]		void													      	  	  */
/* @param[out]		void													      	  	  */
/******************************************************************************************/
void MSPI1_voidInit(void)
{
	SET_BIT(MSPI1->CR1, CPHA);
	SET_BIT(MSPI1->CR1, CPOL);
#if SPI_MODE == MASTER
	SET_BIT(MSPI1->CR1, MSTR);
#elif SPI_MODE == SLAVE
	CLR_BIT(MSPI1->CR1, MSTR);
#else
	/* Do Nothing */
#endif
#if SPI_MODE == ENABLE
	SET_BIT( MSPI1->CR2, 6 );
//	SET_BIT( MSPI1->CR2, 7 );
#else
	CLR_BIT( MSPI1->CR2, 6 );
//	CLR_BIT( MSPI1->CR2, 7 );
#endif
	MSPI1->CR1 |= (PRESCALER << BR0);
	CLR_BIT(MSPI1->CR1, LSBFIRST);
	CLR_BIT(MSPI1->CR1, SSM);
	SET_BIT(MSPI1->CR1, SSI);
	SET_BIT(MSPI1->CR1, SPE);
}


/******************************************************************************************/
/*							02- MSPI1_voidMasterSendReceiveSynch                          */
/*----------------------------------------------------------------------------------------*/
/* @function 		MSPI1_voidMasterSendReceiveSynch									  */
/* @brief 			function is used by master to start SPI communication synchronous	  */
/* @param[in]		Copy_u8SlaveNumber : Slave pin number					      	  	  */
/* @param[in]		Copy_u8DataToTransmit : Data to transmit				      	  	  */
/* @param[in]		*Copy_DataToReceieve : Pointer to data to be received     	  		  */
/******************************************************************************************/
void MSPI1_voidMasterSendReceiveSynch(u8 Copy_u8SlaveNumber, u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceieve)
{
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PORT, Copy_u8SlaveNumber, MGPIO_PIN_LOW);
	MSPI1->DR = Copy_u8DataToTransmit;
	while (GET_BIT(MSPI1->SR, BSY) == 1);
	*Copy_DataToReceieve = MSPI1 -> DR;
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PORT, Copy_u8SlaveNumber, MGPIO_PIN_HIGH);
}


/******************************************************************************************/
/*							03- MSPI1_voidSlaveSendReceiveSynch                           */
/*----------------------------------------------------------------------------------------*/
/* @function 		MSPI1_voidSlaveSendReceiveSynch										  */
/* @brief 			function is used by master to start SPI communication synchronous	  */
/* @param[in]		Copy_u8DataToTransmit : Data to be sent to master upon receiving data */
/* @param[in]		*Copy_DataToReceieve : Pointer to data to be received     	  		  */
/******************************************************************************************/
void MSPI1_voidSlaveSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceieve)
{
	MSPI1->DR = Copy_u8DataToTransmit;
	while (GET_BIT(MSPI1->SR, BSY) == 1);
	*Copy_DataToReceieve = MSPI1 -> DR;
}


/******************************************************************************************/
/*							04- MSPI1_voidSetCallBack  				                      */
/*----------------------------------------------------------------------------------------*/
/* @function 	MSPI1_voidSetCallBack												  	  */
/* @brief 		This function is used to set the callback function for ISR			  	  */
/* @param[in]	PFun : Pointer to the function for callback				        	  	  */
/******************************************************************************************/
void MSPI1_voidSetCallBack(void (*PFun)(void))
{
	MSPI1_CallBack = PFun;
}


/* SPI ISR */
void SPI1_IRQHandler(void)
{
	MSPI1_CallBack();
}

