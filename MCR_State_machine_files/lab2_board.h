#ifndef		LAB2_BOARD_H
#define		LAB2_BOARD_H

/* --------------------------- */

#define		BUTTON1_CHK	(!(P1&(1<<1)))
#define		BUTTON2_CHK	(!(P2&(1<<0)))
#define		BUTTON3_CHK	(!(P3&(1<<5)))
#define		BUTTON4_CHK	(!(P3&(1<<2)))
#define		BUTTON5_CHK	(!(P3&(1<<3)))

// SV lines are inverted
#define		PORT_SV			P0
#define		SV1				4
#define		SV2				5
#define		SV3				6
#define		SV4				7

#define		PORT_LED	P0
#define 	LED2 		7  
#define 	LED3 		6
#define 	LED4 		5
#define 	LED5 		4

#define		PORT_LCD_D		P2
#define		LCD_DB4			4
#define		LCD_DB5			5
#define		LCD_DB6			6
#define		LCD_DB7			7
#define		PORT_LCD_CTRL	P3
#define		LCD_RS			6
#define		LCD_E				7

#define		_SET_E()	(PORT_LCD_CTRL |= (1<<LCD_E))
#define		_CLR_E()	(PORT_LCD_CTRL &= ~(1<<LCD_E))

#define 	PORT_LCD_LED	P2						 
#define		LCD_RED			1
#define		LCD_GREEN			2
#define		LCD_BLUE			3

/* ----------------------------*/

#endif		//LAB2_BOARD_H