#ifndef		LCD_COMM_H
#define		LCD_COMM_H

/* --------------------------- */

#include <intx_t.h>

#define LCD_CLEAR 			0x01
#define LCD_LINE_ONE		0x02
#define LCD_LINE_TWO		0xC0
#define LCD_LINE_THREE	0x8C
#define LCD_LINE_FOUR		0xCC

/* this function has to be provided externally
 * to provide a blocking delay of ms_cnt milliseconds */
extern void LCD_DelayMs (uint16_t ms_cnt);

void LCD_Init (void);													// initializes the LCD
void LCD_Byte (uint8_t ch, uint8_t byte);     // ch == 1 - sends a character; ch == 0 - sends a command; byte - payload
void LCD_SendString (uint8_t *str);						// sends a string ending with 0x00

#define _LCD_CHAR(c) LCD_Byte(1,c)						// sends a single character c; based on the LCD_Byte() function

/* ----------------------------*/

#endif		//LCD_COMM_H