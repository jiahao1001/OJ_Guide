#include <cstdio>
struct tree
{
    int left,right,father;
};
int n;
tree *forest;
bool check(int idx,int pos)
{
    if (idx==0) return true;
    if (pos>n) return false;
    return (check(forest[idx].left,pos*2) && check(forest[idx].right,pos*2+1));
}
int main()
{
    scanf("%d",&n);
    forest=new tree[n+1];
    int i,x,y;
    for (i=1;i<=n;++i)
    {
        forest[i].father=0;
        forest[i].left=0;
        forest[i].right=0;
    }
    for (i=1;i<=n;++i)
    {
        scanf("%d %d",&(forest[i].left),&(forest[i].right));
        if (forest[i].left!=0) forest[forest[i].left].father=i;
        if (forest[i].right!=0) forest[forest[i].right].father=i;
    }
    i=1;
    while (forest[i].father!=0) i=forest[i].father;
    if (check(i,1)) printf("Y");else printf("N");
    delete [] forest;
}
