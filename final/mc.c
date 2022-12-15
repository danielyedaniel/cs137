#include <stdio.h>

int binarySearch(int *a,int left, int right, int target){
    if(left>right)return -1;
    int middle=(right+left)/2;
    if(a[middle]==target)return middle;
    if(a[middle]<target)return binarySearch(a,middle+1,right,target);
    return binarySearch(a,left,middle-1,target);
}

int main(void){
    int a[]={0,1,2,3,4,5,6,7,8,9,10};
    printf("%d\n",binarySearch(a,0,10,7));
}