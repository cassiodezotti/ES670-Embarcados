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
#include "tacometro.h"


/* ************************************************************ */
/* Nome da funcao: 	           iniciarPlaca         		    */
/* Descricao da funcao:        Inicia a placa e o PWM           */
/* parametros de entrada:	   n/a                              */
/* parametros de saida:	       n/a 					            */
/* ************************************************************ */
void tachometer_init()
{
     SIM_SCGC6 |= 0x1000000; //habilitar o clock

     TPM0_SC &= ~(0x7);//divisor preescaler em 1

     SIM_SCGC5 |= 0x2000; //liberar clock para a porta do pino do encoder

     PORTE_PCR29 |= 0x400; //config pino PTE29 como external clock no MUX

     SIM_SPOT4 &= ~(0x1000000); //selecionar pino externo que será usado como entrada

     TMP0_SC &= ~(0x10); //config timer do TPM para borda de subida
     TPM0_SC |= 0x20;
}

unsigned int tachometer_readSensor(unsigned int uiPeriod)
{
    unsigned char ucNPulsos = TPM0_CNT;
    unsigned int uiVelocidade;

    uiVelocidade = ucNPulsos / uiPeriod;

    uiVelocidade *= 60;

    TPM0_CNT &= ~(0xFFFF);

    return uiVelocidade;

}

