/* ***************************************************************** */
/* File name:        lcd.c                                           */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related to the LCD HARDWARE based on the KS006U */
/*                   controller                                      */
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#include "lcd.h"
#include "board.h"
#include "util.h"

/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"

/* line and columns */
#define LINE0        0U
#define COLUMN0        0U

#define L0C0_BASE    0x80 /* line 0, column 0 */
#define L1C0_BASE    0xC0 /* line 1, column 0 */
#define MAX_COLUMN  15U

/* ************************************************ */
/* Method name:        lcd_initLcd                  */
/* Method description: Initialize the LCD function  */
/* Input params:       n/a                          */
/* Output params:       n/a                         */
/* ************************************************ */
void lcd_initLcd(void)
{
	int i;
    unsigned char ucVetorInit = 0;
    /* pins configured as outputs */

    /* un-gate port clock*/
    SIM_SCGC5 |= 0x0800;

    /* set pin as gpio */
    PORTC_PCR8 |= 0X100; //RS
	PORTC_PCR9 |= 0X100; //Enable
	PORTC_PCR0 |= 0X100; //DB0
	PORTC_PCR1 |= 0X100; //DB1
	PORTC_PCR2 |= 0X100; //DB2
	PORTC_PCR3 |= 0X100; //DB3
	PORTC_PCR4 |= 0X100; //DB4
	PORTC_PCR5 |= 0X100; //DB5
	PORTC_PCR6 |= 0X100; //DB6
	PORTC_PCR7 |= 0X100; //DB7

    /* set pin as digital output */
	for(i=0;i<10;i++)
	{
	    ucVetorInit |= (1 << i);
	}
	GPIOC_PDDR |= ucVetorInit;  //colocando 1 nos pinos de 0 a 9

    // turn-on LCD, with no cursor and no blink
    lcd_sendCommand(CMD_NO_CUR_NO_BLINK);

    // init LCD
    lcd_sendCommand(CMD_INIT_LCD);

    // clear LCD
    lcd_sendCommand(CMD_CLEAR);

    // LCD with no cursor
    lcd_sendCommand(CMD_NO_CURSOR);

    // cursor shift to right
    lcd_sendCommand(CMD_CURSOR2R);
}

/* ************************************************ */
/* Method name:        lcd_write2Lcd                */
/* Method description: Send command or data to LCD  */
/* Input params:       ucBuffer => char to be send  */
/*                     cDataType=>command LCD_RS_CMD*/
/*                     or data LCD_RS_DATA          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_write2Lcd(unsigned char ucBuffer,  unsigned char cDataType)
{
	int i;
    /* writing data or command */
    if(LCD_RS_CMD == cDataType)
        /* will send a command */
       GPIOC_PCOR |= (1 << LCD_RS_PIN);
    else
        /* will send data */
       GPIOC_PSOR |= (1 << LCD_RS_PIN);

    for(i=0;i<8;i++)
    {
		GPIOC_PDOR |= ((ucBuffer & (1u << i)) >> i);
    }

    /* enable, delay, disable LCD */
    /* this generates a pulse in the enable pin */
    GPIOC_PSOR |= (1 << LCD_ENABLE_PIN);
    //GPIO_HAL_WritePinOutput(LCD_GPIO_BASE_PNT, LCD_ENABLE_PIN, LCD_ENABLED);
    util_genDelay1ms();
    GPIOC_PCOR |= (1 << LCD_ENABLE_PIN);
    //GPIO_HAL_WritePinOutput(LCD_GPIO_BASE_PNT, LCD_ENABLE_PIN, LCD_DISABLED);
    util_genDelay1ms();
    util_genDelay1ms();
}


/* ************************************************ */
/* Method name:        lcd_writeData                */
/* Method description: Write data to be displayed   */
/* Input params:       ucData => char to be written */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeData(unsigned char ucData)
{
    /* just a relay to send data */
    lcd_write2Lcd(ucData, LCD_RS_DATA);
}

/* ************************************************ */
/* Method name:        lcd_sendCommand              */
/* Method description: Write command to LCD         */
/* Input params:       ucCmd=>command to be executed*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd)
{
    /* just a relay to send command */
    lcd_write2Lcd(ucCmd, LCD_RS_CMD);
}


/* ************************************************ */
/* Method name:        lcd_setCursor                */
/* Method description: Set cursor line and column   */
/* Input params:       cLine = LINE0..LINE1         */
/*                     cColumn = COLUMN0..MAX_COLUMN*/
/* Output params:       n/a                         */
/* ************************************************ */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn)
{
    char cCommand;

    if(LINE0 == cLine)
        /* line 0 */
        cCommand = L0C0_BASE;
    else
        /* line 1 */
        cCommand = L1C0_BASE;

    /* maximum MAX_COLUMN columns */
    cCommand += (cColumn & MAX_COLUMN);

    // send the command to set the cursor
    lcd_sendCommand(cCommand);
}


/* ************************************************ */
/* Method name:        lcd_writeString              */
/* Method description: Write string to be displayed */
/* Input params:       cBuffer => string to be      */
/*                     written in LCD               */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeString(const char *cBuffer)
{
    while(*cBuffer)
    {
        lcd_writeData(*cBuffer++);
    };
}


/* ************************************************ */
/* Method name:        lcd_dummyText                */
/* Method description: Write a dummy hard coded text*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_dummyText(void)
{
    // clear LCD
    lcd_sendCommand(CMD_CLEAR);
    // set the cursor line 0, column 1
    lcd_setCursor(0,1);

    // send string
    lcd_writeString("*** ES670 ***");

    //set the cursor line 1, column 0
    lcd_setCursor(1,0);
    lcd_writeString("Prj Sis Embarcad");
}

void lcd_writeText(int iLinha, const char *cString)
{
	if(0 == iLinha)
	{
		lcd_setCursor(0,0);
		lcd_writeString(cString);
	}
	else if(1 == iLinha)
	{
		lcd_setCursor(1,0);
		lcd_writeString(cString);
	}
}

