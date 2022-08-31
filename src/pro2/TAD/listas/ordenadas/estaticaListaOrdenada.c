//
// Created by alexb on 23/08/2022.
//

#include "estaticaListaOrdenada.h"

bool isEmptyList(tList L) {
    return L.lastPos == LNULL;
}

void createEmptyList(tList *L) {
    L->lastPos = LNULL;
}

bool insertItem(tItemL d, tList *L) {
    tPosL i;
    bool isInserted;

    if(L->lastPos == MAX - 1) { // Comprueba si la lista está llena o no, como es estática hay un límite de elementos
        isInserted = false;
    } else {
        if(isEmptyList(*L) || d > L->data[L->lastPos]) { // Inserta al final de la lista
            L->lastPos++;
            L->data[L->lastPos] = d;
        } else { // Si es en primera posición o en cualquier otra
            L->lastPos++;
            for(i = L->lastPos; (i > 0) && (d < L->data[i - 1]); i--) {
                L->data[i] = L->data[i - 1]; // Desplaza los elementos una posición más adelante
            }
            L->data[i] = d; // Inserta el elemento en la posición deseada
        }
        isInserted = true;
    }
    return isInserted;
}

bool copyList(tList L, tList *M) {
    tPosL p;

    createEmptyList(M);

    for(p = 0; p <= L.lastPos; p++) { // Copia los elementos de una lista a otra
        M->data[p] = L.data[p];
    }

    M->lastPos = L.lastPos;
    return true;
}

void updateItem(tItemL d, tPosL p, tList *L) {
    L->data[p] = d;
}

tPosL findItem(tItemL d, tList L) {
    tPosL p;

    if(isEmptyList(L)) { // Si la lista está vacía no puede haber el elemento buscado, por lo tanto devuelve LNULL
        return LNULL;

    } else if((d < L.data[0]) || (d > L.data[L.lastPos])) { // Comprueba si el item no está en la lista
        // Si el item está en la lista deberá tener un ".data[i]" con 0 <= i <= lastPos
        return LNULL;

    } else {
        // Hace iteraciones mientras haya lista y no se pase del elemento
        for(p = 0; (p < L.lastPos) && (L.data[p] < d); p++);
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
    return 0;
}

tPosL last(tList L) {
    return L.lastPos;
}

tPosL previous(tPosL p, tList L) {
    return --p;
}

tPosL next(tPosL p, tList L) {
    if(p == L.lastPos) {
        return LNULL;
    } else {
        return ++p;
    }
}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL i;

    L->lastPos--;
    // Se desplazan todos los elementos una posición más atrás a partir del elemento que queríamos eliminar
    for(i = p; i <= L->lastPos; i++) {
        L->data[i] = L->data[i + 1];
    }
}

void deleteList(tList *L) {
    L->lastPos = LNULL;
}