#include<iostream>
#include<stdio.h>
using namespace std;
int g[20][20];
int n;
inline int lowbit(int x)
{
    return x&(-x);
}
int log2[(1<<19)+1];
inline int traffic(int s,int t)
{
    int total=0;
    while(s){
        int tt=t;
        while(tt){
            total+=g[log2[lowbit(s)]][log2[lowbit(tt)]];
            tt-=lowbit(tt);
        }
        s-=lowbit(s);
    }
    return total;
}
int main()
{
    for(int i=0;i<=19;i++)
        log2[1<<i]=i;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",&g[i][j]);
    int best=0;
    for(int s=1;s<(1<<n)-1;s++){
        best=max(best,traffic(s,((1<<n)-1)^s));
    }
    printf("%d\n",best);
    return 0;
}
