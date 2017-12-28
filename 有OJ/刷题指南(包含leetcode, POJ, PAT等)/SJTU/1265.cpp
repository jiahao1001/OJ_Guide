#include <cstdio>
int n;
class Bit
{
private:
    int *data;
public:
    Bit()
    {
        data=new int[n+1];
        for (int i=0;i<=n;++i) data[i]=0;
    }
    ~Bit(){delete [] data;}
    void add(int pos,int val)
    {
        for (int i=pos;i<=n;i+=(i&-i)) data[i]+=val;
    }
    int query(int pos)
    {
        if (pos<=0) return 0;
        int res=0;
        for (int i=pos;i>0;i-=(i&-i)) res+=data[i];
        return res;
    }
};
Bit *bit;
int query(int x,int y)
{
    if (x<=0 || y<=0) return 0;
    int res=0;
    for (int i=x;i>0;i-=(i&-i)) res+=bit[i].query(y);
    return res;
}
void swap(int& a,int& b)
{
    if (&a==&b) return;
    a^=b;
    b^=a;
    a^=b;
}
int main()
{
    freopen("1265.in","r",stdin);
    int i,j,c,k,x,y,a,x2,y2;
    int t;
    scanf("%d",&n);
    bit=new Bit[n+1];
    while (scanf("%d",&c)==1)
    {
        if (c==1)
        {
            scanf("%d %d %d",&x,&y,&a);
            ++x;
            ++y;
            for (i=x;i<=n;i+=(i&-i)) bit[i].add(y,a);
        } else if (c==2)
        {
            scanf("%d %d %d %d",&x,&y,&x2,&y2);
            ++x;
            ++y;
            ++x2;
            ++y2;
            if (x>x2) swap(x,x2);
            if (y>y2) swap(y,y2);
            t=query(x2,y2)-query(x-1,y2)-query(x2,y-1)+query(x-1,y-1);
            printf("%d ",t);
        } else break;
        //for (i=1;i<=n;++i) bit[i].disp();
    }
    delete [] bit;
}
