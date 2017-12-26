/*dp(t,w,0) in t, at most w time, under tree 0
    = dp(t-1,w,0)  dp(t-1,w-1,1) +1/0 
    dp(t,w,1)*/

#include<iostream>
#include<limits.h>
using namespace std;
int T,W,apple[1001];
int dp[1001][31][2];

int main()
{
    cin>>T>>W;
    for(int i=1;i<=T;i++) cin>>apple[i],apple[i]--;

    dp[0][0][0] = 0;
    for(int t=1;t<=T;t++)
        dp[t][0][0]=(apple[t]^1)+dp[t-1][0][0];
    
    for(int t=1;t<=T;t++)
        for(int w=1;w<=W;w++)
            for(int k=0;k<2;k++){
                dp[t][w][k]=max(dp[t-1][w][k],dp[t-1][w-1][1-k])+(apple[t]^k^1);
            }
    
    /*for(int t=1;t<=T;t++){
        cout<<"------t="<<t<<endl;
        for(int w=0;w<=W;w++)
            cout<<dp[t][w][0]<<" "<<dp[t][w][1]<<endl;
            }*/
    
    cout<<max(dp[T][W][0],dp[T][W][1])<<endl;
    return 0;
}
