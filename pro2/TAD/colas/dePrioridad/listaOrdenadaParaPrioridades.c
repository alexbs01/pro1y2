//
// Created by alexb on 28/08/2022.
//

#include "listaOrdenadaParaPrioridades.h"

#include <stdbool.h>
#include <stdlib.h>


/*
 *  Explicación del orden:
 *  1 -> Inmediato
 *  2 -> Mur urgente
 *  3 -> Urgente
 *  4 -> Normal
 *  5 -> No es urgente
 */


bool isEmptyList(tOrderedList L) {
    return (L == LNULL);
}

void createEmptyList(tOrderedList *L) {
    *L = LNULL;
}

bool createNodeL(tPosL *p) {
    *p = malloc(sizeof(struct tNodeL));
    return *p != LNULL;
}

tPosL findPosition(tOrderedList L, tItemL d) {
    tPosL p,tmp;

    p = L;
    tmp = L;
    while((p != LNULL) && (p->data.prio < d.prio)) {
        tmp = p;
        p = p->next;
    }
    return tmp;
}

bool insertItem(tPriority prio, tOrderedList *L) {
    tPosL q, p;

    if(!createNodeL(&q) || prio > MAXPRIO) { // Si no puede crear el nodo, o es una prioriodad no permitida retorna fase
        return false;

    } else {
        q->data.prio = prio;
        createEmptyQueue(&q->data.queue); // La cola debe estar inicializada como variable
        q->next = LNULL;

        if(isEmptyList(*L)) { // Si la lista está vacía se inserta en primera posición
            *L = q;
        } else if(prio < (*L)->data.prio) { // Si es menor que la primera posición, se insertará en su lugar
            q->next = *L;
            *L = q;
        } else { // Busca la posición correcta y lo inserta
            p = findPosition(*L, q->data);
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}

void updateItem(tOrderedList *L, tPosL p, tQueue queue) {
    p->data.queue = queue;
}

tPosL findItem(tPriority prio, tOrderedList L) {
    tPosL p;

    for(p = L; (p != LNULL) && (p->data.prio < prio); p = p->next);

    return p;
}


void getItem(tPosL p, tOrderedList L, tPriority *prio, tQueue *queue) {
    *prio = p->data.prio;
    *queue = p->data.queue;
}

tPosL first(tOrderedList L) {
    return L; // El primer elemento de la lista siempre es al que apunta L
}

tPosL last(tOrderedList L) {
    tPosL p;

    for (p = L; p->next != LNULL; p = p->next);
    return p;
}

tPosL previous(tPosL p, tOrderedList L) {
    tPosL q;

    if(p == L) {
        return LNULL;
    } else {
        for(q = L; q->next != p; q = q->next);
        return q;
    }
}

tPosL next(tPosL p, tOrderedList L) {
    return p->next;
}

void deleteAtPosition(tPosL p, tOrderedList *L) {
    tPosL q;

    if(p == *L) { // Elimina el primer elemento
        *L = (*L)->next;
    } else if(p->next == LNULL) { // Elimina el último elemento
        for(q = *L; q->next->next != p; q = q->next);
        q->next = LNULL;

    } else { // Elimina un elemento de una posición intermedia sobreescribiéndolo
        // p -> elemento a eliminar
        // q -> elemento siguiente a p

        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q;
    }

    free(p);
}

void deleteList(tOrderedList *L) {
    tPosL p;

    while(!isEmptyList(*L)) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
}
