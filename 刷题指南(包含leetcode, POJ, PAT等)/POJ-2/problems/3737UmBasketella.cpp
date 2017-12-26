/*
pi*r(r+l)=S 1/3 pi r*r h
    pi*r*r+pi*r*l=S
    pi*r*l=S-pi*r*r
    l=(S-pi*r*r)/pi*r
    sqrt(rr hh)
    
    sqrt(((s-pi*r*r)/pi*r)^2-r*r)
    
    Tenery search
    1/3 pi r*r h */

#include<iostream>
#include<math.h>
#include<stdio.h>
#define pi acos(-1.0)
using namespace std;
inline double sqr(double x)
{
    return x*x;
}

double S;
inline double h(double r)
{
    return sqrt(sqr(S/pi/r-r)-r*r);
}
double f(double r)
{
    //return the volume
    return (1.0/3)*pi*r*r*h(r);
}
int main()
{
    double left,right,leftThird,rightThird;
    while(scanf("%lf",&S)!=EOF){
        left=0,right=sqrt(S/(2*pi));
        while(fabs(left-right)>1e-5)
        {
            leftThird=(2*left+right)/3;
            rightThird=(left+2*right)/3;
            if(f(leftThird)<f(rightThird))
                left=leftThird;
            else right=rightThird;
        }
        printf("%.2f\n%.2f\n%.2f\n",f(left),h(left),left);
    }
    return 0;
}
