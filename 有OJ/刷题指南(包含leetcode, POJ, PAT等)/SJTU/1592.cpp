#include <cstdio>
long long *data;
long long query(int n)
{
    if (n==0) return 0;
    long long ans=0;
    for (;n;n-=(n&-n)) ans+=data[n];
    return ans;
}
int main()
{
    int n,m,x,y,i,j;
    scanf("%d %d",&n,&m);
    data=new long long[n+1];
    for (i=0;i<=n;++i) data[i]=0;
    long long res;
    for (i=1;i<=n;++i)
    {
        scanf("%d",&x);
        for (j=i;j<=n;j+=(j&-j)) data[j]+=x;
    }
    for (i=0;i<m;++i)
    {
        scanf("%d %d",&x,&y);
        res=query(y)-query(x-1);
        printf("%lld\n",res);
    }
    delete [] data;
}
