/* ***************************************************************** */
/* File name:        UART.h                                          */
/* File description: Debugging through UART interface                */
/* Author name:      dloubach, rbacurau                              */
/* Creation date:    22out2015                                       */
/* Revision date:    01mai2020                                       */
/* ***************************************************************** */

#ifndef interruptButton_H_
#define interruptButton_H_

/* ************************************************ */
/* Method name:        UART_init                    */
/* Method description: Initialize the UART0         */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void interruptButton_init (void);

/* ************************************************ */
/* Method name:        UART0_enableIRQ              */
/* Method description: Enable the interruption for  */
/*                     serial port inputs and       */
/*                     prepare the buffer           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void interruptButton_enableIRQ(void);


/* ************************************************ */
/* Method name:        UART0_IRQHandler             */
/* Method description: Serial port interruption     */
/*                     handler method. It Reads the */
/*                     new character and saves in   */
/*                     the buffer                   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void interruptButton_disableIRQ(void);

/* ************************************************ */
/* Method name:        PORTA_IRQHandler             */
/* Method description: Serial port interruption     */
/*                     handler method. It Reads the */
/*                     new character and saves in   */
/*                     the buffer                   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void PORTA_IRQHandler(void);

#endif /* UART_H_ */
