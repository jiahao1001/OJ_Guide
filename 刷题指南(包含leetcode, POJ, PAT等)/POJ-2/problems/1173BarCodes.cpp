include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
int dp[34][34][34];
int n,k,m,s;
string bar;
inline int f(int n,int k){
    //n unit k bar
    int ans = 0;
    for(int i=1;i<=m;i++)
        ans+=dp[n][k][i];
    return ans;
}
int main()
{
    cin>>n>>k>>m;
    dp[1][1][1] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++){
            if(i!=1 || j!=1)
            for(int l=1;l<=m;l++)
                dp[i][j][1]+=dp[i-1][j-1][l];
            for(int l=2;l<=m;l++){
                dp[i][j][l]+=dp[i-1][j][l-1];
            }
        }
    int ans = 0;
    for(int i=1;i<=m;i++)
        ans += dp[n][k][i];
    cout<<ans<<endl;
    cin>>s;
    while(s--){
        cin>>bar;
        ans = 0;
        int cnt = 1;
        int w;
        for(int i=1;i<bar.size();i++){
            if(bar[i]!=bar[i-1]) {
                cnt++;
            }
            if(bar[i]=='1'){
                w=0;
                for(int j=i-1;j>=0;j--)
                    if(bar[j]!='0') break;
                    else w++;
                if(w==0){
                    ans += f(n-i,k-cnt);
                }else if(w==m){
                    ans+= 0;
                }else{
                    int j=1;
                    for(w=w+1;w<=m&&i+j<=n;w++,j++)
                        ans+=f(n-i-j,k-cnt+1);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
