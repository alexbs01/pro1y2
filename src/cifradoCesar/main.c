#include <stdio.h>
#include <string.h>
#define LONGITUD 1000
int main() {
    char texto[LONGITUD];

    printf("Escribe un texto para cifrar: ");
    gets(texto);

    printf("\nEl texto escrito es: %s\n", texto);
    printf("El texto cifrado es: ");
    for(int i = 0; i <= strlen(texto); i++) {
        printf("%c", texto[i] + 1);
    }

    printf("\n\nSi el esta texto cifrado, el texto descifrado es:\n");
    for(int i = 0; i <= strlen(texto); i++) {
        printf("%c", texto[i] - 1);
    }
    return 0;
}
