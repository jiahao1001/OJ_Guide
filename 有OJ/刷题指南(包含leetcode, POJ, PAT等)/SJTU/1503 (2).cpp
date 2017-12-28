#include <stdio.h>
#include <cmath>
int main()
{
    float a,b,c,d;
    scanf("%f %f %f %f",&a,&b,&c,&d);
    float e=sqrt((a-c)*(a-c)+(b-d)*(b-d));
    printf("%0.5f",e);
}
