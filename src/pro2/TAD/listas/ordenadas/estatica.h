//
// Created by alexb on 23/08/2022.
//

#ifndef LISTAS_ESTATICA_H
#define LISTAS_ESTATICA_H

#include <stdbool.h>

/* Definicion de tipos de datos */
#define LNULL -1
#define MAX 1000

typedef int tItemL;
typedef int tPosL;

typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;

/* Cabeceras
 * L -> Lista
 * p -> posición o nodo de la Lista
 */
bool isEmptyList(tList L);
void createEmptyList(tList *L);
bool insertItem(tItemL d, tList *L);
bool copyList(tList L, tList *M);
void updateItem(tItemL d, tPosL p, tList *L);
void deleteAtPosition(tPosL p, tList *L);
void deleteList(tList *L);
tPosL findItem(tItemL d, tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p, tList L);

#endif //LISTAS_ESTATICA_H
