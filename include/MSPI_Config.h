/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	29 / 1 / 20232                                                    */
/* Description     :	MSPI_Config.h -> SPI User Configurations			              */
/******************************************************************************************/
#ifndef MSPI_CONFIG_H
#define MSPI_CONFIG_H

/******************************************************************************************/
/*-------------------------------- Includes ----------------------------------------------*/
/******************************************************************************************/

#define MSPI1_SLAVE_PORT 	MGPIO_PORTA

/* Select SPI Mode
 * 		1) MASTER
 * 		2) SLAVE
 */
#define SPI_MODE			SLAVE

/* Select Pre-Scaler
 * 		1) PRESCALER_2
 * 		2) PRESCALER_4
 * 		3) PRESCALER_8
 * 		4) PRESCALER_16
 * 		5) PRESCALER_32
 * 		6) PRESCALER_64
 * 		7) PRESCALER_128
 * 		8) PRESCALER_256
 */
#define PRESCALER			PRESCALER_2

/* Enable Interrupt
 * 		1) ENABLE
 * 		2) DISABLE
 */
#define INTERRUPT_MODE		ENABLE


#endif /* MSPI_CONFIG_H */

