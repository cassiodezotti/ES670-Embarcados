* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: File dedicated to the ES670 prototype projects  */
/*                   involving the FRDM-KL25Z board together with is */
/*                   daughter board containing more peripherals      */
/*                                                                   */
/*                   Processor MKL25Z128VLK4 characteristics         */
/*                   48 MHz ARM Cortex-M0+ core                      */
/*                   128 KB program flash memory                     */
/*                   16 KB SRAM                                      */
/*                   Voltage range: 1.71 to 3.6 V                    */
/*                                                                   */
/* Author name:      Rodrigo M Bacurau                               */
/* Creation date:    26fev2020                                       */
/* Revision date:    02mar2020                                       */
/* ***************************************************************** */

/* our includes */
#include "ledSwi.h"
#include "board.h"


/* globals */
static unsigned int estados[4];
static unsigned int uisetarLED=0;
static unsigned int uiclearLED=0;
static unsigned int uitoggleLED=0;

/* ************************************************ */
/* Method name:        boardInit                    */
/* Method description: main board all needed        */
/*                     initializations              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void boardInit(int iEntrada[4])
{
	/* fist of all, clock configuration and initialization */
	mcg_clockInit();

	/* RGB LED initialization */
	ledSwi_init(iEntrada);
}


/* ************************************************ */
/* Method name:        main                         */
/* Method description: system entry point           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int main(void)
{
	int iEntrada[4] = {1,0,0,1};
	int iChave = 2;
	int iEstadoBotao;
	/* board initializations */
	boardInit(iEntrada);


	/*chamar as funções criadas*/
	iEstadoBotao = lerChave(iChave);
	printf(&iEstadoBotao);

	escreverLED(1,1);

	setLED(4);

	clearLED(1);

	toggleLED(1);

	escreverLED(4,0);
}
