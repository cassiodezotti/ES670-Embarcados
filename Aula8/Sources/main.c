/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descri��o do arquivo: Este arquivo � dedicado a inicializar a placa      */
/*                       fazendo a inicializa��o do clock e o LCD           */
/*                                                                          */
/*                       Caracter�sticas do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de cria��o:      06abril2020                                        */
/* Data da revis�o:      09abril2020                                        */
/* ************************************************************************ */

/* our includes */
#include "lcd.h"
#include "board.h"
#include "mcg.h"

/* *********************************************************** */
/* Nome da fun��o: 	           iniciarPlaca	         		   */
/* Descri��o da fun��o:        Inicia o clock e as entradas    */
/*                             sa�das desejadas.               */
/* par�metros de entrada:	   n/a                             */
/* par�metros de sa�da:	       n/a 					           */
/* *********************************************************** */
void iniciarPlaca(void)
{
    /* Configura��o e inicializa��o do clock */
    mcg_clockInit();

    /* Inicializa��o das portas de entrada e sa�da */
    lcd_initLcd();
}


/* ******************************************************* */
/* Nome da fun��o:           main                          */
/* Descri��o da fun��o:      Ponto de entrada do sistema   */
/*                           onde s�o realizados os testes */
/* par�metros de entrada:    n/a                           */
/* par�metros de sa�da:      n/a                           */
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
