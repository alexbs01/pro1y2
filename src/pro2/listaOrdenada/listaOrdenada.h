//
// Created by alexb on 21/03/2022.
//

#ifndef LISTADINAMICA_LISTAORDENADA_H
#define LISTADINAMICA_LISTAORDENADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LNULL NULL

typedef int tItemL;
typedef struct Node *tPosL;
struct Node {
    tItemL data;
    tPosL next;
};

typedef tPosL tList;

bool insertItem(tItemL d, tList *L);
bool createNode(tPosL *p);
tPosL findPosition(tList L, tItemL d);

#endif //LISTADINAMICA_LISTAORDENADA_H
