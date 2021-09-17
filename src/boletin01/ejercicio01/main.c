#include <stdio.h>

int main() {
    char nombre[30];
    int edad;
    printf("\nIntroduzca su nombre: ");
    gets(nombre);

    printf("\nIntroduzca su edad: ");
    scanf("%d", &edad);

    printf("\nBuenos dias, %s, tiene usted %d anhos", nombre, edad);
    return 0;
}
