#include <cstdio>
bool wanquan()
{
    int n,i,t,p;
    scanf("%d",&n);
    int *pos=new int[n];
    int *idx=new int[n];
    for (i=1;i<n;++i) pos[i]=-1;
    pos[0]=0;
    idx[0]=0;
    for (i=1;i<n;++i)
    {
        scanf("%d",&t);
        p=idx[t]*2+1;
        if (p>=n)
        {
            delete [] pos;
            delete [] idx;
            return false;
        }
        if (pos[p]!=-1) ++p;
        if (p>=n)
        {
            delete [] pos;
            delete [] idx;
            return false;
        }
        idx[i]=p;
        pos[p]=i;
    }
    delete [] pos;
    delete [] idx;
    return true;
}
int main()
{
    if (wanquan()) printf("true");
    else printf("false");
}
