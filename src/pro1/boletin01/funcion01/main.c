#include <stdio.h>
#include <math.h>

int main() {
    float x, y;
    const float K = 1;
    const float M = 2;

    printf("Escribe un valor de x para f(x) = (K(x-M)^2) / (1+K(x-M)^2)");
    printf("\nDonde K y M tienen los valores %.2f y %.2f", K, M);
    printf("\nInserta un valor de x:");
    scanf("%f", &x);

    y = (K*pow(x-M, 2))/(1+K*pow(x-M, 2));

    printf("El valor de f(X): %f",y);
    return 0;
}
