//
// Created by alexb on 28/08/2022.
//

#ifndef TAD_ESTATICA_H
#define TAD_ESTATICA_H

#include <stdbool.h>

/* Definición de tipos de datos */
#define Q_MAX 10 // Cantidad máxima de elementos en cola

typedef int tItemQ;

typedef struct Queue{
    tItemQ data[Q_MAX];
    int front;
    int rear;
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

#endif //TAD_ESTATICA_H
