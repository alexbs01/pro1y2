//
// Created by alexb on 28/08/2022.
//

#ifndef TAD_LISTAORDENADAPARAPRIORIDADES_H
#define TAD_LISTAORDENADAPARAPRIORIDADES_H

#include "colaDinamica.h"

/* Definición de tipos de datos */
#define LNULL NULL
#define MAXPRIO 5 // Máximo nivel de prioridad

typedef int tPriority;

typedef struct tItemL {
    tPriority prio;
    tQueue queue;
} tItemL;

typedef struct tNodeL* tPosL;

struct tNodeL {
    tItemL data;
    tPosL next;
};

typedef tPosL tOrderedList;

/* Cabeceras
 * L -> Lista de prioridades
 * prio -> prioridad
 * d -> item
 */
bool isEmptyList(tOrderedList L);
void createEmptyList(tOrderedList *L);
bool insertItem(tPriority prio, tOrderedList *L);
tPosL findPosition(tOrderedList L, tItemL d);
void updateItem(tOrderedList *L, tPosL p, tQueue queue);
tPosL findItem(tPriority prio, tOrderedList L);
void getItem(tPosL p, tOrderedList L, tPriority *prio, tQueue *queue);
tPosL first(tOrderedList L);
tPosL last(tOrderedList L);
tPosL previous(tPosL p, tOrderedList L);
tPosL next(tPosL p, tOrderedList L);
void deleteAtPosition(tPosL p, tOrderedList *L);
void deleteList(tOrderedList *L);

#endif //TAD_LISTAORDENADAPARAPRIORIDADES_H
