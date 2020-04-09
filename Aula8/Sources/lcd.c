/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descrição do arquivo: Este arquivo é dedicado a inicializar o lcd        */
/*                   	 e manipulá-lo, utilizando as funções               */
/*                       desenvolvidas, escrevendo uma string na linha      */
/*                       desejada.                                          */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criação:      05abril2020                                        */
/* Data da revisão:      09abril2020                                        */
/* ************************************************************************ */

#include "lcd.h"
#include "board.h"
#include "util.h"

/* includes do sistema */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"

/* linha e coluna zero */
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

    /*
     * set pin as gpio 0 = DB0, 1 = DB1...
     * 8 = RS, 9 = Enable.
     */
    PORTC_PCR8 |= 0X100;
    PORTC_PCR9 |= 0X100;
    PORTC_PCR0 |= 0X100;
    PORTC_PCR1 |= 0X100;
    PORTC_PCR2 |= 0X100;
    PORTC_PCR3 |= 0X100;
    PORTC_PCR4 |= 0X100;
    PORTC_PCR5 |= 0X100;
    PORTC_PCR6 |= 0X100;
    PORTC_PCR7 |= 0X100;

    /* set pin as digital output */
    for(i=0;i<10;i++)
    {
        ucVetorInit |= (1 << i);
    }
    /*
     * Após esse for temos um os primeiros 10 pinos setados com 1
     * para passar como output.
     */
    GPIOC_PDDR |= ucVetorInit;  //colocando 1 nos pinos de 0 a 9


    /* turn-on LCD, with no cursor and no blink */
    lcd_sendCommand(CMD_NO_CUR_NO_BLINK);

    /* init LCD */
    lcd_sendCommand(CMD_INIT_LCD);

    /* clear LCD */
    lcd_sendCommand(CMD_CLEAR);

    /* LCD with no cursor */
    lcd_sendCommand(CMD_NO_CURSOR);

    /* cursor shift to right */
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
    unsigned char ucAux = 0;
    int i;
    /* writing data or command */
    if(LCD_RS_CMD == cDataType)
        /* will send a command */
       GPIOC_PCOR |= (1 << LCD_RS_PIN);
    else
        /* will send data */
       GPIOC_PSOR |= (1 << LCD_RS_PIN);

    /*
     * Faz um E bit a bit com o caracter armazenado no ucBuffer
     * extraindo os 8 primeiros bit do buffer para a variável
     * ucAux.
     */
    for(i=0;i<8;i++)
    {
     ucAux |= (ucBuffer & (1u << i));
    }
    /* Envia os 8 primeiros bits de data para as portas */
    GPIOC_PDOR |= ucAux;
    /*
     *
     *enable, delay, disable LCD
     *this generates a pulse in the enable pin this
     */
    GPIOC_PSOR |= (1 << LCD_ENABLE_PIN);
    util_genDelay1ms();

    GPIOC_PCOR |= (1 << LCD_ENABLE_PIN);
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

    /* send the command to set the cursor */
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
    /* clear LCD */
    lcd_sendCommand(CMD_CLEAR);
    /* set the cursor line 0, column 1 */
    lcd_setCursor(0,1);

    /* send string */
    lcd_writeString("*** ES670 ***");

    /* set the cursor line 1, column 0 */
    lcd_setCursor(1,0);
    lcd_writeString("Prj Sis Embarcad");
}

void lcd_writeText(int iLinha, const char *cString)
{
    /*
     * Primeiro analisa se a linha a ser escrita é a primeira
     * ou a segunda, chamando a fução setCursor para definir onde
     * a mensagem começará. Em seguida enviamos a String para ser escrita
     * no LCD
     */
    if(0 == iLinha)
    {
        lcd_setCursor(LINE0,COLUMN0);
        lcd_writeString(cString);
    }
    else if(1 == iLinha)
    {
        lcd_setCursor(1,COLUMN0);
        lcd_writeString(cString);
    }
}

