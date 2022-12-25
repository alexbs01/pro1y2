//
// Created by alexb on 30/08/2022.
//

#ifndef TAD_DINAMICOS_H
#define TAD_DINAMICOS_H

#include <stdbool.h>
#include <stdio.h>

#define TNULL NULL

typedef int tItemT;

typedef struct tNodeT *tPosT;

struct tNodeT {
    tItemT data;
    tPosT right;
    tPosT left;
};

typedef tPosT tBinTree;

bool isEmptyTree(tBinTree T);                                           // Comprueba si el árbol está vacío
void createEmptyTree(tBinTree *T);                                      // Crea un árbol vacío
bool buildTree(tBinTree LTree, tItemT d, tBinTree RTree, tBinTree *T);  // Inserta un elemento en el árbol, hay que ir de abajo a arriba
tBinTree leftChild(tBinTree T);                                         // Retorna el hijo izquierdo
tBinTree rightChild(tBinTree T);                                        // Retorna el hijo derecho
tItemT root(tBinTree T);                                                // Retorna el raíz del árbol
void deleteTree(tBinTree *T);                                           // Elimina el árbol entero

#endif //TAD_DINAMICOS_H
