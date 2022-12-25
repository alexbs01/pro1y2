#include <stdio.h>

int main() {
    int altura, espaciosPorPiso, espacio, fila = 1;
    char ladrillo;

    printf("Escribe la altura la piramide y el ladrillo que usaras: ");
    scanf("%d %c", &altura, &ladrillo);
    printf("\n");

    for(int i = (altura*2) - 2; i >= 0; i--) {
        printf("%c", ladrillo);
        if(i == 0) {
            printf("\n");
            for(espacio = 1; espacio <= fila; espacio++) {
                printf(" ");
            }
            fila++;
            altura--;
            i = (altura*2) - 1;
        }
    }
    return 0;
}
