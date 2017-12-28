#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
const int INF = INT_MAX/2;
int n,r;
int g[210][210];
int lim[210];
int vis[210];
int main()
{
    string s,e;
    int x,y;
    int q=1;
    int len;
    while(cin>>n>>r, n||r ){
        map<string,int> id;
        int cnt = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) g[i][j] = 0;
        
        for(int i=0;i<r;i++){
            cin>>s>>e>>len;
            if(!id.count(s)) id[s]=++cnt;
            if(!id.count(e)) id[e]=++cnt;
            x = id[s],y = id[e];
            g[x][y] = max(g[x][y],len);
            g[y][x] = max(g[y][x],len);
        }
        cin>>s>>e;
        x = id[s], y = id[e];
        memset(lim,0,sizeof(lim));
        memset(vis,0,sizeof(vis));
        lim[x] = INF;
        for(int k=1;k<=n;k++){
            int best = -1, id = 0;
            for(int i=1;i<=n;i++)
                if(!vis[i] && lim[i]> best) best = lim[i],id=i;
            vis[id] = 1;
            for(int i=1;i<=n;i++)
                if(!vis[i]) lim[i] = max(lim[i],min(lim[id],g[id][i]));
            
        }
        printf("Scenario #%d\n",q++);
        printf("%d tons\n\n",lim[y]);
    }
    return 0;
}
