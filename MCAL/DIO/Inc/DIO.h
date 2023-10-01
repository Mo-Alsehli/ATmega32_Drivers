/*
 * DIO.h
 *
 *  Created on: Sep 27, 2023
 *      Author: dell
 */

#ifndef DIO_INC_DIO_H_
#define DIO_INC_DIO_H_

//------------------------------------------
// Includes
//------------------------------------------

#include "ATmega32.h"

//------------------------------------------
// User Type Definitions (Structures)
//------------------------------------------

typedef struct {
	// Specifies The number of selected pin from the register
	// The parameter must be set as a value of @ref DIO_PIN_define
	volatile uint8_t pinNumber;
	// Specifies The Output and Input Modes.
	// The parameter must be set as a value of @ref DIO_MODE_define
	volatile uint8_t mode;
}DIO_PinConfig_t;



//------------------------------------------
// Macros Configuration References
//------------------------------------------

/*@ref Module DIO_PIN_define
*/
/*@ref DIO_PINS_define
 */
#define DIO_PIN_0						0	// Pin 0 selected
#define DIO_PIN_1						1	// Pin 1 selected
#define DIO_PIN_2						2	// Pin 2 selected
#define DIO_PIN_3						3	// Pin 3 selected
#define DIO_PIN_4						4	// Pin 4 selected
#define DIO_PIN_5						5	// Pin 5 selected
#define DIO_PIN_6						6	// Pin 6 selected
#define DIO_PIN_7						7// Pin 7 selected

/* @ref DIO_MODE_define
 */
#define DIO_MODE_INPUT					0x00000000u
#define DIO_MODE_OUTPUT					0x00000001u
#define DIO_MODE_INPUT_PU				0x00000002u			// Input Mode with internal pull-up

/* @ref DIO_PIN_state
 */
#define DIO_PIN_HIGH					1
#define DIO_PIN_LOW						0

/* @ref DIO_PORT_state
 */
#define DIO_PORT_HIGH					0xFF
#define DIO_PORT_LOW					0x00

//------------------------------------------
// APIs Supported By "MCAL DIO DRIVER"
//------------------------------------------

void 	DIO_Pin_Init		(uint8_t diox, DIO_PinConfig_t* pinConfig);
void 	DIO_Port_Init		(uint8_t diox, uint8_t portConfig);
void 	DIO_WritePin	(uint8_t diox, uint8_t pinNum, uint8_t value);
void 	DIO_WritePort	(uint8_t diox, uint8_t value);
void 	DIO_TogglePin	(uint8_t diox, uint8_t pinNum);
uint8_t DIO_ReadPin		(uint8_t diox, uint8_t pinNum);
uint8_t DIO_ReadPort	(uint8_t diox);



//------------------------------------------
// Generic Macros:
//----------------------------------

#define DIOA							((uint8_t) 1000)
#define DIOB							((uint8_t) 2000)
#define DIOC							((uint8_t) 3000)
#define DIOD							((uint8_t) 4000)

#define SetPin(reg, pin) (reg |= (1 << pin))
#define ClearPin(reg, pin) (reg &= ~(1 << pin))
#define TogglePin(reg, pin) (reg ^= (1 << pin))
#define ReadPin(reg, pin) (reg >> pin & 1)


#endif /* DIO_INC_DIO_H_ */
