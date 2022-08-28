//
// Created by alexb on 02/02/2022.
//

#include <stdlib.h>
#include "rational_pointer.h"
// Operation to create a rational number
Rational createRational(int n, int d) {
    Rational temp;
    temp= malloc(sizeof(*temp));
    temp->num= n;
    temp->den= d;
    return temp;
}
// Operation that returns the numerator of a rational number
int numerator(Rational r) {
    return r->num;
}
// Operation that returns the denominator of a rational number
int denominator(Rational r) {
    return r->den;
}
// Operation that returns the sum of two rationals
Rational sum(Rational r1, Rational r2) {
    Rational s;
    s= malloc(sizeof(*s));
    s->num= r1->num * r2->den + r2->num * r1->den;
    s->den= r1->den * r2->den;
    return s;
}
