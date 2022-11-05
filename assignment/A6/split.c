#include <stdio.h>
#include <stdlib.h>
#include <//assert.h>

int ** split(int a[], int n, int p, int *len1, int *len2){
    int numless=0, nummore=0;
    for(int x=0;x<n;x++){
        if(a[x]<=p){
            numless++;
        }else{
            nummore++;
        }
    }
    len1=(int*)malloc(numless * sizeof(int));
    len2=(int*)malloc(nummore * sizeof(int));
    int c1=0;
    int c2=0;
    for(int x=0;x<n;x++){
        printf("\n\n\nnumber in question: %d\n",a[x]);
        if(a[x]<=p){
            len1[c1]=a[x];
            printf("counter value of c1: %d              less: %d\n",c1, len1[c1]);
            c1++;
        }else{
            len2[c2]=a[x];
            printf("counter value of c2: %d              more: %d\n",c2, len1[c2]);
            c2++;
        }
    }
    int *arr[]={len1,len2};
    return arr;
}

int main(void)
{
    int a[] = {9,3,2,6,-1,3,6,6,7,8,5,2,3,4,1,0};
    int n = sizeof(a)/sizeof(a[0]);
    int n1,n2;
    int **ans = split(a,n,5,&n1, &n2);
    // assert(n1==10);
    // assert(n2==6);
    printf("First Array\n");
    for (int i=0; i<n1; i++){
    printf("%d\n",ans[0][i]);
    }
    printf("Second Array\n");
    for (int i=0; i<n2; i++){
    printf("%d\n",ans[1][i]);
    }
    // free(ans[1]);
    // free(ans[0]);
    // free(ans);

    // ans = split(a,n,-10,&n1, &n2);
    // assert(n1==0);
    // //assert(n2==n);
    // printf("First Array\n");
    // for (int i=0; i<n1; i++){
    // printf("%d\n",ans[0][i]);
    // }
    // printf("Second Array\n");
    // for (int i=0; i<n2; i++){
    // printf("%d\n",ans[1][i]);
    // }
    // free(ans[1]);
    // free(ans[0]);
    // free(ans);

    return 0;
 }