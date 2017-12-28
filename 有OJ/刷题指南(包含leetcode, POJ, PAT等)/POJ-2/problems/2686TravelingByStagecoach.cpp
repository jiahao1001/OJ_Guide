#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
#include<set>
using namespace std;
const double inf = (double)INT_MAX;

int n,m,p,a,b;
int horse[8];
vector<int> v[31];
vector<double> w[31];
double dp[31][1<<8];
double f(int i,int s){
    if(i==a) return 0;
    if(dp[i][s]!=-1) return dp[i][s];
    dp[i][s] = inf;
    for(int j=0;j<v[i].size();j++){
        int k = v[i][j];
        for(int x=0;x<n;x++){
            int ns = s^(1<<x);
            if(ns>s) dp[i][s] = min(dp[i][s],f(k,ns)+ w[i][j]/horse[x]);
        }
    }
    return dp[i][s];
}
int main(){
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b),n){
        for(int i=0;i<n;i++) scanf("%d",horse+i);
        for(int i=1;i<=m;i++) v[i].clear(),w[i].clear();
        int x,y;
        double z;
        for(int i=0;i<p;i++){
            scanf("%d%d%lf",&x,&y,&z);
            v[x].push_back(y);
            w[x].push_back(z);
            v[y].push_back(x);
            w[y].push_back(z);
        }
        for(int i=1;i<=m;i++)
            for(int j=0;j<(1<<n);j++) dp[i][j] = -1;
        double ans = f(b,0);
        if(ans>=inf)printf("Impossible\n");
        else printf("%f\n",ans);
        
    }
    return 0;
}
