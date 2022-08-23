//
// Created by alexb on 25/04/2022.
//

#ifndef ARBOLES_FUNCIONESARBOLES_H
#define ARBOLES_FUNCIONESARBOLES_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TNULL NULL

typedef int tItemT;
typedef struct tNodeT* tPosT;
typedef tNodeT {
    tItemT data;
    tPosT right;
    tPosT left;
};

typedef tPosT tBinTree;

void createEmptyTree(tBinTree *T);
bool isEmptyTree(tBinTree T);
tItemT root(tBinTree T);
tBinTree leftChild(tBinTree T);
tBinTree rightChild(tBinTree T);
bool builTree(tBinTree LTree, tItemT d, tBinTree RTree, tBinTree *T);

#endif //ARBOLES_FUNCIONESARBOLES_H
