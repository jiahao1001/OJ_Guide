#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int q=1;
    int n;
    int dp[100][100];
    int a[100],b[100],h[100];
    while(scanf("%d",&n),n)
    {
        memset(dp,-1,sizeof(dp));
        int dim[3];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)scanf("%d",dim+j);
            sort(dim,dim+3);
            h[i*3+1]=dim[0];
            a[i*3+1]=dim[1];
            b[i*3+1]=dim[2];
            
            h[i*3+2]=dim[1];
            a[i*3+2]=dim[0];
            b[i*3+2]=dim[2];
            
            h[i*3+3]=dim[2];
            a[i*3+3]=dim[0];
            b[i*3+3]=dim[1];
        }
        dp[0][0]=0;
        for(int i=1;i<=3*n;i++)
            dp[0][i]=h[i];
        
        for(int i=1;i<=3*n;i++)
            for(int j=1;j<=3*n;j++)
                if(a[i]<a[j] && b[i]<b[j]) dp[i][j]=h[j];
        
        
        for(int k=0;k<=3*n;k++)
            for(int i=0;i<=3*n;i++)
                for(int j=0;j<=3*n;j++)
                    if(dp[i][k]!=-1 && dp[k][j]!=-1) dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]);
        int height=0;
        for(int i=1;i<=3*n;i++)
            height=max(height,dp[0][i]);
        printf("Case %d: maximum height = %d\n",q++,height);
    }
    return 0;
}
