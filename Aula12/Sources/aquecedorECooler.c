/************************************************************************** */
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
#include "aquecedorECooler.h";

void PWM_init()
{
    SIM_SCG6 |= 0x2000000; //passo 1 - liberar o clock para o timer

    /*TPM1_SC |= //divisor de clock*/

    /*SIM_SOPT2 |= //fonte de clocl */

    /*Configurar o contador do clock como up counting e a cada pulso */
    TPM1_SC &= ~(0x30);
    TPM1_SC |= 0x8;

    /*TPM1_CNT |= //configurar o período do PWM*/

    TPM1_C0NS &= ~(0x14);
    TPM1_C0NS |= 0x28;

    TPM1_C1NS &= ~(0x14);
    TPM1_C1NS |= 0x28;

    /*TPM0_C0V = //colocar 50% de duty cycle */
    /*TPM0_C1V = */

    SIM_SGC5 |= 0x200; //configurar porta do pino PWM

    /*PORTA_PCR12 |=
	PORTA_PCR13 |=   MUX para o pino*/

}

void coolerfan_PWMDuty(float fCoolerDuty)
{

}

void heater_PWMDuty(float fHeaterDuty)
{

}



