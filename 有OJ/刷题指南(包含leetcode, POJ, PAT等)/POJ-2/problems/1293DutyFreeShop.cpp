#include<iostream>
#include<stdio.h>
using namespace std;
int dp[1001],c[2001];
int cnt;
void print(int x)
{
    if(!x){
        printf("%d",cnt);
        return;
    }
    cnt++;
    print(x-c[dp[x]]);
    printf(" %d",dp[x]);
}
int main()
{
    int N,M,L;
    
    int sum;
    while(scanf("%d%d",&M,&L),M||L)
    {
        scanf("%d",&N);
        sum=0;
        for(int i=1;i<=N;i++)scanf("%d",c+i),sum+=c[i];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        cnt=0;
        int ans;
        for(int i=1;i<=N;i++)
        {
            for(int j=M;j>=0;j--)
                if(dp[j]!=-1 && j+c[i]<=M && dp[j+c[i]]==-1){
                    dp[j+c[i]]=i;
                    if(sum-(j+c[i])<=L) {
                        ans=j+c[i];
                        goto success;
                    }
                }
        }
        if(M==0 && sum<=L){
            ans=0;
            goto success;
        }
        printf("Impossible to distribute\n");
        continue;
    success:
        //for(int i=0;i<=M;i++)
        //  printf("%d ",dp[i]);
        //printf("\n");
        print(ans);
        printf("\n");
    }
    return 0;
}
