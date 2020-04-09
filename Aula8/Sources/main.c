/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descrição do arquivo: Este arquivo é dedicado a inicializar a placa      */
/*                       fazendo a inicialização do clock e o LCD           */
/*                                                                          */
/*                       Características do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criação:      06abril2020                                        */
/* Data da revisão:      09abril2020                                        */
/* ************************************************************************ */

/* our includes */
#include "lcd.h"
#include "board.h"
#include "mcg.h"

/* *********************************************************** */
/* Nome da função: 	           iniciarPlaca	         		   */
/* Descrição da função:        Inicia o clock e as entradas    */
/*                             saídas desejadas.               */
/* parâmetros de entrada:	   n/a                             */
/* parâmetros de saída:	       n/a 					           */
/* *********************************************************** */
void iniciarPlaca(void)
{
    /* Configuração e inicialização do clock */
    mcg_clockInit();

    /* Inicialização das portas de entrada e saída */
    lcd_initLcd();
}


/* ******************************************************* */
/* Nome da função:           main                          */
/* Descrição da função:      Ponto de entrada do sistema   */
/*                           onde são realizados os testes */
/* parâmetros de entrada:    n/a                           */
/* parâmetros de saída:      n/a                           */
/* ******************************************************* */
int main(void)
{
	const char cMensagem1[] = "Teste linha 1";
	const char cMensagem2[] = "Teste linha 2";
	const char *c;
	int iLinhaUm = 1;
	int iLinhaZero = 0;

	c = cMensagem1;
	lcd_writeText(iLinhaUm,c);
	c = cMensagem2;
	lcd_writeText(iLinhaZero,c);

}
