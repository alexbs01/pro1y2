//
// Created by alexb on 14/03/2022.
//

#include "implementcacionDinamica.h"
#define LNULL NULL

tPosL previous(tPosL p, tList L) {
    return p->prev;
}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL q;
    if(p == *L) {
        *L = (*L)->next;
        if(*L != LNULL) {
            (*L)->prev=LNULL;
        }
    } else if(p->next != LNULL) {
        p->prev->next=p->next;
        p->next->prev=p->prev;
    } else {
        p->prev->next=LNULL;
    }
    free(p);
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
        q->prev = LNULL;
        if(*L == LNULL) { // Insertar en una lista vacia
            *L = q;
        } else if(p == LNULL) { // Insertar al final de la lista
            for(r = *L; r->next != LNULL; r = r ->next);
            r->next = q;
            q->prev = r;
        } else if(p == *L) { // Insertar en primera posicion
            q->next = p;
            p->prev = q;
            *L = q;
        } else { // Insertar en el medio y medio
            q->prev = p->prev;
            q->next = p;
            p->prev->next = q;
            p->prev = p;
        }
    }
}