#include <stdio.h>
/*Plantee e implemente un programa en Lenguaje C que solicite un número
entero por teclado y muestre por pantalla si es positivo o negativo.*/

int main() {
    int numero;
    printf("Introduce un numero entero para saber su signo: ");
    scanf("%d", &numero);

    if(numero < 0) {
        printf("\nTu numero es negativo");
    } else if(numero == 0) {
        printf("\nEl numero 0 no tiene signo");
    } else {
        printf("\nEs un numero positivo");
    }
    return 0;
}
