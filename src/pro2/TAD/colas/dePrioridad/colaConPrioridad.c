//
// Created by alexb on 28/08/2022.
//

#include "colaConPrioridad.h"

bool isEmptyQueueP(tQueueP queueP){
    return (queueP == LNULL);
}

void createEmptyQueueP(tQueueP *queueP){
    *queueP = LNULL;
}

bool enqueueP(tItemQ item, tPriority prio, tQueueP *queueP) {
    tPosL pos;
    tQueue Q;

    // Comprueba si existe la prioridad que estamos asignando
    pos = findItem(prio, *queueP);

    if(pos == LNULL) {
        // Si no existe se añade
        if(!insertItem(prio, queueP)) {
            return false;
        }
        pos = findItem(prio, *queueP);
    }

    // Extraemos la cola para agregar el elemento
    getItem(pos, *queueP, &prio, &Q);

    // Actualizamos la cola
    if(!enqueue(item, &Q)) { // Si no se puede encolar el elemento, retorna false
        return false;
    }

    // Actualizamos la lista
    updateItem(queueP, pos, Q);
    return true;
}

void dequeueP(tQueueP *queueP) {
    tPosL posL;
    tQueue queue;
    tPriority priority;

    // Extraemos el elemento de la cola
    posL = first(*queueP); // Buscamos la primera posición
    getItem(posL, *queueP, &priority, &queue);
    dequeue(&queue);

    // Si la cola está vacía borra el nodo, si no lo actualiza
    if(isEmptyQueue(queue)) {
        deleteAtPosition(posL, queueP);
    } else {
        updateItem(queueP, posL, queue);
    }
}

tItemQ frontP(tQueueP queueP) {
    tPosL first_pos;
    tQueue queue;
    tPriority node_prio;

    first_pos = first(queueP);
    getItem(first_pos, queueP, &node_prio, &queue);

    return queue.front->item;
}
