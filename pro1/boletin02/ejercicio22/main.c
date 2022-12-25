#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que sume los primeros 100
números enteros pares por una parte y los impares por otra. */

int main() {
    int finalDeLaSuma, resultadoPares = 0, resultadoImpares = 0;

    printf("Escribe el numero hasta el que sumaras los pares y los pares: ");
    scanf("%d", &finalDeLaSuma);

    for(int i = 0; i <= finalDeLaSuma; i++) {
        if((i % 2) == 0) {
            resultadoPares = resultadoPares + i;
        } else {
            resultadoImpares = resultadoImpares + i;
        }
    }

    printf("\nLa suma de los pares es: %d", resultadoPares);
    printf("\nLa suma de los impares es: %d", resultadoImpares);

    return 0;
}

