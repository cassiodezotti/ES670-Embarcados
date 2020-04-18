/* *************************************************************************** */
/* Nome do Arquivo:      display7seg.h                                         */
/* Descricao do arquivo: Este arquivo contem as declaracoes das funcoes usadas */
/*                       no programa                                           */
/*                                                                             */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                         */
/* RA:                   174217/168988                                         */
/* Data de criacao:      16abril2020                                           */
/* Data da revisao:      18abril2020                                           */
/* *************************************************************************** */

#ifndef SOURCES_DISPLAY7SEG_H_
#define SOURCES_DISPLAY7SEG_H_


/* ***************************************************************** */
/* Nome da funcao: 	           display7seg_init         	         */
/* Descricao da funcao:        Configura os pinos como GPIO de saida */
/*                             e habilita o clock                    */
/* parametros de entrada:	   n/a                                   */
/* parametros de saida:	       n/a 					                 */
/* ***************************************************************** */
void display7seg_init();

/* ************************************************************************* */
/* Nome da funcao: 	           display7seg_writeSymbol         	             */
/* Descricao da funcao:        Salva o caracter a ser escrito no vetor       */
/*                             ucVetorCaracter de acordo com o display       */
/*                             e habilita o clock                            */
/* parametros de entrada:	   Valor de 1 a 4 que representa o display       */
/*                             e valor de 0 a 22 que corresponde ao caracter */
/* parametros de saida:	       n/a 					                         */
/* ************************************************************************* */
void display7seg_writeSymbol(unsigned char ucDisplay, unsigned char ucValue);

/* ******************************************************************************** */
/* Nome da funcao: 	           charTo7seg         	                                */
/* Descricao da funcao:        Salva os 5 bits de entrada em variaveis separadas    */
/*                             para aplicar o Karnaugh, depois grava os 8 bits de   */
/*                             saida do Karnaugh no parametro de saida (ucAuxiliar) */
/*                             ucVetorCaracter de acordo com o display              */
/*                                                                                  */
/* parametros de entrada:	   Valor de 0 a 22 que corresponde ao caracter          */
/* parametros de saida:	       Vetor traduzido para os 8 bits de entrada do display */
/* ******************************************************************************** */
unsigned char charTo7seg(unsigned char ucValue);

#endif /* SOURCES_DISPLAY7SEG_H_ */
