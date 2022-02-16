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
        printf("%d\t", fila+1);
        for (int columna = 0; columna < i; columna++) {
            printf("%c  ", matriz[columna][fila]);
        }
        printf("\n");
    }
}

bool buscarPalabraHorizontalDerecha(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;
    bool letrasCoincidentes = false;

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
               for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    if(palabra[longitudPalabra] == matriz[columna+longitudPalabra][fila]) {
                        letrasCoincidentes = true;
                    } else {
                        letrasCoincidentes = false;
                        break;
                    }
               }

            }
            if(letrasCoincidentes == true) break;

            columna++;
        } while(columna < i);
        if(letrasCoincidentes == true) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(letrasCoincidentes == true) {
        printf("\nSe encontro la palabra \"%s\" en\tFILA:%d COLUMNA:%d\t en posicion HORIZONTAL DERECHA", palabra, fila+1, columna+1);
        return true;
    } else {
        return false;
    }
}

bool buscarPalabraHorizontalIzquierda(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;
    bool letrasCoincidentes = false;

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
                for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    if(palabra[longitudPalabra] == matriz[columna-longitudPalabra][fila]) {
                        letrasCoincidentes = true;
                    } else {
                        letrasCoincidentes = false;
                        break;
                    }
                }

            }
            if(letrasCoincidentes == true) break;

            columna++;
        } while(columna < i);
        if(letrasCoincidentes == true) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(letrasCoincidentes == true) {
        printf("\nSe encontro la palabra \"%s\" en\tFILA:%d COLUMNA:%d\t en posicion HORIZONTAL IZQUIERDA", palabra, fila+1, columna+1);
        return true;
    } else {
        return false;
    }
}

bool buscarPalabraVerticalAbajo(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;
    bool letrasCoincidentes = false;

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
                for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    if(palabra[longitudPalabra] == matriz[columna][fila+longitudPalabra]) {
                        letrasCoincidentes = true;
                    } else {
                        letrasCoincidentes = false;
                        break;
                    }
                }

            }
            if(letrasCoincidentes == true) break;

            columna++;
        } while(columna < i);
        if(letrasCoincidentes == true) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(letrasCoincidentes == true) {
        printf("\nSe encontro la palabra \"%s\" en\tFILA:%d COLUMNA:%d\t en posicion VERTICAL DESCENDENTE", palabra, fila+1, columna+1);
        return true;
    } else {
        return false;
    }
}

bool buscarPalabraVerticalArriba(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;
    bool letrasCoincidentes = false;

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
                for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    if(palabra[longitudPalabra] == matriz[columna][fila-longitudPalabra]) {
                        letrasCoincidentes = true;
                    } else {
                        letrasCoincidentes = false;
                        break;
                    }
                }

            }
            if(letrasCoincidentes == true) break;

            columna++;
        } while(columna < i);
        if(letrasCoincidentes == true) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(letrasCoincidentes == true) {
        printf("\nSe encontro la palabra \"%s\" en\tFILA:%d COLUMNA:%d\t en posicion VERTICAL ASCENDENTE", palabra, fila+1, columna+1);
        return true;
    } else {
        return false;
    }
}

bool buscarPalabraDiagonalDerechaAbajo(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;
    bool letrasCoincidentes = false;

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
                for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    if(palabra[longitudPalabra] == matriz[columna+longitudPalabra][fila+longitudPalabra]) {
                        letrasCoincidentes = true;
                    } else {
                        letrasCoincidentes = false;
                        break;
                    }
                }

            }
            if(letrasCoincidentes == true) break;

            columna++;
        } while(columna < i);
        if(letrasCoincidentes == true) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(letrasCoincidentes == true) {
        printf("\nSe encontro la palabra \"%s\" en\tFILA:%d COLUMNA:%d\t en posicion DIAGONAL DERECHA DESCENDENTE", palabra, fila+1, columna+1);
        return true;
    } else {
        return false;
    }
}

bool buscarPalabraDiagonalDerechaArriba(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;
    bool letrasCoincidentes = false;

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
                for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    if(palabra[longitudPalabra] == matriz[columna+longitudPalabra][fila-longitudPalabra]) {
                        letrasCoincidentes = true;
                    } else {
                        letrasCoincidentes = false;
                        break;
                    }
                }

            }
            if(letrasCoincidentes == true) break;

            columna++;
        } while(columna < i);
        if(letrasCoincidentes == true) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(letrasCoincidentes == true) {
        printf("\nSe encontro la palabra \"%s\" en\tFILA:%d COLUMNA:%d\t en posicion DIAGONAL DERECHA ASCENDENTE", palabra, fila+1, columna+1);
        return true;
    } else {
        return false;
    }
}

bool buscarPalabraDiagonalIzquierdaAbajo(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;
    bool letrasCoincidentes = false;

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
                for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    if(palabra[longitudPalabra] == matriz[columna-longitudPalabra][fila+longitudPalabra]) {
                        letrasCoincidentes = true;
                    } else {
                        letrasCoincidentes = false;
                        break;
                    }
                }

            }
            if(letrasCoincidentes == true) break;

            columna++;
        } while(columna < i);
        if(letrasCoincidentes == true) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(letrasCoincidentes == true) {
        printf("\nSe encontro la palabra \"%s\" en\tFILA:%d COLUMNA:%d\t en posicion DIAGONAL IZQUIERDA DESCENDENTE", palabra, fila+1, columna+1);
        return true;
    } else {
        return false;
    }
}
bool buscarPalabraDiagonalIzquierdaArriba(int i, int j, char matriz[i][j], int longitud, char palabra[longitud]) {
    int fila = 0, columna = 0;
    bool letrasCoincidentes = false;

    do {
        do {
            if(palabra[0] == matriz[columna][fila]) {
                for(int longitudPalabra = 0; longitudPalabra < longitud; longitudPalabra++) {
                    if(palabra[longitudPalabra] == matriz[columna-longitudPalabra][fila-longitudPalabra]) {
                        letrasCoincidentes = true;
                    } else {
                        letrasCoincidentes = false;
                        break;
                    }
                }

            }
            if(letrasCoincidentes == true) break;

            columna++;
        } while(columna < i);
        if(letrasCoincidentes == true) break;

        columna = 0;
        fila++;
    } while(fila < j);

    if(letrasCoincidentes == true) {
        printf("\nSe encontro la palabra \"%s\" en\tFILA:%d COLUMNA:%d\t en posicion DIAGONAL IZQUIERDA ASCENDENTE", palabra, fila+1, columna+1);
        return true;
    } else {
        return false;
    }
}
