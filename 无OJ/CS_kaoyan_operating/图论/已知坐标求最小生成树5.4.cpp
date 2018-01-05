#include<stdio.h> //还需加工一下
#include<math.h>
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
		int tmp = findRoot(Tree[x]); //不是findRoot(x)
		Tree[x] = tmp;
		return tmp;
	}
}
struct Edge
{
	int a,b;
	double cost;
	bool operator < (const Edge &eg) const
	{
		return cost<eg.cost;
	}
}edge[6000];
struct Point
{
	double x,y;
	double getDistance(Point pt)
	{
		double tmp = (x-pt.x)*(x-pt.x) + (y-pt.y)*(y-pt.y);
		return sqrt(tmp);
	}
}list[101];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		for(i=1;i<=n;i++)
			scanf("%lf%lf",&list[i].x,&list[i].y);
		int size = 0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				edge[size].a = i;
				edge[size].b = j;
				edge[size].cost = list[i].getDistance(list[j]);
				size++; //不要忘了
			}
		sort(edge,edge+size);
		for(i=1;i<=n;i++)
			Tree[i] = -1;
		double ans =0.0; 
		for(i=0;i<size;i++)
		{
			int a = findRoot(edge[i].a);
			int b = findRoot(edge[i].b);
			if(a!=b)
			{
				Tree[a] = b;
				ans += edge[i].cost; 
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}