#include <cstdio>
int data[400010],que[400010],head=1,tail=0;
int main()
{
    int n,k,i,min=(1<<31)-1;
    scanf("%d %d",&n,&k);
    for (i=1;i<=n;++i)
    {
        scanf("%d",&data[i]);
        data[i+n]=data[i];
    }
    for (i=1;i<=k;++i)
    {
        while (head<=tail && data[que[tail]]<data[i]) --tail;
        que[++tail]=i;
    }
    for (i=1;i<=n;++i)
    {
        if (data[que[head]]<min) min=data[que[head]];
        if (i==que[head]) ++head;
        while (head<=tail && data[que[tail]]<data[i+k]) --tail;
        que[++tail]=i+k;
    }
    printf("%d\n",min);
}
