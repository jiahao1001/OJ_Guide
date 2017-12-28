#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <limits.h>
#include <stdio.h>
using namespace std;
const int N = 201;
map<string,int> id;
vector<int> g[N];
int n,cnt=0;
int dp[N][2],dup[N][2];
void dfs(int i){
    for(int k=0;k<g[i].size();k++){
        int j = g[i][k];
        dfs(j);
    }
    if(!g[i].size()){
        dp[i][0] = 0, dp[i][1] = 1;
        dup[i][0] = 0, dup[i][1] = 0;
    }else{
        dp[i][1] = 1;
        dup[i][1] = 0;
        for(int k=0;k<g[i].size();k++){
            int j = g[i][k];
            dp[i][1] += dp[j][0];
            dup[i][1]|=dup[j][0]; 
        }
        dp[i][0] = 0;
        dup[i][0] = 0;
        for(int k=0;k<g[i].size();k++){
            int j = g[i][k];
            int m = max(dp[j][0],dp[j][1]);
            dp[i][0] += m;
            dup[i][0]|=(m==dp[j][0] && dup[j][0] || m==dp[j][1] && dup[j][1] || dp[j][0]==dp[j][1]);
        }
        
    }
}
int main(){
    string name;
    string em,bo;
    while(cin>>n,n){
        cnt = 0;
        id.clear();
        for(int i=1;i<=n;i++) g[i].clear();
        cin>>name;
        id[name] = ++cnt;
        for(int i=0;i<n-1;i++){
            cin>>em>>bo;
            if(!id.count(em)) id[em] = ++cnt;
            if(!id.count(bo)) id[bo] = ++cnt;
            g[id[bo]].push_back(id[em]);
        }
        dfs(1);
        
        int ans = max(dp[1][0],dp[1][1]);
        printf("%d ",ans);
        if(ans==dp[1][0] && dup[1][0] || ans==dp[1][1] && dup[1][1] || dp[1][0]==dp[1][1])
            printf("No\n");
        else printf("Yes\n");
        
    }
}
