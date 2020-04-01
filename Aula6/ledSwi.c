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
void ledrgb_init(void)
{
	/* ligar o clock*/
	SIM_SCGC5 |= 0x02; //Porta A

	/* set pin as gpio */
	PORTA_PCR0 |= 0X100; //pino 1 porta A
	PORTA_PCR1 |= 0X100; //pino 2 porta A
	PORTA_PCR2 |= 0X100; //pino 4 porta A
	PORTA_PCR3 |= 0X100; //pino 5 porta A

	/* seta pino como output ou input */
	//if(vetor de EstadosGPIO)
	GPIOA_PDDR |= 0x2; //pino 1

	/*setar valor no pin*/
	GPIO_PSOR |= 0x02;

	/* clear all leds */

}

/* ************************************************ */
/* Method name: 	   ledrgb_write	         		*/
/* Method description: Write the color of the RGB   */
/*                     led.REMARKS LEDS are inverted*/
/* Input params:	   ucRGBColor 0..7 (0 = off     */
/*                     1 = red                      */
/*                     2 = green                    */
/*                     3 = red + green              */
/*                     4 = blue                     */
/*                     5 = blue + red               */
/*                     6 = blue + green             */
/*                     7 = blue + green + red)      */
/* Output params:	   n/a 							*/
/* ************************************************ */
void ledrgb_write(unsigned char ucRGBColor)
{
	// if ucRGBColor is 1, 3 or 7
	if (ucRGBColor & 1)
		// lights up red LED
		GPIO_HAL_ClearPinOutput(RED_LED_GPIO_BASE_PNT, RED_LED_PIN);
	else
		// turn off red LED
		GPIO_HAL_SetPinOutput(RED_LED_GPIO_BASE_PNT, RED_LED_PIN);

	// if ucRGBColor is 2, 3 or 6
	if (ucRGBColor & 2)
		// lights up green LED
		GPIO_HAL_ClearPinOutput(GREEN_LED_GPIO_BASE_PNT, GREEN_LED_PIN);
	else
		// turn off green LED
		GPIO_HAL_SetPinOutput(GREEN_LED_GPIO_BASE_PNT, GREEN_LED_PIN);

	// if ucRGBColor is 4, 5 or 6
	if (ucRGBColor & 4)
		// lights up blue LED
		GPIO_HAL_ClearPinOutput(BLUE_LED_GPIO_BASE_PNT, BLUE_LED_PIN);
	else
		// turn off blue LED
		GPIO_HAL_SetPinOutput(BLUE_LED_GPIO_BASE_PNT, BLUE_LED_PIN);
}

/*função de leitura do status*/
/*função para escrita do LED*/
/*função para acender LED*/
/*função para apagar LED*/
/*função para mudar o status do LED*/
