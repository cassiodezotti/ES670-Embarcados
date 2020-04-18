/* ***************************************************************** */
/* File name:        tc_hal.c                                        */
/* File description: This file has a couple of useful functions to   */
/*                   timer and counter hardware abstraction layer    */
/*                                                                   */
/* Author name:      dloubach                                        */
/* Creation date:    23out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#include "display7seg.h"
#include "board.h"

/* system includes */
#include "fsl_lptmr_driver.h"

#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"


/* ************************************************ */
/* Method name:        tc_installLptmr              */
/* Method description: Low power timer 0            */
/*                     initialization and start     */
/* Input params:       uiTimeInUs:                  */
/*                     time in micro seconds        */
/*                     tUserCallback                */
/*                     function pointer to be called*/
/*                     when counter achieves        */
/*                     uiTimeInUs                   */
/* Output params:      n/a                          */
/* ************************************************ */
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
	GPIO_PDDR |= ucVetor;
}


/* ************************************************ */
/* Method name:        tc_installLptmr              */
/* Method description: Low power timer 0            */
/*                     initialization and start     */
/* Input params:       uiTimeInUs:                  */
/*                     time in micro seconds        */
/*                     tUserCallback                */
/*                     function pointer to be called*/
/*                     when counter achieves        */
/*                     uiTimeInUs                   */
/* Output params:      n/a                          */
/* ************************************************ */
void display7seg_writeSymbol(unsigned char ucDisplay, unsigned char ucValue)
{
	unsigned char ucAuxiliar = charTo7seg(ucValue);

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

unsigned char charTo7seg(unsigned char ucValue)
{

	unsigned char ucAuxiliar;
	unsigned char X,Y,Z,W,V,A,B,C,D,E,F,G,DP;

	ucAuxiliar = ucValue
	X = 1&(ucAuxiliar >>4)
	ucAuxiliar = ucValue
	Y = 1&(ucAuxiliar >>3)
	ucAuxiliar = ucValue
	Z = 1&(ucAuxiliar >>2)
	ucAuxiliar = ucValue
	W = 1&(ucAuxiliar >>1)
	ucAuxiliar = ucValue
	V = 1&(ucAuxiliar >>0)

	DP = (Y & W) | (Y & Z) | (X & ~(Z)) | (X & ~(V));
	G= (Y & ~(W)) | (Y & Z) | (~(Y) & ~(Z) & W) | (~(Y) & W & ~(V)) | (~(X) & Z & ~(W)) | (X & ~(Z) & ~(V);
	F = = (X & W) | (~(Z) & ~(W) & ~(V)) | (Z & W & ~(V)) | (Y & ~(Z) & ~(W)) | (Y & ~(Z) & ~(V)) | (Y & Z & W) | (~(X) & ~(Y) & Z & ~(W));
	E = (~(Z) & ~(V)) | (~(Y) & W & ~(V)) | (Y & ~(W) & ~(V));
	D = (~(Z) & ~(V)) | (Y & ~(W)) | (~(Y) & ~(Z) & W) | (~(Y) & W ~(V)) | (Y & Z & V) | (~(X) & Z & ~(W) & V);
	C = (~(X) & V) | (Z & W) | (Y & ~(Z)) | (X & ~(Z)) | (~(X) & ~(Y) & ~(W));
	B = (~(X) & ~(Z)) | (~(Z) & V) | (Y & ~(W)) | (Y & ~(V)) | (X & W) | (~(X) & ~(W) & ~(V)) | (~(Y) & W & V);
	A = (~(Z) & ~(V)) | (~(Y) & W) | (Y & ~(W)) | (X & ~(Z)) | (~(X) & V);

	ucAuxiliar &= 0x0;
	ucAuxiliar |= (DP << DISPLAY_7SEG_DP_PIN);
	ucAuxiliar |= (G << DISPLAY_7SEG_G_PIN);
	ucAuxiliar |= (F << DISPLAY_7SEG_F_PIN);
	ucAuxiliar |= (E << DISPLAY_7SEG_E_PIN);
	ucAuxiliar |= (D << DISPLAY_7SEG_D_PIN);
	ucAuxiliar |= (C << DISPLAY_7SEG_C_PIN);
	ucAuxiliar |= (B << DISPLAY_7SEG_B_PIN);
	ucAuxiliar |= (A << DISPLAY_7SEG_A_PIN);


}
