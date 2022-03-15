//
// Created by alexb on 12/03/2022.
//

#ifndef RESOLVEDORDESUDOKUS_TIPOCASILLA_H
#define RESOLVEDORDESUDOKUS_TIPOCASILLA_H

#include "cabecerasComunes.h"

typedef struct nodo *tPosicionLista;

struct nodo{
    int data;
    tPosicionLista next;
};

typedef tPosicionLista tLista;

typedef struct tCasilla {
    bool esModificable;
    int valor;
    int cuadrante;
    tLista posiblesValores;

} tCasillas;

#endif //RESOLVEDORDESUDOKUS_TIPOCASILLA_H
