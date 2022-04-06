//
// Created by alexb on 28/03/2022.
//

#include "tipoPila.h"

void createEmptyStack(tStack *stack) {
    stack = SNULL;
}

tItemS peek(tStack stack) {
    return stack->data;
}

bool push(tItemS item, tStack *stack) {
    tPosS aux;

    if(!(createNode(&aux))) {
        return false;
    } else {

    }
}

void pop(tStack *stack) {
    tPosS aux;
    aux = *stack;
    *stack = (*stack)->next;
    free(aux):
}