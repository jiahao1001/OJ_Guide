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
const int N = 20;
const int M = 100;
char word[20];
int g[N][M];
int n,m;
char ok[N][3];
int cnt[6];
inline int toI(char c){
    switch(c){
    case 'S':return 1;
    case 'M':return 2;
    case 'L':return 3;
    case 'X':return 4;
    case 'T':return 5;
    }
}
int vis[M],ly[M];
bool dfs(int i){
    for(int j=0;j<m;j++)
        if(g[i][j] && !vis[j]){
            vis[j] = 1;
            if(ly[j]==-1 || dfs(ly[j])){
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

inline void build()
{
    memset(g,0,sizeof(g));
    for(int i=0;i<n;i++){
        int x = toI(ok[i][0]);
        int y = toI(ok[i][1]);
        for(int j=cnt[x-1];j<cnt[y];j++)
            g[i][j] = 1;
    }
}
int main()
{
    while(scanf("%s",word),strcmp(word,"ENDOFINPUT")){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",ok[i]);
        for(int i=1;i<=5;i++) scanf("%d",cnt+i);
        cnt[0]=0;
        for(int i=1;i<=5;i++) cnt[i]+=cnt[i-1];
        m = cnt[5];
        build();
        scanf("%s",word);
        if(max_match()==n) printf("T-shirts rock!\n");
        else printf("I'd rather not wear a shirt anyway...\n");
    }
    return 0;
}
