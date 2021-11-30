#include <stdio.h>
/* Realiza un programa en  lenguaje C gestionado por un menu iterativo que muestre, en pantalla,
 * y permite las opciones (excatamente M,I,S EN MAYÚSCULAS):
 *
M) odificar el contenido de una matriz de NxM enteros positivos
I) permitira mostrar cuantos multiplos de 2 y 7 hay almacenados en la matriz, el minimo y el promedio.
S) permitira terminar el programa, mostrando los creditos (FIN PROGRAMA)
la matriz debera estar inicializada con el valor 1 en todas las celda */

int pedirColumnasMatriz();
int pedirFilasMatriz();
void inicializarMatriz(int i, int j, int matriz[i][j], int valorInicio);
void opciones(int filas, int columnas, int matriz[filas][columnas]);
void modificarMatriz(int filas, int columnas, int matriz[filas][columnas]);
void buscarMultiplos(int i, int j, int matriz[i][j]);
void buscarMinimo(int i, int j, int matriz[i][j]);
void calcularValorMedio(int i, int j, int matriz[i][j]);
void mostrarMatriz(int i, int j, int matriz[i][j]);

int main() {
    int columnas, filas, inicio = 1;
    columnas = pedirColumnasMatriz();
    filas = pedirFilasMatriz();
    int matriz[filas][columnas];

    inicializarMatriz(columnas, filas, matriz, inicio);
    opciones(filas, columnas, matriz);
    mostrarMatriz(columnas, filas, matriz);
    printf("\nPrograma hecho por Alejandro Becerra Suarez");
    return 0;
}

int pedirColumnasMatriz() {
    int valor;
    printf("\nEscribe el numero de columnas que tendra la matriz: ");
    scanf("%d", &valor);
    return valor;
}

int pedirFilasMatriz() {
    int valor;
    printf("\nEscribe el numero de filas que tendra la matriz: ");
    scanf("%d", &valor);
    return valor;
}

void inicializarMatriz(int i, int j, int matriz[i][j], int valorInicio) {
    printf("\n");

    for(int columna = 0;  columna < j; columna++) {
        for(int fila = 0; fila < i; fila++) {
            matriz[fila][columna] = valorInicio;
        }
    }
}

void opciones(int filas, int columnas, int matriz[filas][columnas]) {
    char opcion;
    do {
        mostrarMatriz(filas, columnas, matriz);
        printf("\nEscoge una de estas opciones"
               "\nM) Modificar la matriz"
               "\nI) Mostrar los multiplos, de 2 y 7, el valor minimo y el valor medio"
               "\nS) Salir"
               "\nOpcion: ");
        scanf(" %c[~\n]", &opcion);

        switch(opcion) {
            case 'M':
                modificarMatriz(filas, columnas, matriz);
                break;
            case 'I':
               buscarMultiplos(filas, columnas, matriz);
               buscarMinimo(filas, columnas, matriz);
              calcularValorMedio(filas, columnas, matriz);
                break;
            case 'S': break;
            default:
                printf("\nEsa opcion no es valida.");
        }
    } while(opcion != 'S');
}

void modificarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    int posicionFila, posicionColumna, nuevoValor;
    printf("\nSeleccionaste la opcion de modificar la matriz."
           "\nEscoge una posicion entre [1, %d] para la fila y [1, %d] para la columna, pon el nuevo valor despues: ", filas, columnas);
    scanf("%d %d %d", &posicionFila, &posicionColumna, &nuevoValor);
    matriz[posicionColumna - 1][posicionFila - 1] = nuevoValor;
}

void buscarMultiplos(int i, int j, int matriz[i][j]) {
    printf("\n");
    int contadorMultiplos2 = 0, contadorMultiplos7 = 0;

    for(int columna = 0;  columna < j; columna++) {
        for(int fila = 0; fila < i; fila++) {

            if(matriz[columna][fila] % 2 == 0) {
                contadorMultiplos2++;
            }
            if(matriz[columna][fila] % 7 == 0) {
                contadorMultiplos7++;
            }
        }
    }
    printf("\nExisten %d multiplos de 2 y %d multiplos de 7", contadorMultiplos2, contadorMultiplos7);
}
void buscarMinimo(int i, int j, int matriz[i][j]) {
    printf("\n");
    int minimo = matriz[1][1];
    for(int columna = 0;  columna < j; columna++) {
        for(int fila = 0; fila < i; fila++) {
            if(matriz[1][1] > matriz[columna][fila]) {
                 minimo = matriz[columna][fila];
            }
        }
    }
    printf("El minimo de la matriz es: %d", minimo);
}
void calcularValorMedio(int i, int j, int matriz[i][j]) {
    printf("\n");
    //int ;
    float media, suma = 0, cantidadElementos = i*j;
    for(int columna = 0;  columna < j; columna++) {
        for(int fila = 0; fila < i; fila++) {
            suma += matriz[columna][fila];
        }
    }
    media = suma/cantidadElementos;
    printf("La media de todos los elementos es: %f", media);
}

void mostrarMatriz(int i, int j, int matriz[i][j]) {
    printf("\n");

    for(int columna = 0;  columna < j; columna++) {
        for(int fila = 0; fila < i; fila++) {
            printf("%d  ", matriz[fila][columna]);
            if(fila == i - 1) {
                printf("\n");
            }
        }
    }
}
