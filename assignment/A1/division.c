#include <stdio.h>
int main(void){int x, y;scanf("%d %d", &x, &y);printf("%d\n", x/y + (x%y!=0 ? (x%y>0 ? 1 : (x<0 && y<0 ? 1 : -1)) : 0));return 0;}