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
const int N = 20;
const double INF = DBL_MAX/2;
double hyp(double x,double y){
    return sqrt(x*x+y*y);
}
int n;
int V;
double x[N],y[N][4];
double g[N<<2][N<<2];
bool through_wall(int i,double x1,double y1,double x2,double y2){
    double y0 = (y2-y1)/(x2-x1)*(x[i]-x1)+y1;
    return (y[i][0]<=y0 && y0<=y[i][1]) || (y[i][2]<=y0 && y0<=y[i][3]);
}
double cacl(int i,int j, double x1,double y1, double x2,double y2){  //wall i to j
    for(int k=i+1;k<j;k++){
        if(!through_wall(k,x1,y1,x2,y2)) return INF;
    }
    return hyp(x1-x2,y1-y2);
}
double dist[N<<2];
int vis[N<<2];
int main(){
    while(scanf("%d",&n),n!=-1){
        for(int i=0;i<n;i++){
            scanf("%lf",x+i);
            for(int j=0;j<4;j++)
                scanf("%lf",&y[i][j]);
        }
        //start = 4n, end is 4n+1
        //build_graph
        V = 4*n+2;
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++) g[i][j] = INF;
        for(int i=0;i<4*n;i++)
            g[4*n][i] = cacl(-1,i/4,0,5,x[i/4],y[i/4][i%4]);
        g[4*n][4*n+1] = cacl(-1,n,0,5,10,5);
        for(int i=0;i<4*n;i++)
            g[i][4*n+1] = cacl(i/4,n,x[i/4],y[i/4][i%4],10,5);
        for(int i=0;i<4*n;i++)
            for(int j=i+1;j<4*n;j++) {
                if(i/4<j/4) g[i][j]=cacl(i/4,j/4,x[i/4],y[i/4][i%4],x[j/4],y[j/4][j%4]);
            }
        //dijkstra
        for(int i=0;i<V;i++) dist[i] = INF,vis[i]=0;
        dist[V-2] = 0;
        for(int i=0;i<V;i++){
            double best = INF;
            int id = -1;
            for(int j=0;j<V;j++)
                if(!vis[j] && dist[j]<best) best = dist[j], id=j;
            vis[id] = 1;
            for(int j=0;j<V;j++)
                if(!vis[j] && dist[id]+g[id][j]<dist[j]) dist[j] = dist[id]+g[id][j];
        }
        
        printf("%.2f\n",dist[V-1]);
    }
    return 0;
}
