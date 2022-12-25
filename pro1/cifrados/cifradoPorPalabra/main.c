#include <stdio.h>
#include <string.h>
#define LONGITUD 1000

int main() {
    char texto[LONGITUD], clave[LONGITUD];
    int j = 0;
    printf("\nEscribe el texto que quieres cifrar: ");
    gets(texto);

    printf("\nEscribe una palabara con la que se cifrara el mensaje: ");
    gets(clave);

    printf("\n");
    for(int i = 0; i <= strlen(texto); i++) {
        printf("%c", texto[i]);
        printf("%c\n", clave[j]);
        j++;
        if (j == strlen(clave)) {
            j = 0;
        }
    }

    printf("\nEl texto cifrado es: ");
    for(int i = 0; i <= strlen(texto); i++) {
        printf("%c", texto[i] + clave[j]);
        j++;
        if (j == strlen(clave)-1) {
            j = 0;
        }
    }

    j = 0;
    printf("\nEl texto descifrado es: ");
    for(int i = 0; i <= strlen(texto); i++) {
        printf("%c", texto[i] - clave[j]);
        j++;
        if (j == strlen(clave)-1) {
            j = 0;
        }
    }
    return 0;
}
