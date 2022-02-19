#include <stdio.h>

#include <windows.h>

void imprimirLineaHorizontal();
void generarTablero(int i, int j, char matriz[i][j]);

int main() {
    int turno = 0, fila, columna;
    char tablero[3][3];

    generarTablero(3, 3, tablero);

    do {
        imprimirLineaHorizontal();
        printf("| %c | %c | %c |\n", tablero[0][0], tablero[1][0], tablero[2][0]);
        imprimirLineaHorizontal();
        printf("| %c | %c | %c |\n", tablero[0][1], tablero[1][1], tablero[2][1]);
        imprimirLineaHorizontal();
        printf("| %c | %c | %c |\n", tablero[0][2], tablero[1][2], tablero[2][2]);
        imprimirLineaHorizontal();

        if((turno % 2) == 0) {
            printf("Escribe numero de fila y columna todo junto JUGADOR %d: ", (turno % 2)+1);
            scanf("%1d%1d", &fila, &columna);
            fflush(stdin);
            tablero[columna-1][fila-1] = 'X';
        } else if((turno % 2) == 1) {
            printf("Escribe numero de fila y columna todo junto JUGADOR %d: ", (turno % 2)+1);
            scanf("%1d%1d", &fila, &columna);
            fflush(stdin);
            tablero[columna-1][fila-1] = 'O';
        }

        system("cls");
        turno++;
    } while(turno<= 10);


    return 0;
}

void imprimirLineaHorizontal() {
    printf("+---+---+---+\n");
}

void generarTablero(int i, int j, char matriz[i][j]) {
    for(int fila = 0; fila <= j; fila++) {
        for(int columna = 0; columna <= i; columna++) {
            matriz[columna][fila] = ' ';
        }

    }
}


