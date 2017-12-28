#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
using namespace std;

double dist[105][105];
int n,m;
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main(){
    int a,b,p;
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) dist[i][j] = DBL_MAX/2;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&p);
            dist[a][b] = log(100.0/p);
            dist[b][a] = log(100.0/p);
        }
        floyd();
        //cout<<dist[1][n]<<endl;
        printf("%.6f percent\n",exp(-dist[1][n])*100);
    }
}
