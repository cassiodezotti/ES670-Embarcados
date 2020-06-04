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
/* Data de criacao:      24abril2020                                        */
/* Data da revisao:      26abril2020                                        */
/* ************************************************************************ */

/* our includes */
#include "board.h"
#include "mcg.h"
#include "aquecedorECooler.h"
#include "adc.h"
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


unsigned char ucPeriodo = 0x64;

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
    adc_initADCModule();
    adc_initConvertion();
}

/* *********************************************************************** */
/* Nome da funcao: 	           main         		                       */
/* Descricao da funcao:        Inicializa o contador e chama as funções    */
/*                             dos atuadores para o controle do Duty Cycle */
/* parametros de entrada:	   n/a                                         */
/* parametros de saida:	       n/a 					                       */
/* *********************************************************************** */
int main(void)
{
    float fDutyC = 0.5;
	float fDutyH = 0.5;
	int iValorTemp = 0;

    iniciarPlaca();

    while(1)
    {
        if(adc_isAdcDone)
        {
        	iValorTemp = adc_getConvertionValue();
        	adc_initConvertion();
        }
    }



    coolerfan_init();
    heater_init();

    /* Definindo 50% para o Duty Cycle */
    coolerfan_PWMDuty(fDutyC);
    heater_PWMDuty(fDutyH);

}
