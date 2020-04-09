
/* ************************************************************************ */
/* Nome do Arquivo:      main.c                                             */
/* Descricao do arquivo: Este arquivo e dedicado a inicializar o lcd        */
/*                   	 e manipula-lo, utilizando as funcoes               */
/*                       desenvolvidas, escrevendo uma string na linha      */
/*                       desejada.                                          */
/*                                                                          */
/*                       Caracteristicas do processador MKL25Z128VLK4       */
/*                       48 MHz ARM Cortex-M0+ core                         */
/*                       128 KB program flash memory                        */
/*                       16 KB SRAM                                         */
/*                       Voltage range: 1.71 to 3.6 V                       */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de criacao:      06abril2020                                        */
/* Data da revisao:      09abril2020                                        */
/* ************************************************************************ */

/* our includes */
#include "lcd.h"
#include "board.h"
#include "mcg.h"


/* *********************************************************** */
/* Nome da funcao: 	           iniciarPlaca        		       */
/* Descricao da funcao:        Inicia o clock e o lcd          */
/*                             saidas desejadas                */
/* parametros de entrada:	   n/a                             */
/* parametros de saida:	       n/a  		                   */
/* *********************************************************** */


void iniciarPlaca(void)
{
    /* Configuracao e inicializacao do clock */
    mcg_clockInit();

    /* Inicializacao das portas de entrada e saida */
    lcd_initLcd();
}



/* ******************************************************* */
/* Nome da funcao:           main                          */
/* Descricao da funcao:      Ponto de entrada do sistema   */
/*                           onde sao realizados os testes */
/* parametros de entrada:    n/a                           */
/* parametros de saida:      n/a                           */
/* ******************************************************* */
int main(void)
{
    /* Cria as mensagens e variaveis para teste */
    const char cMensagem1[] = "Teste linha 1";
    const char cMensagem2[] = "Teste linha 2";
    const char *c;
    int iLinhaUm = 1;
    int iLinhaZero = 0;

    /* chama a dummy para testar se conexoes e inicializacao estao corretas */
    lcd_dummyText();

    /*
     * atribui a mensagem a um ponteiro e envia para a writeText, esse ponteiro
     * e a linha que sera escrita.
     */
    c = cMensagem1;
    lcd_writeText(iLinhaUm,c);
    c = cMensagem2;
    lcd_writeText(iLinhaZero,c);

}
