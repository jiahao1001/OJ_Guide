#include <cstdio>
int main()
{
    bool data[1000]={0};
    int n,i,t,size=0;
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d",&t);
        if (!data[t-1]) ++size;
        data[t-1]=true;
    }
    printf("%d\n",size);
    for (i=0;i<1000;++i) if (data[i]) printf("%d ",i+1);
}
