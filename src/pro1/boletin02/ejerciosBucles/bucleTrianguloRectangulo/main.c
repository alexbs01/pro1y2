#include <stdio.h>

int main() {
    int altura, salto = 0, iteracion = 1;
    char ladrillo;

    printf("Escribe altura y que ladrillo usaras: ");
    scanf("%d %c", &altura, &ladrillo);
    printf("\n");

    do {
        printf("%3c", ladrillo);
        if(iteracion > salto) {
            printf("\n");
            salto++;
            if(iteracion < altura) {
                iteracion = 0;
            }
        }
        ++iteracion;
    } while(iteracion <= altura);



    return 0;
}
