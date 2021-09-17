#include <stdio.h>
// Calculo de precios sumando el IVA del 24%
int main() {
    float precio;
    printf("Precio del producto sin IVA (24%%): \b");
    scanf("%f", &precio);

    printf("El importe total (IVA incluido) es de %.2f euros\n", precio * 1.24);
    return 0;
}
