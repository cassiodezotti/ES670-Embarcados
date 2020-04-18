/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Rodrigo M Bacurau                               */
/* Creation date:    26fev2020                                       */
/* Revision date:    02mar2020                                       */
/* ***************************************************************** */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U

/*                 LCD definitions                 */

/* LCD Register Selector
 * Used as register selector input
 * When (LCD_RS = LCD_RS_HIGH) => DATA register is selected
 * When (LCD_RS = LCD_RS_LOW)  => INSTRUCTION register is selected
*/
#define DISPLAY_7SEG_PORT_BASE_PNT       PORTC                                   /* peripheral port base pointer */
#define DISPLAY_7SEG_GPIO_BASE_PNT       PTC                                     /* peripheral gpio base pointer */

#define DISPLAY_7SEG_D1_PIN              13U                                      /* register selector */
#define DISPLAY_7SEG_D1_DIR              (GPIO_OUTPUT << DISPLAY_7SEG_D1_PIN)
#define DISPLAY_7SEG_D1_ALT              kPortMuxAsGpio

#define DISPLAY_7SEG_D2_PIN              12U                                      /* register selector */
#define DISPLAY_7SEG_D2_DIR              (GPIO_OUTPUT << DISPLAY_7SEG_D2_PIN)
#define DISPLAY_7SEG_D2_ALT              kPortMuxAsGpio

#define DISPLAY_7SEG_D3_PIN              11U                                      /* register selector */
#define DISPLAY_7SEG_D3_DIR              (GPIO_OUTPUT << DISPLAY_7SEG_D3_PIN)
#define DISPLAY_7SEG_D3_ALT              kPortMuxAsGpio

#define DISPLAY_7SEG_D4_PIN              10U                                      /* register selector */
#define DISPLAY_7SEG_D4_DIR              (GPIO_OUTPUT << DISPLAY_7SEG_D4_PIN)
#define DISPLAY_7SEG_D4_ALT              kPortMuxAsGpio

#define DISPLAY_CC_HIGH             1U

#define DISPLAY_CC_LOW              0U

#define DISPLAY_7SEG_A              0u
#define DISPLAY_7SEG_B              1u
#define DISPLAY_7SEG_C              2u
#define DISPLAY_7SEG_D              3u
#define DISPLAY_7SEG_E              4u
#define DISPLAY_7SEG_F              5u
#define DISPLAY_7SEG_G              6u
#define DISPLAY_7SEG_DP             7u

/*#define LCD_DATA_DB0_DIR            (GPIO_OUTPUT << LCD_DATA_DB0_PIN)
#define LCD_DATA_DB1_DIR            (GPIO_OUTPUT << LCD_DATA_DB1_PIN)
#define LCD_DATA_DB2_DIR            (GPIO_OUTPUT << LCD_DATA_DB2_PIN)
#define LCD_DATA_DB3_DIR            (GPIO_OUTPUT << LCD_DATA_DB3_PIN)
#define LCD_DATA_DB4_DIR            (GPIO_OUTPUT << LCD_DATA_DB4_PIN)
#define LCD_DATA_DB5_DIR            (GPIO_OUTPUT << LCD_DATA_DB5_PIN)
#define LCD_DATA_DB6_DIR            (GPIO_OUTPUT << LCD_DATA_DB6_PIN)
#define LCD_DATA_DB7_DIR            (GPIO_OUTPUT << LCD_DATA_DB7_PIN)*/
/*                 END OF LCD definitions                 */

#endif /* SOURCES_BOARD_H_ */
