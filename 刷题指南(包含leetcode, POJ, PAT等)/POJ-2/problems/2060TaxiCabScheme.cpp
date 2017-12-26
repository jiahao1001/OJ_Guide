#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;
const int N = 500;
int t,n;
int g[N][N];
int a[N],b[N],c[N],d[N];
int depart[N];
inline int dist(int i,int j){
    return abs(a[i]-c[i])+abs(b[i]-d[i])+abs(a[j]-c[i])+abs(b[j]-d[i]);
}
int vis[N],ly[N];
bool dfs(int i){
    for(int j=0;j<n;j++)
        if(g[i][j] && !vis[j]){
            vis[j] = 1;
            if(ly[j]==-1||dfs(ly[j])){

                ly[j] = i;
                return true;
            }
        }
    return false;
}
int max_match()
{
    int mat = 0;
    memset(ly,-1,sizeof(ly));
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) mat++;
    }
    return mat;
}

int main()
{
    scanf("%d",&t);
    int hh,mm;
    while(t--){
        scanf("%d",&n);
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++){
            scanf("%d:%d %d %d %d %d",&hh,&mm,a+i,b+i,c+i,d+i);
            depart[i] = hh*60+mm;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(depart[i]+dist(i,j)+1<=depart[j]) g[i][j]=1;
        
        printf("%d\n",n-max_match());
    }
}
