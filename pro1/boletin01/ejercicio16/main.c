#include <stdio.h>
// Suma de dos matrices de de 2x2

int main() {
    float pos11A, pos12A, pos21A, pos22A;
    float pos11B, pos12B, pos21B, pos22B;

    printf("Escribe los cuatro numeros de la matriz, separados por un espacio con las posiciones del ejemplo");
    printf("\n[11] [12]\n[21] [22]\nNumeros: ");
    scanf("%f %f %f %f", &pos11A, &pos12A, &pos21A, &pos22A);

    printf("\nY ahora de la segundo matriz: ");
    scanf("%f %f %f %f", &pos11B, &pos12B, &pos21B, &pos22B);

    printf("\n[%.2f] [%.2f]\n[%.2f] [%.2f]", pos11A + pos11B, pos12A + pos12B, pos21A + pos21B, pos22A +pos22B);

    return 0;
}
