//
// Created by alexb on 30/08/2022.
//

#include "dinamicos.h"
#include <stdlib.h>

bool isEmptyTree(tBinTree T) {
    return (T == TNULL);
}

void createEmptyTree(tBinTree *T) {
    *T = TNULL;
}

bool createNode(tPosT *p) {
    *p = malloc(sizeof(struct tNodeT));
    return *p != TNULL;
}

bool buildTree(tBinTree LTree, tItemT d, tBinTree RTree, tBinTree *T) {
    /* Para crear un árbol, se insertan los elementos de abajo a arriba, indicando en LTree y RTree los árboles hijos
     * del nodo d. Si el nodo a añadir es una hoja, sus ramas hijas serán TNULL*/
    if(createNode(T)) {
        (*T)->data = d;
        (*T)->left = LTree;
        (*T)->right = RTree;
        return true;

    } else {
        return false;
    }
}

tBinTree leftChild(tBinTree T) {
    return T->left;
}

tBinTree rightChild(tBinTree T) {
    return T->right;
}

tItemT root(tBinTree T) {
    return T->data;
}

void deleteTree(tBinTree *T){ // Elimina recursivamente un árbol
    if(!isEmptyTree(*T)) {
        deleteTree(&(*T)->left);
        deleteTree(&(*T)->right);

        free(*T);
        *T = TNULL;
    }
}