/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LNULL NULL
typedef struct Node *tPosL;
struct Node {
    tItemL data;
    tPosL next;
};

typedef tPosL tList;

void createEmptyList(tList list);
bool isEmptyList(tList list);
tPosL first(tList list);
tPosL last(tList list);
tPosL next(tPosL position, tList list);
tPosL previous(tPosL position, tList list);
bool createNode(tPosL *position);
bool insertItem(tItemL item, tPosL position, tList list);
tItemL getItem(tPosL position, tList list);
tPosL findItem(tProductId item, tList list);
#endif
