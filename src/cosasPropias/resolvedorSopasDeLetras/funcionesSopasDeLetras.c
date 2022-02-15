//
// Created by alexb on 14/02/2022.
//

#include "funcionesSopasDeLetras.h"

void recogerLetras(int ancho, int alto, char letras[ancho*alto]) {
    int iterador = 0;
    printf("\nEscribe todas las letras seguidas y sin espacios: ");
    do {
        scanf("%s", letras);   //Guarda las letras en un array
        iterador++;
    } while(getchar() != ENTER); // El bucle para cuando entra un ENTER

}

void rellenarMatriz(int i, int j, char matriz[i][j], const char  elementos[i*j]) {
    int indiceElementos = 0;

    printf("\n");
    for(int fila = 0;  fila < j; fila++) {
        for(int columna = 0; columna < i; columna++) {
            matriz[columna][fila] = elementos[indiceElementos];
            printf("%c ", matriz[columna][fila]);
            indiceElementos++;
        }
    }
    printf("\n");

}

void mostrarMatriz(int i, int j, char matriz[i][j]) {
    printf("\n\n");

    for (int fila = 0; fila < j; fila++) {
        for (int columna = 0; columna < i; columna++) {
            printf("%c  ", matriz[columna][fila]);
        }
        printf("\n");
    }
}

void buscarPalabra(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;

    char posiblePalabra[longitud];
    //pChar posiblePalabra = (char*) malloc((int) sizeof(char)*longitud*8);

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
                 /*do {
                    posiblePalabra[longitudPalabra] = matriz[columna+longitudPalabra][fila];
                    longitudPalabra++;
                } while(longitudPalabra < longitud);*/

               for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    posiblePalabra[longitudPalabra] = matriz[columna+longitudPalabra][fila];
               }

            }
            if(strcmp(palabra, posiblePalabra)==0) break;

            columna++;
        } while(columna < i);
        if(strcmp(posiblePalabra, palabra)==0) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(strcmp(posiblePalabra, palabra)==0) {
        printf("\nSe encontro la palabra \"%s\" en fila %d y columna %d", palabra, fila+1, columna+1);
    } else {
        printf("\nNo se encontro la palabra \"%s\" en ninguna linea horizontal", palabra);
    }
    //free(posiblePalabra);
}
// No encuntra palabras con 1, 2, 8, 9, 10 ,11, 12, 13, 17, 18, 24, 25, 26, 27, 28 o 29 letras