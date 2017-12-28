#include <stdio.h>
int t[200000];
void qsort(int l,int r)
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
    qsort(l,i-1);
    qsort(i+1,r);
}
int main()
{
    int tt,n,i,j;
    scanf("%d",&tt);
    for (i=0;i<tt;++i)
    {
        scanf("%d",&n);
        for (j=0;j<n;++j) scanf("%d",&t[j]);
        qsort(0,n-1);
        for (j=0;j<n;++j) printf("%d ",t[j]);
        printf("\n");
    }
}
