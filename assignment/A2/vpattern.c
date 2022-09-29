#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int y=1;y<=n;y++){
            if(y<=i){
                printf("%d",y);
            }else{
                printf(" ");
            }
        }
        for(int y=0;y<n;y++){
            if(n-y<=i){
                printf("%d",n-y);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}