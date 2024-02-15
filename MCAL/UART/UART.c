/*
 * UART.c
 *
 * Created: 11/24/2023 12:29:10 PM
 *  Author: Mohamed Magdi
 */ 

#include "UART.h"

//------------------------------------------
// Global Variables
//------------------------------------------

USARTConfig_t* gUSARTCfg;

void USARTInit(USARTConfig_t* usartCfg){
	gUSARTCfg = usartCfg;
	// Enable UCSRC
	SetPin(UCSRC, 7);
	// Setting Baud Rate.
	UBRRH = (uint8_t)(usartCfg->baudRate >> 8);
	UBRRL = (uint8_t)usartCfg->baudRate;
	// Set Mode:
	if(usartCfg->mode == MODE_Async){
		ClearPin(UCSRC, UMSEL);
		// Setting Speed.
		if(usartCfg->speed == SPEED_Normal){
			ClearPin(UCSRA, U2X);
		}else if(usartCfg->speed == SPEED_Double){
			SetPin(UCSRA, U2X);
		}
	}
	// Interrupt Configuration
	if(usartCfg->interruptModeEn == InterruptMode_NONE){
		ClearPin(UCSRB, RXCIE);
		ClearPin(UCSRB, TXCIE);
	}else if(usartCfg->interruptModeEn == InterruptMode_RXCIE_EN){
		SetPin(UCSRB, RXCIE);
	}else if(usartCfg->interruptModeEn == InterruptMode_TXCIE_EN){
		SetPin(UCSRB, TXCIE);
	}else if(usartCfg->interruptModeEn == InterruptMode_RXTXCIE_EN){
		SetPin(UCSRB, RXCIE);
		SetPin(UCSRB, TXCIE);
	}
	
	// Disable Parity Mode
	ClearPin(UCSRC, 4);
	ClearPin(UCSRC, 5);
	
	// Stop bit 1
	ClearPin(UCSRC, 3);
	
	// Enabling USART.
	SetPin(UCSRB, TXEN);
	SetPin(UCSRB, RXEN); 
}


void USARTSend(uint8_t data){
	if(gUSARTCfg->interruptModeEn == InterruptMode_NONE){
		while(!ReadPin(UCSRA, UDRE));
		UDR = data;
	}else{
		UDR = data;
	}
	
}

uint8_t USARTRecieve(uint8_t* buff){
	if(gUSARTCfg->interruptModeEn == InterruptMode_NONE){
	while(!ReadPin(UCSRA, RXC));
	}
	*buff = UDR;
	return UDR;
}

void USARTSendStr(uint8_t* data){
	uint8_t i = 0;
	for(i = 0; i < data[i]; i++){
		USARTSend(data[i]);
	}
	USARTSend(DefaultStop);
}

uint8_t* USARTRecieveString	(uint8_t* buff){
	uint8_t i = 0;
	buff[i] = USARTRecieve(&buff[i]);
	while(buff[i] != DefaultStop){
		i++;
		buff[i] = USARTRecieve(&buff[i]);
	}
	buff[i] = '\0';
	return buff;
}


void USARTSendNumU32(uint32_t num){
	uint8_t* p = &num;
	USARTSend(p[0]);
	USARTSend(p[1]);
	USARTSend(p[2]);
	USARTSend(p[3]);
}

uint32_t USARTRecieveNum32(void){
	uint32_t num;
	uint8_t*p;
	p = &num;
	p[0] = USARTRecieve(&p[0]);
	p[1] = USARTRecieve(&p[1]);
	p[2] = USARTRecieve(&p[2]);
	p[3] = USARTRecieve(&p[3]);
	
	return num;
}


ISR(USART_RXC_vect)
{
	gUSARTCfg->P_IRQ_Callback();
}

