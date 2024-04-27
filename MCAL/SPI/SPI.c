/*
 * SPI.c
 *
 * Created: 2/9/2024 5:15:20 PM
 *  Author: Mohamed Magdi
 */ 

#include "SPI.h"


void SPIInit(SPIConfig_t* spiCfg){
	
	if(spiCfg->mode == SPI_Mode_Master){
		SetPin(SPCR, MSTR);
	} else if(spiCfg->mode == SPI_Mode_Slave){
		ClearPin(SPCR, MSTR);
	}
	
	if(spiCfg->dataOrder == SPI_DataOrder_LSBFirst){
		SetPin(SPCR, DORD);
	} else if(spiCfg->dataOrder == SPI_DataOrder_MSBFirst){
	    ClearPin(SPCR, DORD);
	}
	
	if(spiCfg->interruptMode == SPI_InterruptMode_En){
		SetPin(SPCR, SPIE);
	} else if(spiCfg->interruptMode == SPI_InterruptMode_Dis){
		ClearPin(SPCR, SPIE);
	}
	
	// This applicable on master mode only
	if(spiCfg->doubleSpeedMode == SPI_DoubleSpeedMode_En){
		SetPin(SPSR, SPI2X);
	} else if(spiCfg->doubleSpeedMode == SPI_DoubleSpeedMode_Dis){
		ClearPin(SPSR, SPI2X);
	}
	SetPin(SPCR, 0);
	// Enable SPI
	SetPin(SPCR, SPE);
}
uint8_t SPITransieve(uint8_t data){
	
	SPDR = data;
	while(ReadPin(SPSR, SPIF) == 0);
	return SPDR;
}

