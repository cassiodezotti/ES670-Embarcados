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
/* Data de criacao:      03abril2020                                        */
/* Data da revisao:      09abril2020                                        */
/* ************************************************************************ */

/* our includes */
#include "board.h"
#include "mcg.h"
#include "aquecedorECooler.h"
#include "adc.h"
#include "UART.h"
#include "print_scan.h"
#include "communicationStateMachine.h"
#include "lcd.h"

#define MAX_VALUE_LENGHT 7

unsigned char ucAnswer[MAX_VALUE_LENGHT];
unsigned char ucTemperatura[4];
unsigned char ucEnable;
unsigned char ucTempAtual[4];
unsigned char ucHeaterDuty[4];
unsigned char ucCoolerDuty[4];
int iValorTempAtual = 0;

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

    /* Iniciando os periféricos */
    adc_initADCModule();
    adc_initConvertion();
    lcd_initLcd();
    UART0_init();
    coolerfan_init();
    heater_init();
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
	int iAux=0;
	const char cMensagem1[] = "A Temperatura é: ";
	const char *c;
	const char cTemp[] = "00";

    iniciarPlaca();

    UART0_enableIRQ();

    while(1){

    	/* clear LCD */
    	lcd_sendCommand(CMD_CLEAR);
    	/* set the cursor line 0, column 1 */
    	lcd_setCursor(0,1);
    	c = cMensagem1;
    	lcd_writeText(0,c);
        lerTemp();
        /*separa dezena de unidade*/
        iAux = (iValorTempAtual/10)+48;
        cTemp[0]=(char)iAux;

        iAux = (iValorTempAtual%10)+48;
        /*converte int para char*/
        cTemp[1]=(char)iAux;
        /* Escreve a temperatura no LCD */
    	c = cTemp;
        lcd_writeText(1,c);
    }
}
