#include <stdio.h>

int main(void){
    int arr[10];
    int success;
    int count=1;       
    int hold;
    do{
        success=scanf("%d", &hold);
        if(success){
            arr[count]=hold;
            count++;
        }
    }while(success==1);
    printf("terminated");
    for(int i=0; i<sizeof(arr)/sizeof(int);i++){
        printf("%d\n",arr[i]);
    }
    return 0;

}