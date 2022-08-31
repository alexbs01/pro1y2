//
// Created by alexb on 20/08/2022.
//

#include "estaticaListaEnlazada.h"

bool isEmptyList(tList L) {
    // Si una lista estática está vacía, el puntero que apunta a la última posición debe ser LNULL
    return L.lastPos == LNULL;
}

void createEmptyList(tList *L) {
    L->lastPos = LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    /* i -> Iterador que moverá todos los elementos una posición más adelante en caso de que se inserte el elemento
     * por el medio de la lista, este comenzará desde el final e irá hasta la posición en la que lo querramos añadir */
    tPosL i;
    bool isInserted;

    if(L->lastPos == MAX - 1) { // Comprueba si la lista está llena
        isInserted = false;
    } else {
        L->lastPos++; // Como estamos insertando un elemento, al tamaño del array aumenta en 1

        if(p == LNULL) { // Si se quiere insertar en la última posición
            L->data[L->lastPos] = d;

        } else { // Si se quiere insertar en primera posición o cualquier otra intermedia
            // Desplazamos todos los elementos una posición más adelante en el array
            for(i = L->lastPos; i > p; i--) {
                L->data[i] = L->data[i - 1];
            }

            L->data[p] = d;
        }

        isInserted = true;
    }
    return isInserted;
}

bool copyList(tList L, tList *M) { // Copiar la lista de un array en otro
    tPosL p;

    createEmptyList(M);

    for(p = 0; p <= L.lastPos; p++) { // Desde la primera posición de L hasta la última
        M->data[p] = L.data[p]; // Iremos igualando el campo data de cada elemento
    }

    M->lastPos = L.lastPos; // Como son dos listas idénticas, la última posición será la misma en ambas

    return true;
}

void updateItem(tItemL d, tPosL p, tList *L) {
    L->data[p] = d;
}

tPosL findItem(tItemL d, tList L) {
    // p -> el iterador que buscará el elemento deseado
    tPosL p;

    if(isEmptyList(L)) {
        return LNULL;
    } else {
        for(p = 0; (p < L.lastPos) && (L.data[p] != d); p++);

        if(L.data[p] == d) {
            return p;
        } else {
            return LNULL;
        }
    }

}

tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}

tPosL first(tList L) {
    return 0; // Como una list estática es un array, la primera posición siempre será la 0
}

tPosL last(tList L) {
    return L.lastPos;
}

tPosL previous(tPosL p, tList L) {
    return --p;
}

tPosL next(tPosL p, tList L) {
    if (p == L.lastPos) {
        return LNULL;
    } else {
        return ++p;
    }
}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL i;

    L->lastPos--; // Como estamos eliminando un elemento, estamos reduciendo el tamaño del array, por eso se resta 1

    for(i = p; i <= L->lastPos; i++) {
        /* Todos los elementos posteriores al eliminado, se desplazan una posición a la izquierda para evitar
         * dejar huecos libres en el array */
        L->data[i] = L->data[i + 1];
    }

}

void deleteList(tList *L) {
    L->lastPos = LNULL;
}