#include <cstdio>
int *floors,*find,*res;
int n,a,b;
bool *vacant;
bool success=false;
bool in(int x,int y)
{
    return (x>0 && x<=n && y>0 && y<=x);
}
int level(int x)
{
    int l=0,r=n,mid;
    while (l<r)
    {
        mid=(l+r)>>1;
        if (floors[mid]>=x) r=mid; else l=mid+1;
    }
    return l;
}
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
        while (parent[x]>0) x=parent[x];
        return x;
    }
    void disp(int a,int b)
    {
        find=new int[size+1];
        res=new int[size+1];
        vacant=new bool[size+1];
        int i,j;
        for (i=1;i<=size;++i)
        {
            find[i]=Find(i);
            vacant[i]=true;
        }
        res[1]=a;
        vacant[a]=false;
        search(1);
        delete [] find;
        delete [] res;
        delete [] vacant;
    }
    void search(int x)
    {
        int i;
        if (res[x]==b && !success)
        {
            for (i=1;i<=x;++i) printf("%d ",res[i]);
            success=true;
        }
        if (success) return;
        int j,t;
        i=level(res[x]);
        j=res[x]-floors[i-1];
        t=floors[i-2]+j-1;
        if (in(i-1,j-1) && vacant[t] && find[x]==find[t])
        {
            res[x+1]=t;
            vacant[t]=false;
            search(x+1);
            vacant[t]=true;
        }
        t=floors[i-2]+j;
        if (in(i-1,j) && vacant[t] && find[x]==find[t])
        {
            res[x+1]=t;
            vacant[t]=false;
            search(x+1);
            vacant[t]=true;
        }
        t=floors[i]+j;
        if (in(i+1,j) && vacant[t] && find[x]==find[t])
        {
            res[x+1]=t;
            vacant[t]=false;
            search(x+1);
            vacant[t]=true;
        }
        t=floors[i]+j+1;
        if (in(i+1,j+1) && vacant[t] && find[x]==find[t])
        {
            res[x+1]=t;
            vacant[t]=false;
            search(x+1);
            vacant[t]=true;
        }
    }
};
int main()
{
    int i,j,x,y;
    scanf("%d %d %d",&n,&a,&b);
    floors=new int[n+1];
    for (i=0;i<=n;++i) floors[i]=i*(i+1)/2;
    Disjointset djs(floors[n]);
    while (scanf("%d %d",&x,&y)==2)
    {
        i=level(x);
        j=x-floors[i-1];
        if (y==0)
        {
            --i;
            --j;
        } else if (y==1)
        {
            --i;
        } else if (y==2)
        {
            ++i;
        } else if (y==3)
        {
            ++i;
            ++j;
        }
        if (in(i,j)) djs.Union(x,floors[i-1]+j);
        if (djs.Find(a)==djs.Find(b))
        {
            djs.disp(a,b);
            return 0;
        }
    }
    delete [] floors;
}
