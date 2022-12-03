#include <stdio.h>

int binarySearch(int * arr, int pivot,int target, int left, int right){
    if(left>right)return -1;
    if(arr[pivot]==target)return pivot;
    if(arr[pivot]>target)return binarySearch(arr,(right-left)/2+left,target,pivot,right);
    if(arr[pivot]<target)return binarySearch(arr,pivot/2,left,right/2);
}

int main(void){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    return 0;
}