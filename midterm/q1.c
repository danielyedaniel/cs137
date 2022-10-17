#include <stdio.h>

int main(void){
    int i = 2;
    i%=3;
    printf("%d\n",i);
    int j=23/2;
    printf("%d\n",j);
    i=j=13;
    printf("%d, %d", i, j );
    return 0;
}