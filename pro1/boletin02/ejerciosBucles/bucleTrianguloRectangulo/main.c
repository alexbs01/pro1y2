#include <stdio.h>
/* Patron de triangulo rectangulo
 * INPUT: 4 a
 * OUTPUT: a
 *         a   a
 *         a   a   a
 *         a   a   a   a
 */
int main() {
    int altura;
    char ladrillo;

    printf("Escribe altura y que ladrillo usaras: ");
    scanf("%d %c", &altura, &ladrillo);
    printf("\n");

    for(int fila = 1; fila <= altura; fila++) {
        for(int i = 1; i <= fila; i++) {
            printf("%3c", ladrillo);
        }
        printf("\n");
    }
    return 0;
}
