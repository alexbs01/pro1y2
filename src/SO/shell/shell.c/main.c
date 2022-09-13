#include <stdio.h>
#include "funcionesAuxiliares.h"
#include "lista.h"

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_TOKENS];

    list historial;
    createEmptyList(&historial);

    while(1) {
        printf("\n> ");
        fgets(input, MAX_INPUT_SIZE, stdin); // stdin es para que lea del teclado, pero fgets tambien vale para ficheros
        splitString(input, tokens);
        processInput(tokens, &historial);
        //printf("\n%s ", input);

        }
    return 0;
}
