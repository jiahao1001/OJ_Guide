#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
int capital_M, capital_r;
int t;
int capital,year,start;
int dp[100010];
int n;
int v[10],w[10];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&start,&year);
        capital_M = start /1000;
        capital_r = start % 1000;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",v+i,w+i),v[i]/=1000;
        //v[i] is a multiple of 1000
        int interest = 0;
        for(int y=1;y<=year;y++){
            memset(dp,0,sizeof(dp));
            interest = 0;
            for(int b=0;b<n;b++)
                for(int i=0;i<=capital_M;i++)
                    if(i+v[b]<=capital_M) dp[i+v[b]] = max(dp[i+v[b]],dp[i]+w[b]);
            for(int i=0;i<=capital_M;i++)
                interest = max(interest,dp[i]);
            capital_M+=(interest+capital_r)/1000;
            capital_r = (interest+capital_r)%1000;
        }
        printf("%d\n",capital_M*1000+capital_r);
    }
    return 0;
}
