//
// Created by alexb on 28/08/2022.
//

#ifndef TAD_DINAMICA_H
#define TAD_DINAMICA_H

#include <stdbool.h>
#include <stdlib.h>

/* Definición de tipos de datos */
#define SNULL NULL

typedef int tItemS;

typedef struct tNodeS *tPosS;

struct tNodeS {
    tItemS data;
    tPosS down;
};

typedef tPosS tStack;

/* Cabeceras
 * S -> Pila
 * p -> posición o nodo de la pila
 */
bool isEmptyStack(tStack S);
void createEmptyStack(tStack *S);
bool createNode(tPosS *p);
bool push(tItemS d, tStack *S);
void pop(tStack *S);
tItemS peek(tStack S);

#endif //TAD_DINAMICA_H
