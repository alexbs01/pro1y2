//
// Created by alexb on 30/08/2022.
//

#include "recorridosYFuncionesExtra.h"

// FUNCIONES PARA RECORRER ÁRBOLES

/* Pre-Order (root left right)
 * Mostramos el raíz y luego vamos su subárbol izquierdo, mostramos el raíz de este y repetimos hasta qeu no haya más
 * subárboles izquierdo. Cuando esto ocurra, mostramos los subárboles derechos. 1 2 4 5 3 6 7
          1
     2         3
   4   5     6   7
*/
void preorder(tBinTree T){
    if(T!=TNULL) {
        printf(" %d ", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

/* In-Order (left root right)
 * Primero se imprime el subárbol izquierdo, luego su nodo y después el subárbol derecho. 4 2 5 1 6 3 7
          1
     2         3
   4   5     6   7
 */
void inorder(tBinTree T){
    if(T!=TNULL) {
        inorder(T->left);
        printf(" %d ", T->data);
        inorder(T->right);
    }
}

/* Post-Order (left right root)
 * Primero tratamos el árbol izquierdo, después el derecho y por último mostramos el raíz de cada sub árbol.
 * Para este caso quedará: 4 5 2 6 7 3 1
          1
     2         3
   4   5     6   7
 */
void postorder(tBinTree T){
    if(T!=TNULL) {
        postorder(T->left);
        postorder(T->right);
        printf(" %d ", T->data);
    }
}

// FUNCIONES EXTRA

int countNodes(tBinTree T) {
    if(isEmptyTree(T)) {
        return 0;
    }

    return 1 + countNodes(leftChild(T)) + countNodes(rightChild(T));
}

int countL(tBinTree T) {
    if(isEmptyTree(T)) {
        return 0;
    } else if((isEmptyTree(leftChild(T))) && (isEmptyTree(rightChild(T)))) {
        // Comprueba si el subárbol izquierdo y el derecho están vacío, si lo está es que solo está el raíz
        return 1;
    } else {
        return ((countL(leftChild(T))) + countL(rightChild(T)));
    }
}

// Función auxiliar para comparar que valor es superior. Se usará en la función de la altura
int comp(int a, int b) { 
    if(a >= b) {
        return a;
    } else {
        return b;
    }
}

int height(tBinTree T) {
    if(isEmptyTree(T)) {
        return 0;
    } else {
        return 1 + comp(height(leftChild(T)), height(rightChild(T)));
    }
}

/* Check if tree is a "proper" tree (full tree)
	- Every parent node/internal node has either two or no children.
	- Leafs only at last level
*/

// Función auxiliar de isFullTree
bool isFullTree_AUX(tBinTree T, int level, int height) { 
    if(isEmptyTree(T)) { // Se comprueba si el árbol está vacío o no
        return false;
    }
    
    if(isEmptyTree(T->left) && isEmptyTree(T->right)) { // Checkea si el subárbol izquierdo y derecho están vacíos
        return (level == height);
    }
    
    if(!isEmptyTree(T->left) && !isEmptyTree(T->right)) { // Si los dos subárboles no están vacíos se vuelve a iterar
        return (isFullTree_AUX(T->left, level + 1, height) && isFullTree_AUX(T->right, level + 1, height));
    }

    // Si solo hay un hijo se retorna false porque queremos comprar si el árbol es completo o no
    return false;
}

bool isFullTree(tBinTree T) { // Comprueba si es un árbol completo o no, haciendo uso de la función auxiliar
    return isFullTree_AUX(T, 1, height(T));
}
