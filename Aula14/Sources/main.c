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
/* Data de criacao:      09maio2020                                        */
/* Data da revisao:      10maio2020                                        */
/* ************************************************************************ */

/* our includes */
#include "board.h"
#include "mcg.h"
#include "tacometro.h"
#include "lptmr.h"


/* *************************************************************** */
/* Nome da funcao: 	           main_cyclicExecuteIsr               */
/* Descricao da funcao:        Função da rotina de interrupção que */
/*                             faz a chamada da função que lê a    */
/*                             velocidade do cooler                */
/* parametros de entrada:	   n/a                                 */
/* parametros de saida:	       n/a 					               */
/* *************************************************************** */
 void main_cyclicExecuteIsr(void)
{
    tachometer_readSensor(250000);
}

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

    /* Inicializacao do PWM */
    tachometer_init();
}

/* *********************************************************************** */
/* Nome da funcao: 	           main         		                       */
/* Descricao da funcao:        Inicializa o contador e a placa             */
/*                             dos atuadores para o controle do Duty Cycle */
/* parametros de entrada:	   n/a                                         */
/* parametros de saida:	       n/a 					                       */
/* *********************************************************************** */
int main(void)
{

    iniciarPlaca();

    /* Dá inicio a contagem da interrupção e chama a função para trata-la quando occore */
    tc_installLptmr0(250000,main_cyclicExecuteIsr);

    /* Loop infinito para prender o sistema até que uma interrupção seja gerada */
    while(1)
    { }
}
