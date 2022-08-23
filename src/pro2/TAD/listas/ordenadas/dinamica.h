//
// Created by alexb on 23/08/2022.
//

#ifndef LISTAS_DINAMICA_H
#define LISTAS_DINAMICA_H

#include <stdbool.h>

/* Definicion de tipos de datos */
#define LNULL NULL

typedef int tItemL;

typedef struct tNode *tPosL;

struct tNode {
    tItemL data;
    tPosL next;
};

typedef tPosL tList;

/* Cabeceras
 * L -> Lista
 * p -> posición o nodo de la Lista
 */
bool isEmptyList(tList L);
void createEmptyList(tList *L);
bool createNode(tPosL *p);
bool insertItem(tItemL d, tList *L);
tPosL findPosition(tList L, tItemL d);
void updateItem(tItemL d, tPosL p, tList *L);
tPosL findItem(tItemL d, tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p, tList L);
void deleteAtPosition(tPosL p , tList *L);
void deleteList(tList *L);

#endif //LISTAS_DINAMICA_H
