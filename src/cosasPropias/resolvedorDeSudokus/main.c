#include <stdio.h>
#include <stdbool.h>
#include "tipoCasilla.h"
#include "funcionesResolvedor.h"

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
        }
    }

    imprimirSudoku(COLUMNAS, FILAS, casilla); // Imprime el sudoku por pantalla
    return 0;
}
