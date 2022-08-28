//
// Created by alexb on 20/08/2022.
//

#ifndef LISTAS_ESTATICA_H
#define LISTAS_ESTATICA_H

#include <stdbool.h>

/* Definición de tipos de datos */
#define LNULL -1
#define MAX 1000

typedef int tItemL;

typedef int tPosL;

typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;

/* Cabeceras
 * L -> Lista
 * p -> posición o nodo de la Lista
 */
bool isEmptyList(tList L);                      // Comprueba si la lista está vacía
void createEmptyList(tList *L);                 // Crea una lista vacía
bool insertItem(tItemL d, tPosL p, tList *L);   // Inserta un item
bool copyList(tList L, tList *M);               // Copia la lista entera
void updateItem(tItemL d, tPosL p, tList *L);   // Actualiza el campo data de la lista
void deleteAtPosition(tPosL p, tList *L);       // Elimina una elemento
void deleteList(tList *L);                      // Elimina la lista entera
tPosL findItem(tItemL d, tList L);              // Busca un nodo de la lista
tItemL getItem(tPosL p, tList L);               // Obtiene el valor de data de ese nodo
tPosL first(tList L);                           // Devuelve el primer elemento de la lista
tPosL last(tList L);                            // Devuelve el último elemento de la lista
tPosL previous(tPosL p, tList L);               // Devuelve cual es el elemento previo al introducido en la función
tPosL next(tPosL p, tList L);                   // Devuelve el siguiente elemento al introducido en la función

#endif //LISTAS_ESTATICA_H
