#include <stdio.h>
#include <math.h>
#define K 1
#define M 2

int main() {
    float x, y;

    printf("Escribe un valor de x para f(x) = (K(x-M)^2) / (1+K(x-M)^2)");
    printf("\nInserta un valor de x:");
    scanf("%f", &x);

    y = (K*pow(x-M, 2))/(1+K*pow(x-M, 2));

    printf("El valor de f(X): %f",y);
    return 0;
}
