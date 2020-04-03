
/* ********************************************************************** */
/* Nome do Arquivo:        ledSwi.h                                       */
/* Descrição do arquivo:   Este arquivo contem funções para inicialização */
/*                   	   e utilização dos leds e botões do kit.         */
/*                                                                        */
/*                                                                        */
/* Author name:            Gustavo Moraes/Cassio Dezotti                  */
/* RA:                     174217/168988                                  */
/* Data de criação:        26mar2020                                      */
/* Data da revisão:        04abril2020                                    */
/* ********************************************************************** */

#ifndef SOURCES_LEDSWI_H_
#define SOURCES_LEDSWI_H_


/* ********************************************************************************* */
/* Nome da função: 	       iniciarLedSwi        		                             */
/* Descrição da função:    Inicializa os LEDS e os botões conforme especificado.     */
/*                         Se 0 --> configura pino como botão(input)                 */
/*                         Se 1 --> configura pino como LED (output)                 */
/* parâmetros de entrada:  Vetor de entrada com quais LEDS ou botões serão usados.   */
/* parâmetros de saída:	   n/a 					                                     */
/* ********************************************************************************* */
void iniciarLedSwi(int iEstados[4]);

/* ************************************************************************** */
/* Nome da função: 	      lerChave	         		                          */
/* Descrição da função:   Recebe do programador um valor de 1 a 4 que         */
/*                        determina qual botão deverão ser lido e retorna     */
/*                        o status atual do botão.                            */
/*                        Se 0 --> botão pressionado                          */
/*                        Se 1 --> botão solto                                */
/* Parâmetros de entrada: Valor de de 1 a 4                                   */
/* Parâmetros de saída:	  Retorna 0 ou 1                                      */
/*      			      0 --> botão pressionado                             */
/*                        1 --> botão solto                                   */
/* *************************************************************************  */
void lerChave(int iChave);
/* **************************************************************************** */
/* Nome da função: 	      escreverLED	         		                        */
/* Descrição da função:   Recebe do programador um valor de 1 a 4 que           */
/*                        determina em qual LED deve-se escrever e qual serão   */
/*                        o status final do LED.                                */
/*                        Se 0 --> LED irá apagar                               */
/*                        Se 1 --> LED irá acender                              */
/* Parâmetros de entrada: Valor de 1 a 4 que indica qual o LED serão usado      */
/*                        SetClear --> 0 ou 1 para indicar status futuro do LED */
/* Parâmetros de saída:	  n/a 							                        */
/* **************************************************************************** */
void escreverLED(int iWriteLed, int iSetClear);
/* ************************************************************************** */
/* Nome da função: 	      setarLED             		                          */
/* Descrição da função:   Recebe do programador um valor de 1 a 4 que         */
/*                        determina qual LED serão alterado.                  */
/*                        Se 1 --> LED 1 acende                               */
/*                        Se 2 --> LED 2 acende                               */
/*                        Se 3 --> LED 4 acende                               */
/*                        Se 4 --> LED 5 acende                               */
/* Parâmetros de entrada: Valor de 1 a 4 que indica qual o LED serão usado    */
/* Parâmetros de saída:	  n/a 							                      */
/* *************************************************************************  */
void setarLED(int setLed);
/* ************************************************************************** */
/* Nome da função: 	      apagarLED             		                      */
/* Descrição da função:   Recebe do programador um valor de 1 a 4 que         */
/*                        determina qual LED serão alterado.                  */
/*                        Se 1 --> LED 1 apaga                                */
/*                        Se 2 --> LED 2 apaga                                */
/*                        Se 3 --> LED 4 apaga                                */
/*                        Se 4 --> LED 5 apaga                                */
/* Parâmetros de entrada: Valor de 1 a 4 que indica qual o LED serão usado    */
/* Parâmetros de saída:	  n/a 							                      */
/* *************************************************************************  */
void apagarLED(int clearLed);
/* ********************************************************************************* */
/* Nome da função: 	      alternarLED             		                             */
/* Descrição da função:   Recebe do programador um valor de 1 a 4 que                */
/*                        determina qual LED mudarão de status (0 para 1 ou 1 para 0)*/
/*                        Se 1 --> LED 1 alterado                                    */
/*                        Se 2 --> LED 2 alterado                                    */
/*                        Se 3 --> LED 4 alterado                                    */
/*                        Se 4 --> LED 5 alterado                                    */
/* Parâmetros de entrada: Valor de 1 a 4 que indica qual o LED serão usado           */
/* Parâmetros de saída:	  n/a 							                             */
/* ********************************************************************************* */
void alternarLED(int iToggleLed);
/* ***********************************************************************************  */
/* Nome da função: 	      mapearEntrada           		                                */
/* Descrição da função:   Recebe um número de 1 a 4 e mapeia ele para o respectivo LED  */
/*                        Se 1 --> retorna 1                                            */
/*                        Se 2 --> retorna 2                                            */
/*                        Se 3 --> retorna 4                                            */
/*                        Se 3 --> retorna 5                                            */
/*                        Se 4 --> LED 5 alterado                                       */
/* Parâmetros de entrada: Valor de 1 a 4                                                */
/* Parâmetros de saída:	  Retorna 1,2,4 ou 5 			                                */
/* ***********************************************************************************  */
int mapearEntrada(int iValor);


#endif /* SOURCES_LEDRGB_H_ */
