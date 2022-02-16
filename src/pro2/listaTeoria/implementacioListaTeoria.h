//
// Created by alexb on 14/02/2022.
//

#ifndef LISTATEORIA_IMPLEMENTACIOLISTATEORIA_H
#define LISTATEORIA_IMPLEMENTACIOLISTATEORIA_H

#include <stdio.h>
#include <stdbool.h>
#define LNULL NULL

typedef int tItemL;
typedef struct Node *tPosL;
struct Node {
    tItemL data;
    tPosL next;
};

typedef tPosL tList;
void createEmptyList(tList L);

bool isEmptyList(tList L);

tItemL getItem(tPosL p, tList L);
void updateItem(tItemL d,tPosL p, tList *L);

tPosL first(tList L);

tPosL previous(tPosL p, tList L);

tPosL next(tPosL p, tList L);

tPosL last(tList L);

#endif //LISTATEORIA_IMPLEMENTACIOLISTATEORIA_H
