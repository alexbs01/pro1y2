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