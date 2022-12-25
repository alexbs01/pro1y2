//
// Created by alexb on 02/09/2022.
//

#include "funcionesVarias.h"

int seleccionDeAccion() {
    int eleccion = 0;

    printf("Que deseas hacer?\n"
           "(1)insertar\n"
           "(2)eliminar\n"
           "(3)mostrar datos\n"
           "(4)salir\n");
    scanf("%d", &eleccion);


    return eleccion;
}