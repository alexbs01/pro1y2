#include <stdio.h>
#include "funcionesFibonacci.h"
#include <windows.h>

int main() {
    int n;
    printf("Introduzca hasta que numero n quiere ver la sucesion de fibonacci: ");
    scanf("%d", &n);

    test(n);
    system("pause");
    return 0;
}
