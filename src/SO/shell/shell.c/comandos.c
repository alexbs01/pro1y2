//
// Created by alexb on 09/09/2022.
//

#include "comandos.h"

int autores(char *tokens[], int ntokens) {
    if(ntokens != 0) {
        if(strcmp(tokens[0], "-l") == 0) {
            printf("\nLogin: a.becerra@udc.es");
        } else if(strcmp(tokens[0], "-n") == 0) {
            printf("\nNombre: Alejandro Becerra Suarez");
        }
    } else {
        printf("\nLogin: a.becerra@udc.es");
        printf("\nNombre: Alejandro Becerra Suarez");
    }


    return 0;
}

int pid(char *tokens[], int ntokens) {
    printf("pid");
    return 0;
}

int carpeta(char *tokens[], int ntokens) {
    printf("carpeta");
    return 0;
}

int fecha(char *tokens[], int ntokens) {
    printf("fecha");
    return 0;
}

int hist(char *tokens[], int ntokens) {
    printf("hist");
    return 0;
}

int comando(char *tokens[], int ntokens) {
    printf("comando");
    return 0;
}

int infosis(char *tokens[], int ntokens) {
    printf("infosis");
    return 0;
}

int ayuda(char *tokens[], int ntokens) {
    printf("ayuda");
    return 0;
}

int fin(char *tokens[], int ntokens) {
    bye(tokens, ntokens);
    return 0;
}

int salir(char *tokens[], int ntokens) {
    bye(tokens, ntokens);
    return 0;
}

int bye(char *tokens[], int ntokens) {
    printf("bye");
    return 0;
}