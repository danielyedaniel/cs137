#include <stdio.h>

int funky(int x, int count){
    if(count==0)return 1;
    return x*funky(x,count--);
}

int fun(int (*f)(int, int),int x, int count){
    printf("asdfdas");
    return f(x, count);
}

int main(void){
    printf("%d",fun(funky, 9, 2));
    return 0;
}