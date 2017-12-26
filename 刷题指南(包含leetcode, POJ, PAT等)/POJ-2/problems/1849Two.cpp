#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
using namespace std;
const int N = 100010;
vector<int> g[N];
vector<int> w[N];
int dp[N];
int n,s;
int dfs(int u,int f){
    int m = 0;
    dp[u] = 0;
    int m1 = 0, m2 = 0;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        int ww = w[u][i];
        if(v==f)continue;
        int x = dfs(v,u)+ww;
        m = max(m,x);
        if(x>=m1) m2 = m1, m1 = x;
        else if(x>m2) m2 = x;
        dp[u] = max(dp[u],dp[v]);
    }
    dp[u] = max(dp[u],m1+m2);
    return m;
}
int main()
{
    int a,b,c;
    int tot = 0;
    scanf("%d%d",&n,&s);
    for(int i=0;i<n-1;i++){
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(b);
        w[a].push_back(c);
        g[b].push_back(a);
        w[b].push_back(c);
        tot += c;
    }
    dfs(s,0);
    printf("%d\n",2*tot-dp[s]);
    return 0;
}
