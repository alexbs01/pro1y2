#include <stdio.h>
#include "funcionesFibonacci.h"

int main() {
    int n;
    printf("Introduzca hasta que numero n quiere ver la sucesion de fibonacci: ");
    scanf("%d", &n);

    test(n);
    return 0;
}
