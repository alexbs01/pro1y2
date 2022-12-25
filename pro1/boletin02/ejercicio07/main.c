#include <stdio.h>
#include <math.h>

/* Implemente un programa que resuelva ecuaciones de segundo grado
empleando sentencias switch para los casos: reales y distintas, complejas
conjugadas y raíz real doble. */

int main() {
    float a, b ,c;
    float interiorRaiz;
    float x1, x2;

    printf("En la ecuacion ax^2 + bx + c = 0\n");
    printf("Introduce los valores de a, b y c separados por espacios: ");
    scanf("%f %f %f", &a, &b, &c);

    interiorRaiz = powf(b, 2) - 4 * a * c;

    switch (a || b == 0) {
        case 0:
            if (a == 0) {
                printf("\nLa solucion es: %f", -c/b);
            } else if (b == 0) {
                printf("\nLas soluciones son: %f y -%f", sqrtf(-c/a), sqrtf(-c/a));
            }

            break;
        default:
            if (interiorRaiz > 0) {
                x1 = (-b + sqrtf(interiorRaiz)) / (2 * a);
                x2 = (-b - sqrtf(interiorRaiz)) / (2 * a);
                printf("\nLas soluciones son: %.2f y %.2f", x1, x2);
            } else if (interiorRaiz == 0) {
                x1 = -b / (2 * a);
                printf("\nLa solucion es: %.2f", x1);
            } else if (interiorRaiz < 0) {
                x1 = sqrtf(-interiorRaiz) / (2 * a);
                x2 = -sqrtf(-interiorRaiz) / (2 * a);
                printf("\nLas soluciones son: %.2f +%.2f i y %.2f %.2f i", -b / (2 * a), x1, -b / (2 * a), x2);
            }
            break;
    }
    return 0;
}
