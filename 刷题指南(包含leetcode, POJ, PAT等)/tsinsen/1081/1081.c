#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
double getRoot(double (*f)(double), double a, double b)
{
    double left=a,right=b,mid=(left+right)/2;
    while(fabs(f(mid))>=1e-6)
    {
        if(f(a)*f(mid)<0)
        {
            right=mid;
            mid=(left+right)/2;
        }
        else
        {
            left=mid;
            mid=(left+right)/2;
        }
    }
    return mid;
}