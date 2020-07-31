/* ************************************************************************* */
/* Nome do Arquivo:      communicationStateMachine.c                         */
/* Descricao do arquivo: Desenvolve a maquina de estados e as outras funcoes */
/*                       que cuidam da comunicacao                           */
/* Nome dos autores:     Gustavo M./Cassio D.                                */
/* RA:                   174217/168988                                       */
/* Data de criacao:      03jun2020                                           */
/* Data da revisao:      28jul2020                                           */
/* ************************************************************************* */

/* definition include */
#include "communicationStateMachine.h"
#include "board.h"
#include "aquecedorECooler.h"
#include "adc.h"
#include "lut_adc_3v3.h"
#include "pid.h"

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

typedef union{
    unsigned char ucBytes[4];
    int iReal;
}
intSetPointCharType;

unsigned char ucUARTState = IDDLE;
unsigned char ucValueCount = '0';
extern int iValorTempAtual;
extern unsigned char ucAnswer[MAX_VALUE_LENGHT];
extern unsigned char ucEnable;
extern unsigned char ucTempAtual[4];
extern float fHDuty;
extern float fCDuty;
extern unsigned int uiSpTempertura;

/* *************************************************** */
/* Nome da funcao:        processamentoByte            */
/* Descricao da funcao:   Funcao contendo maquina de   */
/*                        estados para o processamento */
/*                        de bytes.                    */
/*                                                     */
/* Parametros de entrada: um char representando o byte */
/*                        recebido                     */
/* Parametros de saida:   n/a                          */
/* *************************************************** */
void processamentoByte(unsigned char ucByte)
{
    static unsigned char ucParam;
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
    		     * duty do aquecedor 'a' e duty do cooler 'c',
    		     * 'p', 'i' e 'd' para os valores de Kp, Ki e Kd
    		     * respectivamente
    		     */
    		     case GET:
    		         if('t' == ucByte || 'a' == ucByte || 'c' == ucByte || 'i' == ucByte || 'p' == ucByte || 'd' == ucByte)
    		     	 {
    		             ucParam = ucByte;
    		    	     ucUARTState = PARAM;
    		    	 }else
    		    	 {
    		    	     ucUARTState = IDDLE;
    		         }
    		         break;
    		        /*
    		         * Para set, temos a opcao de temperatura 't',
    		         * 'i' para setar o Ki, 'p' para setar o Kp e 'd'
    		         * para setar o Kd
    		         */
    		     case SET:
    		        if('t' == ucByte || 'i' == ucByte || 'p' == ucByte || 'd' == ucByte)
    		        {
    		    	    ucParam = ucByte;
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
    		    	    returnParam(ucParam);
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
    		    		    setParam(ucParam,ucValue);
    		    	     }
    		    		ucUARTState = IDDLE;
    		        }
    		        break;
    	    }
        }
    }
}

/* *************************************************** */
/* Nome da funcao:       returnParam                   */
/* Descricao da funcao:  Funcaco para retornar a       */
/*                       resposta solicitada por um    */
/*                       comando get                   */
/*                                                     */
/* Parametros de entrada: um char podendo ser 't' para */
/*                        temperatura, 'a' para duty   */
/*                        cycle do aquecedor ou 'c'    */
/*                        para o duty cycle do cooler  */
/* Parametros de saida:   n/a                          */
/* *************************************************** */
void returnParam(unsigned char ucParam)
{
    /*
     * Colocamos o valor #a no comeco de toda mensagem de retorno
     * para identificar a mensagem como resporta, anwser
     */

    ucAnswer[0] = 0x23;
    ucAnswer[1] = 0x61;

    switch(ucParam)
    {
	    case 't':
	        /*Le temperatura e armazena no vetor de answer*/
	        lerTemp();
	        break;
	    case 'a':
	        /*Le duty cycle do aquecedor e armazena no vetor de answer*/
	        lerHeaterDuty();
	        break;
	    case 'c':
	        /*Le duty cycle do cooler e armazena no vetor de answer*/
	        lerCoolerFanDuty();
	        break;
	    case 'p':
	        /*Le Kp e armazena no vetor de answer*/
	        lerKp();
	        break;
	    case 'i':
	        /*Le Ki e armazena no vetor de answer*/
	        lerKi();
	        break;
	    case 'd':
	        /*Le Kd e armazena no vetor de answer*/
	        lerKd();
	        break;
	    default:
	        break;
    }

    /* Envia a resposta de volta para a UART */
    for(int i=0;i<MAX_VALUE_LENGHT;i++){
        debug_putchar(ucAnswer[i]);
    }
}

/* *************************************************** */
/* Nome da funcao:        setParam                     */
/* Descricao da funcao:   Funcao para setar parametros */
/*                                                     */
/* Parametros de entrada: recebe um vetor de char com  */
/*                        o valor para o set, e um     */
/*                        char escolhendo o parametro  */
/*                        a ser alterado, 't' para     */
/*                        temperatura e 'e' para       */
/*                        habilitar ou desabilitar a   */
/*                        interface local              */
/* Parametros de saida:   n/a                          */
/* *************************************************** */
void setParam(unsigned char ucParam,unsigned char ucValue[MAX_VALUE_LENGHT])
{
    float fAux;
    switch(ucParam){
    /*converte o valor de temperatura desejada de char para int e armazena na
     * variavel global
     */
    case 't':

	    for(int i=3; i<MAX_VALUE_LENGHT; i++){
            uiSpTempertura = convertChar2Int(ucValue[i]);
        }
	    break;

    /*converte o valor de Kp desejada de char para float e chama a
     * funcao de set
     */
    case 'p':
        for(int i=3; i<MAX_VALUE_LENGHT; i++){
		    fAux = convertChar2Float(ucValue[i]);
	    }
        pid_setKp(fAux);
	    break;
    /*converte o valor de Ki desejada de char para float e chama a
	 * funcao de set
	 */
    case 'i':
        for(int i=3; i<MAX_VALUE_LENGHT; i++){
    	    fAux = convertChar2Float(ucValue[i]);
	    }
        pid_setKi(fAux);
	    break;
	 /*converte o valor de Kd desejada de char para float e chama a
	  * funcao de set
	  */
    case 'd':
       for(int i=3; i<MAX_VALUE_LENGHT; i++){
    	    fAux = convertChar2Float(ucValue[i]);
	   }
       pid_setKd(fAux);
	   break;
    }
}

/* **************************************************** */
/* Nome da funcao:        lerTemp                       */
/* Descricao da funcao:   Funcao para ler temperatura   */
/*                        sera reformulada nas proximas */
/*                        etapas                        */
/*                                                      */
/* Parametros de entrada: n/a                           */
/* Parametros de saida:   n/a                           */
/* **************************************************** */
void lerTemp()
{
    unsigned char ucSendChar, ucCount;
    unsigned char *ucAux;

    /* inicia a conversao AD e espera terminar */
    adc_initConvertion();
    while(!adc_isAdcDone())
    {

    }

    /* pega o valor correspondente a tabela e converte de int para char*/
    iValorTempAtual = tabela_temp[adc_getConvertionValue()];
    ucAux = convertInt2Char(iValorTempAtual);

    /* armazena o valor na variavel answer*/
    for (ucCount= 0; ucCount< 4; ucCount++)
    {
        ucSendChar= ucAux[ucCount];
        ucAnswer[ucCount+2] = ucSendChar;
    }
    ucAnswer[6] = 0x3b;
}

/* **************************************************** */
/* Nome da funcao:        heater_PWMDuty                */
/* Descricao da funcao:   Funcao para ler duty cycle do */
/*                        aquecedor, sera reformulada   */
/*                        nas proximas etapas           */
/*                                                      */
/* Parametros de entrada: n/a                           */
/* Parametros de saida:   n/a                           */
/* **************************************************** */
void lerHeaterDuty()
{
    unsigned char *ucHeaterDuty;

    /* le a variavel global de duty, converte de float para char e armazena na anwser */
    ucHeaterDuty = convertFloat2Char(fHDuty);
    for(int i=0;i<4;i++){
        ucAnswer[i+2] = ucHeaterDuty[i];
    }
    ucAnswer[6] = 0x3b;
}

/* **************************************************** */
/* Nome da funcao:        coolerFan_PWMDuty             */
/* Descricao da funcao:   Funcao para ler duty cycle do */
/*                        cooler, sera reformulada nas  */
/*                        proximas etapas               */
/*                                                      */
/* Parametros de entrada: n/a                           */
/* Parametros de saida:   n/a                           */
/* **************************************************** */
void lerCoolerFanDuty()
{
    unsigned char *ucCoolerDuty;

    /* le a variavel global de duty, converte de float para char e armazena na anwser */
    ucCoolerDuty = convertFloat2Char(fCDuty);

    for(int i=0;i<4;i++){
	     ucAnswer[i+2] = ucCoolerDuty[i];
    }
    ucAnswer[6] = 0x3b;
}

/* ***************************************************** */
/* Nome da funcao:        lerKp                          */
/* Descricao da funcao:   Funcao para ler o KP setado no */
/*                        controlador                    */
/*                                                       */
/* Parametros de entrada: n/a                            */
/* Parametros de saida:   n/a                            */
/* ***************************************************** */
void lerKp()
{
    unsigned char *ucKp;

    /* le o valor de Kp, converte de float para char e armazena na anwser */
    ucKp = convertFloat2Char(pid_getKp());

    for(int i=0;i<4;i++){
	    ucAnswer[i+2] = ucKp[i];
    }
    ucAnswer[6] = 0x3b;
}

/* ***************************************************** */
/* Nome da funcao:        lerKi                          */
/* Descricao da funcao:   Funcao para ler o KI setado no */
/*                        controlador                    */
/*                                                       */
/* Parametros de entrada: n/a                            */
/* Parametros de saida:   n/a                            */
/* ***************************************************** */
void lerKi()
{
    unsigned char *ucKi;

    /* le o valor de Ki, converte de float para char e armazena na anwser */
    ucKi = convertFloat2Char(pid_getKi());

    for(int i=0;i<4;i++){
    ucAnswer[i+2] = ucKi[i];
    }
    ucAnswer[6] = 0x3b;
}

/* ***************************************************** */
/* Nome da funcao:        lerKd                          */
/* Descricao da funcao:   Funcao para ler o KD setado no */
/*                        controlador                    */
/*                                                       */
/* Parametros de entrada: n/a                            */
/* Parametros de saida:   n/a                            */
/* ***************************************************** */
void lerKd()
{
    unsigned char *ucKd;

    /* le o valor de Kd, converte de float para char e armazena na anwser */
    ucKd = convertFloat2Char(pid_getKd());

    for(int i=0;i<4;i++){
	    ucAnswer[i+2] = ucKd[i];
    }
    ucAnswer[6] = 0x3b;
}

/* ******************************************************* */
/* Nome da funcao:        convertChar2Float                */
/* Descricao da funcao:   Funcao que converte 4 caracteres */
/*                        para um valor float              */
/* Parametros de entrada: caracter                         */
/* Parametros de saida:   valor float                      */
/* ******************************************************* */
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

/* ********************************************************* */
/* Nome da funcao:        convertFloat2Char                  */
/* Descricao da funcao:   Funcao que converte um valor float */
/*                        para um valor de 4 caracteres      */
/* Parametros de entrada: valor float                        */
/* Parametros de saida:   caracter                           */
/* ********************************************************* */
unsigned char* convertFloat2Char(float fReceivedFloat)
{
    floatUCharType varCharUFloat;
    unsigned char *ucAux;

    varCharUFloat.fReal= fReceivedFloat;

    ucAux = varCharUFloat.ucBytes;

    return(ucAux);
}

/* ******************************************************** */
/* Nome da funcao:         convertInt2Char                  */
/* Descricao da funcao:    Funcao que converte um valor int */
/*                         para um valor de 4 caracteres    */
/* Paramentros de entrada: valor int                        */
/* Parametros de saida:    caracter                         */
/* ******************************************************** */
unsigned char* convertInt2Char(int ucReceivedInt)
{
    intUCharType varIntUChar;
    unsigned char *ucAux;

    varIntUChar.iReal= ucReceivedInt;
    ucAux = varIntUChar.ucBytes;

    return(ucAux);
}

/* ******************************************************* */
/* Nome da funcao:        convertChar2Int                  */
/* Descricao da funcao:   Funcao que converte 4 caracteres */
/*                        para um valor int                */
/* Parametros de entrada: caracter                         */
/* Parametros de saida:   valor int                        */
/* ******************************************************* */
int convertChar2Int(unsigned char ucReceivedChar)
{
    intSetPointCharType varChar2int;
    static unsigned char ucCount;

    varChar2int.ucBytes[ucCount] = ucReceivedChar;
    if(++ucCount>= 4)
    {
	    return varChar2int.iReal;
	    ucCount= 0;
    }
    return (0);
}
