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
#include<sstream>
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<assert.h>
#include<numeric>
#include<map>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int g[MAXN][MAXN];

int N,A,B;
//int dist[MAXN][MAXN];
void floyd(){
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
}
int main(){
    scanf("%d%d%d",&N,&A,&B);
    memset(g,0x3f,sizeof(g));
    //memset(dist,0x3f,sizeof(dist));
    int cnt;
    int v;
    for(int i=1;i<=N;i++){
        scanf("%d",&cnt);
        for(int j=0;j<cnt;j++){
            scanf("%d",&v);
            if(!j) g[i][v] = 0;
            else g[i][v] = 1;
        }
    }
    floyd();
    if(g[A][B]==INF)printf("-1\n");
    else printf("%d\n",g[A][B]);
    return 0;
    
}
