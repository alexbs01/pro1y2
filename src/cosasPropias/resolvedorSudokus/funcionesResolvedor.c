//
// Created by alexb on 12/03/2022.
//
#include "funcionesResolvedor.h"

void imprimirSudoku(int columnas, int filas, tCasillas sudoku[columnas][filas]) {
    for(int j = 0; j < filas; j++) {
        for(int i = 0; i < columnas; i++) {
            printf("%d  ", sudoku[i][j].valor);
        }
        printf("\n");
    }
}
