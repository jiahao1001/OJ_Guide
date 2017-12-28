#include<iostream>
#include<stdio.h>
#include<string.h>
#include<limits.h>
using namespace std;
const int inf = INT_MAX/2;
inline int h(char c){
    if(c>='a' && c<='z') return c-'a';
    if(c=='+') return 26;
    if(c=='*') return 27;
    if(c=='/') return 28;
    if(c=='?') return 29;
}
int cnt[30];
char s[40];
int dp[13][31];
int dc[13][31];
int calc(int l,int r){
    int sum = 0;
    for(int i=l;i<=r;i++){
        sum += cnt[i]*(i-l+1);
    }
    return sum;
}
char tc(int x){
    if(x<26) return x+'a';
    if(x==26) return '+';
    if(x==27) return '*';
    if(x==28) return '/';
    if(x==29) return '?';
}
void print(int i,int j){
    if(i==1)return;
    int k = dc[i][j];
    print(i-1,k);
    printf("%c",tc(k));
}
int main()
{
    int t,len,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(cnt,0,sizeof cnt);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            len = strlen(s);
            for(int j=0;j<len;j++){
                cnt[h(s[j])]++;
            }
        }
        for(int i=0;i<=12;i++)
            for(int j=0;j<=30;j++) dp[i][j] = inf;
        dp[0][0] = 0;
        for(int i=1;i<=12;i++)
            for(int j=1;j<=30;j++)
                for(int k=0;k<j;k++){
                    int v = calc(k,j-1);
                    if(dp[i-1][k]+v<dp[i][j]) dp[i][j] = dp[i-1][k]+v,dc[i][j] = k; 
                }
        print(12,30);
        printf("\n");
    }
    return 0;
}
