#include <stdio.h>
#include <math.h>
#include <assert.h>
#define PI acos(-1)

double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n){
    double x = (b-a)/n;
    double sum=0;
    for(int i=1;i<=n;i++){
        sum+=(f(a+x*i)+f(a+x*(i-1)))/2*x;
    }
    double y = (b-a)/(2*n);
    double sum2=0;
    for(int i=1;i<=n*2;i++){
        sum2+=(f(a+y*i)+f(a+y*(i-1)))/2*y;
    }
    
    if(fabs(sum-sum2)<=epsilon)return sum2;
    return trapezoidal(f, a, b, epsilon, 2*n);
}

