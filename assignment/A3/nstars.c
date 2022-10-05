#include <stdio.h>

long int myFunc(long int n){
    if(n<10){printf("%ld",n);return(n);}
    if(n%10==myFunc(n/10))printf("*");
    printf("%ld",n%10);
    return n%10;
}
void stars(long int n){
    myFunc(n);
}
