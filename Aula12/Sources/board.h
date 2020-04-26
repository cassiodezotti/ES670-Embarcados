/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Rodrigo M Bacurau/Gustavo M./Cassio D.          */
/* Creation date:    26fev2020                                       */
/* Revision date:    18abr2020                                       */
/* ***************************************************************** */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/*                 ATUADORES definitions                 */

#define ATUADORES_PORT_BASE_PNT          PORTA                                   /* peripheral port base pointer */
#define ATUADORES_PWM_BASE_PNT           PTA                                     /* peripheral gpio base pointer */

#define COOLER_PIN                       13U                                      /* register selector */
/*#define COOLER_DIR                       (GPIO_OUTPUT << COOLER_PIN)
#define COOLER_ALT                       kPortMuxAsGpio*/

#define AQUECEDOR_PIN                    12U                                      /* register selector */
/*#define DISPLAY_7SEG_D3_DIR              (GPIO_OUTPUT << DISPLAY_7SEG_D3_PIN)
#define DISPLAY_7SEG_D3_ALT              kPortMuxAsGpio*/


/*                 END OF ATUADORES definitions                 */

#endif /* SOURCES_BOARD_H_ */
