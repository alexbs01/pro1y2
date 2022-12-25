#include <stdio.h>

void intercambioDeValoresPorReferencia(int *a, int *b);
void intercambioDeValoresPorValor(int a, int b);
int suma(int a, int b);

int main() {
    int valor1 = 2, valor2 = 3;

    printf("El valor de a es %d y el de b es %d\n", valor1, valor2);

    intercambioDeValoresPorValor(valor1, valor2);
    printf("El valor de a es %d y el de b es %d\n", valor1, valor2);

    intercambioDeValoresPorReferencia(&valor1, &valor2);
    printf("El valor de a es %d y el de b es %d\n", valor1, valor2);

    printf("La suma de a y b es: %d\n", suma(valor1, valor2));
    return 0;
}

void intercambioDeValoresPorReferencia(int *a, int *b) {
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void intercambioDeValoresPorValor(int a, int b) {
    int c;

    c = a;
    a = b;
    b = c;
}

int suma(int a, int b) {
    return a + b;
}