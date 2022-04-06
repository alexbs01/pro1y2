//
// Created by alexb on 28/03/2022.
//

#ifndef PILAS_TIPOPILA_H
#define PILAS_TIPOPILA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SNULL NULL

typedef int tItemS;
typedef struct tNodeS *tPosS;
struct tNodeS {
    tItemS data;
    tPosS next;
};

typedef struct tNodeS tStack;

bool createNode(tPosS *p);
void createEmptyStack(tStack *stack);
tItemS peek(tStack stack);
bool push(tItemS item, tStack *stack);
void pop(tStack *stack);
#endif //PILAS_TIPOPILA_H
