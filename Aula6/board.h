/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Gustavo Moraes/Cassio Dezotti e Angelo Barbosa                              */
/* Creation date:    01abril2020                                       */
/* Revision date:    02mar2020                                       */
/* ***************************************************************** */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/* FDRMKL25Z RGB LED pins defintions */
/*Vou definir o botao e o led na mesma porta com o nome LEDSWI1,LEDSWI2,LEDSWI3,LEDSWI4 ai no programa definimos se é botao ou led*/
#define LEDSWI1_PORT   PORTA /* peripheral port base pointer */
#define LEDSWI1_GPIO   PTA   /* peripheral gpio base pointer */
#define LEDSWI1_PIN	         (uint32_t) 1u
#define LEDSWI2_PORT   PORTA /* peripheral port base pointer */
#define LEDSWI2_GPIO   PTA   /* peripheral gpio base pointer */
#define LEDSWI2_PIN	         (uint32_t) 2u
#define LEDSWI3_PORT   PORTA /* peripheral port base pointer */
#define LEDSWI3_GPIO   PTA   /* peripheral gpio base pointer */
#define LEDSWI3_PIN	         (uint32_t) 4u
#define LEDSWI4_PORT   PORTA /* peripheral port base pointer */
#define LEDSWI4_GPIO   PTA   /* peripheral gpio base pointer */
#define LEDSWI4_PIN	         (uint32_t) 5u
//Definir os botões
//definir os leds
//#define LED1SWi

#endif /* SOURCES_BOARD_H_ */
