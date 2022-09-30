#include <stdio.h>
int myPow(int num1, int num2){
    int sum=1;
    for(int i=0;i<num2;i++){
        sum*=num1;
    }
    return sum;
}
int recurse(int b, int num){
    if(b==0)return 1;
    if(num==0)return 1;
    return myPow(b, num) + recurse(b, num-1);
}
int main(void){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", recurse(x, y));
}