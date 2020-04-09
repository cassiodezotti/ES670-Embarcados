/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descri��o do arquivo: Este arquivo � dedicado a apresentar todas as      */
/*                       fun��es utilizadas no programa                     */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de cria��o:      06abril2020                                        */
/* Data da revis�o:      09abril2020                                        */
/* ************************************************************************ */

#ifndef SOURCES_LCD_H_
#define SOURCES_LCD_H_

/* lcd basic commands list */
#define CMD_INIT_LCD        0x0F
#define CMD_CLEAR           0x01
#define CMD_NO_CURSOR       0x0C
#define CMD_CURSOR2R        0x06 /* cursor to right */
#define CMD_NO_CUR_NO_BLINK 0x38 /* no cursor, no blink */

/* *********************************************************************  */
/* Nome da fun��o: lcd_initLcd                                            */
/* Descri��o da fun��o: Essa fun��o inicializa todo o LCD e os par�metros */
/*                      necess�rios como o clock, a porta e os pinos.     */
/* Par�metros de entrada:    n/a                                          */
/* Par�metros de sa�da:      n/a                                          */
/* *********************************************************************  */
void lcd_initLcd(void);

/* ****************************************************************** */
/* Nome da fun��o: lcd_write2Lcd                                      */
/* Descri��o da fun��o: Fun��o que faz a escrita de um dado no LCD.   */
/*                                                                    */
/* Par�metros de entrada: Recebe um caractere de dado ou comando      */
/*                        e o tipo da a��o que ela realizar�.          */
/*                        Se 0 --> LCD receber� um comando            */
/*                        Se 1 --> LCD receber� um dado               */
/* Par�metros de sa�da:   n/a                                         */
/* ****************************************************************** */
void lcd_write2Lcd(unsigned char ucBuffer,  unsigned char cDataType);

/* ****************************************************************** */
/* Nome da fun��o: lcd_writeData                                      */
/* Descri��o da fun��o: Fun��o de apoio que faz a chamada da          */
/*                      fun��o lcd_Write2Lcd a qual escreve no LCD    */
/*                                                                    */
/* Par�metros de entrada: Recebe um valor 0 ou 1                      */
/*                        Se 0 --> LCD receber� um comando            */
/*                        Se 1 --> LCD receber� um dado               */
/* Par�metros de sa�da:   n/a                                         */
/* ****************************************************************** */
void lcd_writeData(unsigned char ucData);

/* ****************************************************************** */
/* Nome da fun��o: lcd_sendoCommand                                   */
/* Descri��o da fun��o: Fun��o que manda um comando para a            */
/*                      fun��o lcd_Write2Lcd a qual realiza no LCD    */
/*                                                                    */
/* Par�metros de entrada: Recebe um valor 0 ou 1                      */
/*                        Se 0 --> mandar� um comando ao LCD          */
/*                        Se 1 --> mandar� um dado ao LCD             */
/* Par�metros de sa�da:   n/a                                         */
/* ****************************************************************** */
void lcd_sendCommand(unsigned char ucCmd);

/* ****************************************************************** */
/* Nome da fun��o: lcd_setCursor                                      */
/* Descri��o da fun��o: Coloca o cursor na linha e coluna recebidas   */
/*                      por par�metro                                 */
/*                                                                    */
/* Par�metros de entrada: Recebe um valor para a linha e coluna       */
/* Par�metros de sa�da:   n/a                                         */
/* ****************************************************************** */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn);

/* ****************************************************************** */
/* Nome da fun��o: lcd_writeString                                    */
/* Descri��o da fun��o: Recebe a string que ser� enviada ao           */
/*                      o LCD                                         */
/*                                                                    */
/* Par�metros de entrada: A string                                    */
/* Par�metros de sa�da:   n/a                                         */
/* ****************************************************************** */
void lcd_writeString(const char *cBuffer);

/* ********************************************************************** */
/* Nome da fun��o: lcd_dummyText                                          */
/* Descri��o da fun��o: Faz a configura��o da mensagem que ser� exibida   */
/*                                                                        */
/* Par�metros de entrada: n/a                                             */
/* Par�metros de sa�da:   n/a                                             */
/* ********************************************************************** */
void lcd_dummyText(void);

/* ********************************************************************* */
/* Nome da fun��o: lcd_writeText                                         */
/* Descri��o da fun��o: Recebe do programador qual mensagem ser� exibida */
/*                      e em qual linha e coluna do LCD isso ocorrer�    */
/*                                                                       */
/* Par�metros de entrada: A string e a linha e coluna do LCD             */
/* Par�metros de sa�da:   n/a                                            */
/* ********************************************************************* */
void lcd_writeText(int iLinha, const char *cString);

#endif /* SOURCES_LCD_H_ */
