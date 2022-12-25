#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite un número
entero por teclado y muestre por pantalla si es par o impar. */

int main() {
    int numero;

    printf("Escribe un numero entero para ver si es par o impar: ");
    scanf("%d", &numero);

    ((numero % 2) == 0)? printf("\nEl numero %d es par", numero) : printf("\nEl numero %d es impar", numero);
    // Hay dos opciones la primera, donde se ejecuta una parte u otra en funcion de si es verdadero o falso
    // Y la segunda, que esta comentada y que es mas intuitiva

/*
    if((numero % 2) == 0) {
        printf("\nEl numero %d es par", numero);
    } else {
        printf("\nEl numero %d es impar", numero);
    }*/
    return 0;
}
