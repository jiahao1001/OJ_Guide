#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x)
{
	if(Tree[x]==-1)
		return x;
	else
	{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}
struct Edge
{
	int a,b; //边两边的编号
	int cost; //该边的权值
	bool operator < (const Edge &eg)const
	{
		return cost < eg.cost;
	}
}edge[6000];
int main()
{
	int n; //有几个点
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int i;
		for(i=1;i<=n*(n-1)/2;i++)
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
		sort(edge+1,edge+1+n*(n-1)/2);
		//因为edge下标是从1开始的，n*(n-1)/2表示长度
		for(i=1;i<=n;i++)
			Tree[i] = -1;
		int ans=0;
		for(i=1;i<=n*(n-1)/2;i++)
		{
			int a = findRoot(edge[i].a);
			int b = findRoot(edge[i].b);
			if(a!=b)
			{
				Tree[a] = b;
				ans += edge[i].cost;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}