#include <stdio.h>
#define POSICION1 (fila - 2 == filaTablero) && (columna - 1 == columnaTablero)
#define POSICION2 (fila - 2 == filaTablero) && (columna + 1 == columnaTablero)
#define POSICION3 (fila - 1 == filaTablero) && (columna + 2 == columnaTablero)
#define POSICION4 (fila + 1 == filaTablero) && (columna + 2 == columnaTablero)
#define POSICION5 (fila + 2 == filaTablero) && (columna + 1 == columnaTablero)
#define POSICION6 (fila + 2 == filaTablero) && (columna - 1 == columnaTablero)
#define POSICION7 (fila + 1 == filaTablero) && (columna - 2 == columnaTablero)
#define POSICION8 (fila - 1 == filaTablero) && (columna - 2 == columnaTablero)
#define POSICIONES_POSIBLES POSICION1 || POSICION2 || POSICION3 || POSICION4 || POSICION5 || POSICION6 || POSICION7 || POSICION8

void tablero(int fila, int columna);
void casillasFilasImpares(int fila, int filaTablero, int columna, int columnaTablero);
void casillasFilasPares(int fila, int filaTablero, int columna, int columnaTablero);
int main() {
    int fila, columna;
    do {
        printf("Posicion del caballo (fila columna [1,8]) : ");
        scanf("%d %d", &fila, &columna);
        printf("\n");
    } while((fila < 1 || fila > 8) || (columna < 1 || columna > 8));
    tablero(fila, columna);
    return 0;
}
void tablero(int fila, int columna) {
    for(int filaTablero = 1; filaTablero <= 8; filaTablero++) {
        if(filaTablero % 2 == 1) {
            for (int columnaTablero = 1; columnaTablero <= 8; columnaTablero++) {
                casillasFilasImpares(fila, filaTablero, columna, columnaTablero);
            }
            printf("\n");
        } else {
            for (int columnaTablero = 1; columnaTablero <= 8; columnaTablero++) {
                casillasFilasPares(fila, filaTablero, columna, columnaTablero);
            }
            printf("\n");
        }
    }
}
void casillasFilasImpares(int fila, int filaTablero, int columna, int columnaTablero) {
    if(fila == filaTablero && columna == columnaTablero) {
        printf("H  ");
    } else if(POSICIONES_POSIBLES) {
        printf("?  ");
    } else {
        if (columnaTablero % 2 == 1) {
            printf("B  ");
        } else {
            printf("N  ");
        }
    }
}
void casillasFilasPares(int fila, int filaTablero, int columna, int columnaTablero) {
    if(fila == filaTablero && columna == columnaTablero) {
        printf("H  ");
    } else if(POSICIONES_POSIBLES) {
        printf("?  ");
    } else {
        if (columnaTablero % 2 == 1) {
            printf("N  ");
        } else {
            printf("B  ");
        }
    }
}
