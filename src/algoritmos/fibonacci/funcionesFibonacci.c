//
// Created by alexb on 15/09/2022.
//

#include "funcionesFibonacci.h"

/*función fib1 (n);
    si n<2 entonces devolver n
    sino devolver fib1(n-1) + fib1(n-2)
    fin si
fin función
 */
int fib1(int n) {
    if(n < 2) {
        return n;
    } else {
        return fib1(n - 1) + fib1(n - 2);
    }
}

/*
función fib2 (n);
    i := 1; j := 0;
    para k := 1 hasta n hacer
        j := i + j;
        i := j - i;
    fin para;
    devolver j
fin función
 */

int fib2(int n) {
    int i, j, k;
    i = 1;
    j = 0;
    for(k = 1; k <= n; k++) {
        j = i + j;
        i = j - i;
    }
    return j;
}

/*
función fib3 (n);
    i := 1; j := 0; k := 0; h := 1; t := 0
    mientras n>0 hacer
        si n es impar entonces
            t := jh;
            j := ih + jk + t;
            i := ik + t
        fin si;
        t := h^2;
        h := 2kh + t;
        k := k^2 + t;
        n := n div 2
    fin mientras;
    devolver j
fin función
*/
int fib3(int n) {
    int i = 1, j = 0, k = 0, h = 1, t;
    while(n > 0) {
        if((n % 2) != 0) {
            t = j * h;
            j = (i * h) + (j * k) + t;
            i = (i * k) + t;
        }
        t = h * h;
        h = (2 * k * h) + t;
        k = (k * k) + t;
        n = n / 2;
    }
    return j;
}

void test(int n) {
    printf("       n\t|\tfb1(n)\t\tfb2(n)\t\tfb3(n)\n");
    printf("----------------|------------------------------------------------\n");
    for(int i = 0; i <= n; i++) {
        printf("%8d\t|%15d%15d%15d\n", i, fib1(i), fib2(i), fib3(i));
    }
}