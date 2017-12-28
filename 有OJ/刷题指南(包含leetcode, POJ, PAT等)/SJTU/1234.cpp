#include <cstdio>
int n,m;
class Disjointset
{
private:
    int parent[10001];
public:
    Disjointset()
    {
        for (int i=0;i<=10000;++i) parent[i]=-1;
    }
    int Find(int x)
    {
        while (parent[x]>0) x=parent[x];
        return x;
    }
    void Union(int a,int b)
    {
        int r1=Find(a),r2=Find(b);
        if (r1==r2) return;
        if (parent[r1]>parent[r2])
        {
            parent[r2]+=parent[r1];
            parent[r1]=r2;
        } else
        {
            parent[r1]+=parent[r2];
            parent[r2]=r1;
        }
    }
};
struct edge
{
    int from,to,weight;
};
void qsort(edge*v,int l,int r)
{
    if (l>=r) return;
    int i=l,j=r;
    edge tmp=v[i];
    while (i<j)
    {
        while (i<j && v[j].weight>=tmp.weight) --j;
        v[i]=v[j];
        while (i<j && v[i].weight<=tmp.weight) ++i;
        v[j]=v[i];
    }
    v[i]=tmp;
    qsort(v,l,i-1);
    qsort(v,i+1,r);
}
int main()
{
    freopen("1234.in","r",stdin);
    scanf("%d %d",&n,&m);
    int i,x=0,cnt=1,res=0;
    edge *v=new edge[m];
    for (i=0;i<m;++i)
    {
        scanf("%d %d %d",&(v[i].from),&(v[i].to),&(v[i].weight));
    }
    qsort(v,0,m-1);
    Disjointset djs;
    while (cnt<n)
    {
        while (djs.Find(v[x].from)==djs.Find(v[x].to)) ++x;
        djs.Union(v[x].from,v[x].to);
        res+=v[x].weight;
        ++cnt;
    }
    printf("%d\n",res);
    delete [] v;
}
