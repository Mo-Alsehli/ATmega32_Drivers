/*
 * lcd.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohamed Magdi
 */

#include "lcd.h"
#include "DIO.h"

// Execution Time (seconds) = (time * 255 * 4) / F_CPU
// when time = 1, It takes 1 Melli-seconds.
void wait(uint32_t time)
{
	uint32_t i, j;
	for (i = 0; i < time; i++)
	{
		for (j = 0; j < 255; j++)
		;
	}
}

void fallingEdge(void){
	DIO_WritePin(LCD_CTRL_PORT, EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_CTRL_PORT, EN, DIO_PIN_LOW);
	_delay_ms(1);
}


void sendChar(uint8_t data){
#if LCD_BIT_MODE == 8
	DIO_WritePort(LCD_PORT, data);
	// RS = 1, RW = 0, EN = FALLING EDGE;
	DIO_WritePin(LCD_CTRL_PORT, RS, DIO_PIN_HIGH);
	DIO_WritePin(LCD_CTRL_PORT, RW, DIO_PIN_LOW);
	// Falling Edge
	fallingEdge();
	_delay_ms(1);
#endif

}

void sendStr(uint8_t *data){
	while(*data){
		DIO_WritePort(LCD_PORT, *data);
		// RS = 1, RW = 0, EN = FALLING EDGE;
		DIO_WritePin(LCD_CTRL_PORT, RS, DIO_PIN_HIGH);
		DIO_WritePin(LCD_CTRL_PORT, RW, DIO_PIN_LOW);
		// Falling Edge
		fallingEdge();
		data++;
		_delay_ms(1);
	}
}

void sendCommand(uint8_t command){
#if LCD_BIT_MODE == 8
	DIO_WritePort(LCD_PORT, command);
	// RS = 0, RW = 0, EN = FALLING EDGE;
	DIO_WritePin(LCD_CTRL_PORT, RS, DIO_PIN_LOW);
	DIO_WritePin(LCD_CTRL_PORT, RW, DIO_PIN_LOW);
	// Falling Edge
	fallingEdge();
	_delay_ms(1);
#endif
}

void LCDInit(void){
#if LCD_BIT_MODE == 8
	sendCommand(0x02);
	_delay_ms(1);
	_delay_ms(50);
	sendCommand(FUN_SET_8_BIT);
	_delay_ms(1);
	sendCommand(DISP_ON_OFF_CTRL);
	_delay_ms(1);
	displayClear();
	sendCommand(ENTRY_MODE_SET);
	_delay_ms(1);

#endif
}


void displayClear(void){
	sendCommand(DISP_CLEAR);
}








