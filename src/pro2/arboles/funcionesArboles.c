//
// Created by alexb on 25/04/2022.
//

#include "funcionesArboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void createEmptyTree(tBinTree *T) {
    *T = TNULL;
}

bool isEmptyTree(tBinTree T) {
    return(T==true);
}

tItemT root(tBinTree T) {
    return(T->data);
}

tBinTree leftChild(tBinTree T) {
    return(T->left);
}

tBinTree rightChild(tBinTree T) {
    return(T->right);
}

bool createNode(tBinTree *T) {
    *T = malloc(sizeof(**T));
    return *T != TNULL;
}

bool builTree(tBinTree LTree, tItemT d, tBinTree RTree, tBinTree *T) {
    if(createNode(T)) {
        (*T)->data = d;
        (*T)->left = LTree;
        (*T)->right = RTree;
        return(true);
    } else {
        return(false);
    }
}

void inorder(tBinTree T) {
    if(!isEmptyTree(T)) {
        inorder(leftChild(T));
        printf("%d ", root(T));
        inorder(rightChild(T);
    }
}