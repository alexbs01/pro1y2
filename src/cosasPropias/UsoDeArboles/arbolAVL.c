//
// Created by alexb on 02/09/2022.
//

#include "arbolAVL.h"

#include <stdio.h>
#include <stdlib.h>

void createEmptyBST(tBST *tree) {
    *tree = NULLBST;
}

bool isEmptyTree(tBST tree) {
    return tree == NULLBST;
}

tBST leftChild(tBST tree) {
    return tree->left;
}

tBST rightChild(tBST tree) {
    return tree->right;
}

// FUNCIÓN AUXILIAR
int max(int a, int b) { // Retorna el máximo de dos valores
    if(a>=b) {
        return a;
    } else {
        return b;
    }
}

// FUNCIÓN AUXILIAR
int height(tBST tree) { // Retorna la altura de un árbol
    if(isEmptyTree(tree)) {
        return 0;
    } else {
        return tree->height;
    }
}

// FUNCIÓN AUXILIAR
int getBalance(tBST tree) { // Retorna el equilibrio de un árbol, para ver si hay más elementos a la izquierda o derecha
    if(isEmptyTree(tree)) {
        return 0;
    }
    return (height(tree->left)-height(tree->right));

}

tBST findKey(tBST tree, tKey key) {
    if(isEmptyTree(tree)) {
        return NULLBST;

    } else if(key.dni == tree->key.dni) {
        return tree;

    } else if(key.dni < tree->key.dni) {
        return findKey(tree->left, key);

    } else {
        return findKey(tree->right, key);
    }


}

// ROTACIONES PARA EQUILIBRAR UN ÁRBOL

void rr_rotation(tBST *tree) { // Gira hacia la izquierda
    if(isEmptyTree(*tree)) {
        return;
    }

    printf("rr_rotating\n");

    tBST aux1 = (*tree)->right;

    (*tree)->right = aux1->left;
    aux1->left = *tree;

    // Actualización de la altura
    (*tree)->height = max(height((*tree)->left), height((*tree)->right)) + 1;
    aux1->height = max(height(aux1->left), height(aux1->right)) + 1;

    *tree = aux1;
}

void ll_rotation(tBST *tree) { // Gira hacia la derecha
    if(isEmptyTree(*tree)) {
        return;
    }

    printf("ll_rotating\n");

    tBST aux1 = (*tree)->left;

    (*tree)->left = aux1->right;
    aux1->right = *tree;

    // Actualización de la altura
    (*tree)->height = max(height((*tree)->left), height((*tree)->right)) + 1;
    aux1->height = max(height(aux1->left), height(aux1->right)) + 1;

    *tree=aux1;
}

void rl_rotation(tBST *tree) {
    if(isEmptyTree(*tree)) {
        return;
    }

    ll_rotation(&(*tree)->right);
    rr_rotation(tree);
}

void lr_rotation(tBST *tree) {
    if(isEmptyTree(*tree)) {
        return;
    }

    rr_rotation(&(*tree)->left);
    ll_rotation(tree);
}

bool createBSTNode (tBSTPos* p,tKey key) {
    *p = malloc(sizeof(struct tBSTNode));

    if(*p != NULLBST) {
        (*p)->key = key;
        (*p)->left = NULLBST;
        (*p)->right = NULLBST;
        (*p)->height=1;
    }
    return *p!=NULLBST;
}


bool insertKey(tBST* tree, tKey key) {
    bool check = false;
    bool check_createNode= false;

    if(isEmptyTree(*tree)) {
        check_createNode = createBSTNode(tree, key);
        printf("Node Key:%s Height:%d Balance:0 \n", (*tree)->key.dni, (*tree)->height);
        return check_createNode;

    } else if(key.dni == (*tree)->key.dni) {
        return true;

    } else if(key.dni < (*tree)->key.dni) {
        check = insertKey(&(*tree)->left, key);

    } else { // (key > (*tree)->key)
        check = insertKey(&(*tree)->right, key);
    }

    if(check) {
        // Si se inserta se actualiza la altura
        (*tree)->height = max(height((*tree)->left), height((*tree)->right)) + 1;

        // Se busca el balance del árbol
        int balance = getBalance(*tree);

        printf("Node Key:%s Height:%d Balance:%d \n", (*tree)->key.dni, (*tree)->height, balance);

        if(balance > 1) {  // Si el equilibrio es mayor a 1, será a la izquierda, y después se buscará si es LL o LR
            if(key.dni < (*tree)->left->key.dni) { // Left-Left
                ll_rotation(tree);
            } else { // Left-Right
                lr_rotation(tree);
            }
        }

        if(balance<-1) { // Si es menor a -1, será a la derecha, y se buscará si es RR o RL
            if(key.dni > (*tree)->right->key.dni) { // Right-Right
                rr_rotation(tree);
            } else { // Right-Left
                rl_rotation(tree);
            }
        }

    }
    return check;
}


void replace (tBST* subTree,tBST* auxTree) {
    if(!isEmptyTree((*subTree)->right)) { // Si el hijo derecho está vacío, bajamos a la derecha
        replace(&(*subTree)->right, auxTree);

    } else {
        (*auxTree)->key = (*subTree)->key; // Se reemplaza el campo data del nodo
        *auxTree = *subTree;               // Marcamos el nodo que eliminaremos
        (*subTree) = (*subTree)->left;     // Se enlaza la estructura
    }
}

void removeKey(tBST* tree,tKey key) {
    tBST aux;

    // LOCALIZAMOS EL NODO CON LA CLAVE
    if(key.dni < (*tree)->key.dni) {
        removeKey(&(*tree)->left, key);

    } else if(key.dni > (*tree)->key.dni) {
        removeKey(&(*tree)->right, key);

    } else { // (key == (*tree)->key)
        // UNA VEZ ENCONTRADO, LO ELIMINAMOS
        printf("Removing: %s\n", key.dni);

        aux = *tree;

        if(isEmptyTree((*tree)->right)) {
            // Si no hay hijo derecho, se reemplaza por el izquierdo, también cubre el caso de que no tenga hijos
            *tree = (*tree)->left;

        } else if(isEmptyTree((*tree)->left)) { // Si no tiene izquierdo, se reemplaza por el derecho
            *tree = (*tree)->right;

        } else {
            // Si tiene dos hijos, llamamos a replace() pasando como primer parámetro el hijo izquierdo
            replace(&(*tree)->left,&aux);
        }

        free(aux);
        aux = NULLBST;

    }

    if(isEmptyTree(*tree)) {
        return;
    }

    // Actualizamos el factor de equilibrio y la altura
    (*tree)->height = max(height((*tree)->left), height((*tree)->right)) + 1; // La altura

    int balance = getBalance(*tree); // Y el equilibrio

    // Hacemos las rotaciones necesarias hasta que el árbol quede balanceado, -> balance == 0
    while((balance>1)||(balance<-1)) {
        if(balance>1) { // Girar a la izquierda, y luego mirar si LL o LR
            if(getBalance((*tree)->left)>=0) { // Left-Left
                ll_rotation(tree);
            } else { // Left-Right
                lr_rotation(tree);
            }
        }

        if(balance<-1) { // Girar a la derecha y luego mirar si RR o RL
            if(getBalance((*tree)->right)>0) { //Right-Left
                rl_rotation(tree);
            } else { //Right-Right
                rr_rotation(tree);
            }
        }

        balance = getBalance(*tree); // Obtenemos el nuevo factor de equilibrio e iteramos de nuevo si lo necesita
    }
}

tKey recogidaDatos() {
    tKey datos;

    char dni[15];
    char nombre[30];
    char primerApellido[30];
    int edad;

    printf("\ndni: ");
    scanf("%s", dni);
    strcpy(datos.dni, dni);

   /* printf("nombre: ");
    scanf("%s", nombre);
    strcpy(datos.nombre, nombre);

    printf("primer apellido: ");
    scanf("%s", primerApellido);
    strcpy(datos.primerApellido, primerApellido);

    printf("edad: ");
    datos.edad = scanf("%d", &edad);*/

    return datos;

}

void preorder(tBST T) {
    if(T != NULLBST) {
        printf(" %s ", T->key.dni);
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(tBST T){
    if(T!=NULLBST) {
        inorder(T->left);
        printf(" %s ", T->key.dni);
        inorder(T->right);
    }
}

void postorder(tBST T){
    if(T!=NULLBST) {
        postorder(T->left);
        postorder(T->right);
        printf(" %s ", T->key.dni);
    }
}