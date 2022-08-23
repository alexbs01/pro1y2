//
// Created by alexb on 20/08/2022.
//

#ifndef LISTAS_DINAMICA_H
#define LISTAS_DINAMICA_H

#include <stdbool.h>

/* Definicion de tipos de datos */
#define LNULL NULL

typedef int tItemL;

typedef struct tNode *tPosL;

struct tNode {
    tItemL data;
    tPosL next;
};

typedef tPosL tList;

/* Cabeceras */

/*
 * L -> Lista
 * p -> posicion o nodo de la Lista
 */
void createEmptyList(tList *L);                // Crea una lista vacía, esta función es muy importante
bool isEmptyList(tList L);                     // Comprueba si una lista está vacía
bool createNode(tPosL *p);                     // Crea un nodo
bool insertItem(tItemL d, tPosL p, tList *L);  // Inserta un item en una posición de la lista
void updateItem(tItemL d, tPosL p, tList *L);  // Actualiza el campo data de un elemento de la lista
tPosL findItem(tItemL d, tList L);             // Busca un item de la lista en función de lo que contenga el campo data
tItemL getItem(tPosL p, tList L);              // Obtiene el valor del campo data de un item
tPosL first(tList L);                          // Busca el primer elemento de la lista
tPosL last(tList L);                           // Busca el último elemento de la lista
tPosL previous(tPosL p, tList L);              // Indica el elemento previo al introducido en la función
tPosL next(tPosL p, tList L);                  // Indica cual es el elemento siguiente al introducido en la función
void deleteAtPosition(tPosL p, tList *L);      // Elimina un elemento de la lista
void deleteList(tList *L);                     // Borra toda la lista
bool copyList(tList L, tList *M);              // Copiar una lista en otra, para hacer dos listas independientes

/*
 *L -> nodo1(dato1 | posicionNodo2) ->
                       -> nodo2(dato2 | posicionNodo3) ->
                                       -> nodo3(dato3 | posicionNodo4) -> ...
 */

#endif //LISTAS_DINAMICA_H


