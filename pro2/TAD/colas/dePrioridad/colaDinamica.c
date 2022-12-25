//
// Created by alexb on 28/08/2022.
//
/* ************************************************************************** *
 * ES LA MISMA IMPLEMENTACIÓN QUE LA QUE SE HIZO DE COLAS ENLAZADAS DINÁMICAS *
 * ************************************************************************** */
#include "colaDinamica.h"

#include <stdlib.h>

bool isEmptyQueue(tQueue Q) {
    return (Q.front == QNULL);
}

void createEmptyQueue(tQueue *Q) {
    /* Como una fila es una estructura, no se puede hacer *Q = QNULL como si fuero una lista. Y como estamos haciendo
     * una cola vacía, la primera posición será la misma que la última y tendrá el valor NULL */
    Q->front = QNULL;
    Q->rear = QNULL;
}

bool createNode(tPosQ *p) {
    *p = malloc(sizeof(struct tNodeQ));
    return *p != QNULL;
}

bool enqueue(tItemQ d, tQueue *Q) {
    // p -> elemento que se insertará
    tPosQ p;

    if(!createNode(&p)) { // Comprueba si puede crear un nodo, si no, retorna false
        return false;
    } else {
        /* En el caso de que sí se pueda, el item d, irá al campo p->item, y la siguiente posición será NULL porque en
         * una cola, todos los elementos se insertan al final */
        p->item = d;
        p->next = QNULL;

        if(isEmptyQueue(*Q)) { // Si la lista está vacía se insertará al frente como primer y último elemento
            Q->front = p;

        } else { // Si hay más elementos a la cosa, se insertará como siguiente elemento al último
            Q->rear->next = p;
        }

        Q->rear = p; // Cambiamos la posición del último elemento

        return true;
    }
}

void dequeue(tQueue *Q) {
    tPosQ p;

    if(isEmptyQueue(*Q)) { // Si la lista está vacía se termina la función sin retornar nada
        return;
    }

    // Movemos el frente de la cola una posición más adelante para eliminar el primer elemento
    p = Q->front;
    Q->front = p->next;

    if(isEmptyQueue(*Q)) { // Comprobamos si después de eliminar el elemento, esta queda vacía
        Q->rear = QNULL;
    }

    free(p);
}

tItemQ front(tQueue Q) {
    return Q.front->item;
}
