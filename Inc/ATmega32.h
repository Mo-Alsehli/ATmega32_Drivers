/*
 * ATmega32.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Magdi
 */

#ifndef ATMEGA32_H_
#define ATMEGA32_H_

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
#define MCUCR_BASE						(*(volatile uint8_t*)0x55)
// MCU Control And Status Register
#define MCUCSR_BASE						(*(volatile uint8_t*)0x54)
// General Interrupt Control Register
#define GICR_BASE						(*(volatile uint8_t*)0x5B)
// General Interrupt Flag Register
#define GIFR_BASE						(*(volatile uint8_t*)0x5A)


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*



#endif /* ATMEGA32_H_ */
