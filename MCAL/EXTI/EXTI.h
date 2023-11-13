/*
 * EXTI.h
 *
 * Created: 11/11/2023 5:33:25 PM
 *  Author: dell
 */ 


#ifndef EXTI_H_
#define EXTI_H_

typedef struct {
	// Should be assigned @ref EXTI_LINEdefine
	uint8_t		lineNumber;
	// Should be assigned @ref EXTI_TRIG_define
	uint8_t		triggerCase;
	// Callback Function.
	void (*pCallback)(void);
	}EXTI_Config_t;

/*@ref EXTI_LINEdefine
 */
#define EXTI_LINE0					6
#define EXTI_LINE1					7
#define EXTI_LINE2					5 

/*@ref EXTI_TRIG_define
*/
#define EXTI_TRIG_FALLING_EDGE		0
#define EXTI_TRIG_RISING_EDGE		1
#define EXTI_TRIG_LOW_LEVEL			2
#define EXTI_TRIG_ON_CHANGE			3


// APIs:

void updateEXTI(EXTI_Config_t *extiCfg);
void enableEXTI(EXTI_Config_t *extiCfg);
void disableEXTI(uint8_t EXTILine);
uint8_t getEXTIFlag(uint8_t EXTILine);

#endif /* EXTI_H_ */