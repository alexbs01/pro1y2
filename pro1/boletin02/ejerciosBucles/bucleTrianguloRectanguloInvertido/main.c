#include <stdio.h>
/* Patron de triangulo rectangulo invertido
 * INPUT: 4 a
 * OUTPUT: a  a  a  a
 *         a  a  a
 *         a  a
 *         a
 */
int main() {
    int altura;
    char ladrillo;
    printf("Escribe que altura y ladrillo usaras: ");
    scanf("%d %c", &altura, &ladrillo);
    printf("\n");

    for(altura ; altura > 0 ; altura--) {
        for(int i = altura; i > 0; i--) {
            printf("%3c", ladrillo);
        }
        printf("\n");
    }

    return 0;
}
