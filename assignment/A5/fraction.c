#include <stdio.h>
#include "fraction.h"
#include <assert.h>

int gc(int num, int denom) {
    if (denom != 0)
        return gc(denom, num % denom);
    else
        return num;
}

struct fraction reduce(struct fraction a){
    int gcd= gc(a.numerator,a.denominator);
    a.numerator/=gcd;
    a.denominator/=gcd;
    return a;
}

struct fraction fractionCreate(int numerator, int denominator){
    struct fraction a={numerator,denominator};
    a=reduce(a);
    if(a.numerator<0){
        a.numerator=-a.numerator;
        a.denominator=-a.denominator;
    }
    return a;
}

int get_numerator(struct fraction a){
    struct fraction num=fractionCreate(a.numerator,a.denominator);
    return num.numerator;
}

int get_denominator(struct fraction a){
    struct fraction num=fractionCreate(a.numerator,a.denominator);
    return num.denominator;
}

struct fraction fractionAdd(struct fraction a, struct fraction b){
    struct fraction add=fractionCreate(a.numerator*b.denominator+b.numerator*a.denominator, a.denominator*b.denominator);
    return add;
}
struct fraction fractionSubtract(struct fraction a, struct fraction b){
    struct fraction sub=fractionCreate(a.numerator*b.denominator-b.numerator*a.denominator, a.denominator*b.denominator);
    return sub;
}
struct fraction fractionMultiply(struct fraction a, struct fraction b){
    struct fraction mult=fractionCreate(a.numerator*b.numerator, a.denominator*b.denominator);
    return mult;
}
struct fraction fractionDivide(struct fraction a, struct fraction b){
    struct fraction div=fractionCreate(a.numerator*b.denominator, a.denominator*b.numerator);
    return div;
}