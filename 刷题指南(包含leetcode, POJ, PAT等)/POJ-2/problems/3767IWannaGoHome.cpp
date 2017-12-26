
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int INF = 0x3f3f3f3f;
int g[605][605];
int g1[605][605];
int g2[605][605];
int d1[605],d2[605];
int ld[605];
int n,m;
void dijkstra(int g[][605],int s,int d[]){
    d[s] = 0;
    int v[605];
    memset(v,0,sizeof v);
    for(int i=1;i<=n;i++){
        int bx=0,best = INF;
        for(int j=1;j<=n;j++)
            if(!v[j] && d[j]<best) best = d[j], bx = j;
        if(best == INF) return;
        v[bx] = 1;
        for(int j=1;j<=n;j++)
            if(!v[j] && best + g[bx][j]<d[j]) d[j] = best+g[bx][j];
    }
    
}
int main(){
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        int a,b,c;
        memset(g,0x3f,sizeof g);
        memset(g1,0x3f,sizeof g1);
        memset(g2,0x3f,sizeof g2);
        memset(d1,0x3f,sizeof d1);
        memset(d2,0x3f,sizeof d2);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            g[a][b] = g[b][a] = c;
        }
        //dijkstra twice
        for(int i=1;i<=n;i++){
            scanf("%d",ld+i);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(ld[i]!=ld[j]) continue;
                if(ld[i]==1) g1[i][j] = g[i][j];
                else g2[i][j] = g[i][j];
            }
        
        dijkstra(g1,1,d1);
        dijkstra(g2,2,d2);
        int ans = INF;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(ld[i]==1 && ld[j]==2 && g[i][j]<INF) ans = min(ans, g[i][j] + d1[i]+d2[j]);
            }
        
        if(ans==INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
