#include <stdio.h>
#define PI 3.1415926
// Perimetro y area de tres circulos en forma de tabla

int main() {
    float radio1, perimetro1, area1;
    float radio2, perimetro2, area2;
    float radio3, perimetro3, area3;

    printf("Introduce los tres radios de los circulos separados por un espacio: ");
    scanf("%f %f %f", &radio1, &radio2, &radio3);

    perimetro1 = 2 * PI * radio1;
    perimetro2 = 2 * PI * radio2;
    perimetro3 = 2 * PI * radio3;

    area1 = PI * radio1 * radio1;
    area2 = PI * radio2 * radio2;
    area3 = PI * radio3 * radio3;

    printf("\nRadio\t\tPerimetro\t\tArea");
    printf("\n=====\t\t=========\t\t====");
    printf("\n%.2f\t\t%.2f\t\t\t%.2f", radio1, perimetro1, area1);
    printf("\n%.2f\t\t%.2f\t\t\t%.2f", radio2, perimetro2, area2);
    printf("\n%.2f\t\t%.2f\t\t\t%.2f", radio3, perimetro3, area3);
    return 0;
}
