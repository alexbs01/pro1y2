#include <stdio.h>
#include <string.h>
#define LONGITUD 1000
int main() {
    char texto[LONGITUD];
    int clave;
    printf("Escribe un texto para cifrar: ");
    gets(texto);

    printf("\nEscribe un numero que servira de clave para cifar: ");
    scanf("%d", &clave);

    printf("\nEl texto escrito es: %s\n", texto);
    printf("El texto cifrado es: ");
    for(int i = 0; i <= strlen(texto); i++) {
        printf("%c", texto[i] + clave);
    }

    printf("\n\nSi el esta texto cifrado, el texto descifrado es:\n");
    for(int i = 0; i <= strlen(texto); i++) {
        printf("%c", texto[i] - clave);
    }
    return 0;
}
