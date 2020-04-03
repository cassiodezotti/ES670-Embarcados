/* ************************************************************************ */
/* Nome do Arquivo:        board.h                                          */
/* Descri��o do arquivo:   Este arquivo contem o mapeamento dos perif�ricos */
/*                   	   de hardware para a placa da mat�ria ES670        */
/*                                                                          */
/*                                                                          */
/* Nome dos autores:       Gustavo Moraes/Cassio Dezotti                    */
/* RA:                     174217/168988                                    */
/* Data de cria��o:        26mar2020                                        */
/* Data da revis�o:        04abril2020                                      */
/* ************************************************************************ */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/* FDRMKL25Z Defini��es de LED e Bot�o */
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

#endif /* SOURCES_BOARD_H_ */
