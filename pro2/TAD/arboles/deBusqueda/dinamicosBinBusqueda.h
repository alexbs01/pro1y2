//
// Created by alexb on 31/08/2022.
//

#ifndef TAD_DINAMICOS_H
#define TAD_DINAMICOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NULLBST NULL

typedef int tKey;

typedef struct tBSTNode *tBSTPos;

struct tBSTNode {
    tKey key;
    tBSTPos right;
    tBSTPos left;
};

typedef tBSTPos tBST;

bool isEmptyTree(tBST tree);
void createEmptyTree(tBST *tree);
bool insertKey(tBST *tree, tKey key);
tBST findKey(tBST tree, tKey key);          // Retorna el árbol que tenga como raíz la clave que se busca
void replace(tBST *subTree,tBST *auxTree);  // Reemplaza el contenido de un nodo por el de sus predecesores
void removeKey(tBST *tree, tKey key);       // Elimina una clave del árbol
tBST leftChild(tBST tree);
tBST rightChild(tBST tree);
tKey root(tBST tree);

#endif //TAD_DINAMICOS_H
