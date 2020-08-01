/* ***************************************************************** */
/* File name:        UART.c                                          */
/* File description: Debugging through UART interface                */
/* Author name:      dloubach, rbacurau                              */
/* Creation date:    22out2015                                       */
/* Revision date:    01mai2020                                       */
/* ***************************************************************** */

/* definition include */
#include "interruptButton.h"

/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_device_registers.h"
#include "fsl_port_hal.h"
#include "fsl_smc_hal.h"
#include "fsl_debug_console.h"
#include "communicationStateMachine.h"
#include "board.h"

extern int iFlagSetTemp = 0;
extern int iFlagSetK = 0;

/* ************************************************ */
/* Method name:        interruptButton_init               */
/* Method description: Initialize the UART0 as debug*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void interruptButton_init (void)
{
	PORTA_PCR1 |= (0XA0000);
	PORTA_PCR2 |= (0XA0000);

}

/* ************************************************ */
/* Method name:        interruptButton_enableIRQ              */
/* Method description: Enable the interruption for  */
/*                     serial port inputs and       */
/*                     prepare the buffer           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void interruptButton_enableIRQ(void)
{
    /* Enable interruption in the NVIC */
	NVIC_EnableIRQ(PORTA_IRQn);

}

/* ************************************************ */
/* Method name:        interruptButton_enableIRQ              */
/* Method description: Enable the interruption for  */
/*                     serial port inputs and       */
/*                     prepare the buffer           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void interruptButton_disableIRQ(void)
{
    /* Enable interruption in the NVIC */
	NVIC_DisableIRQ(PORTA_IRQn);

}

/* ************************************************ */
/* Method name:        PORTA_IRQHandler             */
/* Method description: Serial port interruption     */
/*                     handler method. It Reads the */
/*                     new character and saves in   */
/*                     the buffer                   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void PORTA_IRQHandler(void)
{
	/* Fazer logica para verificacao de flags de cada botao */
	unsigned char ucAux, ucLido;
	ucLido = PORTA_ISFR;

	ucAux = (0x1) & (ucLido >> 1);
	if(ucAux){
		iFlagSetTemp = 1;
	}
	ucAux = (0x1) & (ucLido >> 2);
	if(ucAux){
		iFlagSetK = 1;
	}
}
