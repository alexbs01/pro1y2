//
// Created by alexb on 09/09/2022.
//

#include "funcionesAuxiliares.h"
#include "lista.h"

int splitString(char *cadena, char *trozos[]) {
    int i=1;
    if((trozos[0] = strtok(cadena, " \n\t")) == NULL) {
        return 0;
    }

    while((trozos[i] = strtok(NULL, " \n\t")) != NULL) {
        i++;
    }
    return i;
}

struct cmd {
    char *cmdName;
    int (*cmdFunction)(char *tokens[], int ntokens);
} cmds[] = {
        {"autores", autores},
        {"pid", pid},
        {"carpeta", carpeta},
        {"fecha", fecha},
        {"hist", hist},
        {"comando", comando},
        {"infosis", infosis},
        {"ayuda", ayuda},
        {"fin", fin},
        {"salir", salir},
        {"bye", bye},
        {NULL, NULL}
};

int processInput(char *tokens[], list *historial, int ntokens) {
    for(int i = 0; cmds[i].cmdName != NULL; i++) {
        if(strcmp(tokens[0], cmds[i].cmdName) == 0) {
            cmds[i].cmdFunction(tokens + 1, ntokens - 1);
            return 0;
        }
    }

    printf("Comando no encontrado");
}

