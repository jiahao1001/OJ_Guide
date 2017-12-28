#include <cstdio>
class Disjointset
{
private:
    int size;
    int *parent;
public:
    Disjointset(int s):size(s)
    {
        parent=new int[size+1];
        for (int i=0;i<=size;++i) parent[i]=-1;
    }
    ~Disjointset(){delete [] parent;}
    void Union(int root1,int root2)
    {
        root1=Find(root1);
        root2=Find(root2);
        if (root1==root2) return;
        if (parent[root1]>parent[root2])
        {
            parent[root2]+=parent[root1];
            parent[root1]=root2;
        } else
        {
            parent[root1]+=parent[root2];
            parent[root2]=root1;
        }
    }
    int Find(int x)
    {
        int t=x;
        while (parent[t]>0) t=parent[t];
        if (parent[t]!=0) return t;
        else
        {
            while (parent[x]>0)
            {
                t=x;
                x=parent[x];
                parent[t]=0;
            }
            return 0;
        }
    }
    void Remove(int x)
    {
        int t;
        while (parent[x]>0)
        {
            t=x;
            x=parent[x];
            parent[t]=0;
        }
        parent[x]=0;
    }
    bool canJoin(int a,int b)
    {
        int r1=Find(a),r2=Find(b);
        return (r1!=0 && r2!=0 && r1!=r2);
    }
    int Size(int x)
    {
        return -parent[Find(x)];
    }
};
class Array
{
private:
    int *data;
    int max;
public:
    Array(int n)
    {
        max=1;
        data=new int[n+1];
        for (int i=2;i<=n;++i) data[i]=0;
        data[0]=data[1]=n;
    }
    ~Array()
    {
        delete [] data;
    }
    void Remove(int x)
    {
        --data[x];
        while (data[max]==0) --max;
    }
    void Insert(int x)
    {
        ++data[x];
        if (x>max) max=x;
    }
    void join(int a,int b)
    {
        Remove(a);
        Remove(b);
        Insert(a+b);
    }
    int Query(int x)
    {
        int n=max;
        while (n>0 && data[n]<x)
        {
            x-=data[n];
            --n;
        }
        return n;
    }
};
int main()
{
    freopen("1056.in","r",stdin);
    int n,m,i,j,k,x,y;
    char f;
    scanf("%d %d",&n,&m);
    getchar();
    Disjointset djs(n);
    Array array(n);
    for (i=0;i<m;++i)
    {
        scanf("%c",&f);
        //printf("%d %c\n",i+1,f);
        if (f=='C')
        {
            scanf("%d %d",&x,&y);
            if (djs.canJoin(x,y))
            {
                array.join(djs.Size(x),djs.Size(y));
                djs.Union(x,y);
            }
        } else if (f=='Q')
        {
            scanf("%d",&x);
            printf("%d\n",array.Query(x));
        } else
        {
            scanf("%d",&x);
            if (djs.Find(x)!=0)
            {
                array.Remove(djs.Size(x));
                djs.Remove(x);
            }
        }
        if (i!=m-1) getchar();
    }
}
