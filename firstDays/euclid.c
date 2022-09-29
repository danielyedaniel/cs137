# include <stdio.h>
int main ( void ) {
    int a = 210;
    int b = 330;
    int r = 0;
    while ( b!= 0){
        r = a % b ;
        a = b ;
        b = r ;
    }
    printf ( " % d \n " ,a );
    return 0;
}
