#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int ** split(int a[], int n, int p, int *len1, int *len2){
    int numless=0, nummore=0;
    for(int x=0;x<n;x++){
        if(a[x]<=p){
            numless++;
        }else{
            nummore++;
        }
    }
    int *arr1 =(int*)malloc(numless * sizeof(int));
    int *arr2 =(int*)malloc(nummore * sizeof(int));
    *len1 = numless;
    *len2 = nummore;
    int c1=0;
    int c2=0;
    for(int x=0;x<n;x++){
        if(a[x]<=p){
            arr1[c1]=a[x];
            c1++;
        }else{
            arr2[c2]=a[x];
            c2++;
        }
    }
    int** arr=(int**)malloc(2*sizeof(void*));
    arr[0]=&arr1[0];
    arr[1]=&arr2[0];
    return arr;
} 

int main(void){
    return 0;
}