//
// Created by alexb on 23/08/2022.
//

#include "dinamicaListaOrdenada.h"
#include <stdbool.h>
#include <stdlib.h>

bool isEmptyList(tList L) {
    return (L == LNULL);
}

void createEmptyList(tList *L) {
    *L = LNULL;
}

bool createNode(tPosL *p) {
    *p = malloc(sizeof(struct tNode));
    return *p != LNULL;
}

tPosL findPosition(tList L, tItemL d) {
    /* p -> posición inicial
     * q -> posición auxiliar */
    tPosL p, q;

    p = L;
    q = L;

    /* Como la lista estará ordenada, el bucle parará cuando llegue al final o cuando se sobrepase la posición
     * que estará buscando */
    while((p != LNULL) && (p->data < d)) {
        q = p;
        p = p->next;
    }
    return q;
}

bool insertItem(tItemL d, tList *L) {
    tPosL q, p;
    bool isInserted;

    if(!createNode(&q)){
        isInserted = false;
    } else {
        q->data = d;
        q->next = LNULL;

        if(isEmptyList(*L)) { // Si la lista está vacía el nuevo elemento se introducirá como el primero de la lista
            *L = q;
        } else if (d < (*L)->data) {
            // Si su valor es menor que el primero de la lista, si insertará el nuevo valor en primera posición
            q->next = *L;
            *L = q;
        } else { // Si no, buscará la posición en la que deberá de ir el elemento, y reorganizará es parte de la lista
            p = findPosition(*L, d);
            q->next = p->next;
            p->next = q;
        }
        isInserted = true;
    }
    return isInserted;
}

void updateItem(tItemL d, tPosL p, tList *L) {
    p->data = d;
}

tPosL findItem(tItemL d, tList L) {
    tPosL p;

    for(p = L; (p != LNULL) && (p->data < d); p = p->next);
    return p;
}

tItemL getItem(tPosL p, tList L) {
    return p->data;
}

tPosL first(tList L) {
    return L;
}

tPosL last(tList L) {
    tPosL p;

    for(p = L; p->next != LNULL; p = p->next);
    return p;
}

tPosL previous(tPosL p, tList L) {
    tPosL q;

    if(p == L) { // Si la lista solo tiene un elemento, no habrá uno previo
        return LNULL;
    } else { // Si no, se ejecutará un bucle para buscar el previo al buscado
        for(q = L; q->next != p; q = q->next);
        return q;
    }
}

tPosL next(tPosL p, tList L) {
    return p->next;
}

void deleteAtPosition(tPosL p, tList *L) {
    /* p -> elemento a borrar
     * q -> elemento siguiente a p */
    tPosL q;

    if(p == *L) { // Borra el primer elemento
        *L = (*L)->next;

    } else if(p->next == LNULL) { // Elimina el último
        for(q = *L; q->next->next != p; q = q->next);
        q->next = LNULL;

    } else { // Si es un elemento intermedio
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
    tPosL p, q, r;
    bool result = true;

    createEmptyList(M);

    if(!isEmptyList(L)) {
        p = L; // p -> primer elemento de la lista
        while((p != LNULL) && (createNode(&r))) { // Si puede crear un nodo, es que hay espacio
            r->data = p->data;
            r->next = LNULL;
            if(p == L) { // Se copia el primer elemento de la lista
                *M = r;
                q = r;
            } else { // Se copian los siguientes
                q->next = r;
                q = r;
            }
            p = p->next; // Pasa a la siguiente posición de la lista para copiarla en la siguiente iteración
        }
        if(p != LNULL) { // Si no hay espacio suficiente elimina lo que creo de M
            result = false;
            deleteList(M);
        }
    }
    return result;
}