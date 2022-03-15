#include "implementacioListaTeoria.h"

int main() {
    tList L;
    tPosL x;
    createEmptyList(L);
    if(insertItem(3, x, L)) {
        printf("Existe el elemento %d", getItem(x, L));
    }


    return 0;
}
