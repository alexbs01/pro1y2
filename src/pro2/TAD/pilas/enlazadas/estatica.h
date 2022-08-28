//
// Created by alexb on 28/08/2022.
//

#ifndef TAD_ESTATICA_H
#define TAD_ESTATICA_H

#include <stdbool.h>

/* Definición de tipos de datos */
#define SNULL -1
#define SMAX 10 // Número máximo de elementos en la pila

typedef int tItemS;

typedef int tPosS;

typedef struct Stack {
    tItemS data[SMAX];
    tPosS top;
} tStack;

/* Cabeceras
 * S -> Pila
 * p -> posición o nodo de la pila
 */
bool isEmptyStack(tStack S);
void createEmptyStack(tStack *S);
bool push(tItemS d, tStack *S);
void pop(tStack *S);
tItemS peek(tStack S);

#endif //TAD_ESTATICA_H
