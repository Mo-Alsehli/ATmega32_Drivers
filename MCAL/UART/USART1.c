/*
 * USART1.c
 *
 * Created: 12/2/2023 8:57:11 PM
 *  Author: dell
 */ 

#include "UART.h"

void USART_init(){
	SetPin(UCSRC, 7);
	
	ClearPin(UCSRC, 4);
	ClearPin(UCSRC, 5);
	
	ClearPin(UCSRC, 3);
	
	SetPin(UCSRC, 1);
	SetPin(UCSRC, 2);
	
	ClearPin(UCSRB, 2);
	
	ClearPin(UCSRC, 7);
	
}

void USART_send(uint8_t data){
	ClearPin(UCSRB, 4);
	SetPin(UCSRB, 3);
	while(ReadPin(UCSRA, 5) == 0){
		asm("NOP");
	};
	
	UDR = data;
	while(ReadPin(UCSRA, 6) == 0);
	}
