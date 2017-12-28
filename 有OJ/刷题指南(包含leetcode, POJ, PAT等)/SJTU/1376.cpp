#include <iostream>
using namespace std;
long long q(long long *c,int p)
{
    if (p==0) return 0;
    else
    {
        int t;long long res=0;
        for (t=p;t!=0;t-=(t&-t)) res+=c[t];
        return res;
    }
}
int main()
{
    int n,m,i,j,type,x,y;
    cin>>n;
    int *a=new int[n+1];
    long long *c=new long long[n+1];
    for (i=0;i<=n;++i) c[i]=0;
    a[0]=0;
    for (i=1;i<=n;++i)
    {
        cin>>a[i];
        for (j=i;j<=n;j+=(j&-j)) c[j]+=a[i];
    }
    cin>>m;
    for (i=0;i<m;++i)
    {
        cin>>type>>x>>y;
        if (type==1)
        {
            for (j=x;j<=n;j+=(j&-j)) c[j]+=(y-a[x]);
            a[x]=y;
        } else cout<<q(c,y)-q(c,x-1)<<endl;
    }
    delete [] a;
    delete [] c;
}
