//
// Created by alexb on 12/03/2022.
//
#include "funcionesResolvedor.h"

void imprimirSudoku(int columnas, int filas, tCasilla sudoku[columnas][filas]) {

    for(int j = 0; j < filas; j++) {
        for(int i = 0; i < columnas; i++) {
            if((i == 3) || (i == 6)) printf("|  ");
            if(((j == 3) || (j == 6)) && (i == 0)) printf("---------+-----------+---------\n");
            printf("%d  ", sudoku[i][j].valor);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirCasillasModificables(int columnas, int filas, tCasilla sudoku[columnas][filas]) {
    for(int j = 0; j < filas; j++) {
        for(int i = 0; i < columnas; i++) {
            if((i == 3) || (i == 6)) printf("|  ");
            if(((j == 3) || (j == 6)) && (i == 0)) printf("---------+-----------+---------\n");
            printf("%d  ", sudoku[i][j].esModificable);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirCuadrantes(int columnas, int filas, tCasilla sudoku[columnas][filas]) {
    for(int j = 0; j < filas; j++) {
        for(int i = 0; i < columnas; i++) {
            if((i == 3) || (i == 6)) printf("|  ");
            if(((j == 3) || (j == 6)) && (i == 0)) printf("---------+-----------+---------\n");
            printf("%d  ", sudoku[i][j].cuadrante);
        }
        printf("\n");
    }
    printf("\n");
}

