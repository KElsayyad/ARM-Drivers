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
#ifndef MSPI_INTERFACE_H
#define MSPI_INTERFACE_H


/******************************************************************************************/
/*-------------------------------- Includes ----------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*                            Standard Types LIB                                          */
/******************************************************************************************/
#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/******************************************************************************************/
/*-------------------------------- Enumerators -------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							    	                                                      */
/******************************************************************************************/


/******************************************************************************************/
/*-------------------------------- Structures --------------------------------------------*/
/******************************************************************************************/


/******************************************************************************************/
/*-------------------------------- Function Prototypes -----------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							01- MSPI1_voidInit			                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MUART_Init															  */
/* @brief 			This function is used to initialise UART							  */
/* @param[in]		void													      	  	  */
/* @param[out]		void													      	  	  */
/******************************************************************************************/
void MSPI1_voidInit(void);


/******************************************************************************************/
/*							02- MSPI1_voidMasterSendReceiveSynch                          */
/*----------------------------------------------------------------------------------------*/
/* @function 		MSPI1_voidMasterSendReceiveSynch									  */
/* @brief 			function is used by master to start SPI communication synchronous	  */
/* @param[in]		Copy_u8SlaveNumber : Slave pin number					      	  	  */
/* @param[in]		Copy_u8DataToTransmit : Data to transmit				      	  	  */
/* @param[in]		*Copy_DataToReceieve : Pointer to data to be received     	  		  */
/******************************************************************************************/
void MSPI1_voidMasterSendReceiveSynch(u8 Copy_u8SlaveNumber, u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceieve);


/******************************************************************************************/
/*							03- MSPI1_voidSlaveSendReceiveSynch                           */
/*----------------------------------------------------------------------------------------*/
/* @function 		MSPI1_voidSlaveSendReceiveSynch										  */
/* @brief 			function is used by master to start SPI communication synchronous	  */
/* @param[in]		Copy_u8DataToTransmit : Data to be sent to master upon receiving data */
/* @param[in]		*Copy_DataToReceieve : Pointer to data to be received     	  		  */
/******************************************************************************************/
void MSPI1_voidSlaveSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceieve);


/******************************************************************************************/
/*							04- MSPI1_voidSetCallBack  				                      */
/*----------------------------------------------------------------------------------------*/
/* @function 	MSPI1_voidSetCallBack												  	  */
/* @brief 		This function is used to set the callback function for ISR			  	  */
/* @param[in]	PFun : Pointer to the function for callback				        	  	  */
/******************************************************************************************/
void MSPI1_voidSetCallBack(void (*PFun)(void));


/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/

#define DISABLE					0u
#define ENABLE					1u


#endif /* SPI_INTERFACE_H */
