#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 1001;
const int K = 100;
int g[N][N];
int n,k,m;
int cow[K];
int visited[N];
int cnt[N];
void dfs(int i){
    visited[i] = 1;
    cnt[i] ++;
    for(int j=1;j<=n;j++)
        if(g[i][j] && !visited[j]) dfs(j);
}

int main()
{
    scanf("%d%d%d",&k,&n,&m);
    int a,b;
    for(int i=0;i<k;i++)
        scanf("%d",cow+i);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a][b] = 1;
    }
    for(int i=0;i<k;i++){
        memset(visited,0,sizeof(visited));
        dfs(cow[i]);
    }
    int answer = 0;
    for(int i=1;i<=n;i++)
        if(cnt[i]==k) answer++;
    printf("%d\n",answer);
    return 0;
}
