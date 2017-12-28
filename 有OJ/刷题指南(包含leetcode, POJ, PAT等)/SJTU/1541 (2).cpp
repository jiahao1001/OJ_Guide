#include <cstdio>
long long data[200010];
int que[200010],head=1,tail=0;
int main()
{
    int n,k,i;
    scanf("%d",&k);
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%lld",&data[i]);
    for (i=1;i<=k;++i)
    {
        while (head<=tail && data[que[tail]]<data[i]) --tail;
        que[++tail]=i;
    }
    for (i=1;i<=n-k;++i)
    {
        printf("%lld ",data[que[head]]);
        if (i==que[head]) ++head;
        while (head<=tail && data[que[tail]]<data[i+k]) --tail;
        que[++tail]=i+k;
    }
    printf("%lld\n",data[que[head]]);
}
