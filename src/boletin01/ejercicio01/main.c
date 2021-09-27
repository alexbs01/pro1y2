#include <stdio.h> // Libreria estandar de cabecera, contiene las principales funciones de entrada y salida
/* Plantee e implemente un programa en lenguaje C que solicite el nombre y la
edad de un usuario por teclado de forma que el ordenador le salude indicándole
la edad que tiene.
*/

int main() {
    char nombre[30]; // Se crea la variable nombre con una capacidad de 30 caracteres
    int edad; // Crea la variable edad
    printf("\nIntroduzca su nombre: "); // La funcion printf muestra texto por pantalla
    gets(nombre); // Recoge datos de entrada, pero solo vale para strings

    printf("\nIntroduzca su edad: ");
    scanf("%d", &edad); //Recoge datos de entrada, pero tambien para numeros y con el formato que se le exija
	// Los valores numericos hay que guardarlo en la dirccion de memoria indicandolo con el &

    printf("\nBuenos dias, %s, tiene usted %d anhos", nombre, edad); // Muestra los datos recogidos
    return 0;
}
