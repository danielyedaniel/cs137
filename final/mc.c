#include <stdio.h>

int main(void){
    char c = 1;
    c &= 7;
    c |= 5;
    c *= 9;
    printf("%d",c);
}