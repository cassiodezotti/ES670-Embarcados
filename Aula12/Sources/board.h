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
#define THERMOMETER_PORT_BASE_PNT       PORTE
#define THERMOMETER_GPIO_BASE_PNT       PTE

#define THERMOMETER_PIN                 21U
#define THERMOMETER_DIR                 (GPIO_INPUT << THERMOMETER_PIN)
#define THERMOMETER_ALT                 0x00U

#define ATUADORES_PORT_BASE_PNT          PORTA                                   /* peripheral port base pointer */
#define ATUADORES_PWM_BASE_PNT           PTA                                     /* peripheral gpio base pointer */

#define COOLER_PIN                       13U                                      /* register selector */
/*#define COOLER_DIR                       (GPIO_OUTPUT << COOLER_PIN)
#define COOLER_ALT                       kPortMuxAsGpio*/

#define AQUECEDOR_PIN                    12U                                      /* register selector */
/*#define DISPLAY_7SEG_D3_DIR              (GPIO_OUTPUT << DISPLAY_7SEG_D3_PIN)
#define DISPLAY_7SEG_D3_ALT              kPortMuxAsGpio*/

#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/*                 END OF ATUADORES definitions                 */


/* LCD Register Selector
 * Used as register selector input
 * When (LCD_RS = LCD_RS_HIGH) => DATA register is selected
 * When (LCD_RS = LCD_RS_LOW)  => INSTRUCTION register is selected
*/
#define LCD_PORT_BASE_PNT           PORTC                                   /* peripheral port base pointer */
#define LCD_GPIO_BASE_PNT           PTC                                     /* peripheral gpio base pointer */

#define LCD_RS_PIN                  8U                                      /* register selector */
#define LCD_RS_DIR                  (GPIO_OUTPUT << LCD_RS_PIN)
#define LCD_RS_ALT                  kPortMuxAsGpio

#define LCD_ENABLE_PIN              9U                                      /* enable pin */
#define LCD_ENABLE_DIR              (GPIO_OUTPUT << LCD_ENABLE_PIN)
#define LCD_ENABLE_ALT              kPortMuxAsGpio

#define LCD_RS_HIGH                 1U
#define LCD_RS_DATA                 LCD_RS_HIGH

#define LCD_RS_LOW                  0U
#define LCD_RS_CMD                  LCD_RS_LOW

#define LCD_ENABLED                 1U
#define LCD_DISABLED                0U

#define LCD_DATA_DIR                kGpioDigitalOutput                      /* LCD data pins */
#define LCD_DATA_ALT                kPortMuxAsGpio

#define LCD_DATA_DB0_PIN            0u
#define LCD_DATA_DB1_PIN            1u
#define LCD_DATA_DB2_PIN            2u
#define LCD_DATA_DB3_PIN            3U
#define LCD_DATA_DB4_PIN            4U
#define LCD_DATA_DB5_PIN            5U
#define LCD_DATA_DB6_PIN            6U
#define LCD_DATA_DB7_PIN            7U

#define LCD_DATA_DB0_DIR            (GPIO_OUTPUT << LCD_DATA_DB0_PIN)
#define LCD_DATA_DB1_DIR            (GPIO_OUTPUT << LCD_DATA_DB1_PIN)
#define LCD_DATA_DB2_DIR            (GPIO_OUTPUT << LCD_DATA_DB2_PIN)
#define LCD_DATA_DB3_DIR            (GPIO_OUTPUT << LCD_DATA_DB3_PIN)
#define LCD_DATA_DB4_DIR            (GPIO_OUTPUT << LCD_DATA_DB4_PIN)
#define LCD_DATA_DB5_DIR            (GPIO_OUTPUT << LCD_DATA_DB5_PIN)
#define LCD_DATA_DB6_DIR            (GPIO_OUTPUT << LCD_DATA_DB6_PIN)
#define LCD_DATA_DB7_DIR            (GPIO_OUTPUT << LCD_DATA_DB7_PIN)
/*                 END OF LCD definitions                 */


/*                 UART definitions                 */

#define BOARD_DEBUG_UART_INSTANCE   0
#define BOARD_DEBUG_UART_BASEADDR   UART0
#define BOARD_DEBUG_UART_BAUD       115200

#define UART_PORT                   PORTA
#define UART_ALT                    kPortMuxAlt2
#define UART_PIN_1                  1u
#define UART_PIN_2                  2u

/*                 END OF UART definitions                 */

#endif /* SOURCES_BOARD_H_ */
