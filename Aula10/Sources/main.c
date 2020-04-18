
/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descrição do arquivo: Este arquivo é dedicado a inicializar a placa      */
/*                       fazendo a inicialização do clock e o LCD           */
/*                                                                          */
/*                       Características do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criação:      06abril2020                                        */
/* Data da revisão:      09abril2020                                        */
/* ************************************************************************ */

/* our includes */
#include "board.h"
#include "mcg.h"
#include "display7seg.h"
#include "lptmr.h"

int iInterruptFlag = 0;
int iIndexCounter = 0;
unsigned char ucVetorDisplay[4] = {13,12,11,10};
unsigned char ucVetorCaracter[4];

void main_cyclicExecuteIsr(void)
{
    iInterruptFlag = 1;

    if(iIndexCounter < 4)
    	iIndexCounter += 1;
    else
    	iIndexCounter = 0;
}


/* *********************************************************** */
/* Nome da função: 	           iniciarPlaca	         		       */
/* Descrição da função:        Inicia o clock e o lcd          */
/*                             saídas desejadas                */
/* parâmetros de entrada:	     n/a                             */
/* parâmetros de saída:	       n/a 					                   */
/* *********************************************************** */
void iniciarPlaca(void)
{
    /* Configuração e inicialização do clock */
    mcg_clockInit();

    /* Inicialização das portas de entrada e saída */
    display7seg_init();
}

/* ******************************************************* */
/* Nome da função:           main                          */
/* Descrição da função:      Ponto de entrada do sistema   */
/*                           onde são realizados os testes */
/* parâmetros de entrada:    n/a                           */
/* parâmetros de saída:      n/a                           */
/* ******************************************************* */
int main(void)
{
	iniciarPlaca();

	//tc_installLptmr(tempoClock,main_cyclicExecuteIsr);
	//display7seg_writeSymbol(1,2);
	while(1)
	{
        //ucVetorDisplay
		//ucVetorCaracter
	    //GPIOC_PDOR |=

		while(iInterruptFlag == 0);
		iInterruptFlag = 0;
	}

    return 0;
}
