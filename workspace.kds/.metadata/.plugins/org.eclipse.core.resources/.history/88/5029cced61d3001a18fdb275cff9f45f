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

/* *************************************************** */
/* Nome da funcao:        processamentoByte            */
/* Descricao da funcao:   Funcao contendo maquina de   */
/*                        estados para o processamento */
/*                        de bytes.                    */
/*                                                     */
/* Parametros de entrada: um char representando o byte */
/*                        recebido                     */
/* Parametros de saida:   n/a                          */
/* *************************************************** */
void processamentoByte(unsigned char ucByte);

/* *************************************************** */
/* Nome da funcao:       returnParam                   */
/* Descricao da funcao:  Funcaco para retornar a       */
/*                       resposta solicitada por um    */
/*                       comando get                   */
/*                                                     */
/* Parametros de entrada: um char podendo ser 't' para */
/*                        temperatura, 'a' para duty   */
/*                        cycle do aquecedor ou 'c'    */
/*                        para o duty cycle do cooler  */
/* Parametros de saida:   n/a                          */
/* *************************************************** */
void returnParam(unsigned char ucParam);

/* *************************************************** */
/* Nome da funcao:        setParam                     */
/* Descricao da funcao:   Funcao para setar parametros */
/*                                                     */
/* Parametros de entrada: recebe um vetor de char com  */
/*                        o valor para o set, e um     */
/*                        char escolhendo o parametro  */
/*                        a ser alterado, 't' para     */
/*                        temperatura e 'e' para       */
/*                        habilitar ou desabilitar a   */
/*                        interface local              */
/* Parametros de saida:   n/a                          */
/* *************************************************** */
void setParam(unsigned char ucParam,unsigned char ucValue[MAX_VALUE_LENGHT]);

/* **************************************************** */
/* Nome da funcao:        lerTemp                       */
/* Descricao da funcao:   Funcao para ler temperatura   */
/*                        sera reformulada nas proximas */
/*                        etapas                        */
/*                                                      */
/* Parametros de entrada: n/a                           */
/* Parametros de saida:   n/a                           */
/* **************************************************** */
void lerTemp();

/* **************************************************** */
/* Nome da funcao:        heater_PWMDuty                */
/* Descricao da funcao:   Funcao para ler duty cycle do */
/*                        aquecedor, sera reformulada   */
/*                        nas proximas etapas           */
/*                                                      */
/* Parametros de entrada: n/a                           */
/* Parametros de saida:   n/a                           */
/* **************************************************** */
void lerHeaterDuty();

/* **************************************************** */
/* Nome da funcao:        coolerFan_PWMDuty             */
/* Descricao da funcao:   Funcao para ler duty cycle do */
/*                        cooler, sera reformulada nas  */
/*                        proximas etapas               */
/*                                                      */
/* Parametros de entrada: n/a                           */
/* Parametros de saida:   n/a                           */
/* **************************************************** */
void lerCoolerFanDuty();

/* ******************************************************* */
/* Nome da funcao:        convertChar2Float                */
/* Descricao da funcao:   Funcao que converte 4 caracteres */
/*                        para um valor float              */
/* Parametros de entrada: caracter                         */
/* Parametros de saida:   valor float                      */
/* ******************************************************* */
float convertChar2Float(unsigned char ucReceivedChar);

/* ******************************************************** */
/* Nome da funcao:         convertInt2Char                  */
/* Descricao da funcao:    Funcao que converte um valor int */
/*                         para um valor de 4 caracteres    */
/* Paramentros de entrada: valor int                        */
/* Parametros de saida:    caracter                         */
/* ******************************************************** */
unsigned char* convertInt2Char(int ucReceivedInt);

/* ******************************************************* */
/* Nome da funcao:        convertChar2Int                  */
/* Descricao da funcao:   Funcao que converte 4 caracteres */
/*                        para um valor int                */
/* Parametros de entrada: caracter                         */
/* Parametros de saida:   valor int                        */
/* ******************************************************* */
int convertChar2Int(unsigned char ucReceivedChar);

/* ********************************************************* */
/* Nome da funcao:        convertFloat2Char                  */
/* Descricao da funcao:   Funcao que converte um valor float */
/*                        para um valor de 4 caracteres      */
/* Parametros de entrada: valor float                        */
/* Parametros de saida:   n/a                                */
/* ********************************************************* */
unsigned char* convertFloat2Char(float fReceivedFloat);

/* ***************************************************** */
/* Nome da funcao:        lerKp                          */
/* Descricao da funcao:   Funcao para ler o KP setado no */
/*                        controlador                    */
/*                                                       */
/* Parametros de entrada: n/a                            */
/* Parametros de saida:   n/a                            */
/* ***************************************************** */
void lerKp();

/* ***************************************************** */
/* Nome da funcao:        lerKi                          */
/* Descricao da funcao:   Funcao para ler o KI setado no */
/*                        controlador                    */
/*                                                       */
/* Parametros de entrada: n/a                            */
/* Parametros de saida:   n/a                            */
/* ***************************************************** */
void lerKi();

/* ***************************************************** */
/* Nome da funcao:        lerKd                          */
/* Descricao da funcao:   Funcao para ler o KD setado no */
/*                        controlador                    */
/*                                                       */
/* Parametros de entrada: n/a                            */
/* Parametros de saida:   n/a                            */
/* ***************************************************** */
void lerKd();

#endif /* COMMUNICATION_STATE_MACHINE_H_ */
