#include <stdio.h>

int main(void){
    int sum=0;
    int x, t;
    scanf("%d", &t);
    x=t;
    while(t){
        sum+=t%10;
        t/=10;
    }
    printf("%d", sum);
    return 0;
}