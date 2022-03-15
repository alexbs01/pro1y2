//
// Created by alexb on 14/03/2022.
//

#ifndef LISTADOBLEMENTEENLAZADA_IMPLEMENTCACIONDINAMICA_H
#define LISTADOBLEMENTEENLAZADA_IMPLEMENTCACIONDINAMICA_H

typedef int tItemL;
typedef struct Node *tPosL;
struct Node {
    tItemL data;
    tPosL next;
    tPosL prev;
};

typedef tPosL tList;

#endif //LISTADOBLEMENTEENLAZADA_IMPLEMENTCACIONDINAMICA_H
