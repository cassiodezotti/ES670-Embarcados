/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Gustavo M./Cassio D.          */
/* Creation date:    22maio2020                                       */
/* Revision date:    24maio2020                                       */
/* ***************************************************************** */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/*                 UART definitions                 */

#define BOARD_DEBUG_UART_INSTANCE   0
#define BOARD_DEBUG_UART_BASEADDR   UART0
#define BOARD_DEBUG_UART_BAUD       115200

#define UART_PORT                   PORTA
#define UART_ALT                    kPortMuxAlt2
#define UART_PIN_1                  1u
#define UART_PIN_2                  2u

#endif /* SOURCES_BOARD_H_ */
