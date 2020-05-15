/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descricao do arquivo: Este arquivo inicializa a placa                    */
/*                       fazendo a inicializacao do clock e do PWM          */
/*                                                                          */
/*                       Caracteristicas do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criacao:      14maio2020                                        */
/* Data da revisao:      15maio2020                                        */
/* ************************************************************************ */

/* our includes */
#include "board.h"
#include "mcg.h"
#include "UART.h"
#include "print_scan.h"


/* ************************************************************ */
/* Nome da funcao: 	           iniciarPlaca         		    */
/* Descricao da funcao:        Inicia a placa e o PWM           */
/* parametros de entrada:	   n/a                              */
/* parametros de saida:	       n/a 					            */
/* ************************************************************ */
void iniciarPlaca(void)
{
    /* Configuracao e inicializacao do clock */
    mcg_clockInit();

    /* Inicializacao do UART */
    UART0_init();
}

/* *********************************************************************** */
/* Nome da funcao: 	           main         		                       */
/* Descricao da funcao:        Inicializa a placa e habilita a             */
/*                             interrup��o                                 */
/* parametros de entrada:	   n/a                                         */
/* parametros de saida:	       n/a 					                       */
/* *********************************************************************** */
int main(void)
{
    iniciarPlaca();

    /* Habilita a interrup��o */
    UART0_enableIRQ();

    /*Loop infinito para aguardar a interrup��o */
    while(1)
    {

    }
}
