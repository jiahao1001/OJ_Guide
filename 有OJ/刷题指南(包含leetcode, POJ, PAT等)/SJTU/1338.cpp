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
    int *a=new int[n],*b=new int[n];
    for (i=0;i<n;++i) scanf("%d",&a[i]);
    for (i=0;i<n;++i) scanf("%d",&b[i]);
    qsort(a,0,n-1);
    qsort(b,0,n-1);
    unsigned long long max=0,min=0;
    for (i=0;i<n;++i)
    {
        max+=a[i]*b[i];
        min+=a[i]*b[n-1-i];
    }
    printf("%d ",max);
    printf("%d",min);
    delete [] a;
    delete [] b;
}
