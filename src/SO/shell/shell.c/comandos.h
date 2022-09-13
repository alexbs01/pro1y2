//
// Created by alexb on 09/09/2022.
//

#ifndef SHELL_C_COMANDOS_H
#define SHELL_C_COMANDOS_H

#include <stdio.h>
#include <stdlib.h>
#include "funcionesAuxiliares.h"

int autores(char *tokens[]);
int pid(char *tokens[]);
int carpeta(char *tokens[]);
int fecha(char *tokens[]);
int hist(char *tokens[]);
int comando(char *tokens[]);
int infosis(char *tokens[]);
int ayuda(char *tokens[]);
int fin(char *tokens[]);
int salir(char *tokens[]);
int bye(char *tokens[]);


#endif //SHELL_C_COMANDOS_H
