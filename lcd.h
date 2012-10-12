// lcd.h - nokia 3310 lcd access
#ifndef __LCD_H
#define __LCD_H

#include "common.h"

// lcd commands
#define LCD_TEMP_CTRL	(1 << 2)
#define LCD_DISP_CTRL 	(1 << 3)
#define LCD_SET_BIAS 	(1 << 4)
#define LCD_FUNC_SET 	(1 << 5)
#define LCD_SET_Y 		(1 << 6)
#define LCD_SET_X 		(1 << 7)
#define LCD_SET_VOP 	(1 << 7)

// H / V / PD bits
#define LCD_FUNC_H		(1 << 0)
#define LCD_FUNC_V		(1 << 1)
#define LCD_FUNC_PD		(1 << 2)

// lcd voltage value
#define LCD_VOLTAGE		7.0
#define LCD_VOP			(char)(LCD_VOLTAGE - 3.06 / 0.06)

// lcd bias
#define LCD_BIAS		0x03

// display control configuration
#define LCD_CFG_BLANK	0x00
#define LCD_CFG_NORMAL	0x04
#define LCD_CFG_ALL_ON	0x01
#define LCD_CFG_INV		0x05

// pic <-> lcd connections
#define SCK		        RD0
#define SDI		        RD1
#define D_C		        RD2
#define _SCE	        RD3
#define _RES 	        RD4

// dram size 
#define LCD_DRAM_SIZE	84 * 6

// start\end characters
#define LCD_START_CHAR  0x20
#ifdef LCD_FULL_ASCII
#define LCD_END_CHAR    0x7f
#else
#define LCD_END_CHAR    0x5a
#endif
#define LCD_COL_SIZE    5

// lcd char table size
#ifdef LCD_FULL_ASCII
#define LCD_TBL_SIZE    480
#else
#define LCD_TBL_SIZE    336
#endif

/*
**	LCD initialization
*/
void lcd_init(void);

/*
**	Write command to LCD
**	Input:
**		command_in - command to send, see lcd commands
*/
void lcd_writecom(char);

/*
**	Write data to LCD's DRAM
**	Input:
**		data_in - input data
*/
void lcd_writedata(char);

/*
**	Send data bit by bit to PCD8544 controller
**	Input:
**		bits_in - input bits
*/
void lcd_clockdata(char);

/*
**	Clear the screen \ erase DRAM
*/
void lcd_clearram(void);

/*
**	Move cursor to (x,y) position
**	Input:
**		x - coordinate X (max 0..83)
**		y - coordinate Y (max 0..5)
*/
void lcd_cursorxy(char,char);

/*
**	Put character to current position
**	Input:
**		character - char to put
*/
void lcd_putchar(char);

/*
**	Put string to current cursor position
**	Input:
**		s - string to send
*/
void lcd_putstr(const char *);

/*
**	Draw point with specified coordinates
**	Input:
**		x - x position
**		y - y position
*/
void lcd_point(unsigned char x, unsigned int y);

#endif // __LCD_H

