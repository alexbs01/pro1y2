#include <stdio.h>
#define EDAD_JUBILACION 67

int main() {
    char apellido[30];
    int edad;
    int edadParaJubilacion=0;

    printf("Apellido:\b");
    scanf(" %[^\n]", &apellido);
    /* Lee todo hasta el \n si pusieramos %2[^\n] leeria solo dos caracteres */
    /* Hay que tener cuidado con esto porque pueden quedar cosas en el buffer de entrada,
     *  para evitar estos problemas hay que añadir debajo de la recogida de datos:
     *  scanf(%*[^\n]);
     *  */

    printf("\nEdad:\b");
    scanf("%d", &edad);
    edadParaJubilacion = EDAD_JUBILACION - edad;
    printf("\nSr/Sra. %s, le faltan aun %d anhos para jubilarse", apellido, EDAD_JUBILACION - edad);
    // Se pueden hacer operaciones en el printf
    return 0;
}
