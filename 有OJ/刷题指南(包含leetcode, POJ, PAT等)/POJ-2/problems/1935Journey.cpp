#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
const int N = 50010;
struct E{
    int v,w,next;
}elist[N<<1];
int head[N];
int e_cnt;
int n,k;
int city[N];
int dp[N][2]; // 0 not coming back, 1 coming back
void addedge(int a,int b,int c){
    elist[e_cnt].v = b;
    elist[e_cnt].w = c;
    elist[e_cnt].next = head[a];
    head[a] = e_cnt++;
}
void dfs(int u,int f){
    dp[u][0] = dp[u][1] = 0;
    int m = 0;
    for(int i=head[u];i!=-1;i=elist[i].next){
        int v = elist[i].v;
        int w = elist[i].w;
        if(v==f)continue;
        dfs(v,u);
        if(!dp[v][1] && !city[v]) continue;
        dp[u][0] += 2*w+dp[v][1];
        dp[u][1] += 2*w+dp[v][1];
        m = max(m,w+dp[v][1]-dp[v][0]);
    }
    dp[u][0] -= m;
}
int main()
{
    int a,b,c;
    scanf("%d%d",&n,&k);
    e_cnt = 0;
    memset(head,-1,sizeof head);
    for(int i=0;i<n-1;i++){
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c);
        addedge(b,a,c);
    }
    int cnt,x;
    scanf("%d",&cnt);
    while(cnt--){
        scanf("%d",&x);
        city[x] =1;
    }
    dfs(k,0);
    printf("%d\n",min(dp[k][0],dp[k][1]));
    
    return 0;
}
