/*
 * Keypad.c
 *
 * Created: 10/1/2023 11:42:16 PM
 *  Author: dell
 */ 

#include "Keypad.h"
#include "ATmega32.h"

uint8_t keypadRow[] = {R0, R1, R2, R3};
uint8_t keypadCol[] = {C0, C1, C2, C3};


void Keypad_Init(){
	DIO_PinConfig_t	pinCnf;
	pinCnf.pinNumber = R0;
	pinCnf.mode = DIO_MODE_INPUT;
	DIO_Pin_Init(KEYPAD_PORT, &pinCnf);
	pinCnf.pinNumber = R1;
	pinCnf.mode = DIO_MODE_INPUT;
	DIO_Pin_Init(KEYPAD_PORT, &pinCnf);
	pinCnf.pinNumber = R2;
	pinCnf.mode = DIO_MODE_INPUT;
	DIO_Pin_Init(KEYPAD_PORT, &pinCnf);
	pinCnf.pinNumber = R3;
	pinCnf.mode = DIO_MODE_INPUT;
	DIO_Pin_Init(KEYPAD_PORT, &pinCnf);
	pinCnf.pinNumber = C0;
	pinCnf.mode = DIO_MODE_OUTPUT;
	DIO_Pin_Init(KEYPAD_PORT, &pinCnf);
	pinCnf.pinNumber = C1;
	pinCnf.mode = DIO_MODE_OUTPUT;
	DIO_Pin_Init(KEYPAD_PORT, &pinCnf);
	pinCnf.pinNumber = C2;
	pinCnf.mode = DIO_MODE_OUTPUT;
	DIO_Pin_Init(KEYPAD_PORT, &pinCnf);
	pinCnf.pinNumber = C3;
	pinCnf.mode = DIO_MODE_OUTPUT;
	DIO_Pin_Init(KEYPAD_PORT, &pinCnf);
	
	DIO_WritePort(KEYPAD_PORT, DIO_PORT_HIGH);
}

uint8_t Keypad_GetChar(){
	uint8_t i, j;
	for(i = 0; i < 4; i++){
		DIO_WritePin(KEYPAD_PORT, keypadCol[0], DIO_PIN_HIGH);
		DIO_WritePin(KEYPAD_PORT, keypadCol[1], DIO_PIN_HIGH);
		DIO_WritePin(KEYPAD_PORT, keypadCol[2], DIO_PIN_HIGH);
		DIO_WritePin(KEYPAD_PORT, keypadCol[3], DIO_PIN_HIGH);
		
		DIO_WritePin(KEYPAD_PORT, keypadCol[i], DIO_PIN_LOW);
		
		for(j = 0; j < 4; j++){
			if(!(DIO_ReadPort(KEYPAD_PORT) & (1 << keypadRow[j]))){
				while(!(DIO_ReadPort(KEYPAD_PORT) & (1 << keypadRow[j])));
				switch(i){
					case 0: 
						if     (j == 0) return '7';
						else if(j == 1) return '4';
						else if(j == 2) return '1';
						else if(j == 3) return '!'; // If it's return we will perform clear screen function.
						break;
				
					case 1: 
						if     (j == 0) return '8';
						else if(j == 1) return '5';
						else if(j == 2) return '2';
						else if(j == 3) return '0'; 
						break;
					
					case 2: 
						if     (j == 0) return '9';
						else if(j == 1) return '6';
						else if(j == 2) return '3';
						else if(j == 3) return '='; 
						break;
					
					case 3: 
						if     (j == 0) return '/';
						else if(j == 1) return '*';
						else if(j == 2) return '-';
						else if(j == 3) return '+'; 
						break;	
				}
			}
		}
	}
	return 'A';
}
	
	
