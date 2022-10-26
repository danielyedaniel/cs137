#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool canComplete(int i, int arr[], int len){
    if(i==len-1)return true;
    if(i>=len)return false;
    for(int x=0;x<arr[i];x++){
        if(canComplete(i+x+1, arr, len))return true;
    }
    return false;
}
