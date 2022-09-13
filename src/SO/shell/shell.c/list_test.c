//
// Created by alexb on 12/09/2022.
//
/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lista.h"

struct data {
    int i;
    char *name[200];
};

struct data2 {
    char c;
};

int main() {
    list l = createEmptyList();
    list l2 = createEmptyList();

    struct data *d1, *d2;

    d1 = malloc(sizeof(struct data));
    d2 = malloc(sizeof(struct data));

    d1->i = 1;
    strcpy(d1->name, "d1");
    d2->i = 2;
    strcpy(d2->name, "d2");

    insert(l, &d1);
    insert(l, d2);

    for(pos p = first(l); !at_end(l, p); p = next(l, p)) {
        struct data *d = get(l, p);
        printf("%i - %s\n", d->i, d->name);
    }

    struct data2 *c1, *c2;

    c1 = malloc(sizeof(struct data2));
    c2 = malloc(sizeof(struct data2));

    c1->c = 'a';
    c2->c = 'b';

    insert(l2, c1);
    insert(l2, c2);

    for(pos p = first(l2); !at_end(l2, p); p = next(l2, p)) {
        struct data2 *d = get(l2, p);
        printf("%c\n", d->c);
    }


    return 0;
}
*/