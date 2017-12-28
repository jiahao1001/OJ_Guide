#include <stdio.h>
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
    int *t=new int[n];
    for (i=0;i<n;++i) scanf("%d",&t[i]);
    qsort(t,0,n-1);
    for (i=0;i<n;++i) printf("%d ",t[i]);
    delete [] t;
}
