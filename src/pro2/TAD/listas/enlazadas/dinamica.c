//
// Created by alexb on 20/08/2022.
//

#include "dinamica.h"

#include <stdlib.h>

void createEmptyList(tList *L) {
    *L = LNULL;
}

bool isEmptyList(tList L) {
    return (L == LNULL);
}

bool createNode(tPosL *p) {
    *p = malloc(sizeof(struct tNode));
    return *p != LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    /*
     * q -> Elemento de la lista a añadir
     * r -> Elemento auxiliar que se usará en el bucle
     */
    tPosL q, r;

    if(!createNode(&q)) {
        return false;
    }
    else {
        q->data = d;
        q->next = LNULL;

        /* Si la lista está vacía, se añadirá el elemento a la primera posición y el puntero de
         * la lista L, apuntará a este primer nodo */
        if (isEmptyList(*L)) {
            *L = q;
        }

        //Si la posición recibida por la función es NULL, se añadirá como último elemento de la lista
        else if(p == LNULL) {
            for(r = *L; r->next != LNULL; r = r->next); // Nos desplazamos al último elemento de la lista
            // El bucle FOR se hace sin las llaves porque solo nos interesa que llegue al último nodo
            r->next = q;
        }

        /* Si la posición recibida es idéntica al valor al que apunta *L, es porque hay que añadir este elemento
         en la primera posición de la lista */
        else if(p == *L) {
            q->next = p;
            *L = q;
        }

        // Si no se cumple ninguna de las otras condiciones, es que se debe insertar en una posición intermedia
        else { // Se realizan intercambios de valores para evitar hacer un bucle
            q->data = p->data;
            p->data = d;
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}

void updateItem(tItemL d, tPosL p, tList *L) {
    p->data = d;
}

tPosL findItem(tItemL d, tList L) {
    tPosL p;

    for(p = L; (p != LNULL) && (p->data != d); p = p->next);
    return p;
}

tItemL getItem(tPosL p, tList L) {
    return p->data;
}

tPosL first(tList L) {
    return L; // L siempre apunta al primer elemento de la lista
}

tPosL last(tList L) {
    tPosL p;

    for(p = L; p->next != LNULL; p = p->next);
    return p;
}

tPosL previous(tPosL p, tList L) {
    tPosL q; // q es el elemento previo

    if(p == L) {
        return LNULL;
    }
    else {
        for(q = L; q->next != p; q = q->next);
        // Mientras el siguiente elemento a q sea distinto al introducido, se seguirá ejecutando el bucle
        return q;
    }
}

tPosL next(tPosL p, tList L) {
    return p->next;
}

void deleteAtPosition(tPosL p, tList *L) {
    /* p elemento a eliminar
     * q elemento siguiente al eliminado */
    tPosL q;

    if(p == *L) { // Eliminado en la primera posición de la lista
        *L = (*L)->next;

    } else if(p->next == LNULL) { // Eliminado en la última posición
        for(q = *L; q->next->next != LNULL; q = q->next);
        q->next = LNULL;

    } else { // Eliminado de un elemento que no se encuentra en los extremos
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q;
    }

    free(p);
}

void deleteList(tList *L) {
    tPosL p;

    while(!isEmptyList(*L)) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
}

bool copyList(tList L, tList *M) {
    /*
     * L -> lista original
     * M -> nueva lista
     * p -> iterador de L
     * q -> iterador de M
     * r -> posición temporal
     */

    tPosL p, q, r;
    bool result = true;

    createEmptyList(M);
    if(!isEmptyList(L)) {
        p = L; // Primer elemento de L

        /* Mientras p no sea LNULL y haya suficiente espacio para el siguiente nodo,
         * se seguirá copiando la lista nodo a nodo */
        while((p != LNULL) && (createNode(&r))) {
            r->data = p->data;
            r->next = LNULL;

            if(p == L) { // Para copiar el primer elemento de la lista
                *M = r;
                q = r;
            } else { // Para copiar otro elemento de otra posición que no sea la primera
                q->next = r;
                q = r;
            }
            p = p->next; // Avanzamos una posición más y volvemos a iterar si procede
        }

        // Si nos quedamos sin espacio para copiar la lista, retornamos false y borramos lo que hubiera de M
        if(p != LNULL) {
            result = false;
            deleteList(M);
        }
    }

    return result;
}