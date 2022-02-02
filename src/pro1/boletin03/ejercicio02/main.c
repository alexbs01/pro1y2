#include <stdio.h>

void diaSemana(char letra);

int main() {
    char inicial;

    printf("Introduce la inicial de un dia de la semana (L M X J V S D): ");
    scanf("%c", &inicial);
    printf("\n");

    diaSemana(inicial);
    return 0;
}

void diaSemana(char letra) {
    switch(letra) {
        case 'L':
            printf("Lunes");
            break;
        case 'M':
            printf("Martes");
            break;
        case 'X':
            printf("Miercoles");
            break;
        case 'J':
            printf("Jueves");
            break;
        case 'V':
            printf("Viernes");
            break;
        case 'S':
            printf("Sabado");
            break;
        case 'D':
            printf("Domingo");
            break;
        default:
            printf("Introduciste una letra que no es de un dia.");
    }
}
