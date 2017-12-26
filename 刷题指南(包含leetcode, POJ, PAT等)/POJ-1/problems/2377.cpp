#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define	VCount	1000//顶点数目
#define	ECount	20000//边的数目	
int rank[ECount];//边值排序的辅助数组,记录排序后边的下标
int parent[VCount];
struct Edge{
	int a;
	int b;
	int weigh;
}edge[ECount];
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (edge[x].weigh<edge[y].weigh)
		return 1;
	else if (edge[x].weigh>edge[y].weigh)
		return -1;
	else return 0;
}
int root(int i){
	int r,p;
	for (r=i;parent[r]>=0;r=parent[r]);
	while (i!=r){
		p=i;
		i=parent[i];
		parent[p]=r;
	}	
	return r;
}
bool merge(int i,int j)//返回之前是否属于同一集合
{
	i=root(i);
	j=root(j);
	if (i==j) return true;
	if (parent[i]<parent[j]){
		parent[i]+=parent[j];
		parent[j]=i;
		return false;
	}
	else {
		parent[j]+=parent[i];
		parent[i]=j;
		return false;
	}
}
int kruskal(int v,int e)
{
	int result=0;
	int count,i;
	memset(parent,-1,sizeof(parent));//并查集预处理,首先将每个元素看作一个独立的集合
	qsort(rank,e,sizeof(rank[0]),cmp);//将边值排序,升序为最小生成树,降序为最大生成树
	for (i=0,count=1;count<v && i<e;i++)
	{
		if (merge(edge[rank[i]].a,edge[rank[i]].b)==false)
		{
			//说明之前两点不在同一个连通分量中,满足要求
			//将该边统计在内,并合并这两点所属的连通分量为一个连通分量
			result+=edge[rank[i]].weigh;
			count++;
		}
	}
	if (count!=v)
		return -1;//找不到最小生成树,注意这里约定-1表示查找失败
	return result;
}
int main()
{
	int a,b,i,n,m;
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&edge[i].weigh);
		rank[i]=i;
		edge[i].a=a-1;
		edge[i].b=b-1;
	}
	printf("%d\n",kruskal(n,m));
	return 0;
}