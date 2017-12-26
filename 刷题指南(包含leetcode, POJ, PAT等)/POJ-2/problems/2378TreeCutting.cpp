#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
const int N = 10001;
vector<int> g[N];
int size[N];
int barns[N];
int n;
void dfs(int u,int f){
    size[u] = 1;
    bool ok = true;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f) continue;
        dfs(v,u);
        size[u]+=size[v];
        if(size[v]>n/2) ok = false;
    }
    if(n-size[u]>n/2) ok = false;
    if(ok) barns[u] = 1;
    
}
int main()
{
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    int cnt = 0;
    for(int i=1;i<=n;i++)
        if(barns[i]){
            printf("%d\n",i);
            cnt++;
        }
    if(!cnt) printf("NONE\n");
}
