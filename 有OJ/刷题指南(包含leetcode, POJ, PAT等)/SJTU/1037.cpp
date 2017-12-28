#include <stdio.h>
void qsort(int* t,int l,int r)
{
    if (l>=r) return;
    int i=l,j=r,v=t[i];
    while (i<j)
    {
        while ((i<j)&&(t[j]<=v)) --j;
        t[i]=t[j];
        while ((i<j)&&(t[i]>=v)) ++i;
        t[j]=t[i];
    }
    t[i]=v;
    qsort(t,l,i-1);
    qsort(t,i+1,r);
}
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    int *high=new int[n],*low=new int[m];
    for (i=0;i<n;++i) scanf("%d",&high[i]);
    for (i=0;i<m;++i) scanf("%d",&low[i]);
    qsort(high,0,n-1);
    qsort(low,0,m-1);
    int a=-1;
    unsigned long long res=n;
    for (i=0;i<n;++i)
    {
        ++a;
        while (a<m && low[a]>=high[i]) ++a;
        if (a==m) break;
        ++res;
    }
    printf("%d",res);
    delete [] high;
    delete [] low;
}
