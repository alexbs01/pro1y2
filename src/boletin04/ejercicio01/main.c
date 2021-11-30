#include <stdio.h>

int funcion();

void main() {
    funcion();
    //return 0;
}

int funcion() {
    int index = 0, longitudFinal = 10;
    int conjunto[longitudFinal];
    printf("Introduce %d numeros, los que sean a mayores se eliminaran: ", longitudFinal);
    do {
        scanf("%d", &conjunto[index]);
        index++;
    } while(longitudFinal != index);

    for(int i = 0; i <= longitudFinal - 1; i++) {
        if(i != longitudFinal - 1) {
            printf("%d, ", conjunto[i]);
        } else {
            printf("%d", conjunto[i]);
        }

    }
}
