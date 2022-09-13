#include <stdio.h>
#include <stdlib.h>
#include "arbolAVL.h"
#include "funcionesVarias.h"

int main() {
    int eleccion = 0;
    tKey persona;
    tBST arbol;

    createEmptyBST(&arbol);

    while(eleccion != 4) {
        eleccion = seleccionDeAccion();

        switch(eleccion) {
            case 1:
                printf("Opcion de insertar\n");
                persona = recogidaDatos();
                insertKey(&arbol, persona);
                break;

            case 2:
                printf("Opcion de eliminar\n");
                persona = recogidaDatos();
                removeKey(&arbol, persona);
                break;

            case 3:
                printf("Opcion de mostrar elementos\n");
                printf("Preorder\n");
                preorder(arbol);
                printf("\nInorder\n");
                inorder(arbol);
                printf("\nPostorder\n");
                postorder(arbol);
                break;

            case 4:
                printf("Opcion de salir\n");
                break;

            default: printf("Opcion no valida\n");

        }
        printf("\n");
    }
    return 0;
}
