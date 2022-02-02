#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define ENTER '\n'

void recogerLetras(int ancho, int alto, char letras[ancho*alto]);
void rellenarMatriz(int i, int j, char matriz[i][j], char elementos[i*j]);
void mostrarMatriz(int i, int j, char matriz[i][j]);
void buscarPalabra(int i, int j, char matriz[i][j], int longitud,  char palabra[longitud]);

int main() {
    int ancho = 15, alto = 15;

    printf("\nEscribe el ancho y el alto de la sopa de letras: ");
   // scanf("%d %d", &ancho, &alto);
    char letras[ancho*alto];
    char palabra[ancho];
    char sopa[ancho-1][alto-1]; //Crea una matriz con el tamano real que tendra la sopa

    //recogerLetras(ancho, alto, letras); //Recoge las letras de la sopa en un array unidimensional

    rellenarMatriz(ancho, alto, sopa, "aholafrojoklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstadios"); //Las letras recogidas antes, se transforman en una matriz bidimensional
    mostrarMatriz(ancho, alto, sopa); //Muestra la matriz con el formato de una sopa de letras

    printf("\nEscribe todas las palabras que deseas buscar separadas por espacios: ");
    do {
        scanf("%s", palabra);

        buscarPalabra(ancho, alto, sopa, strlen(palabra), palabra);
    } while(getchar() != ENTER);

    return 0;
}

void recogerLetras(int ancho, int alto, char letras[ancho*alto]) {
    int iterador = 0;
    printf("\nEscribe todas las letras seguidas y sin espacios: ");
    do {
        scanf("%s", letras);   //Guarda las letras en un array
        iterador++;
    } while(getchar() != ENTER); // El bucle para cuando entra un ENTER

}

void rellenarMatriz(int i, int j, char matriz[i][j], char elementos[i*j]) {
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

void buscarPalabra(int i, int j, char matriz[i][j], int longitud,  char palabra[longitud]) {
    bool palabraEncontrada = false, letraCoincidente = false;
    int contador = 0, fila = 0, columna = 0;

    do {
        do {
            if(matriz[columna][fila] == palabra[contador]) {
                letraCoincidente = true;
                contador++;
            } else if((contador == strlen(palabra)) && (letraCoincidente == true)) {
                palabraEncontrada = true;
                printf("\nSe encontro la palabra en fila %d y columna %d", fila, (int) (columna) - (int) (strlen(palabra)));
            } else {
                contador = 0;
                letraCoincidente = false;
            }

            columna++;
        } while((columna < i) || (palabraEncontrada != true));
        columna = 0;
        contador = 0;
        fila++;
    } while((fila < j) ||(palabraEncontrada != true));



   /* for (int fila = 0; (fila < j) || (palabraEncontrada == true); fila++) {
        for (int columna = 0; (columna < i) || (palabraEncontrada == true); columna++) {
            printf("\nLlegue hasta fila %d columna %d", fila, columna);
            if(matriz[columna][fila] == palabra[0]) {
                do {
                    if(matriz[columna + contador][fila] != palabra[contador]) {
                        palabraEncontrada = false;
                    }
                    printf("\nLlegue hasta aqui %d", contador);
                    contador++;
                } while(contador < longitud && palabraEncontrada == true);
                if(palabraEncontrada == true) {
                    printf("\nSe encontro la palabra la fila %d y columna %d", fila, columna);
                }
            }
        }
    }*/
    printf("\nSe encontro la palabra");
}

//2 2 abcd
//3 3 abcdefghi
//4 4 abcdefghijklmno
//5 5 abcdefghijklmnopqrstuvwxy
//10 10 abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy
//15 15 aholafrojoklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstadios
