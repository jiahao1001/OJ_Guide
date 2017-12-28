#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
const int N = 3010;
int dp[N][N];
int n,m;
int size[N];
vector<int> g[N];
vector<int> w[N];
void dfs(int u){
    if(u>=n-m+1){
        return;
    }
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i], ww = w[u][i];
        dfs(v);
        for(int j=size[u];j>=0;j--)
            for(int k=1;k<=size[v];k++){
                dp[u][j+k] = max(dp[u][j+k],dp[u][j]+dp[v][k]-ww);
            }
        size[u] += size[v];
    }
}
int main()
{
    int x,k,a,c;
    scanf("%d%d",&n,&m);
    memset(size,0,sizeof size);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j] = INT_MIN/2;
    for(int i=1;i<=n-m;i++){
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&a,&c);
            g[i].push_back(a);
            w[i].push_back(c);
        }
    }
    for(int i=n-m+1;i<=n;i++){
        scanf("%d",&x);
        dp[i][1] = x;
        size[i] = 1;
    }
    dfs(1);
    int answer;
    for(int i=m;i>=0;i--){
        if(dp[1][i]>=0){
            answer=i;
            break;
        }
    }
    printf("%d\n",answer);
    return 0;
}
