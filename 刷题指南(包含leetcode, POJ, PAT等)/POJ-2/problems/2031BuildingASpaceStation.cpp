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
#include<float.h>
using namespace std;
const int N = 100;

int n;
double x[N],y[N],z[N],r[N];
double g[N][N];
double dist(double x,double y,double z){
    return sqrt(x*x+y*y+z*z);
}
double corridor(int i,int j){
    //return the corridor length btw station i and j
    double d = dist(x[i]-x[j],y[i]-y[j],z[i]-z[j]);
    if(d<=r[i]+r[j]) return 0;
    return d-r[i]-r[j];
}
double d[N];
int vis[N];
int main()
{
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",x+i,y+i,z+i,r+i);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i][j] = corridor(i,j);
        for(int i=0;i<n;i++) d[i] = DBL_MAX/2;
        d[0] = 0;
        double total = 0;
        memset(vis,0,sizeof(vis));
        for(int k=0;k<n;k++){
            double best = DBL_MAX/2;
            int id = 0;
            for(int i=0;i<n;i++)
                if(!vis[i] && d[i]<best) best = d[i], id = i;
            vis[id] = 1;
            total += d[id];
            for(int i=0;i<n;i++)
                if(!vis[i] && g[id][i]<d[i]) d[i] = g[id][i];
        }
        printf("%.3f\n",total);
    }
    return 0;
}
