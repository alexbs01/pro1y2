#include <stdio.h>
#define PI 3.14 // Define una constante

//Plantee e implemente un programa en Lenguaje C que pida el radio de una esfera y calcule su área y su volumen.

int main() {
    float radio;
    float areaEsfera;
    float volumenEsfera;

    printf("Calcular area y volumen de una esfera\n");
    printf("Cual es el radio de tu esfera: ");
    scanf("%f", &radio);

    areaEsfera = 4 * PI * radio*radio;
    volumenEsfera = (4/3) * PI * radio*radio*radio;

    printf("\nEl area de la esfera de radio %.2f es %.2f y su volumen es %.2f", radio, areaEsfera, volumenEsfera);
    return 0;
}
