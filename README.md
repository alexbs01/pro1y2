# Programación en C

## Tipos de datos

### Tipos de datos simples

- Numéricos: 
  - int <nombreVariable>: Para valores enteros.  
  - float <nombreVariable>: Para valores de coma flotante.
  - double <nombreVariable>: Con decimales pero con más cifras de aproximación. 
- De texto:
  - char <nombreVariable>[tamaño]: Para string o cadenas de texto.  
- Punteros:
  - *: Guardan direcciones de memoria.  

-----

## Funciones

### Función printf

#### Sintaxis

```c
printf("<cadenaDeTexto>", expr1, expr2,...);
```

#### Utilidad

Mostrar cadenas de texto por pantalla. En estas cadenas de texto se pueden introducir valores y en las expresiones se pueden realizar operaciones con variables numéricas.  

Usando el caracter % en los string, se puede decidir en que parte de la cadena irán las variables.

- %d: Para números enteros.  
- %f: Para números de coma flotante.  
- %s: Para strings.  

Ejemplo:

```c 
char nombre = "Alex";
float altura = 1.77467;

printf("Me llamo %s y mido %.2f \n", nombre, a); // Output: Me llamo Alex y mido 1.77
// Poniendo %.2f, se pueden redondear los float a dos decimales
// \n hace un salto de línea
```

-----

### Función scanf

#### Sintaxis

```c
scanf("tipoVar1 [tipoVar2...]", &var1, [&var2...]);
```

#### Utilidad

Permite recibir datos de entrada del teclado, y guardarlos en variables para su posterior uso.  

La función scanf() tiene dos partes, una primera parte entre comillas donde se especifica que tipo de caracteres (%s, %f...) se van a introducir, y una segunda parte donde se indica en que variables se van a guardar nuestros datos de entrada.  

```c
scanf("%d, %d, %d", &vector1, &vector2, &vector3);
// Guarda en las variables vector1, vector2 y vector3, los números que se introduzcan estarán separados por comas y un espacio (", ")
```

#### Cosas a tener en cuenta

Con esta función hay que recordar que se pueden limitar el número de caracteres de entrada si es un string usando el %7s, donde se estaría limitando a 10 caracteres.  

-----

## Sentencias de condicionales

### Sentencia IF-ELSE

#### Sintaxis

```c
if (expresion1) { 
    sentencia1;
} else if (expresion2) {
    sentencia2;
} else {
    sentencia3;
}
```

#### Utilidad

Se utiliza para hacer elecciones dentro de la línea de ejecución del código. Las expresiones comparativas pueden ser **||**, **&&**, **==**, **!=**, **<**, **<=**, **>** y **>=**. (No existe el **===**)

```c
if (edad >= 18) { // Comprueba si tiene más de 18 años
    printf("\nEs mayor de edad");
} else if (edad >= 0 && edad < 18) { // Si no tiene más de 18, comprueba si la edad esta en [0, 17]
    printf("\nEs menor de edad");
} else { // Si el valor de la edad no cumple ninguna de las condiciones ejecuta la del else
    printf("\nHay algo que fuel mal");
}
```

-----

### Sentencia SWITCH-CASE

#### Sintaxis

```c
switch(variable) {
    case 2: 
        sentencia;
        break;
    case 1:
        sentecia;
        break;
    default: 
        sentencia;
        break;
} 
```

#### Utilidad

Tiene la misma utilidad que el condicional *IF*, solo que en algunos casos hace que tenga una estructura más simple y más fácil de leer. En el switch se pueden juntar varios case para una misma intruccion.  

```c
switch (Nota) { // Entra la nota de un alumno, y segun la que sea, ira a un case u otro
    case 10: case 9:
		printf("Sobresaliente");
		break; // Es muy importante, si no, se pone continua ejecutando en el siguiente case
    case 8: case 7: 
		printf("Notable");
		break;
    case 6: case 5: 
		printf("Aprobado");
		break;
    case 4: case 3: case 2: case 1: // Se pueden poner varios case con la misma instruccion
		printf("Suspenso");
    	break;
    default: // Si la variable no coincide con ningun case, la ejecucion ira al default
		printf¨("Caso perdido");
		break;
}
```



## Sentencias de bucles

### Bucle WHILE

#### Sintaxis

```c
while (<expresion>) {
    <acciones>;
}
```

#### Utilidad

Permite ejecutar una misma parte del código múltiples veces, comprobando primero la expresión booleana.

```c
int i = 0;
while (i<10) {
    printf("\n %d", i); // Imprimira el valor de i hasta que se deje de cumplir la expresion
    i++; // Suma uno a la variable i
}
```

-----

### Bucle DO-WHILE

#### Sintaxis

```c
do {
    <acciones>;
} while (<expresion>);
```

#### Utilidad

Al igual que el bucle while sirve para ejecutar una misma parte del código múltiples veces, pero con una ligera diferencia, se ejecuta al menos una vez. Después de ejecutarse esta primera vez comprueba, si se sigue cumpliendo continúa el bucle, y si no, continúa con la línea de ejecución del código.  

```c
int i = 0;
do { // Se ejecutara al menos una vez
    printf("\n %d", i); // Imprimira el valor de i hasta que se deje de cumplir la expresion
    i++; // Suma uno a la variable i 
} while (i<10);
```

----

### Bucle FOR

#### Sintaxis

```c
for (<valorDeInicio>; <valorDeFin; <salto>) {
    <acciones>;
}
```

#### Utilidad

Es muy útil cuando ya se conoce cuantas iteraciones se dará al bucle. En C99 la variable de inicio se puede declarar en el propio bucle for, y el salto es de cuanto en cuanto se incrementa el valor de inicio para llegar hasta el valor de fin.  

```c
for (int i = 0; i <= 0; i++) {
    printf("\n %d", i++);
}
```

