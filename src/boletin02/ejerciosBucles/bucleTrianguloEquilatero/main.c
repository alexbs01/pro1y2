#include <stdio.h>
/* Programa que cree un triangulo equilatero o piramide*/
int main() {
    int altura, ladrillosPorPiso, espacio, fila = 0;
    char ladrillo;

    printf("Escribe la altura la piramide y el ladrillo que usaras: ");
    scanf("%d %c", &altura, &ladrillo);
    printf("\n");

    for(espacio = altura - 1; espacio >= 0; espacio--) { // Da los espacios
        printf(" ");
        if(espacio == 0) {
            ladrillosPorPiso = (2*fila);
            for(int i = 0; i <= ladrillosPorPiso; i++) { // Pone los ladrillos
                printf("%c",ladrillo);
            }
            altura--;
            espacio = altura;
            fila++;
            printf("\n");
        }
    }
    return 0;
}
