//
// Created by alexb on 02/09/2022.
//

#ifndef USODEARBOLES_ARBOLAVL_H
#define USODEARBOLES_ARBOLAVL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NULLBST NULL

typedef struct Persona{
    char dni[15];
   // char nombre[30];
    //char primerApellido[30];
    //int edad;
} tKey;

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
tKey recogidaDatos();
void preorder(tBST T);
void inorder(tBST T);
void postorder(tBST T);

#endif //USODEARBOLES_ARBOLAVL_H
