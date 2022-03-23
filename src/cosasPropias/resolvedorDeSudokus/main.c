#include <stdio.h>
#include <stdbool.h>
#include "tipoCasilla.h"
#include "funcionesResolvedor.h"
#include "funcionesListaPosiblesValores.h"

#define FILAS 9
#define COLUMNAS 9

int main() {
    FILE *ficheroSudoku; // Tipo de archivos para ficheros
    char fichero[50], linea[19]; // Almacena el nombre del fichero
    int numero[COLUMNAS];
    tCasilla casilla[COLUMNAS][FILAS];

    printf("\nEscribe el nombre del fichero que contiene el sudoku: ");
    gets(fichero); // Guarda el nombre del fichero
    ficheroSudoku = fopen(fichero, "r"); // Abre el fichero en modo lectura
    if(ficheroSudoku == NULL) { // Si no lo puede abrir muestra el mensaje de error y se termina la ejecucion
        printf("\nNo se pudo abrir el fichero");
        return 1;
    }

    printf("\n");

    for(int j = 0; j < FILAS; j++) {
        fgets(linea, 19, ficheroSudoku); // Por cada iteracion coge desde la primera fila hasta la ultima y la almacena en "linea"

        // La fila alamacenada en la variable "linea", se descompone en 9 numeros que se guardan en las 9 posiciones del array "numero"
        sscanf(linea, "%d %d %d %d %d %d %d %d %d", &numero[0], &numero[1], &numero[2], &numero[3], &numero[4], &numero[5], &numero[6], &numero[7], &numero[8]);

        for(int i = 0; i < COLUMNAS; i++) {
            casilla[i][j].valor = numero[i]; // Se guarda cada fila de "numero" en cada fila de "casilla"

            // En funcion de si la casilla es 0 o no, se decide si es un valor modificable o fijo
            (casilla[i][j].valor == 0)? (casilla[i][j].esModificable = true) : (casilla[i][j].esModificable = false);

            // Asigna a cada casilla el cuadrante en el que esta
            if     (i <= 2 && j <= 2) casilla[i][j].cuadrante = 1; // Las cuatro esquinas
            else if(i >= 6 && j <= 2) casilla[i][j].cuadrante = 3;
            else if(i <= 2 && j >= 6) casilla[i][j].cuadrante = 7;
            else if(i >= 6 && j >= 6) casilla[i][j].cuadrante = 9;
            else if(i >= 3 && i <= 5 && j <= 2) casilla[i][j].cuadrante = 2; // Las cuatro aristas
            else if(i <= 2 && j >= 3 && j <= 5) casilla[i][j].cuadrante = 4;
            else if(i >= 6 && j >= 3 && j <= 5) casilla[i][j].cuadrante = 6;
            else if(i >= 3 && i <= 5 && j >= 6) casilla[i][j].cuadrante = 8;
            else if(i >= 3 && i <= 5 && j >= 3 && j <= 5) casilla[i][j].cuadrante = 5; // El centro

            for(int posibleValor = 1; posibleValor <= 9; posibleValor++) {

            }
        }
    }

    for(int j = 0; j <= 8; j++) {
        for(int i = 0; i <= 8; i++) {
            if(casilla[i][j].esModificable) {
                createEmptyList(&casilla[i][j].posiblesValores);
                for(int valor = 1; valor <= 9; valor++) {
                    insertPosibleValor(valor, &casilla[i][j].posiblesValores);
                }
            } else {
                createEmptyList(&casilla[i][j].posiblesValores);
            }

        }
    }

    for(int j = 0; j <= 8; j++) {
        for(int i = 0; i <= 8; i++) {
            printf("Casilla[%d][%d]\n", i, j);
            mostrarPosiblesValoresCasilla(casilla[i][j].posiblesValores);
        }
    }

    printf("\n");
    imprimirSudoku(COLUMNAS, FILAS, casilla); // Imprime el sudoku por pantalla
    imprimirCasillasModificables(COLUMNAS, FILAS, casilla); // Imprime que casillas su pueden modificar y cuales no
    imprimirCuadrantes(COLUMNAS, FILAS, casilla); // Imprime el cuadrante de cada casilla


    return 0;
}
