#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
#include <math.h>
#include <queue>
using namespace std;
const int N = 6001;
int dp[N][2];
vector<int> g[N];
int n,L,K;
int rate[N];
int is_root[N];
void dfs(int i){
    bool has_kid = false;
    for(int j=0;j<g[i].size();j++)
         dfs(g[i][j]), has_kid = true;
    if(!has_kid){
        dp[i][0] = 0, dp[i][1] = rate[i];
    }else{
        dp[i][0] = 0;
        for(int k=0;k<g[i].size();k++){
            int j = g[i][k];
            dp[i][0]+=max(dp[j][0],dp[j][1]);
        }
        dp[i][1] = rate[i];
        for(int k=0;k<g[i].size();k++){
            int j = g[i][k];
            dp[i][1]+=dp[j][0];
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) is_root[i] = 1;
    for(int i=1;i<=n;i++) scanf("%d",rate+i);
    for(int i=1;i<n;i++){
        scanf("%d%d",&L,&K);
        g[K].push_back(L);
        is_root[L] = 0;
    }
    scanf("%d%d",&L,&K);
    int id = 0;
    for(int i=1;i<=n;i++)
        if(is_root[i]){
            id = i;
            dfs(i);
            break;
        }
    //cout<<"hi"<<endl;
    printf("%d\n",max(dp[id][0],dp[id][1]));
    return 0;
}
