/*
 * UART.h
 *
 * Created: 11/24/2023 12:29:25 PM
 *  Author: Mohamed Magdi
 */ 


#ifndef UART_H_
#define UART_H_

#include "ATmega32.h"
#include "DIO.h"
#include "lcd.h"

//------------------------------------------
// User Type Definitions (Structures)
//------------------------------------------

typedef struct {
	// Should be assigned as @ref BaudRate_define
	uint8_t baudRate; 
	// Should be assigned as @ref MODE_define
	uint8_t mode;
	// should be assigned as @ref SPEED_define
	uint8_t speed;
	// Should be assigned as @ref InterruptMode_define
	uint8_t interruptModeEn;
	// Set the function() which will be alled once the IRQ Happen.
	void(* P_IRQ_Callback)(void);
} USARTConfig_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral Instants Bits:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

// USART Receive Complete.
#define RXC							7
// USART Transmit Complete.
#define TXC							6
// USART Data Register Empty.
#define UDRE	 					5
// Double the USART Transmission Speed.
#define U2X							1
// Receiver Enable
#define RXEN						4
// Transmitter Enable
#define TXEN						3
// Select Between UCSRC and UBRRH
#define URSEL						7
// USART Mode Select.
#define	UMSEL						6
// Bit 7 – RXCIE: RX Complete Interrupt Enable
#define RXCIE						7
//   Bit 6 – TXCIE: TX Complete Interrupt Enable
#define TXCIE						6

// USART baud rate - UBRRL and UBRRH
// Register select
//#define UMSEL						15

/*@ref BaudRate_define
*/
#define BaudRate_9MHZ_Normal_9600	51
#define BaudRate_9MHZ_Double_9600	103

/*@ref MODE_define
*/

#define MODE_Async					0
#define MODE_Sync					1

/*@ref SPEED_define
*/

#define SPEED_Normal				0
#define SPEED_Double				1

/*@ref InterruptMode_define
*/

#define InterruptMode_NONE			0
#define InterruptMode_RXCIE_EN		1
#define InterruptMode_TXCIE_EN		2
#define InterruptMode_RXTXCIE_EN	3		



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Default stop
#define DefaultStop					'\n'

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// USART APIs:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void USARTInit						(USARTConfig_t* usartCfg);
uint8_t USARTRecieve				(uint8_t* buff);
void USARTSend						(uint8_t data);
uint8_t* USARTRecieveString			(uint8_t* buff);
void USARTSendStr					(uint8_t* data);
uint32_t USARTRecieveNum32			(void);
void USARTSendNumU32				(uint32_t num);
void USARTUpdateCfg					(USARTConfig_t* usartCfg);
void USART_init();
void USART_send(uint8_t data);
uint8_t USART_recieve();


#endif /* UART_H_ */