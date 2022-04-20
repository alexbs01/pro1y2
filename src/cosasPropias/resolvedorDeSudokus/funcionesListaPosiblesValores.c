//
// Created by alexb on 16/03/2022.
//

#include "funcionesListaPosiblesValores.h"

void createEmptyList(tLista *lista) {
    *lista = LNULL;
}

bool isEmptyList(tLista lista) {
    bool empty = NULL;

    if(lista == LNULL) {
        empty = true;
    } else {
        empty = false;
    }
    return empty;
}

bool createNode(tPosicionLista *posicion) {
    *posicion = malloc(sizeof(struct nodo));
    return *posicion != LNULL;
}

bool insertPosibleValor(int valor, tLista *lista) {
    tPosicionLista q;
    bool fueInsertado;
    if(!createNode(&q)) {
        fueInsertado = false;
    } else {
        q->data = valor;
        q->next = LNULL;
        if(isEmptyList(*lista)) {
            *lista = q;
        } else { // Insertar en primera posicion
            q->next = *lista;
            *lista = q;
        }
        fueInsertado = true;
    }
    return fueInsertado;
}

tPosicionLista next(tPosicionLista posicion, tLista lista) {
    return posicion->next;
}

int getNumber(tPosicionLista posicion, tLista lista) {
    return posicion->data;
}

void mostrarPosiblesValoresCasilla(tLista lista) {

    if(isEmptyList(lista)) {
        printf("Esta casilla no es modificable\n");
    } else {
        for (tPosicionLista i = lista; i != LNULL; i = i->next) {
            printf("Valor: %d\n", getNumber(i, lista));
        }
    }
    printf("\n");
}

tPosicionLista findNumber(int numero, tLista lista) {
    tPosicionLista posicion;
    if(isEmptyList(lista)) {
        posicion = LNULL;
    } else {
        for(posicion = lista; (posicion != LNULL) && (numero != posicion->data); posicion = posicion->next);
    }
    return posicion;
}

tPosicionLista previous(tPosicionLista posicion, tLista lista) {
    tPosicionLista q;

    if (posicion == lista) {
        q = LNULL;
    } else {
        for (q = lista; q->next != posicion; q = q->next);
    }
    return q;
}

void deleteAtPosition(int numero, tLista *lista) {
    tPosicionLista r, q, posicion;
    posicion = findNumber(numero, *lista);

    if(isEmptyList(*lista) || posicion == LNULL) {
        /* Para evitar que el programa crashee si se intenta eliminar una posicion en una lista vacia
         * o si se intenta eliminar un numero que no estan en la lista*/
    }else if(posicion == *lista) { // Borrar primer nodo
        *lista = posicion->next;
        free(posicion);
    } else if(posicion->next == LNULL) { // Borrar el ultimo nodo
        r = previous(posicion, *lista); // == for(q = *L; q->next != p; q = q->next);
        r->next = LNULL; // Se puede hacer sin r: previous(p, *L)->next = LNULL;
    } else { // Eliminar un nodo intermedio
        q = posicion->next;
        posicion->data = q->data;
        posicion->next = q->next;
        free(q); // Se elimina el nodo siguiente a p
    }
}

int firstNumber(tLista lista) {
    return lista->data;
}

int elementosEnLista(tLista lista) { // Cantidad de elementos en la lista
    tPosicionLista posicion;
    int posicionFinal = 0;

    for(posicion = lista; posicion != LNULL; posicion = posicion->next) {
        posicionFinal++;
    }

    return posicionFinal;
}

void borrarComunes(tLista *lista, tLista listaConComunes) {
    tPosicionLista posicionABorrar, posicion;

    for(posicion = listaConComunes; posicion != LNULL; posicion = posicion->next) {
        for(posicionABorrar = *lista; posicionABorrar != LNULL; posicionABorrar = posicionABorrar->next) {
            if(posicion->data == posicionABorrar->data) {
                deleteAtPosition(posicion->data, lista);
                break;
            }
        }
    }
}
