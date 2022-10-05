#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int abs(int a){
    if(a<0)return -a;
    return a;
}

bool divide(int a, int b){
    a=abs(a);
    b=abs(b);
    if(b-a==0){
        return true;
    }else if(b-a<0)return false;
    return divide(a, b-a);

}
int IntegerDivision(int a, int b){
    bool opr = (a<0 || b<0 ? (a<0 ? (b<0 ? true : false): false) : true);
    int result=abs(a)-abs(b);
    if(result==0){if(opr)return 1;return -1;}
    if(result<0)return 0;
    if(opr)return 1 + IntegerDivision(a-b, b);
    return -1 + IntegerDivision(a+b, b);
}
