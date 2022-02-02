#include <stdio.h>

int main() {
    int cantidadFinal, cont = 1, resultado = 0;
    printf("Calcula la suma de los primeros 'n' numeros, n = ");
    scanf("%d", &cantidadFinal);

    while(cont<=cantidadFinal) {
        resultado += cont;
        cont++;
    }
    printf("\nLa suma con el numero DO-WHILE es: %d", resultado);

    // Preparacion reinicio de variables para el segundo bucle
    resultado = 0;
    cont = 1;
    do {
       resultado += cont;
        cont++;
    } while(cont<=cantidadFinal);
    printf("\nLa suma con el numero WHILE es: %d", resultado);

    resultado = 0;
    for(int i = 1; i <= cantidadFinal; i++) {
        resultado += i;
    }

    printf("\nLa suma con el numero FOR es: %d", resultado);
    return 0;
}
