#include <stdio.h>
// Convertir el tiempo en segundos a horas, minutos y segundos

int main() {
    int segundosIniciales;
    float horas, minutos, segundos;

    printf("Introduce el numero de segundos para hacer la conversion: ");
    scanf("%d", &segundosIniciales);

    horas = segundosIniciales / 3600;
    minutos = (segundosIniciales % 3600) / 60;
    segundos = segundosIniciales % 60;

    printf("\n%d segundos son: %.f horas %.f minutos y %.f segundos", segundosIniciales, horas, minutos, segundos);
    return 0;
}
