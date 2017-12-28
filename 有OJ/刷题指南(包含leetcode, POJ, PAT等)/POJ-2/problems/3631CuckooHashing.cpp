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
using namespace std;
const int M = 10000;
const int N = 10000;
int t;
int m,n;//m words
int h[M][2];
int ly[N];
int vis[N];
bool dfs(int u){
    for(int i=0;i<2;i++)
        if(!vis[h[u][i]]){
            int v = h[u][i];
            vis[v] = 1;
            if(ly[v]==-1 || dfs(ly[v])){
                ly[v] = u;
                return true;
            }
        }
    return false;
}
int max_match(){
    int mat = 0;
    for(int i=0;i<m;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) mat++;
    }
    return mat;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            scanf("%d%d",&h[i][0],&h[i][1]);
        }
        memset(ly,-1,sizeof(ly));
        if(max_match()==m) printf("successful hashing\n");
        else printf("rehash necessary\n");
        
    }
}
