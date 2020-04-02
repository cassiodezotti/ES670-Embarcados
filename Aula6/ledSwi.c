/* ***************************************************************** */
/* File name:        ledrgb.c                                        */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related RGB LED from the FRDM-KL25Z board       */
/*                   controller. REMARKS LEDS are inverted output    */
/*                                                                   */
/* Author name:      Rodrigo M Bacurau                               */
/* Creation date:    26fev2020                                       */
/* Revision date:    02mar2020                                       */
/* ***************************************************************** */

/* our includes */
#include "board.h"


/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"


/* ************************************************ */
/* Method name: 	   ledrgb_init	         		*/
/* Method description: Initialize the RGB LED device*/
/* Input params:	   n/a                          */
/* Output params:	   n/a 							*/
/* ************************************************ */
void ledSwi_init(void)
{
	unsigned int uiTamanhoEntrada;
	unsigned int uij;

	/* ligar o clock*/
	SIM_SCGC5 |= 0x0200; //Porta A

	/* set pin as gpio */
	PORTA_PCR1 |= 0X100; //pino 1 porta A
	PORTA_PCR2 |= 0X100; //pino 2 porta A
	PORTA_PCR4 |= 0X100; //pino 4 porta A
	PORTA_PCR5 |= 0X100; //pino 5 porta A

	uiTamanhoEntrada = length(uiEstadosGPIO);

	/* seta pino como output ou input */
	if(uiEstadosGPIO[3] == 0)
		GPIOA_PDDR |= 0x0; //zero no pino 1
	elseif(uiEstadosGPIO[3] != NULL)
		GPIOA_PDDR |= 0x2; //um no pino 1

	if(uiEstadosGPIO[2] == 0)
		GPIOA_PDDR |= 0x0; //zero no pino 2
	else
		GPIOA_PDDR |= 0x4; //um no pino 2

	if(uiEstadosGPIO[1] == 0)
		GPIOA_PDDR |= 0x0; //zero no pino 4
	else
		GPIOA_PDDR |= 0x10; //um no pino 4

	if(uiEstadosGPIO[0] == 0)
		GPIOA_PDDR |= 0x0; //zero no pino 5
	else
		GPIOA_PDDR |= 0x20; //um no pino 5
}


/*função de leitura do status*/
void lerLED(void)
{

}
/*função para escrita do LED*/
void escreverLED(void)
{

}
//função para acender LED
void setLED(void)
{
	/*setar valor no pino*/

	if(uiSetarLED == 1)
		GPIOA_PSOR |= 0x02; //setar pino 1
	else if(uiSetarLED == 2)
		GPIOA_PSOR |= 0x4; //setar pino 2
	else if(uiSetarLED == 3)
		GPIOA_PSOR |= 0x10; //setar pino 4
	else
		GPIOA_PSOR |= 0x20; //setar pino 5
}

//função para apagar LED
void clearLED(void)
{
	if(uiclearLED == 1)
		GPIOA_PSOR |= 0x0; //setar pino 1
	else if(uiclearLED == 2)
		GPIOA_PSOR |= 0x0; //setar pino 2
	else if(uiclearLED == 3)
		GPIOA_PSOR |= 0x0; //setar pino 4
	else
		GPIOA_PSOR |= 0x0; //setar pino 5
}

/*função para mudar o status do LED*/
void toggleLED(void)
{
	if(uitoggleLED == 1)
		GPIOA_PTOR |= 0x02; //setar pino 1
	else if(uitoggleLED == 2)
		GPIOA_PTOR |= 0x4; //setar pino 2
	else if(uitoggleLED == 3)
		GPIOA_PTOR |= 0x10; //setar pino 4
	else
		GPIOA_PTOR |= 0x20; //setar pino 5
}
