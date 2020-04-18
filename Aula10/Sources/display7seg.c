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
int mapearEntrada(unsigned char ucDisplay)
{
	int ivalorEntrada;

	switch(ucDisplay)
	{
	    case "1":
	        ivalorEntrada = 13;

	    case "2":
	    	ivalorEntrada = 12;

	    case "3":
	        ivalorEntrada = 11;

	    case "4":
	        ivalorEntrada = 10;
	}

	return ivalorEntrada;
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
	int ivalorEntrada = mapearEntrada(ucDisplay);





}
