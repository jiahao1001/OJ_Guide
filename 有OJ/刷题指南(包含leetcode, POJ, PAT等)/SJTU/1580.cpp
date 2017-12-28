#include <cstdio>
int *data,*res,len=1;
int search(int n)
{
    int l=0,r=len,mid;
    while (l<r)
    {
        mid=(l+r)/2;
        if (res[mid]>=n) r=mid;
        else l=mid+1;
    }
    return l;
}
int main()
{
    freopen("1580.in","r",stdin);
    int n,i;
    scanf("%d",&n);
    data=new int[n+1];
    res=new int[n+1];
    for (i=1;i<=n;++i) scanf("%d",&data[i]);
    res[0]=-200000000;
    res[1]=data[1];
    for (i=2;i<=n;++i)
    {
        if (data[i]>res[len]) res[++len]=data[i];
        else res[search(data[i])]=data[i];
    }
    printf("%d",len);
}
