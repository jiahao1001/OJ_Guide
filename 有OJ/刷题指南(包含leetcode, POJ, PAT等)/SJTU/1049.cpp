#include <cstdio>
bool test()
{
    int n,m,i,count=0,size=0;
    scanf("%d %d",&n,&m);
    if (n<=1) return true;
    int *stack=new int[m+1];
    int *out=new int[n];
    for (i=0;i<n;++i) scanf("%d",&out[i]);
    for (i=0;i<n;++i)
    {
        if (out[count]==i)
        {
            ++count;
            while (size>0 && out[count]==stack[size-1])
            {
                --size;
                ++count;
            }
            continue;
        } else
        {
            if (size==m)
            {
                delete [] stack;
                delete [] out;
                return false;
            }
            stack[size++]=i;
        }
    }
    delete [] stack;
    delete [] out;
    return (size==0);
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for (i=0;i<t;++i)
    {
        if (test()) printf("YES\n");
        else printf("NO\n");
    }
}
