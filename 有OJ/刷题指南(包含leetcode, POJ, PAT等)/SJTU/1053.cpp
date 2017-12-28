#include <cstdio>
const int BASE=200003;
class point
{
private:
    int x,y,data;
public:
    point(int xx,int yy,int zz)
    {
        x=xx;
        y=yy;
        data=zz;
    }
    bool compare(int xx,int yy)
    {
        return (x==xx && y==yy);
    }
    void print()
    {
        printf("%d\n",data);
    }
};
int n,m;
int rows[100010];
int colomns[100010];
point* hash[BASE];
int main()
{
    freopen("1053.in","r",stdin);
    int i,j,k,x,y,z;
    for (i=0;i<=100000;++i)
    {
        rows[i]=i;
        colomns[i]=i;
        hash[i]=NULL;
    }
    for (i=100001;i<BASE;++i) hash[i]=NULL;
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d %d %d",&x,&y,&z);
        j=x+y;k=0;
        while (hash[(j+k*k)%BASE]!=NULL) ++k;
        hash[(j+k*k)%BASE]=new point(x,y,z);
    }
    scanf("%d",&m);
    for (i=0;i<m;++i)
    {
        scanf("%d %d %d",&z,&x,&y);
        if (z==0)
        {
            rows[x]^=rows[y];
            rows[y]^=rows[x];
            rows[x]^=rows[y];
        } else if (z==1)
        {
            colomns[x]^=colomns[y];
            colomns[y]^=colomns[x];
            colomns[x]^=colomns[y];
        } else
        {
            x=rows[x];y=colomns[y];
            j=x+y;k=0;
            while (hash[(j+k*k)%BASE]!=NULL && !(hash[(j+k*k)%BASE]->compare(x,y))) ++k;
            if (hash[(j+k*k)%BASE]!=NULL) hash[(j+k*k)%BASE]->print();
            else printf("0\n");
        }
    }
    for (i=0;i<BASE;++i) if (hash[i]!=NULL) delete hash[i];
}
