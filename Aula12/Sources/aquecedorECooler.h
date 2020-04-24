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

#ifndef SOURCES_AQUECEDORECOOLER_H_
#define SOURCES_AQUECEDORECOOLER_H_


/* *********************************************************************  */
/* Nome da função: lcd_initLcd                                            */
/* Descrição da função: Essa função inicializa todo o LCD e os parâmetros */
/*                      necessários como o clock, a porta e os pinos.     */
/* Parâmetros de entrada:    n/a                                          */
/* Parâmetros de saída:      n/a                                          */
/* *********************************************************************  */
void PWM_init();

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
void coolerfan_PWMDuty(float fCoolerDuty);

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
void heater_PWMDuty(float fHeaterDuty);


#endif /* SOURCES_AQUECEDORECOOLER_H_ */
