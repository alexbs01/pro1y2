//
// Created by alexb on 02/03/2022.
//

#ifndef LISTATEORIA_IMPLEMENTACIOLISTATEORIAESTATICA_H
#define LISTATEORIA_IMPLEMENTACIOLISTATEORIAESTATICA_H
#include <stdbool.h>
#define MAX 1000 // 1000 para el ejemplo
#define LNULL -1

typedef int tPosL;
typedef int tItemL; // En este caso solo guardara enteros
typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;

void createEmptyList(tList *L);
bool isEmptyList(tList L);
tPosL first(tList L);
tPosL previous(tPosL p, tList L);
tPosL last(tList L);
tPosL next(tPosL p, tList L);
void updateItem(tItemL d,tPosL p, tList *L);
tItemL getItem(tPosL p, tList L);
bool copyList(tList L, tList *M);
void deleteAtPosition(tPosL p, tList *L);
bool insertItem(tItemL d, tPosL p, tList *L);
tPosL findItem(tItemL d, tList L);
void deleteList(tList L);

#endif //LISTATEORIA_IMPLEMENTACIOLISTATEORIAESTATICA_H
