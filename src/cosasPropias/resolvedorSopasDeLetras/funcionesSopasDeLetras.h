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

void recogerLetras(int ancho, int alto, char letras[ancho*alto]);
void rellenarMatriz(int i, int j, char matriz[i][j], const char elementos[i*j]);
void mostrarMatriz(int i, int j, char matriz[i][j]);
void buscarPalabra(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]);

typedef char *pChar;

#endif //RESOLVEDORSOPASDELETRAS_FUNCIONESSOPASDELETRAS_H
