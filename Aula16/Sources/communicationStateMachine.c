/* ***************************************************************** */
/* File name:        UART.c                                          */
/* File description: Debugging through UART interface                */
/* Author name:      dloubach, rbacurau                              */
/* Creation date:    22out2015                                       */
/* Revision date:    01mai2020                                       */
/* ***************************************************************** */

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
extern unsigned char ucTempAtual[2];
extern unsigned char ucHeaterDuty[4];
extern unsigned char ucCoolerDuty[4];

void processamentoByte(unsigned char ucByte)
{
	static unsigned char ucPARAM;
	static unsigned char ucValue[MAX_VALUE_LENGHT+1];

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

void returnPARAM(unsigned char ucPARAM)
{
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

void lerTemp()
{
	ucAnswer[2] = ucTempAtual[0];
	ucAnswer[3] = ucTempAtual[1];
	ucAnswer[4] = 0x3b;
}

void heater_PWMDuty()
{
	ucAnswer[2] = ucHeaterDuty[0];
	ucAnswer[3] = ucHeaterDuty[1];
	ucAnswer[4] = ucHeaterDuty[2];
	ucAnswer[5] = ucHeaterDuty[3];
	ucAnswer[6] = 0x3b;
}

void coolerFan_PWMDuty()
{
	ucAnswer[2] = ucCoolerDuty[0];
	ucAnswer[3] = ucCoolerDuty[1];
	ucAnswer[4] = ucCoolerDuty[2];
	ucAnswer[5] = ucCoolerDuty[3];
	ucAnswer[6] = 0x3b;
}


