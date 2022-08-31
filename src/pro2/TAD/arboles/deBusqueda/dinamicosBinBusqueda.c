//
// Created by alexb on 31/08/2022.
//

#include "dinamicosBinBusqueda.h"

#include <stdio.h>
#include <stdlib.h>


bool isEmptyTree(tBST tree) {
    return (tree == NULLBST);
}

void createEmptyTree(tBST* tree) {
    *tree = NULLBST;
}

tBST findKey(tBST tree, tKey key) { // Retornará un árbol cuya raíz sea la clave buscada
    if(isEmptyTree(tree)) { // Si el árbol está vacío retorna un NULL
        return NULLBST;

    } else if(key == tree->key) { // Si la clave es idéntica al raíz, retorna el árbol
        return tree;

    } else if(key < tree->key) { // Si la clave es menor que el raíz, se busca en el subárbol izquierdo
        return findKey(tree->left, key);

    } else { // Mismo caso que arriba pero con mayor que y buscará en el subárbol derecho: (key > tree->key)
        return findKey(tree->right, key);
    }
}

bool createBSTNode(tBSTPos* p,tKey key) {
    *p = malloc(sizeof(struct tBSTNode));

    if(*p != NULLBST) {
        (*p)->key = key;
        (*p)->left = NULLBST;
        (*p)->right = NULLBST;
    }
    return *p!=NULLBST;
}

bool insertKey(tBST* tree, tKey key) {
    /* Para insertar un elemento en un árbol binario de búsqueda, comenzará por el raíz y se desplazará a izquierda
     * o derecha en función de si la clave es menor o mayor al nodo en el que esté en ese momento. Así se seguirá
     * hasta que llegue a una hoja y pueda insertar el nodo, o se encuentre con un nodo con la misma clave, lo que
     * hará que se detenga la función para retornar un true */
    if(isEmptyTree(*tree)) { // Si el árbol está vacío, insertará la clave como nodo raíz
        return createBSTNode(tree, key);

    } else if(key == (*tree)->key) { // Si la clave ya está insertada, retornará un true
        return true;

    } else if(key < (*tree)->key) {
        /* Si la clave es menor que el raíz, seguirá desplazará al subárbol izquierdo y se volverá a ejecutar esta
         * función por recursión*/
        return insertKey(&(*tree)->left, key);

    } else { // Si la clave es mayor se desplazará al subárbol derecho y hará lo mismo. == (key > (*tree)->key)
        return insertKey(&(*tree)->right, key);
    }
}


void replace (tBST* subTree,tBST* auxTree) {
    if(!isEmptyTree((*subTree)->right)) { // Si el subárbol derecho no está vacío, reemplaza al nodo padre
        replace(&(*subTree)->right, auxTree); // Baja por la rama derecha
    } else {
        (*auxTree)->key = (*subTree)->key; // Se reemplaza el campo data del nodo
        *auxTree = *subTree;               // auxTree será el nodo a liberar
        (*subTree) = (*subTree)->left;     // Unimos el subárbol al principal usando el nodo a eliminar
    }
}

void removeKey(tBST* tree,tKey key) {
    tBST aux;

    // BÚSQUEDA DE LA CLAVE
    if(key < (*tree)->key) { // Si la clave es más pequeña que la del raíz, se irá a buscar por el subárbol izquierdo
        removeKey(&(*tree)->left, key);

    } else if(key > (*tree)->key) { // Si es superior se irá por el subárbol derecho
        removeKey(&(*tree)->right, key);

    } else { // Si la clave es idéntica, (key == (*tree)->key), procederemos con su eliminación
        aux = *tree;

        // ELIMINACIÓN DE LA CLAVE
        if(isEmptyTree((*tree)->right)) {
            // Comprueba si tiene hijo derecho, y lo reemplaza por el izquierdo. Si no tiene hijos no pasa nada
            *tree = (*tree)->left;

        } else if (isEmptyTree((*tree)->left)) { // Si no tiene izquierdo, se reemplaza por el derecho
            *tree = (*tree)->right;

        } else {
            // Si tiene dos hijos, llamamos a la función replace(), pasando al hijo izquierdo como primer parámetro
            replace(&(*tree)->left,&aux);
        }
        free(aux);
    }

}

tBST leftChild(tBST tree) {
    return tree->left;
}

tBST rightChild(tBST tree) {
    return tree->right;
}

tKey root(tBST tree) {
    return tree->key;
}
