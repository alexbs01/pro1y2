/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

void createEmptyList(tList list) { // Crea una lista inicializandola con un valor nulo
    list = LNULL;
}

bool isEmptyList(tList list) { // Comprueba si la lista esta vacia
    bool empty;
    if(list == LNULL) {
        empty = true;
    } else {
        empty = false;
    }

    return empty;
}

tPosL first(tList list){
    return list; // Devuelve la primera posicion de la lista
}

tPosL last(tList list) {
    tPosL position;

    for(position = list; position->next != LNULL; position = position->next);
    return position;
}

tPosL next(tPosL position, tList list) {
    return position->next;
}

tPosL previous(tPosL position, tList list) {
    tPosL previousPosition;

    if(position == list) {
        previousPosition = LNULL;
    } else {
        for(previousPosition = list; list->next != position; list = list->next);
    }
    return previousPosition;

}

bool createNode(tPosL *position) {
    *position = malloc(sizeof(struct Node));
    return *position != LNULL;
}

bool insertItem(tItemL item, tPosL position, tList list) {
    tPosL newNode, auxiliarNode;

    if(!createNode(&newNode)) {
        return false;
    } else {
        newNode->data = item;
        newNode->next = LNULL;
        if(isEmptyList(list)) {
            list = newNode;
        } else if(position == LNULL) {
            for(auxiliarNode = list; auxiliarNode->next != LNULL; auxiliarNode = auxiliarNode->next);
            // Tambien valdria: auxiliarNode = previous(position, list);
            auxiliarNode->next = newNode;
        } else if(position == list) {
            newNode->next = list->next;

        }
    }
}

tItemL getItem(tPosL position, tList list) {
    return(position->data);
}

tPosL findItem(tProductId item, tList list) {
    tPosL p;
    if(isEmptyList(list)) {
        p = LNULL;
    } else {
        for(p = list; (p != NULL) && (strcmp(item, p->data.productId) == 0); p = p->next);
        return p;
    }

}