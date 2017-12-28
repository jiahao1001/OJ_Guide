#include<stdio.h>
#include<iostream>
using namespace std;
int N,P,C;
int A[1001];
int sum(int x)
{
    int ret=0;
    while(x) ret+=A[x],x-=(x&(-x));
    return ret;
}
void add(int x,int d)
{
    while(x<=P) A[x]+=d,x+=(x&(-x));
}
int main()
{
    scanf("%d%d%d",&N,&P,&C);
    P--;
    int p;
    for(int i=0;i<N;i++)
        scanf("%d",&p),add(p,1);
    
    int ans=0;
    for(int len=1;len<=P;len++)
        for(int i=1;i+len-1<=P;i++)
            if(sum(i+len-1)-sum(i-1)<=C) ans=max(ans,len);
    
    printf("%d\n",ans);
    return 0;
    
}
