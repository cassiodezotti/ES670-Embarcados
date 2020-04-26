/* ************************************************************************ */
/* Nome do Arquivo:      aquecedorECooler.h                                 */
/* Descri��o do arquivo: Este arquivo � dedicado a apresentar todas as      */
/*                       fun��es utilizadas no programa                     */
/*                                                                          */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                      */
/* RA:                   174217/168988                                      */
/* Data de cria��o:      24abril2020                                        */
/* Data da revis�o:      26abril2020                                        */
/* ************************************************************************ */

#ifndef SOURCES_AQUECEDORECOOLER_H_
#define SOURCES_AQUECEDORECOOLER_H_

/* *********************************************************************  */
/* Nome da fun��o: PWM_init                                               */
/* Descri��o da fun��o: Essa fun��o inicializa o PWM e os par�metros      */
/*                      necess�rios como o clock e contador.              */
/* Par�metros de entrada:    n/a                                          */
/* Par�metros de sa�da:      n/a                                          */
/* *********************************************************************  */
void PWM_init();

/* ******************************************************************** */
/* Nome da fun��o: coolerfan_init                                       */
/* Descri��o da fun��o: Fun��o que habilita o clock, a porta do atuador */
/*                      e configura o pino 13 como PWM                  */
/*                                                                      */
/* Par�metros de entrada: n/a                                           */
/* Par�metros de sa�da:   n/a                                           */
/* ******************************************************************** */
void coolerfan_init();

/* ******************************************************************** */
/* Nome da fun��o: heater_init                                          */
/* Descri��o da fun��o: Fun��o que habilita o clock, a porta do atuador */
/*                      e configura o pino 12 como PWM                  */
/*                                                                      */
/* Par�metros de entrada: n/a                                           */
/* Par�metros de sa�da:   n/a                                           */
/* ******************************************************************** */
void heater_init();

/* ************************************************************************* */
/* Nome da fun��o: coolerfan_PWMDuty                                         */
/* Descri��o da fun��o:  Recebe um numero que corresponde ao Duty Cycle      */
/*                       desejado para o cooler e altera o Duty Cycle do PWM */
/*                                                                           */
/* Par�metros de entrada: Recebe um float entre 0 e 1                        */
/* Par�metros de sa�da:   n/a                                                */
/* ************************************************************************* */
void coolerfan_PWMDuty(float fCoolerDuty);

/* **************************************************************************** */
/* Nome da fun��o: heater_PWMDuty                                               */
/* Descri��o da fun��o:  Recebe um numero que corresponde ao Duty Cycle         */
/*                       desejado para o aquecedor e altera o Duty Cycle do PWM */
/*                                                                              */
/* Par�metros de entrada: Recebe um float entre 0 e 1                           */
/* Par�metros de sa�da:   n/a                                                   */
/* **************************************************************************** */
void heater_PWMDuty(float fHeaterDuty);

/* ******************************************************************* */
/* Nome da fun��o: convertDuty                                         */
/* Descri��o da fun��o: Fun��o de apoio recebe o valor do Duty Cycle   */
/*                      e converte para um numero de 16 bits           */
/*                                                                     */
/* Par�metros de entrada: Recebe um float entre 0 e 1                  */
/* Par�metros de sa�da:   Retorna um unsigned char com o valor do Duty */
/*                        Cycle nos primeiros 16 bits                  */
/* ******************************************************************* */
unsigned char convertDuty(float duty);

#endif /* SOURCES_AQUECEDORECOOLER_H_ */
