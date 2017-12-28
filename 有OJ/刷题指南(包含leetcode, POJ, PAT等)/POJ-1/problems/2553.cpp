#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 5001	//最大顶点数
typedef struct edge{
	int adjvex;//边的终点
	struct edge *next;//指向下一个边结点
}*ELink;
ELink G[maxn],GT[maxn];	//邻接表存储,G是原图,GT是转置图
bool c[maxn];	//标记深搜过程中是否已访问
bool bottom[maxn],find[maxn];	//bottom为最后的集合,find存储某个强连通分量
int n,m,e,q;	//n为顶点数目,e是边数,m为完成时间降序表的指针,q是p的队列指针
int a1[maxn],a2[maxn],p[maxn];//c是顶点颜色表,a1是完成时间降序表,a2是辅助表,p用来保存强连通分量内顶点
void ADJLIST()	//建图和图的转置
{
	int k,vi,vj;
	ELink P,Q;
	for (k=0;k<e;k++)
	{
		scanf("%d%d",&vi,&vj);//输入顶点偶对,始点在前，终点在后
		P=(ELink)malloc(sizeof(edge));
		P->adjvex=vj;
		P->next=G[vi];
		G[vi]=P;
		Q=(ELink)malloc(sizeof(edge));
		Q->adjvex=vi;
		Q->next=GT[vj];
		GT[vj]=Q;
	}
}
void gt()	//建立转置
{
	int i;
	ELink P,Q;
	for (i=1;i<=n;i++)
	{
		P=G[i];
		while (P!=NULL)
		{
			Q=(ELink)malloc(sizeof(edge));
			Q->adjvex=i;
			Q->next=GT[P->adjvex];
			GT[P->adjvex]=Q;
			P=P->next;
		}
	}
}
void dfs_visit_first(int u)
{
	ELink P=G[u];
	c[u]=true;
	while (P!=NULL)
	{
		if (c[P->adjvex]==false)
			dfs_visit_first(P->adjvex);
		P=P->next;
	}
	a1[m--]=u;	//降序保存完成时间
}
void dfs_visit_second(int u)
{
	ELink P=GT[u];
	c[u]=true;
	while (P!=NULL)
	{
		if (c[P->adjvex]==false)
			dfs_visit_second(P->adjvex);
		P=P->next;
	}
	p[q++]=u;	//保存强连通分量中的点
	find[u]=true;
}
void dfs_first()	//原图的DFS
{
	int u;
	memset(c,false,sizeof(c));
	m=n;	//m的初始化
	for (u=1;u<=n;u++)
	{
		if (c[a2[u]]==false)
			dfs_visit_first(a2[u]);
	}
}
void dfs_second()	//转置图的DFS
{
	int u,i;
	ELink P;
	memset(c,false,sizeof(c));
	for (u=1;u<=n;u++)
	{
		if (c[a2[u]]==false)
		{
			q=0;
			memset(find,false,sizeof(find));
			dfs_visit_second(a2[u]);
			for (i=0;i<q;i++)
			{
				P=G[p[i]];
				while (P!=NULL)
				{
					if (find[P->adjvex]==false)
						break;
					P=P->next;
				}
				if (P!=NULL)
					break;
			}
			if (i==q)
			{
				for (i=0;i<q;i++)
					bottom[p[i]]=true;
			}
		}
	}
}
int main()
{
	int i;
	while (scanf("%d",&n),n!=0)
	{
		scanf("%d",&e);
		memset(G,NULL,sizeof(G));
		memset(GT,NULL,sizeof(GT));
		memset(bottom,false,sizeof(bottom));
		ADJLIST();
		for (i=1;i<=n;i++)
			a2[i]=i;
		dfs_first();
		for (i=1;i<=n;i++)	//之所以要建立一个辅助数组a2,是因为在dfs过程中a1中的值会改变
			a2[i]=a1[i];
		dfs_second();
		for (i=1;i<=n;i++)
			if (bottom[i]==true)
				printf("%d ",i);
		putchar('\n');
	}
	return 0;
}
