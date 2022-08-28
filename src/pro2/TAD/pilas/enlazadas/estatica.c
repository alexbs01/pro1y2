//
// Created by alexb on 28/08/2022.
//

#include "estatica.h"

#include "static_stack.h"

bool isEmptyStack(tStack S) {
    return (S.top == SNULL);
}

void createEmptyStack(tStack *S) {
    S->top = SNULL;
}

bool push(tItemS d, tStack *S) {
    if(S->top == SMAX - 1) { // Comprueba si la pila no está llena
        return false;
    } else { // Si no lo está, suma una posición a top, y en el campo data de esta posición inserta el item d
        S->top++;
        S->data[S->top] = d;
    }
    return true;
}

void pop(tStack *S) {
    /* Para eliminar el último elemento de la pila, lo único que se hace, es bajar el puntero que apunta al la parte
     * superior de la pila, restándole 1 */
    S->top--;
}

tItemS peek(tStack S) {
    return S.data[S.top]; // Retorna el valor del último elemento insertado en la pila
}
