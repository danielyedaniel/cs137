#include <stdio.h>
#include <assert.h>
#include "functions.h"

int isPrime(int num){
    int div=2;
    while(div*div<=num){
        if(num%div==0){
            return 0;
        }
        div++;
    }
    return 1;
}
int isSophieGermainPrime(int p){
    if(isPrime(p) && isPrime(2*p+1)){
        return 1;
    }
    return 0;
}
int myPow(int num1, int num2){
    int result=1;
    for(int i=0;i<num2;i++){
        result*=num1;
    }
    return result;
}
int base2nat(int bs, int num){
    int sum=0;
    int counter=0;
    while(num>0){
        sum+=(num%10)*myPow(bs,counter);
        num/=10;
        counter++;
    }
    return sum;
}
int nat2base(int bs, int num){
    int counter=9;
    int number=0;
    while(counter>=0){
        if(num/myPow(bs,counter)>0){
            number+=num/myPow(bs,counter)*myPow(10,counter);
            num%=myPow(bs,counter);
        }
        counter--;
    }
    return number;
}

