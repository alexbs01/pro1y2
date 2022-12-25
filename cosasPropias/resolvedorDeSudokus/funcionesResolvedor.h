//
// Created by alexb on 12/03/2022.
//

#ifndef RESOLVEDORDESUDOKUS_FUNCIONESRESOLVEDOR_H
#define RESOLVEDORDESUDOKUS_FUNCIONESRESOLVEDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tipoCasilla.h"

void imprimirSudoku(int columnas, int filas, tCasilla sudoku[columnas][filas]);
void imprimirCasillasModificables(int columnas, int filas, tCasilla sudoku[columnas][filas]);
void imprimirCuadrantes(int columnas, int filas, tCasilla sudoku[columnas][filas]);


#endif //RESOLVEDORDESUDOKUS_FUNCIONESRESOLVEDOR_H
