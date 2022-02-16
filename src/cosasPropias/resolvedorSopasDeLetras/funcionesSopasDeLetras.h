//
// Created by alexb on 14/02/2022.
//

#ifndef RESOLVEDORSOPASDELETRAS_FUNCIONESSOPASDELETRAS_H
#define RESOLVEDORSOPASDELETRAS_FUNCIONESSOPASDELETRAS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ENTER '\n'

typedef char *pChar;

void recogerLetras(int ancho, int alto, char letras[ancho*alto]);
void rellenarMatriz(int i, int j, char matriz[i][j], const char elementos[i*j]);
void mostrarMatriz(int i, int j, char matriz[i][j]);
bool buscarPalabraHorizontalDerecha(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);
bool buscarPalabraHorizontalIzquierda(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);
bool buscarPalabraVerticalAbajo(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);
bool buscarPalabraVerticalArriba(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);
bool buscarPalabraDiagonalDerechaAbajo(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);
bool buscarPalabraDiagonalDerechaArriba(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);
bool buscarPalabraDiagonalIzquierdaAbajo(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);
bool buscarPalabraDiagonalIzquierdaArriba(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);

#endif //RESOLVEDORSOPASDELETRAS_FUNCIONESSOPASDELETRAS_H
