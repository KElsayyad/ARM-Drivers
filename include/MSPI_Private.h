/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	29 / 1 / 20232                                                    */
/* Description     :	MUART_Private.h -> Register Definition Macros                      */
/******************************************************************************************/
#ifndef MSPI_PRIVATE_H
#define MSPI_PRIVATE_H

/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/
#define MSPI1_BASE_ADDRESS			0x40013000

#define MSPI1						((volatile SPI_t*)(MSPI1_BASE_ADDRESS))
/******************************************************************************************/
/*							    I2C Registers			                              	  */
/******************************************************************************************/
typedef struct
{
	u32 CR1			;
	u32 CR2			;
	u32	SR			;
	u32	DR			;
	u32 CRCPR		;
	u32 RXCRCR		;
	u32	TXCRCR		;
	u32 I2SCFGR		;
	u32 I2SPR		;
}SPI_t;

/******************************************************************************************/
/*									SPI Registers                                         */
/******************************************************************************************/
typedef enum
{
	CPHA		,
	CPOL		,
	MSTR		,
	BR0			,
	BR1			,
	BR2			,
	SPE			,
	LSBFIRST	,
	SSI			,
	SSM			,
	RX_ONLY		,
	DFF			,
	CRCNEXT	,
	CRCEN		,
	BIDIOE		,
	BIDIMODE	,
}SPI_CR1_t;

typedef enum
{
	RXDMAEN		,
	TXDMAEN		,
	SSOE		,
	RESERVED	,
	FRF			,
	ERRIE		,
	RXNEIE		,
	TXEIE
}SPI_CR2_t;

typedef enum
{
	RXNE		,
	TXE			,
	CHSIDE		,
	UDR			,
	CRCERROR	,
	MODF		,
	OVR			,
	BSY			,
	FRE
}SPI_SR_t;
/******************************************************************************************/
/*						           User Configuration                                     */
/******************************************************************************************/
#define MASTER		0u
#define SLAVE		1u
#define DISABLE		0u
#define ENABLE		1u

typedef enum
{
	PRESCALER_2  	,
	PRESCALER_4  	,
	PRESCALER_8  	,
	PRESCALER_16 	,
	PRESCALER_32 	,
	PRESCALER_64 	,
	PRESCALER_128	,
	PRESCALER_256
}SPI_PreScaler_t;

#endif /* MSPI_PRIVATE_H */
