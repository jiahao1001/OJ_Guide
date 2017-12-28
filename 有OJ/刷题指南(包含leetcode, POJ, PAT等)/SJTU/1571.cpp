#include <iostream>
using namespace std;
void qsort(int* a,int* b,int l,int r)
{
    if (l>=r) return;
    int i=l,j=r,ka=a[l],kb=b[l];
    while (i<j)
    {
        while ((i<j)&&(a[j]>=ka)) --j;
        a[i]=a[j];b[i]=b[j];
        while ((i<j)&&(a[i]<=ka)) ++i;
        a[j]=a[i];b[j]=b[i];
    }
    a[i]=ka;
    b[i]=kb;
    qsort(a,b,l,i-1);
    qsort(a,b,i+1,r);
}
int query(int* c,int p)
{
    if (p==0) return 0;
    int res=0;
    for (int t=p;t;t-=(t&-t)) res+=c[t];
    return res;
}
void inc(int* c,int p,int n)
{
    for (int t=p;t<=n;t+=(t&-t)) ++c[t];
}
int main()
{
    int n,i,*a,*aa,*b,*bb,*c;
    cin>>n;
    a=new int[n+1];
    aa=new int[n+1];
    b=new int[n+1];
    bb=new int[n+1];
    c=new int[n+1];
    for (i=1;i<=n;++i)
    {
        cin>>a[i];
        aa[i]=i;
    }
    for (i=1;i<=n;++i)
    {
        cin>>b[i];
        bb[i]=i;
    }
    qsort(a,aa,1,n);
    qsort(b,bb,1,n);
    for (i=1;i<=n;++i) b[aa[i]]=bb[i];
    for (i=0;i<=n;++i) c[i]=0;
    unsigned long long res=0;
    for (i=n;i>0;--i)
    {
        res=(res+query(c,b[i]))%99999997;
        inc(c,b[i],n);
    }
    cout<<res;
}
