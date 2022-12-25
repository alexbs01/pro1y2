#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que implemente el algoritmo
necesario para calcular la edad de una persona suponiendo que se le pide al
usuario que introduzca su fecha de nacimiento por teclado y a la salida muestra
por pantalla su edad con respecto a la fecha actual. Tenga en cuenta el
cumpleaños exacto de la persona para realizar el cálculo. */

int main() {
    int diaNac, mesNac, anoNac;
    int diaAct, mesAct, anoAct;
    int diaRes, mesRes, anoRes;

    printf("Introduce tu fecha de nacimiento separada por espacios: ");
    scanf("%d %d %d", &diaNac, &mesNac, &anoNac);

    printf("\nIntroduce la fecha actual: ");
    scanf("%d %d %d", &diaAct, &mesAct, &anoAct);

    if (mesAct <= mesNac) {// A | N ;; 1 10 2021 | 10 11 2001
        mesRes = mesNac - mesAct;
        if (diaAct <= diaNac) { // Aun no fue el cumple
            diaRes = diaNac - diaAct;
            anoRes = anoAct - anoNac - 1;
        }
    } else if (mesAct > mesNac && diaAct >= diaNac) {// A | N ;; 5 10 2021 | 10 11 2001

    }

    printf("\nAhora mismo tienes: %d anos, %d mes y %d dias", anoRes, mesRes, diaRes);

    return 0;
}
