#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;
typedef pair<double,double> PDD;
pair<double,double> cylinders[10][10];
int n;
double dist(double x,double y)
{
    return sqrt(x*x+y*y);
}
pair<double,double> get_cylinder(PDD c1, PDD c2)
{
    double x1 = c1.first, y1 = c1.second;
    double x2 = c2.first, y2 = c2.second;
    double x=(x1+x2)/2,y=(y1+y2)/2;
    double d = dist(x1-x2,y1-y2);
    double len = sqrt(2.0*2.0-d*d/4);
    double dx = y1-y2, dy = x2-x1;
    d = dist(dx,dy);
    dx/=d, dy/=d;
    x+=len*dx;
    y+=len*dy;
    return make_pair(x,y);
    
}
double base[10];
int main()
{
    double x;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++){
            scanf("%lf",&x);
            base[i] = x;
        }
        sort(base,base+n);
        for(int i=0;i<n;i++){
            cylinders[0][i].first = base[i];
            cylinders[0][i].second  = 1;
        }
        for(int i=1;i<n;i++)
            for(int j=0;j<n-i;j++){
                cylinders[i][j] = get_cylinder(cylinders[i-1][j],cylinders[i-1][j+1]);
            }
        printf("%.4f %.4f\n",cylinders[n-1][0].first,cylinders[n-1][0].second);
    }
    
    return 0;
}
