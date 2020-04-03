/* ******************************************************************** */
/* Nome do Arquivo:        ledSwi.h                                     */
/* Descri��o do arquivo: Este arquivo contem fun��es para inicializa��o */
/*                   	 e utiliza��o dos leds e bot�es do kit.         */
/*                                                                      */
/*                                                                      */
/* Author name:      Gustavo Moraes/Cassio Dezotti                      */
/* RA:               174217/168988                                      */
/* Creation date:    26mar2020                                          */
/* Revision date:    04abril2020                                        */
/* ******************************************************************** */

#ifndef SOURCES_LEDSWI_H_
#define SOURCES_LEDSWI_H_


/* ************************************************ */
/* Nome da fun��o: 	   ledSwi_init	         		*/
/* Descri��o da fun��o: Ini                         */
/* par�metros de entrada:	   n/a                  */
/* par�metros de sa�da:	       n/a 					*/
/* ************************************************ */
void ledSwi_init(void);

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
void lerChave(void);
void escreverLED(void);
void setLED(void);
void clearLED(void);
void toggleLED(void);

#endif /* SOURCES_LEDRGB_H_ */
