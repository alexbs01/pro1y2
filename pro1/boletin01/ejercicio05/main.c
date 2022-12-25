#include <stdio.h>

int main() {
    float longitudBase;
    float longitudAltura;
    float superficie;
    printf("Calcular area del rectangulo\n");
    printf("Introduce la longitud de la base: ");
    scanf("%f", &longitudBase);

    printf("\nIntroduce la longitud de la altura: ");
    scanf("%f", &longitudAltura);

    superficie = longitudBase * longitudAltura;

    printf("\nLa superficie del triangulo de base %.2f y altura %.2f es %.2f", longitudBase, longitudAltura, superficie);
    /* El %.2f redondea a dos decimales*/
    return 0;
}
