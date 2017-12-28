#include <cstdio>
void qsort(int* t,int l,int r)
{
    if (l>=r) return;
    int i=l,j=r,v=t[i];
    while (i<j)
    {
        while ((i<j)&&(t[j]>=v)) --j;
        t[i]=t[j];
        while ((i<j)&&(t[i]<=v)) ++i;
        t[j]=t[i];
    }
    t[i]=v;
    qsort(t,l,i-1);
    qsort(t,i+1,r);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int *t=new int[n+1];
    for (i=1;i<=n;++i) scanf("%d",&t[i]);
    qsort(t,1,n);
    t[0]=t[1]-1;
    int res=0;
    for (i=1;i<=n;++i) if (t[i]!=t[i-1]) ++res;
    printf("%d",res);
    delete [] t;
}
