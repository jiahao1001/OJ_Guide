#include<iostream>
#include<stdio.h>
#include<cmath>
#define PI acos(-1.0)
using namespace std;
int N,F,T;
int r[10000];
bool check(double size)
{
    //has F pieces of size
    int pieces = 0;
    for(int i=0;i<N;i++){
        pieces += floor((PI*r[i]*r[i])/size);
        if(pieces >= F+1) return true;
    }
    return false;
    
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&F);
        double l=0,h=0;
        for(int i=0;i<N;i++) scanf("%d",r+i),h=max(h,r[i]*1.0);
        h = PI*h*h;
        //printf("%lf %lf\n",l,h);
        double mid;
        while(fabs(l-h)>1e-6){
            mid=(l+h)/2;
            if(check(mid)) l=mid;
            else h=mid;
        }
        printf("%.4f\n",l);
        
    }
    return 0;
}
