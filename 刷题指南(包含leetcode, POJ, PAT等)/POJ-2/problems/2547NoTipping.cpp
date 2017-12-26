#include<iostream>
#include<stdio.h>
using namespace std;
int len,w,n;
int px[20],pw[20];
int dp[1<<20];
inline bool balance(int mask){
    double left = 0, right = 0;
    double light = 1.0*w*(len/2.0-1.5)/len;
    double heavy = w - light;
    left = right = light*(len-3.0)/4.0 - heavy*(len+3.0)/4.0;
    for(int i=0;i<n;i++)
        if(mask&(1<<i)){
            left += pw[i]*(-1.5-px[i]);
            right+= pw[i]*(px[i]-1.5);
        }
    return left<=0 && right<=0;
}
int f(int mask){
    if(!mask) return dp[mask] = 1;
    if(dp[mask]!=-1) return dp[mask];
    dp[mask] = 0;
    if(!balance(mask)) return dp[mask];
    for(int i=0;i<n;i++)
        if(((1<<i)&mask) && f(mask^(1<<i))) return dp[mask]=1;
    return dp[mask] = 0;
}
void print(int mask){
    if(!mask) return;
    for(int i=0;i<n;i++)
        if(((1<<i)&mask) && f(mask^(1<<i))){
            printf("%d %d\n",px[i],pw[i]);
            print(mask^(1<<i));
            break;
        }
}
int main()
{
    int q=1;
    while(scanf("%d%d%d",&len,&w,&n),len||w||n){
        for(int i=0;i<n;i++)
            scanf("%d%d",px+i,pw+i);
        printf("Case %d:\n",q++);
        memset(dp,-1,sizeof dp); //0 no, 1 yes
        if(!f((1<<n)-1))printf("Impossible\n");
        else{
            print((1<<n)-1);
        }
    }
    return 0;
}
