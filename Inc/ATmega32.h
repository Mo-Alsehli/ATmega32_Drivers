/*
 * ATmega32.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Magdi
 */

#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#define F_CPU	1000000UL

//---------------------------------------------------
//Includes
//---------------------------------------------------

#include <stdint.h>

#define F_CPU 1000000UL


//---------------------------------------------------
//Base addresses for memories
//---------------------------------------------------

#define FLASH_BASE						0x0000
#define INTERNAL_SRAM_BASE				0x0060
// EEPROM Address Register
#define	EEARH_BASE						0x3F
// EEPROM Data Register
#define EECR_BASE						0x3D




//---------------------------------------------------
//Base addresses for Bus Peripherals.
//---------------------------------------------------

// Digital I/O Bases
// PORTA
#define PORTA 							*((volatile uint8_t*) 0x3B)
#define DDRA 							*((volatile uint8_t*) 0x3A)
#define PINA 							*((volatile uint8_t*) 0x39)

// PORTB
#define PORTB 							*((volatile uint8_t*) 0x38)
#define DDRB 							*((volatile uint8_t*) 0x37)
#define PINB 							*((volatile uint8_t*) 0x36)

// PORTC
#define PORTC 							*((volatile uint8_t*) 0x35)
#define DDRC 							*((volatile uint8_t*) 0x34)
#define PINC 							*((volatile uint8_t*) 0x33)

// PORTD
#define PORTD 							*((volatile uint8_t *) 0x32)
#define DDRD 							*((volatile uint8_t *) 0x31)
#define PIND 							*((volatile uint8_t *) 0x30)

// Special Function I/O Register
#define SFIOR_BASE						(*(volatile uint8_t*)0x50)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register:	EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// MCU Control Register.
#define MCUCR						*((volatile uint8_t*)0x55)
// MCU Control And Status Register
#define MCUCSR						*((volatile uint8_t*)0x54)
// General Interrupt Control Register
#define GICR						*((volatile uint8_t*)0x5B)
// General Interrupt Flag Register
#define GIFR						*((volatile uint8_t*)0x5A)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register:	UART
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

// USART I/O Data Register
#define UDR							*((volatile uint8_t*)0x2C)

// USART Control and Status Register A
#define UCSRA						*((volatile uint8_t*)0x2B)

// USART Control and Status Register B
#define UCSRB						*((volatile uint8_t*)0x2A)

// USART Control and Status Register C
#define UCSRC						*((volatile uint8_t*)0x40)

// USART Baud Rate Registers
#define UBRRH						*((volatile uint8_t*)0x40)
#define UBRRL						*((volatile uint8_t*)0x29)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register:	SPI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

// SPI Control Register
#define SPCR						*((volatile uint8_t*)0x2D)

// SPI Status Register
#define SPSR						*((volatile uint8_t*)0x2E)

// SPI Data Register
#define SPDR						*((volatile uint8_t*)0x2F)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*



#endif /* ATMEGA32_H_ */
