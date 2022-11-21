#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
bool newSearch(int arr[], int len, int x){
    int bb=0, ba=len-1;
    printf("start with the range %d to %d\n",arr[bb],arr[ba]);
    if(bb==ba){
        if(arr[bb]==x){
            printf("%d was found in position %d\n",x,bb);
            return true;            
        }else{
            printf("%d not in the range between %d and %d\n",x,arr[bb],arr[ba]);
            return false;
        }
    }
    if((arr[ba]-arr[bb])!=0){
         int pos=(bb + (float)(x - arr[bb]) / (float)((arr[ba]-arr[bb])) * (ba-bb));
    }else{
         return false;
    }
    int pos=(bb + (float)(x - arr[bb]) / (float)((arr[ba]-arr[bb])) * (ba-bb));
    while(pos>=0 && pos<len && x>=arr[bb] && x<=arr[ba]){
        if(arr[pos]==x){
            printf("%d was found in position %d\n",x,pos);
            return true;
        }
        if(x<arr[pos]){
            ba=pos-1;
        }else if(x>arr[pos]){
            bb=pos+1;
        }
        if(pos>=0 && pos<len && x>=arr[bb] && x<=arr[ba]){
            pos=(bb + (float)(x - arr[bb]) / (float)(arr[ba]-arr[bb]) * (ba-bb));
            printf("move to search in the range between %d and %d\n",arr[bb],arr[ba]);
        }
    }        
    printf("%d not in the range between %d and %d\n",x,arr[bb],arr[ba]);
    return false;
}