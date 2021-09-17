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
// Guarda en las variables vector1, vector2 y vector3, los números que se introduzcan separados por espacios
```

#### Cosas a tener en cuenta

Con esta función hay que recordar que se pueden limitar el número de caracteres de entrada si es un string usando el %7s, donde se estaría limitando a 10 caracteres.  
