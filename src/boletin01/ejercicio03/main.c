#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite por teclado la
base y altura de un triángulo rectángulo y muestre por pantalla su superficie.
Presente la salida con el siguiente formato:
 */
 
int main() {
    float longitudBase=0.00;
    float longitudAltura=0.00;
    float superficie;
    printf("Calcular area del triangulo\n");
    printf("Introduce la longitud de la base: ");
    scanf("%f", &longitudBase);

    printf("\nIntroduce la longitud de la altura: ");
    scanf("%f", &longitudAltura);

    superficie = (longitudBase * longitudAltura)/2;

    printf("\nLa superficie del triángulo de base %f y altura %f es %f", longitudBase, longitudAltura, superficie);
    return 0;
}
