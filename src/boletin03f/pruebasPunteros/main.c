#include <stdio.h>
int entero();
void pedirEntero(int * numero);
int main() {
    int n;
    n = entero();
    pedirEntero(&n);
    return 0;
}
int entero() {
    int numero;
    printf("Introduzca un numero: ");
    scanf("%d", &numero);
    return numero;
}
void pedirEntero(int * numero) {
    printf("Introduzca un numero entero: ");
    scanf("%d", numero);
}
