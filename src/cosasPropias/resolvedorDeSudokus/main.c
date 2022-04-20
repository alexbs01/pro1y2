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
    tLista numerosFijosPorCuadrante[COLUMNAS], numerosFijosPorFilas[FILAS], numerosFijosPorColumnas[COLUMNAS];
    bool continuarDandoVueltas = false;

    for(int i = 0; i <= 8; i++) { // Inicializar la lista de numeros fijos por cuadrante
        createEmptyList(&numerosFijosPorCuadrante[i]);
        createEmptyList(&numerosFijosPorColumnas[i]);
        createEmptyList(&numerosFijosPorFilas[i]);
    }

    /*
     * APERTURA DEL FICHERO
     */
    printf("\nEscribe el nombre del fichero que contiene el sudoku: ");
    gets(fichero); // Guarda el nombre del fichero
    ficheroSudoku = fopen(fichero, "r"); // Abre el fichero en modo lectura
    if(ficheroSudoku == NULL) { // Si no lo puede abrir muestra el mensaje de error y se termina la ejecucion
        printf("\nNo se pudo abrir el fichero");
        return 1;
    }

    printf("\n");

    /*
     * RECOGIDA DE DATOS DEL FICHERO Y ASIGNACION DE LOS VALORES CORREPONDIENTES A CADA CASILLA
     */
    for(int j = 0; j < FILAS; j++) {
        fgets(linea, 19, ficheroSudoku); // Por cada iteracion coge desde la primera fila hasta la ultima y la almacena en "linea"

        // La fila alamacenada en la variable "linea", se descompone en 9 numeros que se guardan en las 9 posiciones del array "numero"
        sscanf(linea, "%d %d %d %d %d %d %d %d %d", &numero[0], &numero[1], &numero[2], &numero[3], &numero[4], &numero[5], &numero[6], &numero[7], &numero[8]);

        for(int i = 0; i < COLUMNAS; i++) {
            casilla[i][j].valor = numero[i]; // Se guarda cada fila de "numero" en cada fila de "casilla"

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

            /* En funcion de si la casilla es 0 o no, se decide si es un valor modificable o fijo
            * en ambos casos crea una lista vacia, y la rellena si es de un valor modificable*/
            if(casilla[i][j].valor == 0) { // Es modificable
                casilla[i][j].esModificable = true;
                createEmptyList(&casilla[i][j].posiblesValores);
                for(int valor = 1; valor <= 9; valor++) {
                    insertPosibleValor(valor, &casilla[i][j].posiblesValores);
                }
            } else { // Es fijo
                casilla[i][j].esModificable = false;
                createEmptyList(&casilla[i][j].posiblesValores);
                // Tambien se inserta ese valor en una lista que almacena los valores fijos por cuadrante
                insertPosibleValor(casilla[i][j].valor, &numerosFijosPorCuadrante[ casilla[i][j].cuadrante ] - 1);
                insertPosibleValor(casilla[i][j].valor, &numerosFijosPorColumnas[ i ]);
                insertPosibleValor(casilla[i][j].valor, &numerosFijosPorFilas[ j ]);
            }
        }
    }

    /*
     * IMPRIMIR EL SUDOKU E INFORMACION DEL MISMO (casillas modificables y cuadrantes)
     */
    printf("\n");
    imprimirSudoku(COLUMNAS, FILAS, casilla); // Imprime el sudoku por pantalla

    /*
     * SE RESUELVE EL SUDOKU
     */
    for(int numeroMaximoVueltas = 0; numeroMaximoVueltas <= 10; numeroMaximoVueltas++) {
        for(int j = 0; j <= 8; j++) {
            for(int i = 0; i <= 8; i++) {
                if(casilla[i][j].esModificable) {
                    borrarComunes(&casilla[i][j].posiblesValores, numerosFijosPorFilas[j]);
                    borrarComunes(&casilla[i][j].posiblesValores, numerosFijosPorCuadrante[casilla[i][j].cuadrante - 1]);
                    borrarComunes(&casilla[i][j].posiblesValores, numerosFijosPorColumnas[i]);
                    continuarDandoVueltas = true;
                }
                if(casilla[i][j].esModificable && casilla[i][j].posiblesValores->next == LNULL) {
                    casilla[i][j].valor = firstNumber(casilla[i][j].posiblesValores);
                    casilla[i][j].esModificable = false;
                    insertPosibleValor(casilla[i][j].valor, &numerosFijosPorCuadrante[ casilla[i][j].cuadrante ] - 1);
                    insertPosibleValor(casilla[i][j].valor, &numerosFijosPorColumnas[ i ]);
                    insertPosibleValor(casilla[i][j].valor, &numerosFijosPorFilas[ j ]);
                }

            }
        }
        if(continuarDandoVueltas) {
            continuarDandoVueltas = false;
        } else {
            printf("+++++++++++++++++++++++++++++++ En %d vueltas\n\n", numeroMaximoVueltas);
            break;
        }
    }

    // Se imprime la solución del sudoku a la que se llego, si no se puedo resolver, mostrara
    // todo lo que pudo resolver
    imprimirSudoku(COLUMNAS, FILAS, casilla); // Imprime el sudoku por pantalla

    return 0;
}
