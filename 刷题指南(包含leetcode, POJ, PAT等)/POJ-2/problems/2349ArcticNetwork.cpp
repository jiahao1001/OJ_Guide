#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<set>
#include<string>
#include<limits.h>
#include<algorithm>
#include<float.h>
using namespace std;
const int N = 500;
int t,n,s;
double g[N][N];
int x[N],y[N];
double tree_edge[N];
double hyp(double x,double y){
    return sqrt(x*x+y*y);
}
double dist[N];
int vis[N];
void prim(){
    for(int i=0;i<n;i++) dist[i] = DBL_MAX/2;
    dist[0] = 0;
    memset(vis,0,sizeof(vis));
    for(int k=0;k<n;k++){
        double e = DBL_MAX/2;
        int e_i;
        for(int i=0;i<n;i++)
            if(!vis[i] && dist[i]<e) e=dist[i],e_i=i;
        tree_edge[k] = e;
        vis[e_i] = 1;
        for(int i=0;i<n;i++)
            if(!vis[i] && g[e_i][i]<dist[i]) dist[i]=g[e_i][i];   
    }   
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&s,&n);
        for(int i=0;i<n;i++) scanf("%d%d",x+i,y+i);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) g[i][j] = hyp(x[i]-x[j],y[i]-y[j]);
        prim();
        sort(tree_edge,tree_edge+n);
        //for(int i=0;i<n;i++) printf("%.2f ",tree_edge[i]);
        printf("%.2f\n",tree_edge[n-s]);
    }
}
