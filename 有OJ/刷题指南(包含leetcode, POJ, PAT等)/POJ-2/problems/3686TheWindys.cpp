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
const int MAXN = 50;
const int MAXM = 2500;
int n,m;
int cost[MAXN][MAXN];
int g[MAXN][MAXM];
int lx[MAXN],ly[MAXM];
int linky[MAXM],visx[MAXN],visy[MAXM];
int slack[MAXM];
bool dfs(int u)
{
    visx[u] = 1;
    for(int i=0;i<m;i++)
        if(!visy[i]){
            int t = lx[u]+ly[i]-g[u][i];
            if(t==0){
                visy[i] = 1;
                if(linky[i]==-1 || dfs(linky[i])){
                    linky[i] = u;
                    return true;
                }
            }
        }
    return false;
}
int kuhn_munkres()
{
    for(int i=0;i<m;i++) ly[i] = 0,linky[i] = -1;
    for(int i=0;i<n;i++){
        lx[i] = INT_MIN;
        for(int j=0;j<m;j++) lx[i] = max(lx[i],g[i][j]);
    }
    for(int k=0;k<n;k++){
        while(1){
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(dfs(k)) break;
            int d = INT_MAX;
            for(int i=0;i<n;i++)
                if(visx[i])
                    for(int j=0;j<m;j++)
                        if(!visy[j]) d = min(d,lx[i]+ly[j]-g[i][j]);
            
            for(int j=0;j<n;j++)
                if(visx[j]) lx[j]-=d;
            for(int j=0;j<m;j++)
                if(visy[j]) ly[j]+=d;
        }
        
    }
    
    int res = 0;
    for(int i=0;i<m;i++)
        if(linky[i]!=-1) res += g[linky[i]][i];
    
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) scanf("%d",&cost[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<m;k++) g[i][j*m+k] = -(j+1)*cost[i][k];
        m = n*m;
        double ans = 1.0*(-kuhn_munkres())/n;
        printf("%.6f\n",ans);
    }
    return 0;
}
