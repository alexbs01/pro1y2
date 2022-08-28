//
// Created by alexb on 28/08/2022.
//

#ifndef TAD_DINAMICA_H
#define TAD_DINAMICA_H

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
    tPosQ front; // Primer elemento
    tPosQ rear; // Último elemento

} tQueue;

/* Cabeceras
 * Q -> Fila o cola
 * d -> item de la fila
 */
bool isEmptyQueue(tQueue Q);        // Comprueba si la cola está vacía
void createEmptyQueue(tQueue *Q);   // Crea una cola vacía
bool enqueue(tItemQ d, tQueue *Q);  // Inserta un elemento en la cola
void dequeue(tQueue *Q);            // Elimina un elemento de la cola
tItemQ front(tQueue Q);             // Muestra el campo item del primer elemento de la cola

#endif //TAD_DINAMICA_H
