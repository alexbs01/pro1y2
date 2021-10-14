#include <stdio.h>
#define ENTER '\n'

int main() {
    float nota, max, min, media, suma = 0;
    int cont = 0;

    printf("Introduzca la secuencia de notas separadas por un espacio y finaliza con ENTER: ");
    do {
        do {
            /* Bucle condicional: Solo continua la ejecucion (sumar 1 al "cont" e ir al IF)
             * si la expresion es distinta a la del WHILE, al ser un bucle DO-WHILE siempre se ejecutara
             * minimo una vez, solo que se el numero esta fuera de los parametros marcados leera el
             * siguiente valor para solo usar los que si se usaran en el programa */
            scanf("%f", &nota);
        } while(nota < 0 || nota > 10 );

        //printf("\nEscribiste un %f", nota); //Muestra que numero se lean para testear
        cont++; // Va sumando uno al contador para posteriormente formar parte del denominador de la media
        if(cont == 1) { // Mete en min o max si el valor minimo o maximo segun corresponda
            max = nota;
            min = nota;
        } else if(nota > max) {
            max = nota;
        } else if (nota < min) {
            min = nota;
        }
        suma += nota;
    } while(ENTER != getchar()); // Se ejecutara el bucle hasta que el valor de entrada sea igual a \n
        if(cont > 0) {
            media = suma / cont;
            printf("\nLa suma es: %f\n"
                   "La maxima nota es: %f\n"
                   "La nota mininma fue: %f\n"
                   "Y la nota media fue: %f\n",suma, max, min, media);
        }
    return 0;
}
