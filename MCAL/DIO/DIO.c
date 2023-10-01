/*
 * DIO.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Magdi
 */

#include "DIO.h"

/**=============================================================
 * @Fn - DIO_Init
 * @brief - Initializes a specific pin in a specific port with mode.
 * @param [in] -	PORT, pin configuration.
 * @param [out] - none
 * @retval - none
 * Note - none
 */
void DIO_Pin_Init (uint8_t diox, DIO_PinConfig_t *pinConfig){
	if(pinConfig->mode == DIO_MODE_INPUT){
		switch(diox){
		case DIOA:
			ClearPin(DDRA, pinConfig->pinNumber);
			break;
		case DIOB:
			ClearPin(DDRB, pinConfig->pinNumber);
			break;
		case DIOC:
			ClearPin(DDRC, pinConfig->pinNumber);
			break;
		case DIOD:
			ClearPin(DDRD, pinConfig->pinNumber);
			break;
		}
	}else if(pinConfig->mode == DIO_MODE_OUTPUT){
		switch(diox){
		case DIOA:
			SetPin(DDRA, pinConfig->pinNumber);
			break;
		case DIOB:
			SetPin(DDRB, pinConfig->pinNumber);
			break;
		case DIOC:
			SetPin(DDRC, pinConfig->pinNumber);
			break;
		case DIOD:
			SetPin(DDRD, pinConfig->pinNumber);
			break;
		}
	}else if(pinConfig->mode == DIO_MODE_INPUT_PU){
		switch(diox){
		case DIOA:
			ClearPin(DDRA, pinConfig->pinNumber);
			SetPin(PORTA, pinConfig->pinNumber);
			break;
		case DIOB:
			ClearPin(DDRB, pinConfig->pinNumber);
			SetPin(PORTB, pinConfig->pinNumber);
			break;
		case DIOC:
			ClearPin(DDRC, pinConfig->pinNumber);
			SetPin(PORTC, pinConfig->pinNumber);
			break;
		case DIOD:
			ClearPin(DDRD, pinConfig->pinNumber);
			SetPin(PORTD, pinConfig->pinNumber);
			break;
		}
	}
}

void DIO_Port_Init(uint8_t diox, uint8_t portConfig){
	if(portConfig == DIO_MODE_INPUT){
		switch(diox){
		case DIOA:
			DDRA = DIO_PORT_LOW;
			break;
		case DIOB:
			DDRB = DIO_PORT_LOW;
			break;
		case DIOC:
			DDRC = DIO_PORT_LOW;
			break;
		case DIOD:
			DDRD = DIO_PORT_LOW;
			break;
		}
	}else if(portConfig == DIO_MODE_OUTPUT){
		switch(diox){
		case DIOA:
			DDRA = DIO_PORT_HIGH;
			break;
		case DIOB:
			DDRB = DIO_PORT_HIGH;
			break;
		case DIOC:
			DDRC = DIO_PORT_HIGH;
			break;
		case DIOD:
			DDRD = DIO_PORT_HIGH;
			break;
		}
	}
}

/**=============================================================
 * @Fn - DIO_WritePin
 * @brief - It writes a specific pin with a value (1 or 0).
 * @param [in] -	PORT, pin number.
 * @param [out] - none
 * @retval - none
 * Note - none
 */

void DIO_WritePin (uint8_t diox, uint8_t pinNum, uint8_t value){
	switch(diox){
	case DIOA:
		if(value == DIO_PIN_HIGH){
			SetPin(PORTA, pinNum);
		}else{
			ClearPin(PORTA, pinNum);
		}
		break;
	case DIOB:
		if(value == DIO_PIN_HIGH){
			SetPin(PORTB, pinNum);
		}else{
			ClearPin(PORTB, pinNum);
		}
		break;
	case DIOC:
		if(value == DIO_PIN_HIGH){
			SetPin(PORTC, pinNum);
		}else{
			ClearPin(PORTC, pinNum);
		}
		break;
	case DIOD:
		if(value == DIO_PIN_HIGH){
			SetPin(PORTD, pinNum);
		}else{
			ClearPin(PORTD, pinNum);
		}
		break;
	}
}
void DIO_WritePort(uint8_t diox, uint8_t value){
	switch(diox){
	case DIOA:
		PORTA = value;
		break;
	case DIOB:
		PORTB = value;
		break;
	case DIOC:
		PORTC = value;
		break;
	case DIOD:
		PORTD = value;
		break;
	}
}
void DIO_TogglePin(uint8_t diox, uint8_t pinNum){
	switch(diox){
	case DIOA:
		TogglePin(PORTA, pinNum);
		break;
	case DIOB:
		TogglePin(PORTB, pinNum);
		break;
	case DIOC:
		TogglePin(PORTC, pinNum);
		break;
	case DIOD:
		TogglePin(PORTD, pinNum);
		break;
	}
}
uint8_t DIO_ReadPin	(uint8_t diox, uint8_t pinNum){
	switch(diox){
	case DIOA:
		if((PINA & pinNum) != DIO_PIN_LOW){
			return (uint8_t) DIO_PIN_LOW;
		}else{
			return (uint8_t) DIO_PIN_HIGH;
		}
		break;
	case DIOB:
		if((PINB & pinNum) != DIO_PIN_LOW){
			return (uint8_t) DIO_PIN_LOW;
		}else{
			return (uint8_t) DIO_PIN_HIGH;
		}
		break;
	case DIOC:
		if((PINC & pinNum) != DIO_PIN_LOW){
			return (uint8_t) DIO_PIN_LOW;
		}else{
			return (uint8_t) DIO_PIN_HIGH;
		}
		break;
	case DIOD:
		if((PIND & pinNum) != DIO_PIN_LOW){
			return (uint8_t) DIO_PIN_LOW;
		}else{
			return (uint8_t) DIO_PIN_HIGH;
		}
		break;
	}

	return -1; // shouldn't be reached.
}
uint8_t DIO_ReadPort	(uint8_t diox){
	switch(diox){
	case DIOA:
		return PINA;
		break;
	case DIOB:
		return PINB;
		break;
	case DIOC:
		return PINC;
		break;
	case DIOD:
		return PIND;
		break;
	}
	return -1; // shouln't be reached.
}
