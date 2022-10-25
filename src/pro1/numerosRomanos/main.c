#include <stdio.h>

int main() {
    int numero, millares, centenas, decenas, unidades;

        printf("Escribe un numero decimal para pasar romanos [0, 3999]: ");
        scanf("%d", &numero);

        unidades = numero % 10;
        decenas = (numero / 10) % 10;
        centenas = (numero / 100) % 10;
        millares = (numero / 1000) % 10;

        printf("\bEn numeros romanos es: ");

        switch(millares) {
            case 3: printf("M");
            case 2: printf("M");
            case 1: printf("M");
            default: printf("");
        }

        switch(centenas) {
            case 9: printf("CM"); break;
            case 8: printf("DCCC"); break;
            case 7: printf("DCC"); break;
            case 6: printf("DC"); break;
            case 5: printf("D"); break;
            case 4: printf("CD"); break;
            case 3: printf("C");
            case 2: printf("C");
            case 1: printf("C");
            default:printf("");
        }

        switch(decenas) {
            case 9: printf("CX"); break;
            case 8: printf("LXXX"); break;
            case 7: printf("LXX"); break;
            case 6: printf("LX"); break;
            case 5: printf("L"); break;
            case 4: printf("XL"); break;
            case 3: printf("X");
            case 2: printf("X");
            case 1: printf("X");
            default:printf("");
        }

        switch(unidades) {
            case 9: printf("IX"); break;
            case 8: printf("VIII"); break;
            case 7: printf("VII"); break;
            case 6: printf("VI"); break;
            case 5: printf("V"); break;
            case 4: printf("IV"); break;
            case 3: printf("I");
            case 2: printf("I");
            case 1: printf("I");
            default:printf("");
        }

    return 0;
}
