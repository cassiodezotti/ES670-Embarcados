/* ******************************************************************************* */
/* Nome do Arquivo:      tacometro.h                                               */
/* Descricao do arquivo: Este arquivo apresenta as fun��es que ser�o desenvolvidas */
/*                       no programa.                                              */
/*                                                                                 */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                             */
/* RA:                   174217/168988                                             */
/* Data de criacao:      09maio2020                                                */
/* Data da revisao:      10maio2020                                                */
/* ******************************************************************************* */


/* ****************************************************************** */
/* Nome da funcao: 	           tachometer_init         		          */
/* Descricao da funcao:        Inicia o PWM e configura os par�metros */
/*                             necess�rios do modo correto            */
/* parametros de entrada:	   n/a                                    */
/* parametros de saida:	       n/a 					                  */
/* ****************************************************************** */
void tachometer_init();

/* *********************************************************************** */
/* Nome da funcao: 	           tachometer_readSensor                       */
/* Descricao da funcao:        Recebe o valor do per�odo do sinal do clock */
/*                             e calcula a velocidade do cooler em RPM     */
/*                                                                         */
/* parametros de entrada:	   Per�odo do sinal                            */
/* parametros de saida:	       Velocidade do cooler em RPM                 */
/* *********************************************************************** */
unsigned int tachometer_readSensor(unsigned int uiPeriod);
