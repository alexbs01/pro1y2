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
    int  height;
    tBSTPos right;
    tBSTPos left;
};

typedef tBSTPos tBST;

void createEmptyBST(tBST *tree);
bool isEmptyTree (tBST tree);
bool createBSTNode (tBSTPos *p, tKey key);
bool insertKey(tBST *tree, tKey key);
tBST findKey(tBST tree, tKey key);              // Retorna el árbol que tenga como raíz la clave que se busca
void replace (tBST *subTree, tBST *auxTree);    // Se reemplaza un nodo por sus predecesores
void removeKey(tBST *tree, tKey key);

#endif //TAD_DINAMICOS_H
