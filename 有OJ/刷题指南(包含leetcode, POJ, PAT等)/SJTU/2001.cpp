#include <cstdio>
int array[10001]={0};
int n;
void ins(int pos,int value)
{
    for (int i=pos;i<=n;i+=(i&-i)) array[i]+=value;
}
int query(int pos)
{
    int res=0;
    for (int i=pos;i;i-=(i&-i)) res+=array[i];
    return res;
}
int main()
{
    scanf("%d",&n);
    int i,t,p,m;
    for (i=1;i<=n;++i)
    {
        scanf("%d",&t);
        ins(i,t);
    }
    scanf("%d",&m);
    for (i=1;i<=m;++i)
    {
        scanf("%d %d",&t,&p);
        printf("%d\n",query(p)-query(t-1));
    }
}
