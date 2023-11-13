/*
 * EXTI.c
 *
 * Created: 11/11/2023 5:33:04 PM
 *  Author: Mohamed Magdi
 */ 

#include "ATmega32.h"
#include "EXTI.h"
#include "DIO.h"

void (*gPCallback[3])(void);


void updateEXTI(EXTI_Config_t *extiCfg){
	// Enable External Interrupt Request.
	SetPin(GICR, extiCfg->lineNumber);
	// Setting Trigger Case && Callback.
	switch(extiCfg->lineNumber){
		case EXTI_LINE1:
			gPCallback[1] = extiCfg->pCallback;
			switch(extiCfg->triggerCase){
				case EXTI_TRIG_LOW_LEVEL:
					ClearPin(MCUCR, DIO_PIN_2);
					ClearPin(MCUCR, DIO_PIN_3);
					break;
				case EXTI_TRIG_ON_CHANGE:
					SetPin(MCUCR, DIO_PIN_2);
					ClearPin(MCUCR, DIO_PIN_3);
					break;
				case EXTI_TRIG_FALLING_EDGE:
					ClearPin(MCUCR, DIO_PIN_2);
					SetPin(MCUCR, DIO_PIN_3);
					break;
				case EXTI_TRIG_RISING_EDGE:
					SetPin(MCUCR, DIO_PIN_2);
					SetPin(MCUCR, DIO_PIN_3);
					break;
			}
		break;
		case EXTI_LINE0:
			gPCallback[0] = extiCfg->pCallback;
			switch(extiCfg->triggerCase){
				case EXTI_TRIG_LOW_LEVEL:
					ClearPin(MCUCR, DIO_PIN_0);
					ClearPin(MCUCR, DIO_PIN_1);
					break;
				case EXTI_TRIG_ON_CHANGE:
					SetPin(MCUCR, DIO_PIN_0);
					ClearPin(MCUCR, DIO_PIN_1);
					break;
				case EXTI_TRIG_FALLING_EDGE:
					ClearPin(MCUCR, DIO_PIN_0);
					SetPin(MCUCR, DIO_PIN_1);
					break;
				case EXTI_TRIG_RISING_EDGE:
					SetPin(MCUCR, DIO_PIN_0);
					SetPin(MCUCR, DIO_PIN_1);
					break;
			}
		break;
		case EXTI_LINE2:
			gPCallback[2] = extiCfg->pCallback;
			switch(extiCfg->triggerCase){
				case EXTI_TRIG_FALLING_EDGE:
					ClearPin(MCUCSR, DIO_PIN_6);
					break;
				case EXTI_TRIG_RISING_EDGE:
					SetPin(MCUCSR, DIO_PIN_6);
					break;
			}
		break;
	}
}

void enableEXTI(EXTI_Config_t *extiCfg){
	updateEXTI(extiCfg);
}

void disableEXTI(uint8_t EXTILine){
	ClearPin(GICR, EXTILine);
}

uint8_t getEXTIFlag(uint8_t EXTILine){
	return (uint8_t)ReadPin(GIFR, EXTILine);
}

void clearFlag(uint8_t EXTILine){
	SetPin(GIFR, EXTILine);
}

// ISR() Implementation:
// EXTI0
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(gPCallback[0]){
		gPCallback[0]();
		clearFlag(EXTI_LINE0);
	}
}

// EXTI1
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(gPCallback[1]){
		gPCallback[1]();
		clearFlag(EXTI_LINE1);
	}
}

// EXTI2
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(gPCallback[2]){
		gPCallback[2]();
		clearFlag(EXTI_LINE2);
	}
}


