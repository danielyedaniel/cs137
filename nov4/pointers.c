#include <stdio.h>

int main ( void ) {
    int i = 6;
    int * p ;
    p = & i ;
    * p = 10;
    // p now points to 10
    printf ( " %d\n " , i );
    int * q ;
    q = p ;
    printf("%d\n",i);
    * q = 17;
    printf ( " %d\n " , i );
    int a [] = {1 ,2 ,3};
    return 0;
}