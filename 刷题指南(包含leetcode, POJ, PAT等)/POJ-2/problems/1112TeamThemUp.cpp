#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int N = 120;
int g[N][N];
int n;
vector<vector<int> > x;
vector<vector<int> > y;
int color[N];
bool ok;
void dfs(int i,int c){
    color[i] = c;
    if(!c) x.back().push_back(i);
    else y.back().push_back(i);
    for(int j=1;j<=n;j++)
        if(g[i][j]&&i!=j){
            if(color[j]==-1) dfs(j,1-c);
            else if(color[j]==c) ok = false;
        }
}
int dp[N][N][N];
int answer[N][N][N];
vector<int> team[2];
void get(int d,int i,int j){
    if(d==0) return;
    if(answer[d][i][j]){
        i-=y[d-1].size();
        j-=x[d-1].size();
        for(int k=0;k<x[d-1].size();k++)
            team[1].push_back(x[d-1][k]);
        for(int k=0;k<y[d-1].size();k++)
            team[0].push_back(y[d-1][k]);
    }else{
        i-=x[d-1].size();
        j-=y[d-1].size();
        for(int k=0;k<x[d-1].size();k++)
            team[0].push_back(x[d-1][k]);
        for(int k=0;k<y[d-1].size();k++)
            team[1].push_back(y[d-1][k]);
        
    }
    get(d-1,i,j);
    
}
int main()
{
    int t=1;
    //scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) g[i][j] = 1;
        for(int i=1;i<=n;i++){
            int j;
            while(scanf("%d",&j),j) g[i][j] = 0;
        }
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++) if(g[i][j])g[j][i]=1;
        
        ok = true;
        memset(color, -1, sizeof color);
        x.clear();
        y.clear();
        for(int i=1;i<=n;i++)
            if(color[i]==-1) x.push_back(vector<int>()), y.push_back(vector<int>()),dfs(i,0);
        
        if(!ok){
            printf("No solution\n");
        }else{
            memset(dp,0,sizeof dp);
            dp[0][0][0] = 1;
            for(int i=0;i<x.size();i++){
                for(int j=0;j<=n;j++)
                    for(int k=0;k<=n;k++) if(dp[i][j][k]){
                            dp[i+1][j+x[i].size()][k+y[i].size()] = 1;
                            answer[i+1][j+x[i].size()][k+y[i].size()] = 0;
                            dp[i+1][j+y[i].size()][k+x[i].size()] = 1;
                            answer[i+1][j+y[i].size()][k+x[i].size()] = 1;
                        }
            }
            int xx = 0, yy = 0;
            int diff = n;
            for(int i=1;i<=n-1;i++)
                if(dp[x.size()][i][n-i]){
                    if(abs(n-2*i)<diff)diff = abs(n-2*i),xx=i,yy=n-i;
                }
            team[0].clear();
            team[1].clear();
            get(x.size(),xx,yy);
            for(int i=0;i<2;i++){
                printf("%d",team[i].size());
                for(int j=0;j<team[i].size();j++)
                    printf(" %d",team[i][j]);
                printf("\n");
            }
        }
        if(t)printf("\n");
    }
    return 0;
}
