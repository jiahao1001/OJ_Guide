// f(i,j)  categories i, buy, j..c class
// f(i,i)  money in i, + min f(i+1,i+1) f(i+2,i+1), meantime, update f(i+1,i) f(i+2,i)

#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;

int c,a[1000],p[1000];
int dp[1000][1000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&c);
        for(int i=0;i<c;i++)
            scanf("%d%d",a+i,p+i);
        dp[c-1][c-1]=(10+a[c-1])*p[c-1];
        for(int i=c-2;i>=0;i--)
        {
            int best=INT_MAX;
            dp[i][i]=(10+a[i])*p[i];
            for(int j=i+1;j<c;j++)
                best=min(best,dp[j][i+1]);
            dp[i][i]+=best;
            for(int j=i+1;j<c;j++)
                dp[j][i]=dp[j][i+1]+(a[i])*p[j];
        }
        int best=INT_MAX;
        for(int i=0;i<c;i++)
            best=min(best,dp[i][0]);
        printf("%d\n",best);
        
    }
    return 0;
}
