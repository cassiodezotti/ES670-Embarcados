/* ***************************************************************** */
/* File name:        UART.h                                          */
/* File description: Debugging through UART interface                */
/* Author name:      dloubach, rbacurau                              */
/* Creation date:    22out2015                                       */
/* Revision date:    01mai2020                                       */
/* ***************************************************************** */

#ifndef COMMUNICATION_STATE_MACHINE_H_
#define COMMUNICATION_STATE_MACHINE_H_


#define MAX_VALUE_LENGHT 7

/* ************************************************ */
/* Method name:        UART_init                    */
/* Method description: Initialize the UART0         */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void processamentoByte(unsigned char ucByte);

void returnPARAM(unsigned char ucPARAM);

void setPARAM(unsigned char ucPARAM,unsigned char ucValue[MAX_VALUE_LENGHT+1]);

void lerTemp();

void heater_PWMDuty();

void coolerFan_PWMDuty();

#endif /* UART_H_ */
