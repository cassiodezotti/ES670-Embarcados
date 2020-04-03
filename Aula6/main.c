
/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descrição do arquivo: Este arquivo é dedicado a inicializar leds         */
/*                   	 e botões utilizando as funções desenvolvidas       */
/*                       e depois manipulá-lo, acendendo, apagando os leds  */
/*                       e lendo as chaves                                  */
/*                                                                          */
/*                       Características do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criação:      26mar2020                                          */
/* Data da revisão:      04abril2020                                        */
/* ************************************************************************ */


/* our includes */
#include "ledSwi.h"
#include "board.h"


/* globals */
static int iEstados[4];

/* *********************************************************** */
/* Nome da função: 	           iniciarPlaca	         		   */
/* Descrição da função:        Inicia o clock e as entradas    */
/*                             saídas desejadas                */
/* parâmetros de entrada:	   vetor com 4 posições            */
/*                             indicando a se a porta          */
/*                             deve ser iniciada como          */
/*                             led ou como botão. 1            */
/*                             significa iniciar como          */
/*                             led e 0 como botão              */
/* parâmetros de saída:	       n/a 					           */
/* *********************************************************** */

void iniciarPlaca(int iEntrada[4])
{
    /* Configuração e inicialização do clock */
    mcg_clockInit();

    /* Inicialização das portas de entrada e saída */
    iniciarLedSwi(iEntrada);
}


/* ****************************************************** */
/* Nome da função:           main                         */
/* Descrição da função:      Ponto de entrada do sistema  */
/* parâmetros de entrada:    n/a                          */
/* parâmetros de saída:      n/a                          */
/* ****************************************************** */
int main(void)
{
    /* Vetor para informar a configuração de leds e botões*/
	int iEntrada[4] = {1,0,0,1};
	/* Variável para informar a chave que será lida */
	int iChave = 2;
	/* Variável para armazenar o estado do botão*/
	int iEstadoBotao;
	/* Inicializa placa */
	iniciarPlaca(iEntrada);

	/*Lê chave 2 e armazena na variável*/
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
