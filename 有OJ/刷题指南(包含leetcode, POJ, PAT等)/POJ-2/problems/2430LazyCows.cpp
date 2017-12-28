#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
short p[15000001][2];
int N,K,B;
vector<pii> up;
vector<pii> down;
int dp[2][5][1001];
int main()
{
    int x,y;
    scanf("%d%d%d",&N,&K,&B);
    for(int i=0;i<N;i++){
        scanf("%d%d",&x,&y);
        p[y][x-1] = 1;
    }
    int u = 1, d = 1;
    int um = p[1][0], dm = p[1][1];
    for(int i=2;i<=B;i++){
        if(p[i][0]!=um || p[i][1]!=dm){
            up.push_back(make_pair(um,u));
            down.push_back(make_pair(dm,d));
            um = p[i][0], dm = p[i][1];
            u = d = 1;
        }else u++,d++;
    }
    up.push_back(make_pair(um,u));
    down.push_back(make_pair(dm,d));
    
    //0 no 1 up  2 down   3 up down sep 4 up down toge
    int cur=0,nxt=1;
    for(int i=0;i<5;i++)
        for(int j=0;j<=K;j++) dp[cur][i][j] = INT_MAX/2;
    for(int j=0;j<=K;j++)
        dp[cur][0][j] = 0;
    for(int k=0;k<up.size();k++){
        for(int i=0;i<5;i++)
            for(int j=0;j<=K;j++) dp[nxt][i][j] = INT_MAX/2;
        for(int i1=0;i1<5;i1++){
            for(int i2=0;i2<5;i2++){
                if(i2==0 && (up[k].first || down[k].first)) continue;
                if(i2==1 && down[k].first) continue;
                if(i2==2 && up[k].first) continue;
                for(int j=0;j<=K;j++){
                    if(dp[cur][i1][j]==INT_MAX/2) continue;
                    if(i1==0){
                        if(i2==0) dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]);
                        else if(i2==1) {
                            if(j+1<=K)dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second);
                        }else if(i2==2){
                            if(j+1<=K) dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+down[k].second);
                        }else if(i2==3){
                            if(j+2<=K) dp[nxt][i2][j+2] = min(dp[nxt][i2][j+2],dp[cur][i1][j]+up[k].second*2);
                        }else if(i2==4){
                            if(j+1<=K) dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second*2);
                        }
                    }else if(i1==1){
                        if(i2==0) dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]);
                        else if(i2==1) dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]+up[k].second);
                        else if(i2==2){
                            if(j+1<=K) dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+down[k].second);
                        }
                        else if(i2==3){
                            if(j+1<=K) dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second*2);
                        }else if(i2==4){
                            if(j+1<=K) dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second*2);
                        }
                    }else if(i1==2){
                        // down has
                        if(i2==0) dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]);
                        else if(i2==1) {
                            if(j+1<=K)
                            dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second);
                        }
                        else if(i2==2){
                             dp[nxt][i2][j]= min(dp[nxt][i2][j],dp[cur][i1][j]+down[k].second);
                        }
                        else if(i2==3){
                            if(j+1<=K) dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second*2);
                        }else if(i2==4){
                            if(j+1<=K) dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second*2);
                        }
                        
                        
                    }else if(i1==3){
                        //both sep
                        if(i2==0) dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]);
                        else if(i2==1) {
                            dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]+up[k].second);
                        }
                        else if(i2==2){
                            dp[nxt][i2][j]= min(dp[nxt][i2][j],dp[cur][i1][j]+down[k].second);
                        }
                        else if(i2==3){
                            dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]+up[k].second*2);
                        }else if(i2==4){
                            if(j+1<=K) dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second*2);
                        }
                        
                        
                        
                    }else{
                        //both
                        if(i2==0) dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]);
                        else if(i2==1) {
                            if(j+1<=K)
                            dp[nxt][i2][j+1] = min(dp[nxt][i2][j+1],dp[cur][i1][j]+up[k].second);
                        }
                        else if(i2==2){
                            if(j+1<=K) dp[nxt][i2][j+1]= min(dp[nxt][i2][j+1],dp[cur][i1][j]+down[k].second);
                        }
                        else if(i2==3){
                            if(j+2<=K) dp[nxt][i2][j+2] = min(dp[nxt][i2][j+2],dp[cur][i1][j]+up[k].second*2);
                        }else if(i2==4){
                            dp[nxt][i2][j] = min(dp[nxt][i2][j],dp[cur][i1][j]+up[k].second*2);
                        }
                        
                    }
                }
            }
        }
        cur ^= 1;
        nxt ^= 1;
    }
    int ans = INT_MAX/2;
    for(int i=0;i<5;i++) ans = min(ans,dp[cur][i][K]);
    printf("%d\n",ans);
    return 0;
}
