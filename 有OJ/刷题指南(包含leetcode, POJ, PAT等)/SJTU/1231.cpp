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
        if (root1==root2) return;
        //printf("%d %d\n",root1,root2);
        parent[root2]=root1;
    }
    int Find(int x)
    {
        while (parent[x]>0) x=parent[x];
        return x;
    }
};
int n,x,y,res=0;
int *left,*right,*father;
Disjointset *djs;
void hxbl(int n)
{
    if (res!=0) return;
    int r1,r2;
    if (left[n]!=0)
    {
        hxbl(left[n]);
        djs->Union(n,left[n]);
    }
    if (right[n]!=0)
    {
        hxbl(right[n]);
        djs->Union(n,right[n]);
    }
    r1=djs->Find(x);
    r2=djs->Find(y);
    if (r1==r2 && res==0) res=r1;
}
int main()
{
    freopen("1231.in","r",stdin);
    scanf("%d %d %d",&n,&x,&y);
    int i,j;
    left=new int[n+1];
    right=new int[n+1];
    father=new int[n+1];
    djs=new Disjointset(n);
    left[0]=0;
    right[0]=0;
    father[0]=0;
    for (i=1;i<=n;++i) father[i]=0;
    for (i=1;i<=n;++i)
    {
        scanf("%d %d",&left[i],&right[i]);
        if (left[i]!=0) father[left[i]]=i;
        if (right[i]!=0) father[right[i]]=i;
    }
    int root=1;
    while (father[root]!=0) root=father[root];
    hxbl(root);
    printf("%d\n",res);
    delete [] left;
    delete [] right;
    delete [] father;
    delete djs;
}
