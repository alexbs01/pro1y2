#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite al usuario una
fecha del año en curso y le muestre en el centro de la pantalla
(aproximadamente) el número de días transcurridos desde el comienzo de año
hasta esa fecha. */

int main() {
    int dia, mes, resultado = 0;

    do {
        printf("\nIntroduce el dia y el mes separado por un espacio: ");
        scanf("%d %d", &dia, &mes);

        switch (mes) {
            case 12: resultado = dia;
            case 11: (mes == 11)? (resultado = dia) : (resultado = resultado + 30);
            case 10: (mes == 10)? (resultado = dia) : (resultado = resultado + 31);
            case 9:  (mes == 9) ? (resultado = dia) : (resultado += 30);
            case 8:  (mes == 8) ? (resultado = dia) : (resultado += 31);
            case 7:  (mes == 7) ? (resultado = dia) : (resultado += 31);
            case 6:  (mes == 6) ? (resultado = dia) : (resultado += 30);
            case 5:  (mes == 5) ? (resultado = dia) : (resultado += 31);
            case 4:  (mes == 4) ? (resultado = dia) : (resultado += 30);
            case 3:  (mes == 3) ? (resultado = dia) : (resultado += 31);
            case 2:  (mes == 2) ? (resultado = dia) : (resultado += 28);
            case 1:  (mes == 1) ? (resultado = dia) : (resultado += 31);
        }
    } while (dia <= 0 || mes <= 0);

    printf("\nLa fecha introducida corresponde al dia %d del ano en curso", resultado);

    return 0;
}
