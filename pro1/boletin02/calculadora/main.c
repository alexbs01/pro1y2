#include <stdio.h>
// Se crea una funcion que realice la operacion que se escoja y devuelva el resultado con el *return*
float resultado(float num1, char signo, float num2) {
    switch (signo) {
        case '+' :
            return (num1 + num2);

        case '-' :
            return (num1 - num2);

        case '*' :
            return (num1 * num2);

        case '/' :
            return (num1 / num2);

        case 's':
            return 0;
        default:
            printf("\nERROR");
    }
    return 0;
}

int main() {
    float numero1, numero2, ans;
    char signo;

    printf("***************");
    printf("\n* CALCULADORA *");
    printf("\n***************");
    printf("\nEscribe la palabra 'salir' para parar el programa ");

    printf("\n>> ");
    scanf("%f%c%f", &numero1, &signo, &numero2); // Pide la operacion y guarda sus valores las variables

    // Se guarda el resultado de la funcion en la variable 'ans'
    ans = resultado(numero1, signo, numero2);

    /* Tras la primera operacion se comienza con el bucle DO-WHILE que parara
     * cuando se escriba una palabra que empiece con 's' */
    do {
        printf("\n>> %f", ans); // Se imprime el resultado
        scanf(" %c%f", &signo, &numero1); // Y la siguiente operacion ya es a partir del resultado anterior

        // Se almacena en 'ans' el resultado de su opercion con el numero que le pasamos antes
        ans = resultado(ans, signo, numero1);
    } while(signo != 's'); // Se ejecutara hasta que le pongamos una palabra que empiece por 's'

    return 0;
}
