//
// Created by alexb on 28/08/2022.
//

#include "dinamicaPilaEnlazada.h"

#include <stdlib.h>

bool isEmptyStack(tStack S) {
    return (S == SNULL);
}

void createEmptyStack(tStack *S) {
    *S = SNULL;
}

bool createNode(tPosS *p) {
    *p = malloc(sizeof(struct tNodeS));
    return (*p != SNULL);
}

bool push(tItemS d, tStack *S) {
    // aux -> elemento que se insertará
    tPosS aux;

    if(!(createNode(&aux))) { // Comprueba si puede insertar un nodo en la pila, si no puede retorna false
        return false;
    } else {
        aux->data = d;  // En el campo data se inserta el item d
        aux->down = *S; // El campo down apuntará al último elemento insertado, porque ahora este es el primero de la pila
        *S = aux;       // Y ahora el puntero *S, deberá apuntar a este último elemento llamado aux
        return true;
    }
}

void pop(tStack *S) {
    // aux -> elemento que se quitará de la pila
    tPosS aux;

    aux = *S;
    *S = (*S)->down; // El puntero que apunta a la pila, lo bajamos al siguiente elemento
    free(aux); // El elemento que queda por encima lo eliminamos, el último en añadirse, lo eliminamos
}

tItemS peek(tStack S) { // Obtenemos el campo data del último elemento añadido a la pila
    return S->data;
}
