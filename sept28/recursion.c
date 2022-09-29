#include <stdio.h>
int power(int x){
    if(x==0){
        return 1;
    }else{
        return 10 * power(x-1);
    }
}
int factorial(int x){
    if(x==0){
        return 1;
    }else{
        return x*factorial(x-1);
    }
}
int fibonacci(int x){
    if(x<=1)return 1;
    return fibonacci(x-1)+fibonacci(x-2);
}
int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}
int main(void){
    printf("The result of 10 to the power of 3 is: %d\n", power(3));
    printf("The result of the factorial of 9 is: %d\n", factorial(9));
    printf("The 7th term of the fibonacci sequence is: %d\n", fibonacci(7));
    printf("The gcd between 12 and 24 is: %d", gcd(24,  12));
}