/* *************************************************************************** */
/* Nome do Arquivo:      communicationStateMachine.c                           */
/* Descricao do arquivo: Contêm a descrição das funções utilizadas no programa */
/* Nome dos autores:     Gustavo M./Cassio D.                                  */
/* RA:                   174217/168988                                         */
/* Data de criacao:      03jun2020                                             */
/* Data da revisao:      09jun2020                                             */
/* *************************************************************************** */

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
void returnParam(unsigned char ucParam);

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
void setParam(unsigned char ucParam,unsigned char ucValue[MAX_VALUE_LENGHT]);

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
/* Method name:        lerHeaterDuty                */
/* Method description: Funcao para ler duty cycle do */
/*                     aquecedor, sera reformulada   */
/*                     nas proximas etapas           */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerHeaterDuty();

/* ************************************************* */
/* Method name:        lerCoolerFanDuty             */
/* Method description: Funcao para ler duty cycle do */
/*                     cooler, sera reformulada nas  */
/*                     proximas etapas               */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerCoolerFanDuty();

/* **************************************************** */
/* Method name:        convertChar2Float                */
/* Method description: Funcao que converte 4 caracteres */
/*                     para um valor float              */
/* Input params:       caracter                         */
/* Output params:      valor float                      */
/* **************************************************** */
float convertChar2Float(unsigned char ucReceivedChar);

/* **************************************************** */
/* Method name:        convertInt2Char                  */
/* Method description: Funcao que converte um valor int */
/*                     para um valor de 4 caracteres    */
/* Input params:       valor int                        */
/* Output params:      n/a                              */
/* **************************************************** */
unsigned char* convertInt2Char(int ucReceivedInt);

/* **************************************************** */
/* Method name:        convertChar2Float                */
/* Method description: Funcao que converte 4 caracteres */
/*                     para um valor float              */
/* Input params:       caracter                         */
/* Output params:      valor float                      */
/* **************************************************** */
int convertChar2Int(unsigned char ucReceivedChar);

/* **************************************************** */
/* Method name:        convertChar2Float                */
/* Method description: Funcao que converte 4 caracteres */
/*                     para um valor float              */
/* Input params:       caracter                         */
/* Output params:      valor float                      */
/* **************************************************** */
unsigned char* convertFloat2Char(float fReceivedFloat);

/* ************************************************* */
/* Method name:        lerKp                         */
/* Method description: Funcao para ler duty cycle do */
/*                     cooler, sera reformulada nas  */
/*                     proximas etapas               */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerKp();

/* ************************************************* */
/* Method name:        lerKi                        */
/* Method description: Funcao para ler duty cycle do */
/*                     cooler, sera reformulada nas  */
/*                     proximas etapas               */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerKi();

/* ************************************************* */
/* Method name:        lerKd                         */
/* Method description: Funcao para ler duty cycle do */
/*                     cooler, sera reformulada nas  */
/*                     proximas etapas               */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************* */
void lerKd();

#endif /* COMMUNICATION_STATE_MACHINE_H_ */
