//
// Created by alexb on 09/09/2022.
//

#ifndef SHELL_C_FUNCIONESAUXILIARES_H
#define SHELL_C_FUNCIONESAUXILIARES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // strdup para el historial, es un strcpy pero con malloc incluido

#include "comandos.h"
#include "lista.h"

int splitString(char *cadena, char *trozos[]);
int processInput(char *tokens[], list *historial, int ntokens);

#endif //SHELL_C_FUNCIONESAUXILIARES_H