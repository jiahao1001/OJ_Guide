#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int dp[2000][2000];
int L[40];
int area(double a,double b,double c){
    if(a>b) swap(a,b);
    if(a>c) swap(a,c);
    if(b>c) swap(b,c);
    if(a+b<=c) return 0;
    double s = (a+b+c)/2;
    return floor(100.0*sqrt(s*(s-a)*(s-b)*(s-c)));
}
int main(){
    int n;
    scanf("%d",&n);
    int tot = 0;
    for(int i=0;i<n;i++)
        scanf("%d",L+i),tot+=L[i];
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;
    for(int i=0;i<n;i++)
        for(int j=tot;j>=0;j--)
            for(int k=tot;k>=0;k--)
                if(dp[j][k])dp[j+L[i]][k] = 1, dp[j][k+L[i]] = 1;
    int best = 0;
    for(int i=0;i<=tot;i++)
        for(int j=0;j<=tot;j++)
            if(dp[i][j])
            best = max(best,area(i,j,tot-i-j));
    if(best==0)printf("-1\n");
    else printf("%d\n",best);
}
