#include <stdio.h>

int sum(int array[], int inicio, int fin);
int main() {
    int vector[] = {10, 20, 30, 40, 50, 60, 70, 90, 100};
    int solucion, inicio, fin;

    printf("Pon inicio y fin: ");
    scanf("%d %d", &inicio, &fin);

    printf("\n La suma es: %d", sum(vector, inicio, fin));



    return 0;
}

int sum(int array[], int inicio, int fin) {
    if(inicio == fin) {
        return array[inicio];
    } else {
        return sum(array, inicio, fin-1) + array[fin];
    }
}
