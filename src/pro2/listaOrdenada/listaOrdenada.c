//
// Created by alexb on 21/03/2022.
//

#include "listaOrdenada.h"

bool createNode(tPosL *p) {
    *p = malloc(sizeof(struct Node));
    return *p != LNULL;
}

bool insertItem(tItemL d, tList *L) {
    tPosL q, p;

    if(!createNode(&q)) {
        return false;
    } else {
        q->data = d;
        q->next = LNULL;

        if(*L == LNULL) {
            *L = q;
        } else if(d < (*L)->data) {
            q->next = *L;
            *L = q;
        } else {
            p = findPosition(*L, d);
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}

tPosL findPosition(tList L, tItemL d) {
    tPosL p;
    p = L;
    while((p != LNULL) && (p->next->data < d)) {
        p = p->next;
    }
    return p;
}