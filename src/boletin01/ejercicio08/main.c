#include <stdio.h>

int main() {
    char nombre[30];
    int edad;
    float gastoCanas;
    float gastoTransporte;

    printf("Introduzca usted su nombre: ");
    scanf("%[^\n]", nombre);
    scanf("%*[^\n]");

    printf("Introduzca usted su edad: ");
    scanf(" %d", &edad);

    printf("Introduzca usted el total de sus gastos semanales en canhas (en euros): ");
    scanf(" %f", &gastoCanas);

    printf("Introduzca usted el total de sus gastos semanales en transporte (en euros): ");
    scanf("%f", &gastoTransporte);

    printf("Nombre: %s", nombre);
    printf("\nEdad: %d", edad);
    printf("\nGasto semanal en canhas: %.2f", gastoCanas);
    printf("\nGasto semanal en transporte: %.2f", gastoTransporte);
    printf("\nTotal gastos semanales: %.2f", gastoTransporte + gastoCanas);
    return 0;
}
