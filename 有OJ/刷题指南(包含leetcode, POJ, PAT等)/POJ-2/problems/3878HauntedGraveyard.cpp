#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
const int N = 900;
const int INF = 0x3f3f3f3f;
int W,H,G,E,X1,Y1,X2,Y2,T;
char grave[30][40];//W*H
int dist[N];
vector<PII> g[N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main()
{
    int x,y;
    while(scanf("%d%d",&W,&H),W||H){
        memset(grave,'.',sizeof(grave));
        for(int i=0;i<N;i++) g[i].clear();
        scanf("%d",&G);
        for(int i=0;i<G;i++){
            scanf("%d%d",&x,&y);
            grave[x][y] = 'G';
        }
        scanf("%d",&E);
        for(int i=0;i<E;i++){
            scanf("%d%d%d%d%d",&X1,&Y1,&X2,&Y2,&T);
            g[X1*H+Y1].push_back(make_pair(X2*H+Y2,T));
            grave[X1][Y1] = 'H';
        }
        for(int i=0;i<W;i++)
            for(int j=0;j<H;j++){
                if(i*H+j==W*H-1) continue;
                if(grave[i][j]!='.') continue;
                for(int k=0;k<4;k++){
                    x = i+dx[k], y = j+dy[k];
                    if(x>=0 && x<W && y>=0 && y<H &&
                       grave[x][y]!='G')
                        g[i*H+j].push_back(make_pair(x*H+y,1));
                }
            }
        int n = W*H;
        memset(dist,0x3f,sizeof(dist));
        dist[0]=0;
        for(int k=0;k<n-1;k++)
            for(int u=0;u<n;u++){
                if(dist[u]==INF) continue;
                for(int i=0;i<g[u].size();i++){
                    PII &e = g[u][i];
                    if(dist[u]+e.second<dist[e.first])
                        dist[e.first] = dist[u]+e.second;
                }
            }
        bool negative = false;
        for(int u=0;u<n;u++)
            for(int i=0;i<g[u].size();i++){
                PII &e = g[u][i];
                if(dist[u]==INF) continue;
                if(dist[u]+e.second<dist[e.first])
                    negative=true;//dist[e.first] = dist[u]+e.second;
            }
        //if(best>dist[n-1]) negative = true;
        if(negative) printf("Never\n");
        else if(dist[n-1]==INF) printf("Impossible\n");
        else printf("%d\n",dist[n-1]);
    }
    return 0;
}
