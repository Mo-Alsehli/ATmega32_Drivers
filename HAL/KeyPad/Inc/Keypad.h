/*
 * Keypad.h
 *
 * Created: 10/1/2023 11:42:05 PM
 *  Author: Mohamed Magdi
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define KEYPAD_PORT	DIOC

// Rows
#define R0 (uint8_t)DIO_PIN_0
#define R1 (uint8_t)DIO_PIN_1
#define R2 (uint8_t)DIO_PIN_2
#define R3 (uint8_t)DIO_PIN_3
// Columns
#define C0 (uint8_t)DIO_PIN_4
#define C1 (uint8_t)DIO_PIN_5
#define C2 (uint8_t)DIO_PIN_6
#define C3 (uint8_t)DIO_PIN_7  

void Keypad_Init(void);
uint8_t Keypad_GetChar(void);


#endif /* KEYPAD_H_ */