#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
const int N = 50010;
struct Edge{
    int v,next;
} elist[2*N];
int head[N];
int size[N];
int dp[N];
int n;
int e_cnt=1;
void addedge(int a,int b){
    elist[e_cnt].v = b;
    elist[e_cnt].next = head[a];
    head[a] = e_cnt++;
}
void dfs1(int u,int f){
    size[u] = 1;
    for(int i=head[u];i;i=elist[i].next){
        int v = elist[i].v;
        if(v!=f){
            dfs1(v,u);
            size[u]+=size[v];
        }
    }
}
void dfs2(int u,int f){
    dp[u] = size[1]-size[u];
    for(int i=head[u];i;i=elist[i].next){
        int v = elist[i].v;
        if(v!=f){
            dp[u]=max(dp[u],size[v]);
            dfs2(v,u);
        }
    }
    
}

int main(){
    int a,b;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    dfs1(1,0);
    dfs2(1,0);
    int god = 1<<30;
    for(int i=1;i<=n;i++) god=min(god,dp[i]);
    bool first = true;
    for(int i=1;i<=n;i++)
        if(dp[i]==god){
            if(first){
                first = !first;
                printf("%d",i);
            }else printf(" %d",i);
        }
    printf("\n");
    return 0;
}
