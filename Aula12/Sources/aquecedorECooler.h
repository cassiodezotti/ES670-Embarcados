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

#ifndef SOURCES_AQUECEDORECOOLER_H_
#define SOURCES_AQUECEDORECOOLER_H_


/* *********************************************************************  */
/* Nome da fun��o: lcd_initLcd                                            */
/* Descri��o da fun��o: Essa fun��o inicializa todo o LCD e os par�metros */
/*                      necess�rios como o clock, a porta e os pinos.     */
/* Par�metros de entrada:    n/a                                          */
/* Par�metros de sa�da:      n/a                                          */
/* *********************************************************************  */
void PWM_init();

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
void coolerfan_PWMDuty(float fCoolerDuty);

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
void heater_PWMDuty(float fHeaterDuty);


#endif /* SOURCES_AQUECEDORECOOLER_H_ */
