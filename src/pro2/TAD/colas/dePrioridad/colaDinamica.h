//
// Created by alexb on 28/08/2022.
//

#ifndef TAD_COLADINAMICA_H
#define TAD_COLADINAMICA_H

#include <stdbool.h>

/* Definición de tipos de datos */
#define QNULL NULL

typedef int tItemQ;

typedef struct tNodeQ *tPosQ;

struct tNodeQ{
    tItemQ item;
    tPosQ next;
};

typedef struct Queue{
    tPosQ front;
    tPosQ rear;

} tQueue;

/* Cabeceras
 * Q -> Fila o cola
 * d -> item de la fila
 */
bool isEmptyQueue(tQueue Q);
void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);
void dequeue(tQueue *Q);
tItemQ front(tQueue Q);

#endif //TAD_COLADINAMICA_H
