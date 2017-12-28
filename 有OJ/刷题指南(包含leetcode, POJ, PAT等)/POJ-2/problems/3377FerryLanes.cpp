#include<queue>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<limits.h>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<long long,int> P;
const int N =  1000010;
const long long inf = ~0ull>>1;
LL dp[N][2];
LL lane[N];
LL dock[N][2];
int n;
int main()
{
    while(scanf("%d",&n),n){
        //0 mean north
        int sc,s,t,tc;
        scanf("%d%d%d%d",&sc,&s,&tc,&t);
        if(s>t) swap(s,t),swap(sc,tc);
        for(int i=0;i<n;i++)
            scanf("%lld",&dock[i][0]);
        for(int i=0;i<n+1;i++)
            scanf("%lld",&lane[i]);
        for(int i=0;i<n;i++)
            scanf("%lld",&dock[i][1]);
        for(int i=0;i<n+1;i++)
            for(int j=0;j<2;j++) dp[i][j] = inf;
        
        //dijkstra
        priority_queue<P,vector<P>, greater<P> > pq;
        
        dp[s][sc] = 0;
        pq.push(make_pair(0,sc*(n+1)+s));
        while(!pq.empty()){
            P h = pq.top();
            pq.pop();
            int d = h.first;
            int i = h.second%(n+1), j = h.second/(n+1);
            if(d>dp[i][j]) continue;
            if(d+lane[i]<dp[i][1-j]){
                dp[i][1-j] = d+lane[i], pq.push(make_pair(d+lane[i],(1-j)*(n+1)+i));
            }
            if(i>0 && d+dock[i-1][j]<dp[i-1][j]) {
                //i-1,j
                dp[i-1][j] = d+dock[i-1][j];
                pq.push(make_pair(d+dock[i-1][j],j*(n+1)+i-1));
            }
            if(i<n && d+dock[i][j]<dp[i+1][j]) {
                //i+1, j
                dp[i+1][j] = d+dock[i][j];
                pq.push(make_pair(d+dock[i][j],j*(n+1)+i+1));
            }
            
        }
        printf("%lld\n",dp[t][tc]);
    }
    return 0;
}
