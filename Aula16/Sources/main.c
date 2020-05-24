/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descricao do arquivo: Este arquivo inicializa a placa                    */
/*                       fazendo a inicializacao da interrupção e da UART   */
/*                                                                          */
/*                       Caracteristicas do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criacao:      22maio2020                                         */
/* Data da revisao:      24maio2020                                         */
/* ************************************************************************ */

/* our includes */
#include "board.h"
#include "mcg.h"
#include "UART.h"
#include "print_scan.h"
#include "communicationStateMachine.h"

#define MAX_VALUE_LENGHT 7

unsigned char ucAnswer[MAX_VALUE_LENGHT+1];
unsigned char ucTemperatura[MAX_VALUE_LENGHT+1];
unsigned char ucEnable;
unsigned char ucTempAtual[4];
unsigned char ucHeaterDuty[4];
unsigned char ucCoolerDuty[4];

/* ************************************************************ */
/* Nome da funcao: 	           iniciarPlaca         		    */
/* Descricao da funcao:        Inicia a placa e o UART          */
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
/*                             interrupção                                 */
/* parametros de entrada:	   n/a                                         */
/* parametros de saida:	       n/a 					                       */
/* *********************************************************************** */
int main(void)
{
    iniciarPlaca();

    /* Habilita a interrupção */
    UART0_enableIRQ();

    while(1)
    {

    }
}
