
/* ********************************************************************** */
/* Nome do Arquivo:        ledSwi.h                                       */
/* Descri��o do arquivo:   Este arquivo contem fun��es para inicializa��o */
/*                   	   e utiliza��o dos leds e bot�es do kit.         */
/*                                                                        */
/*                                                                        */
/* Author name:            Gustavo Moraes/Cassio Dezotti                  */
/* RA:                     174217/168988                                  */
/* Data de cria��o:        26mar2020                                      */
/* Data da revis�o:        04abril2020                                    */
/* ********************************************************************** */

#ifndef SOURCES_LEDSWI_H_
#define SOURCES_LEDSWI_H_


/* ********************************************************************************* */
/* Nome da fun��o: 	       iniciarLedSwi        		                             */
/* Descri��o da fun��o:    Inicializa os LEDS e os bot�es conforme especificado.     */
/*                         Se 0 --> configura pino como bot�o(input)                 */
/*                         Se 1 --> configura pino como LED (output)                 */
/* par�metros de entrada:  Vetor de entrada com quais LEDS ou bot�es ser�o usados.   */
/* par�metros de sa�da:	   n/a 					                                     */
/* ********************************************************************************* */
void iniciarLedSwi(int iEstados[4]);

/* ************************************************************************** */
/* Nome da fun��o: 	      lerChave	         		                          */
/* Descri��o da fun��o:   Recebe do programador um valor de 1 a 4 que         */
/*                        determina qual bot�o dever�o ser lido e retorna     */
/*                        o status atual do bot�o.                            */
/*                        Se 0 --> bot�o pressionado                          */
/*                        Se 1 --> bot�o solto                                */
/* Par�metros de entrada: Valor de de 1 a 4                                   */
/* Par�metros de sa�da:	  Retorna 0 ou 1                                      */
/*      			      0 --> bot�o pressionado                             */
/*                        1 --> bot�o solto                                   */
/* *************************************************************************  */
void lerChave(int iChave);
/* **************************************************************************** */
/* Nome da fun��o: 	      escreverLED	         		                        */
/* Descri��o da fun��o:   Recebe do programador um valor de 1 a 4 que           */
/*                        determina em qual LED deve-se escrever e qual ser�o   */
/*                        o status final do LED.                                */
/*                        Se 0 --> LED ir� apagar                               */
/*                        Se 1 --> LED ir� acender                              */
/* Par�metros de entrada: Valor de 1 a 4 que indica qual o LED ser�o usado      */
/*                        SetClear --> 0 ou 1 para indicar status futuro do LED */
/* Par�metros de sa�da:	  n/a 							                        */
/* **************************************************************************** */
void escreverLED(int iWriteLed, int iSetClear);
/* ************************************************************************** */
/* Nome da fun��o: 	      setarLED             		                          */
/* Descri��o da fun��o:   Recebe do programador um valor de 1 a 4 que         */
/*                        determina qual LED ser�o alterado.                  */
/*                        Se 1 --> LED 1 acende                               */
/*                        Se 2 --> LED 2 acende                               */
/*                        Se 3 --> LED 4 acende                               */
/*                        Se 4 --> LED 5 acende                               */
/* Par�metros de entrada: Valor de 1 a 4 que indica qual o LED ser�o usado    */
/* Par�metros de sa�da:	  n/a 							                      */
/* *************************************************************************  */
void setarLED(int setLed);
/* ************************************************************************** */
/* Nome da fun��o: 	      apagarLED             		                      */
/* Descri��o da fun��o:   Recebe do programador um valor de 1 a 4 que         */
/*                        determina qual LED ser�o alterado.                  */
/*                        Se 1 --> LED 1 apaga                                */
/*                        Se 2 --> LED 2 apaga                                */
/*                        Se 3 --> LED 4 apaga                                */
/*                        Se 4 --> LED 5 apaga                                */
/* Par�metros de entrada: Valor de 1 a 4 que indica qual o LED ser�o usado    */
/* Par�metros de sa�da:	  n/a 							                      */
/* *************************************************************************  */
void apagarLED(int clearLed);
/* ********************************************************************************* */
/* Nome da fun��o: 	      alternarLED             		                             */
/* Descri��o da fun��o:   Recebe do programador um valor de 1 a 4 que                */
/*                        determina qual LED mudar�o de status (0 para 1 ou 1 para 0)*/
/*                        Se 1 --> LED 1 alterado                                    */
/*                        Se 2 --> LED 2 alterado                                    */
/*                        Se 3 --> LED 4 alterado                                    */
/*                        Se 4 --> LED 5 alterado                                    */
/* Par�metros de entrada: Valor de 1 a 4 que indica qual o LED ser�o usado           */
/* Par�metros de sa�da:	  n/a 							                             */
/* ********************************************************************************* */
void alternarLED(int iToggleLed);
/* ***********************************************************************************  */
/* Nome da fun��o: 	      mapearEntrada           		                                */
/* Descri��o da fun��o:   Recebe um n�mero de 1 a 4 e mapeia ele para o respectivo LED  */
/*                        Se 1 --> retorna 1                                            */
/*                        Se 2 --> retorna 2                                            */
/*                        Se 3 --> retorna 4                                            */
/*                        Se 3 --> retorna 5                                            */
/*                        Se 4 --> LED 5 alterado                                       */
/* Par�metros de entrada: Valor de 1 a 4                                                */
/* Par�metros de sa�da:	  Retorna 1,2,4 ou 5 			                                */
/* ***********************************************************************************  */
int mapearEntrada(int iValor);


#endif /* SOURCES_LEDRGB_H_ */
