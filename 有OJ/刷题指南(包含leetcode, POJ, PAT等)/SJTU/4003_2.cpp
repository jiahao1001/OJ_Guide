#include <cstdio>
int main()
{
    int n,k,i,len=30,count=0,res=0;
    scanf("%d %d",&n,&k);
    while (n&(1<<len)==0) --len;
    for (i=0;i<=len;++i) if (n&(1<<i)) ++count;
    i=0;
    while (count>k)
    {
        while (n&(1<<i)==0) ++i;
        res|=(1<<i);
        while (n&(1<<i))
        {
            n^=(1<<i);
            ++i;
            --count;
        }
        n|=(1<<i);
        ++count;
    }
    printf("%lld",res);
}
