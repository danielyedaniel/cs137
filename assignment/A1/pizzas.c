#include <stdio.h>
int main(void){int x,y,z;scanf("%d %d %d",&x,&y,&z);printf("%d\n",x*z/y+(x*z%y>0?1:0));return 0;}