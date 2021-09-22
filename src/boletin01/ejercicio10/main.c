#include <stdio.h>

int main() {
    int vX1, vY1, vZ1;
    int vX2, vY2, vZ2;
    int resultado;

    printf("Coordenadas cartesianas primer vector (separadas por espacio): ");
    scanf("%d %d %d[^\n]", &vX1, &vY1, &vZ1);

    printf("\nCoordenadas cartesianas segundo vector (separadas por espacio): ");
    scanf("%d %d %d[^\n]", &vX2, &vY2, &vZ2);

    resultado = vX1 * vX2 + vY1 * vY2 + vZ1 * vZ2;

    printf("\nEl producto escalar es: %d", resultado);
    return 0;
}
