#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que muestre por pantalla tres
números enteros introducidos por teclado ordenados de menor a mayor. */

int main() {
    int a, b, c;

    printf("Escribe 3 numeros enteros distintos separados por espacios para ordenarlos por tamano: ");
    scanf("%d %d %d", &a, &b, &c);

    // Metodo de la profesora
    if(a < b) {
        if(b < c) {
            printf("%d < %d < %d", a, b, c);
        } else {
            printf("%d < %d < %d", a, c, b);
        }
    } else if(b < a) {
        if(a < c) {
            printf("%d < %d < %d", b, a, c);
        } else {
            printf("%d < %d < %d", b, c, a);
        }
    } else if(c < a) {
        if(a < b) {
            printf("%d < %d < %d", c, a, b);
        } else {
            printf("%d < %d < %d", c, b, a);
        }
    }

    // Metodo propio
    /*
    if ((a < b) && (a < c)) {
        printf("\n%d < ", a);
        (b<c)? printf(" %d < %d", b, c) : printf(" %d < %d", c, b);

    } else if ((b < a) && (b < c)) {
        printf("\n%d <", b);
        (a<c)? printf(" %d < %d", a, c) : printf(" %d < %d", c, a);

    } else if ((c < a) && (c < b)) {
        printf("\n%d <", c);
        (a<b)? printf(" %d < %d", a, b) : printf(" %d < %d", b, a);
    }*/
    return 0;
}