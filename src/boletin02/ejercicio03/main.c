#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite por teclado dos
números enteros y que muestre un mensaje indicando si el primero es o no
divisible por el segundo. */

int main() {
    int num1, num2;

    printf("Escribe dos numero enteros separados por un espacio: ");
    scanf("%d %d", &num1, &num2);

    if((num1 % num2) == 0) {
        printf("\nEl numero %d es divisible por el %d", num1, num2);
    } else {
        printf("\nEstos dos numero no se pueden dividir entre si");
    }
    return 0;
}
