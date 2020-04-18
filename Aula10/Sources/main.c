/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descricao do arquivo: Este arquivo inicializa a placa                    */
/*                       fazendo a inicializacao do clock e do display      */
/*                                                                          */
/*                       Caracteristicas do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criacao:      16abril2020                                        */
/* Data da revisao:      18abril2020                                        */
/* ************************************************************************ */

/* our includes */
#include "board.h"
#include "mcg.h"
#include "display7seg.h"
#include "lptmr.h"


int iInterruptFlag = 0;
int iIndexCounter = 0;
unsigned char ucVetorDisplay[4] = {0x1000,0x800,0x400,0x200};
unsigned char ucVetorCaracter[4];

/* ************************************************************ */
/* Nome da funcao: 	           main_cyclicExecuteIsr   		    */
/* Descriçao da funcao:        Tratamento da interrupcao        */
/*                             do clock, atraves do acionamento */
/*                             da variavel global               */
/*                             saidas desejadas.                */
/* parametros de entrada:	   n/a                              */
/* parametros de saida:	       n/a 					            */
/* ************************************************************ */
void main_cyclicExecuteIsr(void)
{
	iInterruptFlag = 1;

	if(iIndexCounter < 4)
		iIndexCounter += 1;
	else
		iIndexCounter = 0;
}

/* ************************************************************ */
/* Nome da funcao: 	           iniciarPlaca         		    */
/* Descricao da funcao:        Inicia a placa e os displays     */
/* parametros de entrada:	   n/a                              */
/* parametros de saida:	       n/a 					            */
/* ************************************************************ */
void iniciarPlaca(void)
{
    /* Configuracao e inicializacao do clock */
    mcg_clockInit();

    /* Inicializacao das portas de saida */
    display7seg_init();
}

/* ************************************************************** */
/* Nome da funcao: 	           main         		              */
/* Descricao da funcao:        Inicializa o timer e controla a    */
/*                             escrita nos displays de acordo com */
/*                             a interrupcao                      */
/* parametros de entrada:	   n/a                                */
/* parametros de saida:	       n/a 					              */
/* ************************************************************** */
int main(void)
{
    unsigned char ucValor7seg = 0;
    iniciarPlaca();

    /* Inicializa o timer com 4ms */
    tc_installLptmr0(4000,main_cyclicExecuteIsr);

    /* Enviando 1,2,3,4 para escrever nos displays */
    display7seg_writeSymbol(1,1);
    display7seg_writeSymbol(2,2);
    display7seg_writeSymbol(3,3);
    display7seg_writeSymbol(4,4);

    while(1)
    {
    	/* Zerando os pinos de catodo dos displays nao utilizados */
	    GPIOC_PDOR &= ~(ucVetorDisplay[iIndexCounter] ^ 0x3c0);
	    /* Unindo o caracter a ser escrito com o pino do display que queremos escrever */
	    ucValor7seg = (ucVetorDisplay[iIndexCounter] | ucVetorCaracter[iIndexCounter]);
	    GPIOC_PDOR |= ucValor7seg;

	    /* Espera a interrupcao para fazer a proxima iteracao */
        while(iInterruptFlag == 0)
            iInterruptFlag = 0;
    }
    return 0;
}
