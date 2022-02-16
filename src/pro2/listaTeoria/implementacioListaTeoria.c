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
        for(q = L;q->next!=p ;q=q->next) {
            return q;
        }
}

tPosL next(tPosL p, tList L) {
    return(p->next);
}

tPosL last(tList L) {
    tPosL p;

    for(p = L; p->next!=LNULL; p = p->next) {
        return p;
    }
}