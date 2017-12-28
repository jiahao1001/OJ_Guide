#include <stdio.h>
#include <math.h>

int main(){

    double a,b,c,d,x,y,ds;
    scanf("%lf%lf%lf%lf%lf",&a, &b, &c, &d, &x);

    int count=1;
    y=a*x*x*x+b*x*x+c*x+d;
    while(fabs(y)>1e-7){
        ds= 3*a*x*x+2*b*x+c;
        x= x-(y/ds);
        y= a*x*x*x+b*x*x+c*x+d;
        count++;
    }
    printf("%.3lf %d\n",x, count);
    
    return 0;
}