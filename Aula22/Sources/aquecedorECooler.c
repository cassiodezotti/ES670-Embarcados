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
/* *********************************************************************  */
/* Nome da fun��o: PWM_init                                               */
/* Descri��o da fun��o: Essa fun��o inicializa o PWM e os par�metros      */
/*                      necess�rios como o clock e contador.              */
/* Par�metros de entrada:    n/a                                          */
/* Par�metros de sa�da:      n/a                                          */
/* *********************************************************************  */
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

    /*configurar o per�odo do PWM para 10 Hz com o contador
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

/* ******************************************************************** */
/* Nome da fun��o: coolerfan_init                                       */
/* Descri��o da fun��o: Fun��o que habilita o clock, a porta do atuador */
/*                      e configura o pino como PWM                     */
/*                                                                      */
/* Par�metros de entrada: n/a                                           */
/* Par�metros de sa�da:   n/a                                           */
/* ******************************************************************** */
void coolerfan_init()
{
	/* Habilitando o clock e selecionando como PWM o MUX de cada pino */
    SIM_SCGC5 |= 0x200;
    PORTA_PCR13 &= ~(0x400);
    PORTA_PCR13 |= 0x300;
    coolerfan_PWMDuty(0.5);
}

/* ******************************************************************** */
/* Nome da fun��o: heater_init                                          */
/* Descri��o da fun��o: Fun��o que habilita o clock, a porta do atuador */
/*                      e configura o pino 12 como PWM                  */
/*                                                                      */
/* Par�metros de entrada: n/a                                           */
/* Par�metros de sa�da:   n/a                                           */
/* ******************************************************************** */
void heater_init()
{
	/* Habilitando o clock e selecionando como PWM o MUX de cada pino */
    SIM_SCGC5 |= 0x200;
    PORTA_PCR12 &= ~(0x400);
	PORTA_PCR12 |= 0x300;
	heater_PWMDuty(0);
}

/* ************************************************************************* */
/* Nome da fun��o: coolerfan_PWMDuty                                         */
/* Descri��o da fun��o:  Recebe um numero que corresponde ao Duty Cycle      */
/*                       desejado para o cooler e altera o Duty Cycle do PWM */
/*                                                                           */
/* Par�metros de entrada: Recebe um float entre 0 e 1                        */
/* Par�metros de sa�da:   n/a                                                */
/* ************************************************************************* */
void coolerfan_PWMDuty(float fCoolerDuty)
{

	fCDuty = fCoolerDuty;
    /* Define o novo valor para o Duty Cycle do cooler */
    if(fCoolerDuty > 0 && fCoolerDuty < 1)
    {
        TPM0_C0V |= convertDuty(fCoolerDuty);
    }
}

/* **************************************************************************** */
/* Nome da fun��o: heater_PWMDuty                                               */
/* Descri��o da fun��o:  Recebe um numero que corresponde ao Duty Cycle         */
/*                       desejado para o aquecedor e altera o Duty Cycle do PWM */
/*                                                                              */
/* Par�metros de entrada: Recebe um float entre 0 e 1                           */
/* Par�metros de sa�da:   n/a                                                   */
/* **************************************************************************** */
void heater_PWMDuty(float fHeaterDuty)
{


	if (fHeaterDuty > 0.5){
		fHeaterDuty = 0.5;
	}

	fHDuty = fHeaterDuty;

    /* Define o novo valor para o Duty Cycle do aquecedor */
    if(fHeaterDuty > 0.5 && fHeaterDuty < 1)
    {
        TPM0_C0V |= convertDuty(fHeaterDuty);
    }
}

/* ******************************************************************* */
/* Nome da fun��o: convertDuty                                         */
/* Descri��o da fun��o: Fun��o de apoio recebe o valor do Duty Cycle   */
/*                      e converte para um numero de 16 bits           */
/*                                                                     */
/* Par�metros de entrada: Recebe um float entre 0 e 1                  */
/* Par�metros de sa�da:   Retorna um unsigned char com o valor do Duty */
/*                        Cycle nos primeiros 16 bits                  */
/* ******************************************************************* */
unsigned char convertDuty(float duty)
{
    unsigned char cValor = 0;
    int iValor = duty*10000;

    /* Converte o float para um valor de 0 a periodo em 16 bits */
    iValor = iValor*ucPeriodo;
    iValor = iValor/10000;
    cValor |= (0xFFFF & iValor);

   return(cValor);
}
