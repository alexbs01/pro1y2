//
// Created by alexb on 09/09/2022.
//

#ifndef SHELL_C_COMANDOS_H
#define SHELL_C_COMANDOS_H

#include <stdio.h>
#include <stdlib.h>
#include "funcionesAuxiliares.h"

int autores(char *tokens[], int ntokens);
int pid(char *tokens[], int ntokens);
int carpeta(char *tokens[], int ntokens);
int fecha(char *tokens[], int ntokens);
int hist(char *tokens[], int ntokens);
int comando(char *tokens[], int ntokens);
int infosis(char *tokens[], int ntokens);
int ayuda(char *tokens[], int ntokens);
int fin(char *tokens[], int ntokens);
int salir(char *tokens[], int ntokens);
int bye(char *tokens[], int ntokens);


#endif //SHELL_C_COMANDOS_H
