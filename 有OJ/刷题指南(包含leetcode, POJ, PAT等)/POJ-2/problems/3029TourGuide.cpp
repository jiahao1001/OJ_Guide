#include<iostream>
#include<stdio.h>
#include<float.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct Guest
{
    double x,y,v,a;
} guests[8];
int order[8];
int n;
double x,y,v,t;
int main()
{
    while(scanf("%d",&n),n)
    {
        
        
        scanf("%lf",&v);
        double best=DBL_MAX;
        for(int i=0;i<n;i++)
            order[i]=i,
            scanf("%lf%lf%lf%lf",&guests[i].x,&guests[i].y,&guests[i].v,&guests[i].a);
        do{
            x=y=t=0;
            double last=0;
            for(int i=0;i<n;i++)
            {
                Guest &guest=guests[order[i]];
                double xi=guest.x,yi=guest.y,vi=guest.v,ai=guest.a;
                double vx=vi*cos(ai),vy=vi*sin(ai);
                xi+=vx*t,yi+=vy*t;
                double a=(vx*vx+vy*vy-v*v);
                double b=2*(xi-x)*vx+2*(yi-y)*vy;
                double c=(xi-x)*(xi-x)+(yi-y)*(yi-y);
                double d=sqrt(b*b-4*a*c);
                double e=(-b-d)/(2*a);
                //cout<<"e "<<e<<endl;
                t+=e;
                x=xi+vx*e,y=yi+vy*e;
                double home=t+(sqrt(x*x+y*y))/vi;
                if(home>last) last=home;
            }
            
            if(last<best) best = last;
            
        }while(next_permutation(order,order+n));
        
        printf("%d\n",(int)round(best));
    }
    return 0;
}
