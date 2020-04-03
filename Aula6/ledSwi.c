/* ***************************************************************** */
/* File name:        ledrgb.c                                        */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related RGB LED from the FRDM-KL25Z board       */
/*                   controller. REMARKS LEDS are inverted output    */
/*                                                                   */
/* Author name:      Rodrigo M Bacurau                               */
/* Creation date:    26fev2020                                       */
/* Revision date:    02mar2020                                       */
/* ***************************************************************** */

/* our includes */
#include "board.h"


/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"


/* ************************************************ */
/* Method name: 	   ledrgb_init	         		*/
/* Method description: Initialize the RGB LED device*/
/* Input params:	   n/a                          */
/* Output params:	   n/a 							*/
/* ************************************************ */
void ledSwi_init(int estados[4])
{
	unsigned char estado = 0;
	/* ligar o clock*/
	SIM_SCGC5 |= 0x0200; //Porta A

	/* set pin as gpio */
	PORTA_PCR1 |= 0X100; //pino 1 porta A
	PORTA_PCR2 |= 0X100; //pino 2 porta A
	PORTA_PCR4 |= 0X100; //pino 4 porta A
	PORTA_PCR5 |= 0X100; //pino 5 porta A
	/* Aqui percorri o vetor e shiftei o lugar que ele deveria corresponder no vetor final*/
	estado |= (estados[0] << 1);
	estado |= (estados[1] << 2);
	estado |= (estados[2] << 4);
	estado |= (estados[3] << 5);

	GPIOA_PDDR |= estado;

}

int mapeaEntrada(int valor)//como queremos que os números 1234 representem 1245 fiz essa função pra usar
{
	if(valor>2){
		valor += 1;
	}

	return valor;
}
/*função de leitura do status*/
<<<<<<< Updated upstream
int lerChave(int chave)
=======
int lerChave(int iChave)
>>>>>>> Stashed changes
{
	unsigned char chaveLida = 0;
	int valorChave = mapeaEntrada(chave);//faço o mapeamento para 1245

	chaveLida = (GPIOA_PDIR >> valorChave) & 1;//lê o bit que queremos (passado na entrada), do retorna da função de leitura da porta A
	if( '1' == chaveLida){ //talvez aqui tenha q definir esse '1' como char
		return 0;
	}
	if( '0' == chaveLida){
		return 1;
	}

}
/*função para escrita do LED*/
<<<<<<< Updated upstream
void escreverLED(int writeLed, int setClear)
=======
void escreverLED(int iWriteLed, int iSetClear)
>>>>>>> Stashed changes
{
	int ledWrite = mapeaEntrada(writeLed);//faço o mapeamento para 1245
	unsigned char numeroDeComando = 1;

<<<<<<< Updated upstream
	if(1 == setClear){//primeiro vejo se é set ou clear
=======
	if(1 == isetClear){//primeiro vejo se é set ou clear
>>>>>>> Stashed changes
		GPIOA_PDOR |= (numeroDeComando << ledWrite);//se for set dou OU com a mascara do bit q eu quero
	}
	else if(0 == setClear){
			GPIOA_PDOR &= ~(numeroDeComando << ledWrite);//se for clear dou E com a mascara de bits negada
		}

}
//função para acender LED
void setLED(int setLed)
{
	/*setar valor no pino*/
	int ledSetado = 0;
	unsigned char numeroDeComando = 1;

	ledSetado = mapeaEntrada(setLed);//faço o mapeamento para 1245
	GPIOA_PSOR |= (numeroDeComando << ledSetado);//shifto o numero de comando para a posição do led que queremos setar e mando o comando

}

//função para apagar LED
void clearLED(int clearLed)
{
	int ledClear = 0;
	unsigned char numeroDeComando = 1;

	ledClear = mapeaEntrada(clearled);//faço o mapeamento para 1245
	GPIOA_PCOR |= (numeroDeComando << ledClear);

}

/*função para mudar o status do LED*/
void toggleLED(int toggleLed)
{
	int ledToggled = 0;
	unsigned char numeroDeComando = 1;

	ledToggled = mapeaEntrada(toggleLed);
	GPIOA_PTOR |= (numeroDeComando << ledToggled);


}
