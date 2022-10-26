#include <stdio.h>
#include <assert.h>

int help(int i, int j, int m, int n, int a[m][n]){ 
    if(a[m-i-1][n-j-1]==0)return 0;
    if(m-i-1==0 && n-j-1==0)return 1;
    if(n-j>0)if(help(i,j+1,m,n,a))return 1;
    if(m-i>0)if(help(i+1,j,m,n,a))return 1;
    return 0;
}

int monotonePath(int m, int n, int a[m][n]){ 
    int i=0;
    int j=0;
    return help(i,j,m,n,a);
}