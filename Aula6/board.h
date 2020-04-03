/* ************************************************************************ */
/* Nome do Arquivo:        board.h                                          */
/* Descrição do arquivo:   Este arquivo contem o mapeamento dos periféricos */
/*                   	   de hardware para a placa da matéria ES670        */
/*                                                                          */
/*                                                                          */
/* Nome dos autores:       Gustavo Moraes/Cassio Dezotti                    */
/* RA:                     174217/168988                                    */
/* Data de criação:        26mar2020                                        */
/* Data da revisão:        04abril2020                                      */
/* ************************************************************************ */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/* FDRMKL25Z Definições de LED e Botão */
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
