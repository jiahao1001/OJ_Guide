#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N = 1001;
int n,m;
int v[N][2];
//x column num  y row num
int vis[N],ly[N];
int lx[N];
bool dfs(int u){
    for(int i=0;i<2;i++){
        int vv = v[u][i];
        if(!vis[vv]){
            vis[vv] = 1;
            if(!ly[vv] || dfs(ly[vv])){
                ly[vv] = u;
                return true;
            }
        }
    }
    return false;
}
int max_match(){
    int mat = 0;
    memset(ly,0,sizeof ly);
    memset(lx,0,sizeof lx);
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)) mat++;
    }
    return mat;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++)
            for(int j=0;j<2;j++)
                scanf("%d",&v[i][j]);
        if(n<m||max_match()!=m){
            printf("NO\n");
            continue;
        }
        for(int i=1;i<=m;i++)
            lx[ly[i]] = i;
        for(int i=1;i<=n;i++)
            if(!lx[i]) lx[i] = v[i][0];
        for(int i=1;i<n;i++)
            printf("%d ",lx[i]);
        printf("%d\n",lx[n]);
    }
    return 0;
}
