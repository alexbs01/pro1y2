#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite por teclado los
lados de un rectángulo y muestre por pantalla su perímetro. Presente la salida
con el siguiente formato: */

int main() {
    float longitudBase;
    float longitudAltura;
    float perimetro;
    printf("Calcular perimetro del rectangulo\n");
    printf("Introduce la longitud de la base: ");
    scanf("%f", &longitudBase);

    printf("\nIntroduce la longitud de la altura: ");
    scanf("%f", &longitudAltura);

    perimetro = 2 * longitudBase + 2 * longitudAltura;

    printf("\nLa superficie del triangulo de base %.2f y altura %.2f es %.2f", longitudBase, longitudAltura, perimetro);
    /* El %.2f redondea a dos decimales*/
    return 0;
}
