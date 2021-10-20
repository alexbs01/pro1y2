#include <stdio.h>
/* Bucle que crea un cuadrado vacio con el lado que le digas y la letra mayuscula que se escoja*/
int main() {
    int pisos;
    char ladrillo;

    do {
        printf("Longitud del cuadrado "
               "y que ladrillo usaras para el cuadrado (escribe una letra mayuscula y separa por espacio): ");
        scanf("%d%*c%c", &pisos, &ladrillo);
    } while ((pisos <= 0 || pisos >=51) ||(ladrillo < 'A' || ladrillo > 'Z'));
    printf("\n");
    for(int fila = 1; fila <= pisos; fila++) {
        if(fila == 1 || fila == pisos) {
            for (int i = 1; i <= pisos; i++) {
                printf("%3c", ladrillo);
            }
        } else {
            printf("%3c", ladrillo);
            for (int i = 1; i <= pisos; i++) {
                printf("  ");
            }
            printf("%3c", ladrillo);
        }
        printf("\n");
    }
    return 0;
}
