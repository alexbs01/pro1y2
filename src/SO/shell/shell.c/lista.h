//
// Created by alexb on 09/09/2022.
//

#ifndef SHELL_C_LISTA_H
#define SHELL_C_LISTA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node *list;
typedef struct node *pos;

list createEmptyList();
void insert(list L, void *name);

pos first(list L);
pos next(list L, pos p);
int at_end(list L, pos p);
void *get(list L, pos p);
void mostrarLista(list L);


#endif //SHELL_C_LISTA_H
