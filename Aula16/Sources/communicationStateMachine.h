/* *********************************************************************** */
/* File name:        communicationStateMachine.c                           */
/* File description: Contêm a descrição das funções utilizadas no programa */
/* Author name:      Gustavo M./Cassio D.                                  */
/* Creation date:    22mai2020                                             */
/* Revision date:    24mai2020                                             */
/* *********************************************************************** */

#ifndef COMMUNICATION_STATE_MACHINE_H_
#define COMMUNICATION_STATE_MACHINE_H_


#define MAX_VALUE_LENGHT 7

/* ************************************************ */
/* Method name:        processamentoByte            */
/* Method description: Funcao contendo maquina de   */
/*                     estados para o processamento */
/*                     de bytes.                    */
/* Input params:       um char representando o byte */
/*                     recebido                     */
/* Output params:      n/a                          */
/* ************************************************ */
void processamentoByte(unsigned char ucByte);

/* ************************************************ */
/* Method name:        returnPARAM                  */
/* Method description: Funcaco para retornar a      */
/*                     resposta solicitada por um   */
/*                     comando get                  */
/* Input params:       um char podendo ser 't' para */
/*                     temperatura, 'a' para duty   */
/*                     cycle do aquecedor ou 'c'    */
/*                     para o duty cycle do cooler  */
/* Output params:      n/a                          */
/* ************************************************ */
void returnPARAM(unsigned char ucPARAM);

/* ************************************************ */
/* Method name:        setPARAM                     */
/* Method description: Funcao para setar parametros */
/*                                                  */
/* Input params:       recebe um vetor de char com  */
/*                     o valor para o set, e um     */
/*                     char escolhendo o parametro  */
/*                     a ser alterado, 't' para     */
/*                     temperatura e 'e' para       */
/*                     habilitar ou desabilitar a   */
/*                     interface local              */
/* Output params:      n/a                          */
/* ************************************************ */
void setPARAM(unsigned char ucPARAM,unsigned char ucValue[MAX_VALUE_LENGHT+1]);

/* ************************************************* */
/* Method name:        lerTemp                       */
/* Method description: Funcao para ler temperatura   */
/*                     sera reformulada nas proximas */
/*                     etapas                        */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerTemp();

/* ************************************************* */
/* Method name:        heater_PWMDuty                */
/* Method description: Funcao para ler duty cycle do */
/*                     aquecedor, sera reformulada   */
/*                     nas proximas etapas           */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void heater_PWMDuty();

/* ************************************************* */
/* Method name:        coolerFan_PWMDuty             */
/* Method description: Funcao para ler duty cycle do */
/*                     cooler, sera reformulada nas  */
/*                     proximas etapas               */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void coolerFan_PWMDuty();

#endif /* UART_H_ */
