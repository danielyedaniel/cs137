# include <stdio.h>
void swap ( int *p , int * q ) {
    int temp = * p ;
    * p = * q ;
    * q = temp ;
}
int main () {
    int i = 0, j = 2;
    swap (& i , & j ); // references . Why ?
    printf ( " %d%d\n " , i , j );
    return 0;
}