/* ******************************************************************** */
/* Nome do Arquivo:      aquecedorECooler.h                             */
/* Descricao do arquivo: Este arquivo eh dedicado a apresentar todas as */
/*                       funcoes utilizadas no programa                 */
/* Nome dos autores:     Gustavo Moraes/Cassio Dezotti                  */
/* RA:                   174217/168988                                  */
/* Data de criacao:      24abril2020                                    */
/* Data da revisao:      26abril2020                                    */
/* ******************************************************************** */

#ifndef SOURCES_AQUECEDORECOOLER_H_
#define SOURCES_AQUECEDORECOOLER_H_

/* ******************************************************************* */
/* Nome da funcao:        PWM_init                                     */
/* Descricao da funcao:   Essa função inicializa o PWM e os parâmetros */
/*                        necessários como o clock e contador.         */
/*                                                                     */
/* Parametros de entrada: n/a                                          */
/* Parametros de saida:   n/a                                          */
/* ******************************************************************* */
void PWM_init();

/* ********************************************************************** */
/* Nome da funcao:        coolerfan_init                                  */
/* Descricao da funcao:   Função que habilita o clock, a porta do atuador */
/*                        e configura o pino como PWM                     */
/*                                                                        */
/* Parametros de entrada: n/a                                             */
/* Parametros de saida:   n/a                                             */
/* ********************************************************************** */
void coolerfan_init();

/* ********************************************************************** */
/* Nome da funcao:        heater_init                                     */
/* Descricao da função:   Função que habilita o clock, a porta do atuador */
/*                        e configura o pino 12 como PWM                  */
/*                                                                        */
/* Parametros de entrada: n/a                                             */
/* Parametros de saida:   n/a                                             */
/* ********************************************************************** */
void heater_init();

/* ************************************************************************** */
/* Nome da funcao:        definirDutyC                                        */
/* Descricao da funcao:   Recebe um numero que corresponde ao Duty Cycle      */
/*                        desejado para o cooler e altera o Duty Cycle do PWM */
/*                                                                            */
/* Parametros de entrada: Recebe um float entre 0 e 1                         */
/* Parametros de saida:   n/a                                                 */
/* ************************************************************************** */
void definirDutyC(float fCoolerDuty);

/* ***************************************************************************** */
/* Nome da funcao:        definirDutyH                                           */
/* Descricao da funcao:   Recebe um numero que corresponde ao Duty Cycle         */
/*                        desejado para o aquecedor e altera o Duty Cycle do PWM */
/*                                                                               */
/* Parametros de entrada: Recebe um float entre 0 e 1                            */
/* Parametros de saida:   n/a                                                    */
/* ***************************************************************************** */
void definirDutyH(float fHeaterDuty);

/* ******************************************************************* */
/* Nome da funcao:        convertDuty                                  */
/* Descricao da funcao:   Função de apoio recebe o valor do Duty Cycle */
/*                        e converte para um numero de 16 bits         */
/*                                                                     */
/* Parametros de entrada: Recebe um float entre 0 e 1                  */
/* Parametros de saida:   Retorna um unsigned char com o valor do Duty */
/*                        Cycle nos primeiros 16 bits                  */
/* ******************************************************************* */
unsigned char convertDuty(float duty);

#endif /* SOURCES_AQUECEDORECOOLER_H_ */
