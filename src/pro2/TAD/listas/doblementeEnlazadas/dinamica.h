//
// Created by alexb on 27/08/2022.
//

#ifndef LISTAS_DINAMICA_H
#define LISTAS_DINAMICA_H

#include <stdbool.h>

/* Definición de tipos de datos */
#define LNULL NULL

typedef int tItemL;

typedef struct tNode* tPosL;

// Al ser doblemente enlazada, habrá un puntero que apunte hacia la siguiente posición, y otro que apunte a la anterior
struct tNode {
    tItemL data;
    tPosL next;
    tPosL prev;
};

typedef tPosL tList;

/* Cabeceras
 * L -> Lista
 * p -> posición o nodo de la Lista
 */
bool isEmptyList(tList L);
void createEmptyList(tList *L);
bool createNode(tPosL *p);
bool insertItem(tItemL d, tPosL p, tList *L);
void updateItem(tItemL d, tPosL p, tList *L);
tPosL findItem(tItemL d, tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p, tList L);
void deleteAtPosition(tPosL p, tList *L);
void deleteList(tList *L);

#endif //LISTAS_DINAMICA_H

/* De las listas doblemente enlazadas, solo estará en código las dinámicas, porque no tiene sentido y no se puede
 * hacer estática. Una lista estática se crea con un array, y un array ya es una estructura de acceso aleatorio por
 * lo que para ir a un elemento se puede acceder de forma inmediata y no hay que recorrer la lista entera  como en
 * una estructura dinámica */
