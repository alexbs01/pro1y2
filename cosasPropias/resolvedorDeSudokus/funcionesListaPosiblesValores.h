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
int getNumber(tPosicionLista posicion, tLista lista);
void mostrarPosiblesValoresCasilla(tLista lista);
tPosicionLista findNumber(int numero, tLista lista);
tPosicionLista previous(tPosicionLista posicion, tLista lista);
void deleteAtPosition(int numero, tLista *lista);
int firstNumber(tLista lista);
int elementosEnLista(tLista lista);
void borrarComunes(tLista *lista, tLista listaConComunes);

#endif //RESOLVEDORDESUDOKUS_FUNCIONESLISTAPOSIBLESVALORES_H
