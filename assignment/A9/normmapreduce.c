#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <math.h>

typedef struct Vector {
    double x, y, z;
} Vector;

void EuclideanNorm(void *src, void *dest){
    *(double *)dest=sqrt(pow(((Vector *)src)->x,2)+pow(((Vector *)src)->y,2)+pow(((Vector *)src)->z,2));
}

void sum(void *src, void *dest){
    *(double *)dest=*(double *)dest+*(double *)src;
}
 