/* ********************************************************************* */
/* File name:        communicationStateMachine.c                         */
/* File description: Desenvolve a maquina de estados e as outras funções */
/*                   que cuidam da comunicação                           */
/* Author name:      Gustavo M./Cassio D.                                */
/* Creation date:    03jun2020                                           */
/* Revision date:    09jun2020                                           */
/* ********************************************************************* */

/* definition include */
#include "communicationStateMachine.h"
#include "board.h"
#include "aquecedorECooler.h"
#include "adc.h"
#include "lut_adc_3v3.h"

/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_device_registers.h"
#include "fsl_port_hal.h"
#include "fsl_smc_hal.h"
#include "fsl_debug_console.h"

#define IDDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define VALUE '5'
#define MAX_VALUE_LENGHT 7

typedef union{
    unsigned char ucBytes[4];
    float fReal;
}floatUCharType;

typedef union{
    unsigned char ucBytes[4];
    int iReal;
}
intUCharType;

unsigned char ucUARTState = IDDLE;
unsigned char ucValueCount = '0';
extern int iValorTempAtual;
extern unsigned char ucAnswer[MAX_VALUE_LENGHT];
extern unsigned char ucTemperatura[4];
extern unsigned char ucEnable;
extern unsigned char ucTempAtual[4];
extern unsigned char ucHeaterDuty[4];
extern unsigned char ucCoolerDuty[4];


/* ************************************************ */
/* Method name:        processamentoByte            */
/* Method description: Funcao contendo maquina de   */
/*                     estados para o processamento */
/*                     de bytes.                    */
/* Input params:       um char representando o byte */
/*                     recebido                     */
/* Output params:      n/a                          */
/* ************************************************ */
void processamentoByte(unsigned char ucByte)
{
	static unsigned char ucPARAM;
	static unsigned char ucValue[MAX_VALUE_LENGHT];

	/* Toda mensagem comeca com '#'*/

    if('#' == ucByte)
    {
    	ucUARTState = READY;
    }else
    {
    	if(IDDLE != ucUARTState)
    	{
    		switch(ucUARTState)
    		{
    		    case READY:
    		    	/* As opcoes sao get 'g' e set 's' */
    		    	switch(ucByte)
    		    	{
    		    	    case 'g':
    		    	    	ucUARTState = GET;
    		    	    	break;
    		    	    case 's':
    		    	    	ucUARTState = SET;
    		    	    	break;
    		    	    default:
    		    	    	ucUARTState = IDDLE;
    		    	}
    		    	break;
    		    /*
    		     * Para get, temos a opcao de temperatura 't',
    		     * duty do aquecedor 'a' e duty do cooler 'c'
    		     */
    		    case GET:
    		    	if('t' == ucByte || 'a' == ucByte || 'c' == ucByte)
    		    	{
    		    		ucPARAM = ucByte;
    		    		ucUARTState = PARAM;
    		    	}else
    		    	{
    		    		ucUARTState = IDDLE;
    		    	}
    		        break;
    		      /*
    		      * Para set, temos a opcao de temperatura 't',
    		      * a opcao de habilitar/desabilitar a interface
    		      * local 'e' e as opcoes 'a' e 'c' para o duty cycle
    		      * do aquecedor e cooler.
    		      */
    		    case SET:
    		    	if('t' == ucByte || 'e' == ucByte || 'a' == ucByte || 'c' == ucByte)
    		    	{
    		    		ucPARAM = ucByte;
    		      		ucUARTState = VALUE;
    		      		ucValueCount = 0;
         		    	}else
        		    	{
    		    	        ucUARTState = IDDLE;
    		    	  	}
    		 	        break;
    		    case PARAM:
    		    	if(';' == ucByte)
    		    	{
    		    		returnPARAM(ucPARAM);
    		    	}
    		    	ucUARTState = IDDLE;
    		    	break;
    		    /*
    		      * Verificamos se o byte recedido e um numero
    		      * ou uma virgula para o float.
    		    */
    		    case VALUE:
    		    	if((ucByte >= '0' && ucByte <= '9') || ',' == ucByte)
    		    	{
    		    		if(ucValueCount < MAX_VALUE_LENGHT)
    		    		{
    		    			ucValue[ucValueCount++] = ucByte;
    		    		}
    		    	}else
    		    	{
    		    		if(';' == ucByte)
    		    		{
    		    			ucValue[ucValueCount] = '\0';
    		    			setPARAM(ucPARAM,ucValue);
    		    		}
    		    		ucUARTState = IDDLE;
    		    	}
    		    	break;
    		}
    	}
    }

}

/* ************************************************ */
/* Method name:        returnPARAM                  */
/* Method description: Funcaco para retornar a      */
/*                     resposta solicitada por um   */
/*                     comando get                  */
/* Input params:       um char podendo ser 't' para */
/*                     temperatura, 'a' para duty   */
/*                     cycle do aquecedor ou 'c'    */
/*                     para o duty cycle do cooler  */
/* Output params:      n/a                          */
/* ************************************************ */
void returnPARAM(unsigned char ucPARAM)
{
	/*
	 * Colocamos o valor #a no comeco de toda mensagem de retorno
	 * para identificar a mensagem como resporta, anwser
	 */
	ucAnswer[0] = 0x23; //"#"
	ucAnswer[1] = 0x61; //"a";

	switch(ucPARAM)
	{
	    case 't':
	    	lerTemp();
	        break;
	    case 'a':
	    	/*no futuro será implementado*/
	    	lerHeaterDuty();
	    	break;
	    case 'c':
	    	/*no futuro será implementado*/
	    	lerCoolerFanDuty();
	    	break;
	    default:
	    	break;
	}
	/* Envia a resposta de volta para a UART */
	for(int i=0;i<MAX_VALUE_LENGHT;i++){
        debug_putchar(ucAnswer[i]);
	}
}

/* ************************************************ */
/* Method name:        setPARAM                     */
/* Method description: Funcao para setar parametros */
/*                                                  */
/* Input params:       recebe um vetor de char com  */
/*                     o valor para o set, e um     */
/*                     char escolhendo o parametro  */
/*                     a ser alterado, 't' para     */
/*                     temperatura e 'e' para       */
/*                     habilitar ou desabilitar a   */
/*                     interface local              */
/* Output params:      n/a                          */
/* ************************************************ */
void setPARAM(unsigned char ucPARAM,unsigned char ucValue[MAX_VALUE_LENGHT])
{
    float aux;
    switch(ucPARAM){
    case 't':
	    /*no projeto será implementado*/
	    for(int i=0; i<MAX_VALUE_LENGHT; i++){
            ucTemperatura[i] = ucValue[i];
        }
	    break;
     case 'e':
	    /*no projeto será implementado*/
	    ucEnable = ucValue[0];
        break;
     case 'a':
	    for(int i=0;i<4;i++){
            aux = convertChar2Float(ucValue[i]);
	    }
	    /* Limita o duty cycle do aquecedor em 50% */
	    if(aux>0.5){
	        aux=0.5;
	    }
	    heater_PWMDuty(aux);
        break;
     case 'c':
	    for(int i=0;i<4;i++){
            aux = convertChar2Float(ucValue[i]);
        }
	    coolerfan_PWMDuty(aux);
        break;
    }
}

/* ************************************************* */
/* Method name:        lerTemp                       */
/* Method description: Funcao para ler temperatura   */
/*                     sera reformulada nas proximas */
/*                     etapas                        */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerTemp()
{
    adc_initConvertion();
    while(!adc_isAdcDone())
    {

    }
    iValorTempAtual = tabela_temp[adc_getConvertionValue()];
    convertInt2Char(iValorTempAtual);
}

/* ************************************************* */
/* Method name:        heater_PWMDuty                */
/* Method description: Funcao para ler duty cycle do */
/*                     aquecedor, sera reformulada   */
/*                     nas proximas etapas           */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerHeaterDuty()
{
    for(int i=0;i<4;i++){
        ucAnswer[i+2] = ucHeaterDuty[i];
    }
    ucAnswer[6] = 0x3b;
}

/* ************************************************* */
/* Method name:        coolerFan_PWMDuty             */
/* Method description: Funcao para ler duty cycle do */
/*                     cooler, sera reformulada nas  */
/*                     proximas etapas               */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerCoolerFanDuty()
{
    for(int i=0;i<4;i++){
	    ucAnswer[i+2] = ucCoolerDuty[i];
    }
    ucAnswer[6] = 0x3b;
}

/* **************************************************** */
/* Method name:        convertChar2Float                */
/* Method description: Funcao que converte 4 caracteres */
/*                     para um valor float              */
/* Input params:       caracter                         */
/* Output params:      valor float                      */
/* **************************************************** */
float convertChar2Float(unsigned char ucReceivedChar)
{
	floatUCharType varFloatUChar;
	static unsigned char ucCount;

	varFloatUChar.ucBytes[ucCount] = ucReceivedChar;
	if(++ucCount>= 4)
	{
		return varFloatUChar.fReal;
		ucCount= 0;

	}
	return (0);
}

/* **************************************************** */
/* Method name:        convertInt2Char                  */
/* Method description: Funcao que converte um valor int */
/*                     para um valor de 4 caracteres    */
/* Input params:       valor int                        */
/* Output params:      n/a                              */
/* **************************************************** */
void convertInt2Char(int ucReceivedInt)
{
	intUCharType varIntUChar;
	unsigned char ucSendChar, ucCount;

	varIntUChar.iReal= ucReceivedInt;

	for (ucCount= 0; ucCount< 4; ucCount++)
	{
		ucSendChar= varIntUChar.ucBytes[ucCount];
		ucAnswer[ucCount+2] = ucSendChar;
	}
	ucAnswer[6] = 0x3b;
}
