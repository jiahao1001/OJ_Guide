#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
using namespace std;
double cost[1000][1000];
double dist[1000][1000];
int x[1000],y[1000],z[1000];
int n;
int vis[1000];
double d[1000];
int f[1000];
inline double prim(double rate){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        d[i]=DBL_MAX/2;
    d[0]=0;
    f[0]=0;
    double totalcost=0,totaldist=0;
    double cos=0,dis=0;
    int jj;
    double tmp=DBL_MAX/2;
    for(int i=0;i<n;i++)
    {
        tmp=DBL_MAX/2;
        for(int j=0;j<n;j++)
            if(!vis[j]&&d[j]<tmp) tmp=d[j],jj=j;
        vis[jj]=1;
        totalcost+=cost[f[jj]][jj];
        totaldist+=dist[f[jj]][jj];
        for(int j=0;j<n;j++)
            if(!vis[j]&&(tmp=cost[jj][j]-rate*dist[jj][j])<d[j]) d[j]=tmp,f[j]=jj;
    }
    
    return totalcost/totaldist;
    
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d%d",x+i,y+i,z+i);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cost[i][j]=1.0*abs(z[i]-z[j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j]));
        double r0=0,r1=0;
        do{
            r0=r1;
            r1=prim(r1);
            
        }while(fabs(r0-r1)>1e-5);
        printf("%.3f\n",r0);
    }
    return 0;
}
