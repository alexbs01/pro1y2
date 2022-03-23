//
// Created by alexb on 16/03/2022.
//

#ifndef RESOLVEDORDESUDOKUS_FUNCIONESLISTAPOSIBLESVALORES_H
#define RESOLVEDORDESUDOKUS_FUNCIONESLISTAPOSIBLESVALORES_H

#include <stdlib.h>
#include <stdbool.h>
#include "tipoCasilla.h"

#define LNULL NULL

void createEmptyList(tLista *lista);
bool isEmptyList(tLista lista);
bool createNode(tPosicionLista *posicion);
bool insertPosibleValor(int valor, tLista *lista);
tPosicionLista next(tPosicionLista posicion, tLista lista);
int getItem(tPosicionLista posicion, tLista lista);
void mostrarPosiblesValoresCasilla(tLista lista);

#endif //RESOLVEDORDESUDOKUS_FUNCIONESLISTAPOSIBLESVALORES_H
