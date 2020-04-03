
/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descri��o do arquivo: Este arquivo � dedicado a inicializar leds         */
/*                   	 e bot�es utilizando as fun��es desenvolvidas       */
/*                       e depois manipul�-lo, acendendo, apagando os leds  */
/*                       e lendo as chaves                                  */
/*                                                                          */
/*                       Caracter�sticas do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de cria��o:      26mar2020                                          */
/* Data da revis�o:      04abril2020                                        */
/* ************************************************************************ */


/* our includes */
#include "ledSwi.h"
#include "board.h"


/* globals */
static int iEstados[4];

/* *********************************************************** */
/* Nome da fun��o: 	           iniciarPlaca	         		   */
/* Descri��o da fun��o:        Inicia o clock e as entradas    */
/*                             sa�das desejadas                */
/* par�metros de entrada:	   vetor com 4 posi��es            */
/*                             indicando a se a porta          */
/*                             deve ser iniciada como          */
/*                             led ou como bot�o. 1            */
/*                             significa iniciar como          */
/*                             led e 0 como bot�o              */
/* par�metros de sa�da:	       n/a 					           */
/* *********************************************************** */

void iniciarPlaca(int iEntrada[4])
{
    /* Configura��o e inicializa��o do clock */
    mcg_clockInit();

    /* Inicializa��o das portas de entrada e sa�da */
    iniciarLedSwi(iEntrada);
}


/* ****************************************************** */
/* Nome da fun��o:           main                         */
/* Descri��o da fun��o:      Ponto de entrada do sistema  */
/* par�metros de entrada:    n/a                          */
/* par�metros de sa�da:      n/a                          */
/* ****************************************************** */
int main(void)
{
    /* Vetor para informar a configura��o de leds e bot�es*/
	int iEntrada[4] = {1,0,0,1};
	/* Vari�vel para informar a chave que ser� lida */
	int iChave = 2;
	/* Vari�vel para armazenar o estado do bot�o*/
	int iEstadoBotao;
	/* Inicializa placa */
	iniciarPlaca(iEntrada);

	/*L� chave 2 e armazena na vari�vel*/
	iEstadoBotao = lerChave(iChave);
	/* Exibe estado*/
	printf(&iEstadoBotao);
    /* Escreve o valor 1 no LED1, acendendo-o*/
	escreverLED(1,1);
    /*acende o LED4* */
	setarLED(4);
    /* Apaga LED1 */
	clearLED(1);
    /* Altera estado LED1*/
	alternarLED(1);
    /* Escreve o valor 0 no LED4, apagando-o*/
	escreverLED(4,0);
}
