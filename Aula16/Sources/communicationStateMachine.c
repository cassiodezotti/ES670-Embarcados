/* ********************************************************************* */
/* File name:        communicationStateMachine.c                         */
/* File description: Desenvolve a maquina de estados e as outras funções */
/*                   que cuidam da comunicação                           */
/* Author name:      Gustavo M./Cassio D.                                */
/* Creation date:    22mai2020                                           */
/* Revision date:    24mai2020                                           */
/* ********************************************************************* */

/* definition include */
#include "communicationStateMachine.h"
#include "board.h"

#define IDDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define VALUE '5'
#define MAX_VALUE_LENGHT 7

unsigned char ucUARTState = IDDLE;
unsigned char ucValueCount = '0';
extern unsigned char ucAnswer[MAX_VALUE_LENGHT+1];
extern unsigned char ucTemperatura[MAX_VALUE_LENGHT+1];
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
	static unsigned char ucValue[MAX_VALUE_LENGHT+1];


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
    		      * e a opcao de habilitar/desabilitar a interface
    		      * local 'e'.
    		      */
    		    case SET:
    		    	if('t' == ucByte || 'e' == ucByte)
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
	    	heater_PWMDuty();
	    	break;
	    case 'c':
	    	coolerFan_PWMDuty();
	    	break;
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
void setPARAM(unsigned char ucPARAM,unsigned char ucValue[MAX_VALUE_LENGHT+1])
{
	if('t' == ucPARAM)
	{
		for(int i=0; i<MAX_VALUE_LENGHT; i++)
		{
			ucTemperatura[i] = ucValue[i];
		}
	}

	else if('e' == ucPARAM)
	   ucEnable = ucValue[0];
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
	for(int i=0;i<4;i++){
	    ucAnswer[i+2] = ucTempAtual[i];
	}
	ucAnswer[6] = 0x3b;
}

/* ************************************************* */
/* Method name:        heater_PWMDuty                */
/* Method description: Funcao para ler duty cycle do */
/*                     aquecedor, sera reformulada   */
/*                     nas proximas etapas           */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void heater_PWMDuty()
{
	for(int i=0;i<4;i++){
        ucAnswer[i+2] = ucHeaterDuty[0];
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
void coolerFan_PWMDuty()
{
	for(int i=0;i<4;i++){
	    ucAnswer[i+2] = ucCoolerDuty[0];
	}
	ucAnswer[6] = 0x3b;
}
