#include <stdio.h>

int main() {
    char caracter;

        printf("\nIntroduce un caracter: ");
        scanf("%c[^\n]", &caracter);

        switch (caracter) {
            case 'a': case 'A': case 'e': case 'E': case 'i': case 'I': case 'o': case 'O': case 'u': case 'U':
                printf("\n%c es una vocal.", caracter);
            break;
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                printf("\n%c es un numero", caracter);
            break;
            case '@': case '*': case '/': case '-': case '+': case '.': case ',': case '_': case '\'': case '?': case '!': case '<':
                printf("\n%c es un caracter especial.", caracter);
            break;
            default:
                printf("\n%c es una consonante", caracter);
        }

    return 0;
}
