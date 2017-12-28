#include <stdio.h>
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
int main()
{
    int n,m,*p,*a,i,t;
    unsigned long long res=0;
    scanf("%d %d",&n,&m);
    p=new int[m];
    a=new int[m];
    for (i=0;i<m;++i) scanf("%d %d",&p[i],&a[i]);
    qsort(p,a,0,m-1);
    i=0;
    while (n>0)
    {
        t=(n>a[i])?a[i]:n;
        res+=t*p[i];
        n-=t;
        ++i;
    }
    printf("%d",res);
    delete [] p;
    delete [] a;
}
