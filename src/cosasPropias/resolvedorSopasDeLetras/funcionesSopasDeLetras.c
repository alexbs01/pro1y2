#include "funcionesSopasDeLetras.h"

void recogerLetras(int ancho, int alto, char letras[ancho*alto]) {
    int iterador = 0;
    printf("\nEscribe todas las letras seguidas y sin espacios: ");
    do {
        scanf("%s", letras);   //Guarda las letras en un array
        iterador++;
    } while(getchar() != ENTER); // El bucle para cuando entra un ENTER

}

// Transforma el array unidimensional en uno bidimensional
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

// Muestra el array de dos dimensiones por pantalla, haciendo que sea como una sopa
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

/* Busca la palabra que entre como parametro en posicion horizontal y en el sentido habitual de la palabra,
 * recorre todas las letras buscando las que coincidan con la primera letra de la palabra, llegado a ese punto,
 * compara las n letras de la palabra con las n siguientes letras de la matriz. Si son identicas, dira que esa es
 * la palabra buscada, en caso contrario, continuara la busqueda por donde la dejo*/
// El resto de funciones funcionan exactamente igual, solo que que cambiando el sentido de busqueda
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
