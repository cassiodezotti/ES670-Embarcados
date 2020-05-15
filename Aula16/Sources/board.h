/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Rodrigo M Bacurau/Gustavo M./Cassio D.          */
/* Creation date:    26fev2020                                       */
/* Revision date:    10maio2020                                       */
/* ***************************************************************** */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/*                 ATUADORES definitions                 */

#define COOLER_PORT_BASE_PNT           PORTA                                   /* peripheral port base pointer */
#define COOLER_PWM_BASE_PNT            PTA                                     /* peripheral gpio base pointer */

#define COOLER_PIN                     13U                                      /* register selector */


#define ENCODER_PORT_BASE_PNT           PORTE                                   /* peripheral port base pointer */
#define ENCODER_PWM_BASE_PNT            PTE                                     /* peripheral gpio base pointer */

#define ENCODER_PIN                     29U                                      /* register selector */

/*                 END OF ATUADORES definitions                 */

#endif /* SOURCES_BOARD_H_ */
