//
// Created by alexb on 02/03/2022.
//

#include "implementacioListaTeoriaEstatica.h"
void createEmptyList(tList *L) {
    L->lastPos = LNULL;
}

bool isEmptyList(tList L) {
    return L.lastPos == LNULL;
}

tPosL first(tList L) {
    return 0;
}

tPosL previous(tPosL p, tList L) {
    return p-1; // O bien: return --p;
}

tPosL last(tList L) {
    return L.lastPos;
}

tPosL next(tPosL p, tList L) {
    if(L.lastPos == p) {
        return LNULL;
    } else {
        return p+1;
    }
}

void updateItem(tItemL d, tPosL p, tList *L) {
    L->data[p] = d; // O bien: (*L).data[p] = d;
}
tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}

bool copyList(tList L, tList *M) {
    tPosL i;
    for(i = 0; i<=L.lastPos; i++) {
        M->data[i] = L.data[i];
    }
    M->lastPos = L.lastPos;
    return true;
}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL i;

    L->lastPos--;
    for(i = p; i<=L->lastPos; i++) {
        L->data[i] = L->data[i+1];
    }
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL i;

    if(L->lastPos == MAX-1) {
        return false;
    } else {
        L->lastPos++;
        if(p == LNULL) { // Insertar al final
            L->data[L->lastPos] = d;
        } else {
            for(i = L->lastPos; i>=p+1; i--) {
                L->data[i] = L->data[i-1];
            }
            L->data[p] = d;
        }
        return true;
    }
}

tPosL findItem(tItemL d, tList L) {
    tPosL i;

    if(isEmptyList(L)) {
        return LNULL;
    } else {
        for (i = 0; i != (i < L.lastPos) && (L.data[i]!=d); i++);
        if(L.data[i] == d) {
            return i;
        } else {
            return LNULL;
        }
    }
}