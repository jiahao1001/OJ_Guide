#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double Ax,Ay,Bx,By,Cx,Cy;
double x1,yy1,dx1,dy1,x2,y2,dx2,dy2;
double a,b,x,y,r;
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf",&Ax,&Ay,&Bx,&By,&Cx,&Cy)!=EOF)
    {
        x1=(Ax+Bx)/2;
        yy1=(Ay+By)/2;
        x2=(Bx+Cx)/2;
        y2=(By+Cy)/2;
        dx1=By-Ay;
        dy1=Ax-Bx;
        
        dx2=Cy-By;
        dy2=Bx-Cx;
        b=(dy1*(x1-x2)-dx1*(yy1-y2))/(dx2*dy1-dx1*dy2);
        x=x2+b*dx2;
        y=y2+b*dy2;
        r=sqrt((x-Ax)*(x-Ax)+(y-Ay)*(y-Ay));
        printf("(x ");
        if(x>0) printf("- %.3f)^2 + (y ",x);
        else printf("+ %.3f)^2 + (y ",-x);
        if(y>0) printf("- %.3f)^2 = ",y);
        else printf("+ %.3f)^2 = ",-y);
        printf("%.3f^2\n",r);
        double c=-2*x,d=-2*y,e=x*x+y*y-r*r;
        printf("x^2 + y^2 ");
        if(c>0) printf("+ %.3fx ",c);
        else printf("- %.3fx ",-c);
        if(d>0) printf("+ %.3fy ",d);
        else printf("- %.3fy ",-d);
        if(e>0) printf("+ %.3f = 0\n",e);
        else printf("- %.3f = 0\n",-e);
        printf("\n");
    }
    return 0;
}
