//
// Created by alexb on 09/09/2022.
//

#include "comandos.h"

int autores(char *tokens[]) {
    printf("autores");
    if(strcmp(tokens[0], "-l") == 0) {
        printf("\nLogin: a.becerra@udc.es");
    } else if(strcmp(tokens[0], "-n") == 0) {
        printf("\nNombre: Alejandro Becerra Suarez");
    } else {
        printf("\nLogin: a.becerra@udc.es");
        printf("\nNombre: Alejandro Becerra Suarez");
    }

    return 0;
}

int pid(char *tokens[]) {
    printf("pid");
    return 0;
}

int carpeta(char *tokens[]) {
    printf("carpeta");
    return 0;
}

int fecha(char *tokens[]) {
    printf("fecha");
    return 0;
}

int hist(char *tokens[]) {
    printf("hist");
    return 0;
}

int comando(char *tokens[]) {
    printf("comando");
    return 0;
}

int infosis(char *tokens[]) {
    printf("infosis");
    return 0;
}

int ayuda(char *tokens[]) {
    printf("ayuda");
    return 0;
}

int fin(char *tokens[]) {
    bye(tokens);
    return 0;
}

int salir(char *tokens[]) {
    bye(tokens);
    return 0;
}

int bye(char *tokens[]) {
    printf("bye");
    return 0;
}