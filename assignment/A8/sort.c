#include <stdio.h>
#include <stdbool.h>
void sort(void *arr, int n, size_t elemsize, bool (*compare)(const void *a, const void *b), void (*swap)(void *a, void *b)){
    for(int i=0;i<n;i++){
        bool sw=false;
        for(int j=0;j<n-1;j++){
            if(compare(((char *) arr) + (j+1) * elemsize,((char *) arr) + j * elemsize)){
                swap(((char *) arr) + (j+1) * elemsize,((char *) arr) + j * elemsize);
                sw=true;
            }
        }
        if(!sw)break;
    }
}