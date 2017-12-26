#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int n,m;
int ele[40][40];
int w;
int inf = 100000000;
const double eps = 1e-7;
//water <= w
bool check(double h){
    double tot = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(h>ele[i][j]) tot += 100*(h-ele[i][j]);
    return tot<=w;
}
int main()
{
    int q=1;
    while(scanf("%d%d",&n,&m),n||m){
        double l = inf;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) scanf("%d",&ele[i][j]),l = min(l,1.0*ele[i][j]);
        scanf("%d",&w);
        double  r = inf;
        double mid;
        while(fabs(l-r)>eps){
            mid = (l+r)/2;
            if(check(mid)) l=mid;
            else r = mid;
        }
        int me = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(l>ele[i][j]) me++;
        printf("Region %d\n",q++);
        printf("Water level is %.2f meters.\n",l);
        printf("%.2f percent of the region is under water.\n",100.0*me/(n*m));
    }
    return 0;
}
