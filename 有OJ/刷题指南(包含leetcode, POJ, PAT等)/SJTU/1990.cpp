#include <cstdio>
int n,m;
int *pos,*num,*value;
int lower_b(int x)//value[]中大于x的首个位置
{
    int l=0,r=n,mid;
    while (l<r)
    {
        mid=(l+r)>>1;
        if (value[mid]>x) r=mid;
        else l=mid+1;
    }
    return l;
}
void swap(int& a,int& b)
{
    a^=b;
    b^=a;
    a^=b;
}
void disp()
{
    int i;
    printf("num[]: ");
    for (i=1;i<=n;++i) printf("%d ",num[i]);
    printf("\npos[]: ");
    for (i=1;i<=n;++i) printf("%d ",pos[i]);
    printf("\nvalue[]: ");
    for (i=1;i<=n;++i) printf("%d ",value[i]);
    printf("\n");
}
int main()
{
    int i,j,x,y,t,k,z;
    scanf("%d %d",&n,&m);
    pos=new int[n+1];
    num=new int[n+1];
    value=new int[n+1];
    value[0]=-10;
    for (i=1;i<=n;++i)
    {
        scanf("%d",&value[i]);
        pos[i]=i;
        num[i]=i;
    }
    for (i=1;i<=m;++i)
    {
        scanf("%d %d",&x,&y);
        if (y==1)
        {
            while (pos[x] < n && value[pos[x]]==value[pos[x]+1])
            {
                t=pos[x]+1;k=num[t];
                swap(num[t],num[pos[x]]);
                swap(pos[x],pos[k]);
            }
            ++value[pos[x]];
        } else
        {
            while (pos[x]>1 && value[pos[x]-1]==value[pos[x]])
            {
                t=pos[x]-1;k=num[t];
                swap(num[t],num[pos[x]]);
                swap(pos[x],pos[k]);
            }
            --value[pos[x]];
            while (pos[x]>1 && value[pos[x]-1]==value[pos[x]])
            {
                t=pos[x]-1;
                swap(num[t],num[pos[x]]);
                swap(pos[x],pos[num[t]]);
            }
        }
        //disp();
        printf("%d\n",num[1]);
    }
}
