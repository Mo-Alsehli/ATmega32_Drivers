/*
 * lcd.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohamed Magdi
 */
#include "ATmega32.h"
#include "util/delay.h"

#ifndef LCD_DRIVER_LCD_H_
#define LCD_DRIVER_LCD_H_

#define LCD_BIT_MODE 8

#define LCD_PORT DIOA
#define LCD_CTRL_PORT DIOB

#define RS DIO_PIN_0
#define RW DIO_PIN_1
#define EN DIO_PIN_2



#define FUN_SET_8_BIT 0X38
#define FUN_SET_4_BIT 0X28
#define DISP_ON_OFF_CTRL 0X0c
#define DISP_CLEAR 0X01
#define ENTRY_MODE_SET 0X06

void sendChar(uint8_t data);
void sendStr(uint8_t *data);
void sendCommand(uint8_t command);
void displayClear(void);
void LCDInit(void);





#endif /* LCD_DRIVER_LCD_H_ */
