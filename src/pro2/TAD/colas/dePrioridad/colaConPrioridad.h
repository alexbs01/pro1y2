//
// Created by alexb on 28/08/2022.
//

#ifndef TAD_COLACONPRIORIDAD_H
#define TAD_COLACONPRIORIDAD_H

#include "listaOrdenadaParaPrioridades.h"
#include <stdio.h>

/* Definición de tipos de datos */
#define LNULL NULL

typedef tOrderedList tQueueP;

/* Cabeceras
 * queueP -> Fila o cola con prioridad
 * prio -> prioridad
 * item -> datos del elemento a insertar
 *
 * En una cola con prioridad, deberemos insertar los elementos con una prioridad para que se inserten correctamente
 */
bool isEmptyQueueP(tQueueP queueP);
void createEmptyQueueP(tQueueP *queueP);
bool enqueueP(tItemQ item, tPriority prio, tQueueP *queueP);    // Para que encole, debe haber espacio en memoria
void dequeueP(tQueueP *queueP);                                 // La lista de prioridades no está vacía
tItemQ frontP(tQueueP queueP);                                  // La cola con prioridad no debe estar vacía

#endif //TAD_COLACONPRIORIDAD_H
