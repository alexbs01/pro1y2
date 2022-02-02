#include <stdio.h>

int main() {
    double cantidad, a = 0, b = 1, c;
    printf("Cuantos numero de la sucesion de Fibonacci quieres: ");
    scanf("%lf", &cantidad);

    for(int i = 1; i <= cantidad; i++) {
        printf("\n%.lf", a);
        c = b;
        b = a;
        a = b + c;
    }
    return 0;
}
