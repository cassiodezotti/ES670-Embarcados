/* ******************************************************************** */
/* Nome do Arquivo:        ledSwi.h                                     */
/* Descrição do arquivo: Este arquivo contem funções para inicialização */
/*                   	 e utilização dos leds e botões do kit.         */
/*                                                                      */
/*                                                                      */
/* Author name:      Gustavo Moraes/Cassio Dezotti                      */
/* RA:               174217/168988                                      */
/* Creation date:    26mar2020                                          */
/* Revision date:    04abril2020                                        */
/* ******************************************************************** */

/* our includes */
#include "board.h"


/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"


void iniciarLedSwi(int iEstados[4])
{
	unsigned char ucEstado = 0;
	/* ligar o clock da porta A*/
	SIM_SCGC5 |= 0x0200;

	/* seta os pinos 1 2 4 5 como gpio */
	PORTA_PCR1 |= 0X100;
	PORTA_PCR2 |= 0X100;
	PORTA_PCR4 |= 0X100;
	PORTA_PCR5 |= 0X100;
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
