
/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descrição do arquivo: Este arquivo é dedicado a apresentar todas as      */
/*                       funções utilizadas no programa                     */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criação:      06abril2020                                        */
/* Data da revisão:      09abril2020                                        */
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
/* Nome da função: lcd_initLcd                                            */
/* Descrição da função: Essa função inicializa todo o LCD e os parâmetros */
/*                      necessários como o clock, a porta e os pinos.     */
/* Parâmetros de entrada:    n/a                                          */
/* Parâmetros de saída:      n/a                                          */
/* *********************************************************************  */
void lcd_initLcd(void);

/* ****************************************************************** */
/* Nome da função: lcd_write2Lcd                                      */
/* Descrição da função: Função que faz a escrita de um dado no LCD.   */
/*                                                                    */
/* Parâmetros de entrada: Recebe um caractere de dado ou comando      */
/*                        e o tipo da ação que ela realizará.          */
/*                        Se 0 --> LCD receberá um comando            */
/*                        Se 1 --> LCD receberá um dado               */
/* Parâmetros de saída:   n/a                                         */
/* ****************************************************************** */
void lcd_write2Lcd(unsigned char ucBuffer,  unsigned char cDataType);

/* ****************************************************************** */
/* Nome da função: lcd_writeData                                      */
/* Descrição da função: Função de apoio que faz a chamada da          */
/*                      função lcd_Write2Lcd a qual escreve no LCD    */
/*                                                                    */
/* Parâmetros de entrada: Recebe um valor 0 ou 1                      */
/*                        Se 0 --> LCD receberá um comando            */
/*                        Se 1 --> LCD receberá um dado               */
/* Parâmetros de saída:   n/a                                         */
/* ****************************************************************** */
void lcd_writeData(unsigned char ucData);

/* ****************************************************************** */
/* Nome da função: lcd_sendoCommand                                   */
/* Descrição da função: Função que manda um comando para a            */
/*                      função lcd_Write2Lcd a qual realiza no LCD    */
/*                                                                    */
/* Parâmetros de entrada: Recebe um valor 0 ou 1                      */
/*                        Se 0 --> mandará um comando ao LCD          */
/*                        Se 1 --> mandará um dado ao LCD             */
/* Parâmetros de saída:   n/a                                         */
/* ****************************************************************** */
void lcd_sendCommand(unsigned char ucCmd);

/* ****************************************************************** */
/* Nome da função: lcd_setCursor                                      */
/* Descrição da função: Coloca o cursor na linha e coluna recebidas   */
/*                      por parâmetro                                 */
/*                                                                    */
/* Parâmetros de entrada: Recebe um valor para a linha e coluna       */
/* Parâmetros de saída:   n/a                                         */
/* ****************************************************************** */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn);

/* ****************************************************************** */
/* Nome da função: lcd_writeString                                    */
/* Descrição da função: Recebe a string que será enviada ao           */
/*                      o LCD                                         */
/*                                                                    */
/* Parâmetros de entrada: A string                                    */
/* Parâmetros de saída:   n/a                                         */
/* ****************************************************************** */
void lcd_writeString(const char *cBuffer);

/* ********************************************************************** */
/* Nome da função: lcd_dummyText                                          */
/* Descrição da função: Faz a configuração da mensagem que será exibida   */
/*                                                                        */
/* Parâmetros de entrada: n/a                                             */
/* Parâmetros de saída:   n/a                                             */
/* ********************************************************************** */
void lcd_dummyText(void);

/* ********************************************************************* */
/* Nome da função: lcd_writeText                                         */
/* Descrição da função: Recebe do programador qual mensagem será exibida */
/*                      e em qual linha e coluna do LCD isso ocorrerá    */
/*                                                                       */
/* Parâmetros de entrada: A string e a linha e coluna do LCD             */
/* Parâmetros de saída:   n/a                                            */
/* ********************************************************************* */

void lcd_writeText(int iLinha, const char *cString);

#endif /* SOURCES_LCD_H_ */
