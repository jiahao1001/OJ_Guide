#include <cstdio>
struct rec
{
    int time;
    bool in;
};
void qsort(rec* t,int l,int r)
{
    if (l>=r) return;
    int i=l,j=r,v=t[i].time;
    bool record=t[i].in;
    while (i<j)
    {
        while ((i<j)&&(t[j].time>=v)) --j;
        t[i]=t[j];
        while ((i<j)&&(t[i].time<=v)) ++i;
        t[j]=t[i];
    }
    t[i].time=v;t[i].in=record;
    qsort(t,l,i-1);
    qsort(t,i+1,r);
}
int main()
{
    freopen("1262.in","r",stdin);
    int n,i,t;
    scanf("%d",&n);
    rec *a=new rec[n<<1];
    for (i=0;i<n;++i)
    {
        scanf("%d",&t);
        a[i<<1].time=t;
        a[i<<1].in=true;
        scanf("%d",&t);
        a[(i<<1) | 1].time=t;
        a[(i<<1) | 1].in=false;
    }
    n=n<<1;
    qsort(a,0,n-1);
    int in_s,ou_s=0,inmax=0,oumax=0;
    t=0;
    for (i=0;i<n;++i)
    {
        if (a[i].in) ++t;else --t;
        if (t==1 && a[i].in)
        {
            in_s=a[i].time;
            if (ou_s!=0 && a[i].time-ou_s>oumax) oumax=a[i].time-ou_s;
        }
        else if (t==0)
        {
            ou_s=a[i].time;
            if (a[i].time-in_s>inmax) inmax=a[i].time-in_s;
        }
    }
    printf("%d\n%d",inmax,oumax);
    delete [] a;
}
