#include<iostream>
#include<stdio.h>
using namespace std;
double h[1000];
int dp1[1000],dp2[1000]; //dp1 increase from 0
int n;
int main()
{
    scanf("%d",&n);
    int best=0;
    for(int i=0;i<n;i++)
        scanf("%lf",h+i);
    
    dp1[0]=1;
    for(int i=1;i<n;i++){
        dp1[i]=1;
        for(int j=0;j<i;j++)
            if(h[j]<h[i]) dp1[i]=max(dp1[i],dp1[j]+1);
    }
    dp2[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        dp2[i]=1;
        for(int j=i+1;j<n;j++)
            if(h[j]<h[i]) dp2[i]=max(dp2[i],dp2[j]+1);
    }
    for(int i=0;i<n;i++){
        int lo=0;
        for(int j=i+1;j<n;j++)
            if(h[j]==h[i]) lo=max(lo,dp2[j]);
        best=max(best,max(dp1[i]+lo,dp1[i]+dp2[i]-1));
        
    }
    printf("%d\n",n-best);
    return 0;
}
