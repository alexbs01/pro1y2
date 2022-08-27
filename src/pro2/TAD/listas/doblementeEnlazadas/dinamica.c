//
// Created by alexb on 27/08/2022.
//

#include "dinamica.h"
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

bool insertItem(tItemL d, tPosL p, tList *L) {
    /* q -> elemento que se va a insertar
     * r -> elemento previo a q */
    tPosL q, r;

    if(!createNode(&q)) { // Si no se puede crear un nodo, no se podrá insertar, por lo que se retorna false
        return false;
    } else {
        q->data = d;
        q->next = LNULL;
        q->prev = LNULL;
        if(isEmptyList(*L)) { // Si la lista está vacía se inserta en primera posición
            *L = q;
        } else if(p == LNULL) { // Si la posición es la LNULL, se añadirá al final por ser la última posición
            for(r = *L; r->next != LNULL; r = r->next); // Con este bucle nos dirigimos a la última posición de la lista
            r->next = q;
            q->prev = r;

        } else if(p == *L) { // Si es el primer elemento de la lista
            q->next = p;
            p->prev = q;
            *L = q;

        } else { // O bien, si se quiere insertar en una posición intermedia

            q->data = p->data; // Intercambiamos los valores, para insertar desde la variable q
            p->data = d;
            if(p->next != LNULL) { // Comprueba si la siguiente posición no es la última
                p->next->prev = q;
            }
            q->next = p->next;
            p->next = q;
            q->prev = p;
        }
        return true;
    }
}

void updateItem(tItemL d, tPosL p, tList *L) {
    p->data = d;
}

tPosL findItem(tItemL d, tList L) {
    tPosL p;

    for(p = L; (p != NULL) && (p->data != d); p = p->next);
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
    return p->prev;
}

tPosL next(tPosL p, tList L) {
    return p->next;
}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL q;

    if(p == *L) { // Se elimina el primer elemento
        *L = (*L)->next;

        if(!isEmptyList(*L)) {
            (*L)->prev = LNULL;
        }

    } else { // Se elimina un elemento en una posición distinta a la primera. En la intermedio o final
        q = p->prev;
        q->next = p->next;

        if(p->next != LNULL) {
            p->next->prev = p->prev;
        }
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
     * p -> iterador de L
     * q -> iterador de q
     * r -> posición temporal
     * result -> dirá si se copió la lista o no
     */
    tPosL p, q, r;
    bool result = true;

    createEmptyList(M);
    if(!isEmptyList(L)) {
        p = L;
        while((p != LNULL) && (createNode(&r))) { // se comprueba si se puede crear otro nodo y se ejecuta el bucle si sí
            r->data = p->data;
            r->next = LNULL;
            r->prev = LNULL;
            if(p == L) { // Comprueba si estamos copiando el primer elemento de la lista, y se copia en M
                *M = r;
                q = r;
            } else { // Del segundo en adelante, y se copia en M
                q->next = r;
                r->prev = q;
                q = r;
            }
            p = p->next; // Avanza una posición en la lista L
        }

        // Si no hay más espació para seguir copiando, se eliminará lo que se copió de M, y retornará false
        if(p != LNULL) {

            result = false;
            deleteList(M);
        }
    }
    return result;
}
