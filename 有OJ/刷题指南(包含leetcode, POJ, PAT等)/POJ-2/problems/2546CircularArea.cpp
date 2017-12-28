#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
double x1,y11,r1,x2,y22,r2;
double PI = acos(-1.0);
inline double dis(double x, double y)
{
    return sqrt(x*x+y*y);
}
const double eps = 1e-9;
int main()
{
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y11,&r1,&x2,&y22,&r2);
    //cin>>x1>>y1>>r1>>x2>>y2>>r2;
    double d = dis(x1-x2,y11-y22);
    if(d>=r1+r2-eps) printf("%.3f\n",0.0);
    else if(d<=fabs(r2-r1)+eps) printf("%.3f\n",PI*min(r1,r2)*min(r1,r2));
    else{
        //cout<<"err"<<endl;
        double t1 = d, t2 = (r1*r1-r2*r2)/d;
        double a = (t1+t2)/2, b = (t1-t2)/2;
        double alpha = acos(a/r1), beta = acos(b/r2);
        //if(alpha>PI/2) alpha -= PI;
        //if(beta>PI/2) beta -= PI;
        //cout<<a<<" "<<b<<endl;
        //cout<<alpha<<" "<<beta<<endl;
        double area = alpha*r1*r1 - r1*r1*sin(alpha)*cos(alpha) + beta*r2*r2 - r2*r2*sin(beta)*cos(beta);
        printf("%.3f\n",area);
    }
    return 0;
}
