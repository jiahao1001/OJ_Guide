#include <cstdio>
#include <queue>
struct tree
{
    int value,left,right,father;
};
int n;
tree *forest;
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
        scanf("%d %d %d",&(forest[i].left),&(forest[i].right),&(forest[i].value));
        if (forest[i].left!=0) forest[forest[i].left].father=i;
        if (forest[i].right!=0) forest[forest[i].right].father=i;
    }
    i=1;
    while (forest[i].father!=0) i=forest[i].father;
    std::queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        i=q.front();
        printf("%d ",forest[i].value);
        q.pop();
        if (forest[i].left!=0) q.push(forest[i].left);
        if (forest[i].right!=0) q.push(forest[i].right);
    }
    delete [] forest;
}
