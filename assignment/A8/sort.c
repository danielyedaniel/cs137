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


bool pointCompare1(struct point *p1, struct point *p2)
{
    if (p1->x < p2->x) return true;
    else return false;
}

bool pointCompare2(struct point *p1, struct point *p2)
{
    if (p1->x > p2->x) return true;
    else return false;
}
bool pointCompare3(struct point *p1, struct point *p2)
{
    if (p1->x <= p2->x) return true;
    else return false;
}
bool pointCompare4(struct point *p1, struct point *p2)
{
    if (p1->x >= p2->x) return true;
    else return false;
}
void pointSwap(struct point *p1, struct point *p2)
{
    struct point temp = *p1;
    *p1=*p2;
    *p2=temp;
}
int main (void)
{
    struct point points[4] = {{10,5},{0,0},{-4,-5},{0,10}};
    sort(points,4, sizeof(struct point), pointCompare1, pointSwap );
    for (int i=0; i<4; i++)
    printf("%d %d\n", points[i].x, points[i].y);
    printf("\n\n");
    struct point points2[4] = {{10,5},{0,0},{-4,-5},{0,10}};
    sort(points2,4, sizeof(struct point), pointCompare2, pointSwap );
    for (int i=0; i<4; i++)
    printf("%d %d\n", points2[i].x, points2[i].y);
    printf("\n\n");
    struct point points3[4] = {{10,5},{0,0},{-4,-5},{0,10}};
    sort(points3,4, sizeof(struct point), pointCompare3, pointSwap );
    for (int i=0; i<4; i++)
    printf("%d %d\n", points3[i].x, points3[i].y);
    printf("\n\n");
    struct point points4[4] = {{10,5},{0,0},{-4,-5},{0,10}};
    sort(points4,4, sizeof(struct point), pointCompare4, pointSwap );
    for (int i=0; i<4; i++)
    printf("%d %d\n", points4[i].x, points4[i].y);
    printf("\n\n");
    return 0;
}