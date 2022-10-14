#include <stdio.h>
#include <assert.h>

int monotonePath(int m, int n, int a[m][n]){ 
    // printf("%d , %d , %d \n", a[m-1][n-1], m, n);
    printf("%d %d %d\n\n", a[9][10], m, n);
    for(int x=0;x<m;x++){
        for(int i=0;i<n;i++){
            printf("%d ",a[x][i]);
        }
        printf("\n");
    }
    if(a[m-1][n-1]==0)return 0;
    if(m-1==0 && n-1==0)return 1;
    if(n>0)if(monotonePath(m,n-1,a))return 1;
    if(m>0)if(monotonePath(m-1,n,a))return 1;
    return 0;
}
int main(void)
{
    int m = 10;
    int n = 12;
    int a[][12] = {
    {1,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0},
    {0,1,1,0,0,1,1,0,0,0,0,0},
    {0,1,0,0,0,0,1,0,0,0,0,0},
    {0,1,1,0,0,0,1,1,1,0,0,0},
    {0,0,1,0,0,0,0,0,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,1,1}
    };

    // a, but with one entry switched eliminating the monotone path
    int b[10][12] = {{1,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,0,1,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0},
    {0,1,1,0,0,1,1,0,0,0,0,0},
    {0,1,0,0,0,0,1,0,0,0,0,0},
    {0,1,1,0,0,0,1,1,1,0,0,0},
    {0,0,1,0,0,0,0,0,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,1,1}
    };

    printf("%d",monotonePath(m, n, a));
    // assert (!monotonePath(m, n, b));
    return 0;
 }