/* *************************************************************************** */
/* Nome do Arquivo:      display7seg.c                                         */
/* Descricao do arquivo: Este arquivo contem as funcoes usadas para manipular  */
/*                       o display de 7 segmentos                              */
/*                                                                             */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                         */
/* RA:                   174217/168988                                         */
/* Data de criacao:      16abril2020                                           */
/* Data da revisao:      18abril2020                                           */
/* *************************************************************************** */

#include "display7seg.h"
#include "board.h"

/* system includes */
#include "fsl_lptmr_driver.h"

#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"

extern unsigned char ucVetorDisplay[4];
extern unsigned char ucVetorCaracter[4];

/* ***************************************************************** */
/* Nome da funcao: 	           display7seg_init         	         */
/* Descricao da funcao:        Configura os pinos como GPIO de saida */
/*                             e habilita o clock                    */
/* parametros de entrada:	   n/a                                   */
/* parametros de saida:	       n/a 					                 */
/* ***************************************************************** */
void display7seg_init()
{
	int i;
	unsigned char ucVetor;

	/*Habilitando o clock*/
	SIM_SCGC5 |= 0X801;

	/*Habilitando os pinos da porta C como GPIO*/
	PORTC_PCR10 |= 0x100;
	PORTC_PCR10 &= ~(0x600);

	PORTC_PCR11 |= 0x100;
	PORTC_PCR11 &= ~(0x600);

	PORTC_PCR12 |= 0x100;
	PORTC_PCR12 &= ~(0x600);

	PORTC_PCR13 |= 0x100;
	PORTC_PCR13 &= ~(0x600);

	PORTC_PCR0  |= 0x100;
	PORTC_PCR0  &= ~(0x600);

	PORTC_PCR1  |= 0x100;
	PORTC_PCR1  &= ~(0x600);

	PORTC_PCR2  |= 0x100;
	PORTC_PCR2  &= ~(0x600);

	PORTC_PCR3  |= 0x100;
	PORTC_PCR3  &= ~(0x600);

	PORTC_PCR4  |= 0x100;
	PORTC_PCR4  &= ~(0x600);

	PORTC_PCR5  |= 0x100;
	PORTC_PCR5  &= ~(0x600);

	PORTC_PCR6  |= 0x100;
	PORTC_PCR6  &= ~(0x600);

	PORTC_PCR7  |= 0x100;
	PORTC_PCR7  &= ~(0x600);

	for(i=0;i<8;i++)
	{
		ucVetor |= (1 << i);
	}
	ucVetor   |= (1 << DISPLAY_7SEG_D4_PIN);
	ucVetor   |= (1 << DISPLAY_7SEG_D3_PIN);
	ucVetor   |= (1 << DISPLAY_7SEG_D2_PIN);
	ucVetor   |= (1 << DISPLAY_7SEG_D1_PIN);
	GPIOC_PDDR |= ucVetor;
}

/* ************************************************************************* */
/* Nome da funcao: 	           display7seg_writeSymbol         	             */
/* Descricao da funcao:        Salva o caracter a ser escrito no vetor       */
/*                             ucVetorCaracter de acordo com o display       */
/*                             e habilita o clock                            */
/* parametros de entrada:	   Valor de 1 a 4 que representa o display       */
/*                             e valor de 0 a 22 que corresponde ao caracter */
/* parametros de saida:	       n/a 					                         */
/* ************************************************************************* */
void display7seg_writeSymbol(unsigned char ucDisplay, unsigned char ucValue)
{
	unsigned char ucAuxiliar = charTo7seg(ucValue);

	/* De acordo com o display desejado salva o valor no vetor de caracter */
	switch(ucDisplay)
	{
		    case '1':
		        ucVetorCaracter[0] = ucAuxiliar ;
		        break;

		    case '2':
		    	ucVetorCaracter[1] = ucAuxiliar ;
		    	break;

		    case '3':
		    	ucVetorCaracter[2] = ucAuxiliar ;
		        break;

		    case '4':
		    	ucVetorCaracter[3] = ucAuxiliar ;
		        break;
	}
}

/* ******************************************************************************** */
/* Nome da funcao: 	           charTo7seg         	                                */
/* Descricao da funcao:        Salva os 5 bits de entrada em variaveis separadas    */
/*                             para aplicar o Karnaugh, depois grava os 8 bits de   */
/*                             saida do Karnaugh no parametro de saida (ucAuxiliar) */
/*                             ucVetorCaracter de acordo com o display              */
/*                                                                                  */
/* parametros de entrada:	   Valor de 0 a 22 que corresponde ao caracter          */
/* parametros de saida:	       Vetor traduzido para os 8 bits de entrada do display */
/* ******************************************************************************** */
unsigned char charTo7seg(unsigned char ucValue)
{
	unsigned char ucAuxiliar;
	unsigned char X,Y,Z,W,V,A,B,C,D,E,F,G,DP;

	/* Salva os 5 primeiros bits de entrada em variaveis separadas */
	ucAuxiliar = ucValue;
	X = 1&(ucAuxiliar >>4);
	ucAuxiliar = ucValue;
	Y = 1&(ucAuxiliar >>3);
	ucAuxiliar = ucValue;
	Z = 1&(ucAuxiliar >>2);
	ucAuxiliar = ucValue;
	W = 1&(ucAuxiliar >>1);
	ucAuxiliar = ucValue;
	V = 1&(ucAuxiliar >>0);

	/*
	 *  Para 5 bits de entrada fizemos um mapa de Karnaugh para cada bit de saida
	 *  analisando as 23 primeiras entradas.
	 *  Utilizamos o site http://www.32x8.com/var5.html para gerar as instrucoes logicas
	 */

	DP =  (Y & W) | (Y & Z) | (X & ~(Z)) | (X & ~(V));
	G  =  (Y & ~(W)) | (Y & Z) | (~(Y) & ~(Z) & W) | (~(Y) & W & ~(V)) | (~(X) & Z & ~(W)) | (X & ~(Z) & ~(V));
	F  =  (X & W) | (~(Z) & ~(W) & ~(V)) | (Z & W & ~(V)) | (Y & ~(Z) & ~(W)) | (Y & ~(Z) & ~(V)) | (Y & Z & W) | (~(X) & ~(Y) & Z & ~(W));
	E  =  (~(Z) & ~(V)) | (~(Y) & W & ~(V)) | (Y & ~(W) & ~(V));
	D  =  (~(Z) & ~(V)) | (Y & ~(W)) | (~(Y) & ~(Z) & W) | (~(Y) & W & ~(V)) | (Y & Z & V) | (~(X) & Z & ~(W) & V);
	C  =  (~(X) & V) | (Z & W) | (Y & ~(Z)) | (X & ~(Z)) | (~(X) & ~(Y) & ~(W));
	B  =  (~(X) & ~(Z)) | (~(Z) & V) | (Y & ~(W)) | (Y & ~(V)) | (X & W) | (~(X) & ~(W) & ~(V)) | (~(Y) & W & V);
	A  =  (~(Z) & ~(V)) | (~(Y) & W) | (Y & ~(W)) | (X & ~(Z)) | (~(X) & V);

	/* Coloca cada bit de saida do Karnaugh no seu respectivo bit do display */
	ucAuxiliar &= 0x0;
	ucAuxiliar |= (DP << DISPLAY_7SEG_DP_PIN);
	ucAuxiliar |= (G << DISPLAY_7SEG_G_PIN);
	ucAuxiliar |= (F << DISPLAY_7SEG_F_PIN);
	ucAuxiliar |= (E << DISPLAY_7SEG_E_PIN);
	ucAuxiliar |= (D << DISPLAY_7SEG_D_PIN);
	ucAuxiliar |= (C << DISPLAY_7SEG_C_PIN);
	ucAuxiliar |= (B << DISPLAY_7SEG_B_PIN);
	ucAuxiliar |= (A << DISPLAY_7SEG_A_PIN);

	return ucAuxiliar;
}
