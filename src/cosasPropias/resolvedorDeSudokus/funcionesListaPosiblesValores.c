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

int getItem(tPosicionLista posicion, tLista lista) {
    return posicion->data;
}

void mostrarPosiblesValoresCasilla(tLista lista) {

    if(isEmptyList(lista)) {
        printf("Esta casilla no es modificable\n");
    } else {
        for (tPosicionLista i = lista; i != LNULL; i = i->next) {
            printf("Valor: %d\n", getItem(i, lista));
        }
    }
    printf("\n");
}

