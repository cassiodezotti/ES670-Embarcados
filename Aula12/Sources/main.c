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
#include "aquecedorECooler.h"


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
    PWM_init();
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

    float fDutyC,fDutyH;

    iniciarPlaca();

    coolerfan_init();
    heater_init();

    coolerfan_PWMDuty(fDutyC);
    heater_PWMDuty(fDutyH)

}
