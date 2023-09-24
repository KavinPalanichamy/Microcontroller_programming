#include <aduc834.h>
#include <lab2_board.h>
#include <lcd_comm.h>

void LCD_Init (void)
{
	LCD_DelayMs(50);
	PORT_LCD_CTRL &= ~(1<<LCD_RS);
	PORT_LCD_D &= 0x0F;
	PORT_LCD_D |= 0x03 << 4;
	_SET_E();
	_CLR_E();
	LCD_DelayMs(10);
	_SET_E();
	_CLR_E();
	LCD_DelayMs(1);
	_SET_E();
	_CLR_E();
	LCD_DelayMs(1);

	/* 4b interface */
	PORT_LCD_D &= 0x0F;
	PORT_LCD_D |= 0x02 << 4;	
	_SET_E();
	_CLR_E();
	LCD_DelayMs(1);

	LCD_Byte (0,0x28);
	LCD_Byte (0,0x08);
	LCD_Byte (0,LCD_CLEAR);
	LCD_Byte (0,0x06);
	LCD_Byte (0,0x0C);
}	

void LCD_Byte (uint8_t ch, uint8_t byte)
{
	if (ch==1)
		PORT_LCD_CTRL |= (1<<LCD_RS);
	else
		PORT_LCD_CTRL &= ~(1<<LCD_RS);
	
	_SET_E();
	PORT_LCD_D &= 0x0F;
	PORT_LCD_D |= byte & 0xF0;
	_CLR_E();
	
	_SET_E();
	PORT_LCD_D &= 0x0F;
	PORT_LCD_D |= byte << 4;
	_CLR_E();
	LCD_DelayMs(2);
}

void LCD_SendString (uint8_t *str)
{
	while(*str != 0)
	{
		_LCD_CHAR(*str);
		str++;
	}
}