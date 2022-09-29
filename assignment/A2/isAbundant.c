#include <stdio.h>

int main(void){
    int x;
    scanf("%d",&x);
    int div=1;
    int sum=0;
    while(div*2<=x){
        if(x%div==0){
            sum+=div;
        }
        div++;
    }
    printf("%s\n", sum>x ? "abundant" : (sum<x ? "deficient" : "perfect"));
    return 0;
}