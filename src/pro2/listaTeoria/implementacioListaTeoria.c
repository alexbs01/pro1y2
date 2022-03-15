//
// Created by alexb on 14/02/2022.
//

#include "implementacioListaTeoria.h"

void createEmptyList(tList L) {
    L = LNULL;
}

bool isEmptyList(tList L) {
    bool empty = NULL;
    if(L == LNULL) {
        empty = true;
    } else {
        empty = false;
    }
    return empty;
    // Equivalente a: return L == LNULL;
}

tItemL getItem(tPosL p, tList L) {
    return(p->data);
}

void updateItem(tItemL d,tPosL p, tList *L) {
    p->data=d;
}

tPosL first(tList L) {
    return(L);
}

tPosL previous(tPosL p, tList L) {
    tPosL q;
    if  (p == L) {
        return LNULL;
    }
    else
        for(q = L; q->next!=p ;q = q->next) {
            return q;
        }
}

tPosL next(tPosL p, tList L) {
    return(p->next);
}

tPosL last(tList L) {
    tPosL p;

    for(p = L; p->next!=LNULL; p = p->next);
    return p;
}

tPosL findItem(tItemL d, tList L) {
    tPosL p;
    if(isEmptyList(L)) {
        p = LNULL;
    } else {
        for(p = L; (p != NULL) && (d == p->data); p = p->next);
        return p;
    }

}

bool createNode(tPosL *p) {
    *p = malloc(sizeof(struct Node));
    return *p != LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL q, r;
    if(!createNode(&q)) {
        return false;
    } else {
        q->data = d;
        q->next = LNULL;
        if(isEmptyList(*L)) {
            *L = q;
        } else if(p == LNULL) { // Insertar al final de la lista no vacia
            for(r = *L; r->next != LNULL; r = r->next);
            r->next = q;
        } else if(p == *L) { // Insertar en primera posicion
            q->next = p;
            *L = q;
        } else { // Insertar en una posicin intermedia
            q->next = p->next; // Enganchar q a continuacion de p
            p->next = q;

            q->data = p->data; // Intercambiar los contenidos de *p y *q
            p->data = d;
        }
        return true;
    }

}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL r, q;

    if(p == *L) { // Borrar primer nodo
        *L = p->next;
        free(p);
    } else if(p->next == LNULL) { // Borrar el ultimo nodo
        r = previous(p, *L); // == for(q = *L; q->next != p; q = q->next);
        r->next = LNULL; // Se puede hacer sin r: previous(p, *L)->next = LNULL;
    } else { // Eliminar un nodo intermedio
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        free(q); // Se elimina el nodo siguiente a p
    }
}

void deleteList(tList *L) {
    tPosL p;

    while(*L != LNULL) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
}

int countElements(tList L) {
    tPosL p;
    int count = 0;

    if(isEmptyList(L)) {
        return 0;
    } else {
        for(p = first(L); p != last(L) ; p = next(p, L)) {
            count++;
        }
    }
    return count;
}

