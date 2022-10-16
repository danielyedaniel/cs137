#include <stdio.h>
#include <math.h>
#include <assert.h>
#define PI acos(-1)

double f1(double x)
{
    return x * x;
}

double f2(double x)
{
    return cos(x);
}

double f3(double x)
{
    return sqrt(x);
}

double sum(double (*f)(double), double a, double b, int n){
    double x = (b-a)/n;
    double sum=(x*(f(a)+f(b)))/2;
    for(int i=1;i<n;i++){
        sum+=x(2*f(a+i*x));
    }
    return sum;
}

double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n){
    double x = (b-a)/n;
    double sum=(x*(f(a)+f(b)))/2;
    for(int i=1;i<n;i++){
        sum+=x(2*f(a+i*x));
    }
    double sum=sum(f, a, b, n);
    if(fabs(sum-sum(f, a, b, 2*n))<epsilon)return sum;
    return trapezoidal(f, a, b, epsilon, 2*n);
}

int main(void)
{
    // printf("%f",(trapezoidal(f1, 5, 10, 0.00001, 2) - 291.667));
    assert(fabs(trapezoidal(f1, 5, 10, 0.00001, 2) - 291.667) <= 0.001);
    assert(fabs(trapezoidal(f2, PI / 2, 3, 0.00001, 5) - -0.858879) <= 0.000001);
    assert(fabs(trapezoidal(f3, 1, 4, 0.00001, 2) - 4.666) <= 0.001);
    return 0;
}
