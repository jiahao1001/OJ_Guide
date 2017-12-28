#include <stdio.h>
#include <queue>
using namespace std;
int k,p,q;
int prime(int n)
{
    int i,sum=0;
    while (n>0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
int pcs(int sum)
{
    int r=1,i;
    for (i=0;i<k;++i) r*=sum;
    return (r*p+q);
}
int main()
{
    int l,r,i,n=0,t;
    queue<int> res;
    scanf("%d %d %d",&k,&p,&q);
    scanf("%d %d",&l,&r);
    for (i=0;i<=81;++i)
    {
        t=pcs(i);
        if (l<=t && t<=r && prime(t)==i)
        {
            ++n;
            res.push(t);
        }
    }
    if (n==0) printf("0\n-1\n");
    else
    {
        printf("%d\n",n);
        while (!res.empty())
        {
            printf("%d ",res.front());
            res.pop();
        }
    }
}
