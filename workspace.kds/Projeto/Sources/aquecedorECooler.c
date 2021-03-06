/************************************************************************ */
/* Nome do Arquivo:      aquecedorECooler.c                               */
/* Descricao do arquivo: Arquivo que construi as funcoes que controlam o  */
/*                       PWM e os atuadores                               */
/*                                                                        */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                    */
/* RA:                   174217/168988                                    */
/* Data de criacao:      24abril2020                                      */
/* Data da revisao:      27jul2020                                        */
/* ********************************************************************** */

/* our includes */
#include "aquecedorECooler.h"
#include "board.h"

extern unsigned char ucPeriodo;
extern float fHDuty;
extern float fCDuty;

/* ******************************************************************* */
/* Nome da funcao:        PWM_init                                     */
/* Descricao da funcao:   Essa fun��o inicializa o PWM e os par�metros */
/*                        necess�rios como o clock e contador.         */
/*                                                                     */
/* Parametros de entrada: n/a                                          */
/* Parametros de saida:   n/a                                          */
/* ******************************************************************* */
void PWM_init()
{
    /* liberar o clock para o timer */
    SIM_SCGC6 |= 0x2000000;

    /* escolhendo divisor 32 para o clock */
    TPM1_SC |= 0x05;

    /* fonte de clock seleciona o mcgirclk (32KHz) para o TPM */
    SIM_SOPT2 |= 0x3000000;

    /*Configurar o contador do clock como up counting e a cada pulso */
    TPM1_SC &= ~(0x030);
    TPM1_SC |= 0x8;

    /*configurar o periodo do PWM para 10 Hz com o contador
     * estourando em 100 (MOD+1) MOD = 99 (0x0063)
     */

    /* Configura o estouro do contador como Periodo - 1 = 0x0063 (99) */
    TPM1_MOD |= 0x0063;

    /* Configura o TPM como Edge aligned com High-true pulses */
    TPM1_C0SC &= ~(0x14);
    TPM1_C0SC |= 0x28;
    TPM1_C1SC &= ~(0x14);
    TPM1_C1SC |= 0x28;
}

/* ********************************************************************** */
/* Nome da funcao:        coolerfan_init                                  */
/* Descricao da funcao:   Fun��o que habilita o clock, a porta do atuador */
/*                        e configura o pino como PWM                     */
/*                                                                        */
/* Parametros de entrada: n/a                                             */
/* Parametros de saida:   n/a                                             */
/* ********************************************************************** */
void coolerfan_init()
{
    /* Habilitando o clock e selecionando como PWM o MUX de cada pino */
    SIM_SCGC5 |= 0x200;
    PORTA_PCR13 &= ~(0x400);
    PORTA_PCR13 |= 0x300;
    definirDutyC(0.5);
}

/* ********************************************************************** */
/* Nome da funcao:        heater_init                                     */
/* Descricao da fun��o:   Fun��o que habilita o clock, a porta do atuador */
/*                        e configura o pino 12 como PWM                  */
/*                                                                        */
/* Parametros de entrada: n/a                                             */
/* Parametros de saida:   n/a                                             */
/* ********************************************************************** */
void heater_init()
{
    /* Habilitando o clock e selecionando como PWM o MUX de cada pino */
    SIM_SCGC5 |= 0x200;
    PORTA_PCR12 &= ~(0x400);
    PORTA_PCR12 |= 0x300;
    definirDutyH(0);
}

/* ************************************************************************** */
/* Nome da funcao:        definirDutyC                                        */
/* Descricao da funcao:   Recebe um numero que corresponde ao Duty Cycle      */
/*                        desejado para o cooler e altera o Duty Cycle do PWM */
/*                                                                            */
/* Parametros de entrada: Recebe um float entre 0 e 1                         */
/* Parametros de saida:   n/a                                                 */
/* ************************************************************************** */
void definirDutyC(float fCoolerDuty)
{

    fCDuty = fCoolerDuty;

    /* Define o novo valor para o Duty Cycle do cooler */
    if(fCoolerDuty > 0 && fCoolerDuty < 1)
    {
        TPM0_C0V |= convertDuty(fCoolerDuty);
    }
}

/* ***************************************************************************** */
/* Nome da funcao:        definirDutyH                                           */
/* Descricao da funcao:   Recebe um numero que corresponde ao Duty Cycle         */
/*                        desejado para o aquecedor e altera o Duty Cycle do PWM */
/*                                                                               */
/* Parametros de entrada: Recebe um float entre 0 e 1                            */
/* Parametros de saida:   n/a                                                    */
/* ***************************************************************************** */
void definirDutyH(float fHeaterDuty)
{

    /* Limita-se o duty cycle do aquecedor
     * em 50% caso o valor recebido seja maior
     */
    if (fHeaterDuty > 0.5){
	    fHeaterDuty = 0.5;
    }

    fHDuty = fHeaterDuty;

    /* Define o novo valor para o Duty Cycle do aquecedor */
    TPM0_C0V |= convertDuty(fHeaterDuty);
}

/* ******************************************************************* */
/* Nome da funcao:        convertDuty                                  */
/* Descricao da funcao:   Fun��o de apoio recebe o valor do Duty Cycle */
/*                        e converte para um numero de 16 bits         */
/*                                                                     */
/* Parametros de entrada: Recebe um float entre 0 e 1                  */
/* Parametros de saida:   Retorna um unsigned char com o valor do Duty */
/*                        Cycle nos primeiros 16 bits                  */
/* ******************************************************************* */
unsigned char convertDuty(float fDuty)
{
    unsigned char ucValor = 0;
    int iValor = fDuty*10000;

    /* Converte o float para um valor de 0 a periodo em 16 bits */
    iValor = iValor*ucPeriodo;
    iValor = iValor/10000;
    ucValor |= (0xFFFF & iValor);

    return(ucValor);
}
