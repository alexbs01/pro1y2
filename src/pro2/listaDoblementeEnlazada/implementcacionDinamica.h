//
// Created by alexb on 14/03/2022.
//

#ifndef LISTADOBLEMENTEENLAZADA_IMPLEMENTCACIONDINAMICA_H
#define LISTADOBLEMENTEENLAZADA_IMPLEMENTCACIONDINAMICA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define LNULL NULL

typedef int tItemL;
typedef struct Node *tPosL;
struct Node {
    tItemL data;
    tPosL next;
    tPosL prev;
};

typedef tPosL tList;

tPosL previous(tPosL p, tList L);
void deleteAtPosition(tPosL p, tList *L);
bool createNode(tPosL *p);
bool insertItem(tItemL d, tPosL p, tList *L);

#endif //LISTADOBLEMENTEENLAZADA_IMPLEMENTCACIONDINAMICA_H
