/*
 * Lcd_PbCfg.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Mohamed Tarek
 */

#include "Lcd.h"

Lcd_DisplayControlType Lcd_Configuration = {
    LCD_STATE_ON,
    LCD_STATE_OFF,
    LCD_STATE_OFF,
    LCD_LINES_2,
    LCD_FONT_5X10
};
