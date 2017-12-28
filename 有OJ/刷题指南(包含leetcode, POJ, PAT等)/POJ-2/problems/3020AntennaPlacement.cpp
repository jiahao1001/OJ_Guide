#include<iostream>
#include<stdio.h>

using namespace std;
int t,w,h;
char g[42][15];
int dp[42][1<<10];
inline int getbit(int s,int i)
{
    return (s>>i)&1;
}
void dfs(int i,int cur,int s,int t,int cnt)
{
    if(cur==w){
        if(dp[i][t]==-1) dp[i][t]=cnt+dp[i-1][s];
        else dp[i][t]=min(dp[i][t],cnt+dp[i-1][s]);
        return ;
    }
    //vertial
    if(!getbit(s,cur)) dfs(i,cur+1,s,t+(1<<cur),cnt+1);
    else
    {
        if(cur>0 && !getbit(t,cur-1)) dfs(i,cur+1,s,t+(3<<(cur-1)),cnt+1);
        dfs(i,cur+1,s,t+((g[i][cur]=='o'?1:0)<<cur),cnt);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&h,&w);
        for(int i=0;i<w;i++)
            g[0][i]=g[h+1][i]='o';
        for(int i=1;i<=h;i++)
            scanf("%s",g[i]);
        memset(dp,-1,sizeof(dp));
        dp[0][(1<<w)-1]=0;
        for(int i=1;i<=h+1;i++)
            for(int s=0;s<(1<<w);s++)
                if(dp[i-1][s]!=-1) dfs(i,0,s,0,0);

        printf("%d\n",dp[h+1][(1<<w)-1]);
    }
    return 0;
}
