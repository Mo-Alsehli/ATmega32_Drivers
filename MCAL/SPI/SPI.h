/*
 * SPI.h
 *
 * Created: 2/9/2024 5:15:32 PM
 *  Author: Mohamed Magdi
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "ATmega32.h"
#include "DIO.h"

//------------------------------------------
// User Type Definitions (Structures)
//------------------------------------------

typedef struct {
	// determines Master/Slave mode.
	// Should be set as @ref SPI_Mode_define
	uint8_t	mode;
	// determines data order LSB/MSB
	// Should be set as @ref SPI_DataOrder_define
	uint8_t dataOrder;
	// determines Interrupt Enable
	// Should be set as @ref SPI_InterruptMode_define
	uint8_t interruptMode;
	// determines clock rate
	// Should be set as @ref SPI_ClockRate_define
	uint8_t clockRate;
	// determines Speed
	// Should be set as @ref SPI_DoubleSpeedMode_define
	uint8_t doubleSpeedMode;
	}SPIConfig_t;
	
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral Instants Bits:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

// Interrupt enable pin
#define SPIE						7
// SPI Enable
#define SPE							6
// data order pin
#define DORD						5
// master slave select pin
#define MSTR						4
// clock rate pins
#define SPR1						1
#define SPR0						0
// Interrupt flag pin
#define SPIF						7
// double speed pin
#define SPI2X						0

/*@ref SPI_Mode_define
*/
#define SPI_Mode_Master				1
#define SPI_Mode_Slave				0

/*@ref SPI_DataOrder_define
*/
#define SPI_DataOrder_LSBFirst		1
#define SPI_DataOrder_MSBFirst		0

/*@ref SPI_InterruptMode_define
*/
#define SPI_InterruptMode_En		1
#define SPI_InterruptMode_Dis		0

/*@ref SPI_DoubleSpeedMode_define
*/
#define SPI_DoubleSpeedMode_En		1
#define SPI_DoubleSpeedMode_Dis		0

/*@ref SPI_ClockRate_define
*/
#define SPI_ClockRate_FDev4			0	


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// SPI APIs:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void SPIInit(SPIConfig_t* spiCfg);
uint8_t SPITransieve(uint8_t data);



#endif /* SPI_H_ */