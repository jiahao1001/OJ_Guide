#include <cstdio>
int data[200010],que[200010],head=1,tail=0;
int main()
{
    int n,k,i,min=(1<<31)-1;
    scanf("%d %d",&k,&n);
    for (i=1;i<=n;++i)
    {
        scanf("%d",&data[i]);
    }
    for (i=1;i<=k;++i)
    {
        while (head<=tail && data[que[tail]]<data[i]) --tail;
        que[++tail]=i;
    }
    for (i=1;i<=n-k;++i)
    {
        printf("%d ",data[que[head]]);
        if (i==que[head]) ++head;
        while (head<=tail && data[que[tail]]<data[i+k]) --tail;
        que[++tail]=i+k;
    }
    printf("%d ",data[que[head]]);
}
