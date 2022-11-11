#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int ** split(int a[], int n, int p, int *len1, int *len2){
    int *one=NULL;
    int *two=NULL;
    (*len1)=0;
    (*len2)=0;
    for(int i=0;i<n;i++){
        if(a[i]<=p){
            (*len1)++;
            one=realloc(one,*len1*sizeof(int));
            one[*len1-1]=a[i];
        }else{
            (*len2)++;
            two=realloc(two,*len2*sizeof(int));
            two[*len2-1]=a[i];
        }
    }
    int **arr=malloc(2*sizeof(void*));
    arr[0]=one;
    arr[1]=two;
    return arr;
}