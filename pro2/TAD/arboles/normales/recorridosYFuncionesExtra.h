//
// Created by alexb on 30/08/2022.
//

#ifndef TAD_RECORRIDOSYFUNCIONESEXTRA_H
#define TAD_RECORRIDOSYFUNCIONESEXTRA_H

#include "dinamicosBinNormales.h"

#include <stdio.h>
#include <stdlib.h>
// RECORRIDOS
void preorder(tBinTree T);
void inorder(tBinTree T);
void postorder(tBinTree T);

// FUNCIONES EXTRA
int countNodes(tBinTree T);                             // Cuentas cuantos nodos hay en el árbol
int countL(tBinTree T);                                 // Cuenta cuantas hojas hay (nodo sin hijos)
int height(tBinTree T);                                 // Cuenta la altura máxima del árbol
bool isFullTree(tBinTree T);

#endif //TAD_RECORRIDOSYFUNCIONESEXTRA_H
