/* ******************************************************************************* */
/* Nome do Arquivo:      tacometro.c                                               */
/* Descricao do arquivo: Este arquivo desenvolve as funções que fazem de acordo    */
/*                       com o que foi solicitado.                                 */
/*                                                                                 */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                             */
/* RA:                   174217/168988                                             */
/* Data de criacao:      09maio2020                                                */
/* Data da revisao:      10maio2020                                                */
/* ******************************************************************************* */

/* our includes */
#include "board.h"
#include "mcg.h"
#include "tacometro.h"
#include "lptmr.h"

/* ****************************************************************** */
/* Nome da funcao: 	           tachometer_init         		          */
/* Descricao da funcao:        Inicia o PWM e configura os parâmetros */
/*                             necessários do modo correto            */
/* parametros de entrada:	   n/a                                    */
/* parametros de saida:	       n/a 					                  */
/* ****************************************************************** */
void tachometer_init()
{
	/* Habilita o clock*/
    SIM_SCGC6 |= 0x1000000;

    /* Escolhe o divisor preescaler como 1 */
    TPM0_SC &= ~(0x7);

    /* Libera o clock para a porta do pino do encoder */
    SIM_SCGC5 |= 0x2000;

    /* Configura o pino PTE29 como external clock no MUX */
    PORTE_PCR29 |= 0x400;

    /* Seleciona o pino externo que será usado como entrada */
    SIM_SOPT4 &= ~(0x1000000);

    /* Configura o timer do TPM para borda de subida */
    TPM0_SC &= ~(0x10);
    TPM0_SC |= 0x20;
}

/* *********************************************************************** */
/* Nome da funcao: 	           tachometer_readSensor                       */
/* Descricao da funcao:        Recebe o valor do período do sinal do clock */
/*                             e calcula a velocidade do cooler em RPM     */
/*                                                                         */
/* parametros de entrada:	   Período do sinal                            */
/* parametros de saida:	       Velocidade do cooler em RPM                 */
/* *********************************************************************** */
unsigned int tachometer_readSensor(unsigned int uiPeriod)
{
    unsigned char ucNPulsos = TPM0_CNT;
    unsigned int uiVelocidade;

    /* Divide o número de pulsos pelo período recebido */
    uiVelocidade = ucNPulsos / uiPeriod;

    /* Multiplica a velocidade encontrada por 60 para obtê-lá em RPM */
    uiVelocidade *= 60;

    /* Zera o contador */
    TPM0_CNT &= ~(0xFFFF);

    return uiVelocidade;
}

