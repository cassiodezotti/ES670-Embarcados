/* ***************************************************************** */
/* File name:        lptmr.c                                        */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling timers and counter      */
/*                   from the FRDM-KL25Z board                       */
/* Author name:      dloubach                                        */
/* Creation date:    23out2015                                       */
/* Revision date:    25fev2016                                   s    */
/* ***************************************************************** */

#ifndef SOURCES_DISPLAY7SEG_H_
#define SOURCES_DISPLAY7SEG_H_


/* ************************************************ */
/* Method name:        tc_installLptmr              */
/* Method description: Low power timer 0            */
/*                    initialization and start      */
/* Input params:      uiTimeInUs:                   */
/*                    time in micro seconds         */
/*                    tUserCallback                 */
/*                    function pointer to be called */
/*                    when counter achieves         */
/*                    uiTimeInUs                    */
/* Output params:     n/a                           */
/* ************************************************ */
void display7seg_init();

/* ************************************************ */
/* Method name:        tc_installLptmr              */
/* Method description: Low power timer 0            */
/*                    initialization and start      */
/* Input params:      uiTimeInUs:                   */
/*                    time in micro seconds         */
/*                    tUserCallback                 */
/*                    function pointer to be called */
/*                    when counter achieves         */
/*                    uiTimeInUs                    */
/* Output params:     n/a                           */
/* ************************************************ */
void display7seg_writeSymbol(unsigned char ucDisplay, unsigned char ucValue);

#endif /* SOURCES_LPTMR_H_ */
