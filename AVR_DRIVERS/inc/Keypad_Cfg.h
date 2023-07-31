/*
 * Keypad_Cfg.h
 *
 *  Created on: Feb 4, 2023
 *      Author: Mohamed Tarek
 */

#ifndef INC_KEYPAD_CFG_H_
#define INC_KEYPAD_CFG_H_

#include "Dio.h"
#include "Keypad.h"

#define KEYPAD_PIN_R1   DIO_PORTD,DIO_PIN4
#define KEYPAD_PIN_R2   DIO_PORTD,DIO_PIN5
#define KEYPAD_PIN_R3   DIO_PORTD,DIO_PIN6
#define KEYPAD_PIN_R4   DIO_PORTD,DIO_PIN7
#define KEYPAD_PIN_C1   DIO_PORTD,DIO_PIN3
#define KEYPAD_PIN_C2   DIO_PORTD,DIO_PIN2
#define KEYPAD_PIN_C3   DIO_PORTD,DIO_PIN1
#define KEYPAD_PIN_C4   DIO_PORTD,DIO_PIN0

#endif /* INC_KEYPAD_CFG_H_ */