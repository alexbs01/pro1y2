#include <stdio.h>
void lineasEnBlanco(int lineas);
int recogidaDatos();
int main() {
    lineasEnBlanco(recogidaDatos());
    return 0;
}

void lineasEnBlanco(int lineas) {
    for(int i = 1; i < lineas; i++) {
        printf("\n");
    }
}
int recogidaDatos() {
    int aux;
    do {
        printf("Cuantas lineas en blanco quieres[0, 25): ");
        scanf("%d", &aux);
    } while(aux <= 0 || aux > 25);
    return aux;
}
