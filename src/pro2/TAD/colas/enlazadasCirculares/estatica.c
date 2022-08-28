//
// Created by alexb on 28/08/2022.
//

#include "estatica.h"

#include <stdbool.h>

int addOne(int i) {
    /* Avanzamos una posición, se usará para añadir un espacio en el final de la cola a la hora de insertar un
     * nuevo elemento en la cola circular */
    if(i == Q_MAX - 1) { // Si no hay más espacio en la cola no avanzamos posición
        return 0;
    } else {
        return ++i;
    }
}

bool isEmptyQueue(tQueue Q) {
    return (Q.front == addOne(Q.rear));
}

void createEmptyQueue(tQueue *Q) {
    Q->front = 0;
    Q->rear = Q_MAX - 1;
}

bool enqueue(tItemQ d, tQueue *Q) {
    /* Añadimos una posición por detrás del último elemento de la cola, en one_forward se almacenará en que posción
     * se deberá añadir el siguiente elemento */
    int one_fordward = addOne(Q->rear);

    if(Q->front == addOne(one_fordward)) { // Si no hay más espacio, 0 == 0, y retonará false
        return false;
    } else { // Si hay espacio en la cola, si inserta y se retorna true
        Q->rear = one_fordward;
        Q->data[Q->rear] = d;
        return true;
    }
}

void dequeue(tQueue *Q) { // Eliminamos el primer elemento de la cola
    Q->front = addOne(Q->front);
}

tItemQ front(tQueue Q) { // Retorna el primer valor de la cola
    return Q.data[Q.front];
}
