#include <stdio.h>
#include <stdbool.h>

struct point
{
    int x;
    int y;
};
void sort(void *arr, int n, size_t elemsize, bool (*compare)(const void *a, const void *b), void (*swap)(void *a, void *b)){
    for(int i=1;i<n;i++){
        struct point *temp=((char *) arr) + i * elemsize;
        int x=temp->x;
        int y=temp->y;
        struct point tem={x,y};
        struct point *a=&tem;
        int count=i-1;
        while(count>=0 && compare(a,((char *) arr) + count * elemsize)){ 
            swap(((char *) arr) + count * elemsize+elemsize,((char *) arr) + count * elemsize);
            count--;
        }
        struct point *p=((char *) arr) + (count+1) * elemsize;
        p->x=x;
        p->y=y;
    }
}