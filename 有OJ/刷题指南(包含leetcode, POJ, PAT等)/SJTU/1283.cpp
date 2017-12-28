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
        while (parent[x]>0) x=parent[x];
        return x;
    }
};
int gjd[5001];
void disp(int n)
{
    int i,j,len=1;
    gjd[0]=1;
    for (i=1;i<=5000;++i) gjd[i]=0;
    for (i=0;i<n;++i)
    {
        for (j=0;j<len;++j) gjd[j]*=2;
        for (j=0;j<len;++j) if (gjd[j]>9)
        {
            gjd[j+1]+=gjd[j]/10;
            gjd[j]%=10;
        }
        if (gjd[len]!=0) ++len;
    }
    for (i=len-1;i>=0;--i) printf("%d",gjd[i]);
}
int main()
{
    int n,m,i,j,x,y,res=0;
    scanf("%d %d",&n,&m);
    Disjointset djs(n);
    for (i=0;i<m;++i)
    {
        scanf("%d %d",&x,&y);
        djs.Union(x,y);
    }
    for (i=1;i<n;++i)
    {
        if (djs.Find(i)==djs.Find(i+1)) ++res;
        else djs.Union(i,i+1);
    }
    disp(res);
}
