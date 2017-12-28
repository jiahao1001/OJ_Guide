#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 10001
typedef struct edge{
	int adjvex;//边的终点
	struct edge *next;//指向下一个边结点
}*ELink;
ELink G[maxn]={NULL},GT[maxn]={NULL};
bool c[maxn];
bool find[maxn],cow=false;
int n,m,e,q,num=0;	//n为顶点数目,e是边数,m为完成时间降序表的指针,q是p的队列指针
int a1[maxn],a2[maxn],p[maxn];//c是顶点颜色表,a1是完成时间降序表,a2是辅助表,p用来保存强连通分量内顶点
void ADJLIST()
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
	a1[m--]=u;
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
	p[q++]=u;
	find[u]=true;
}
void dfs_first()
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
void dfs_second()
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
				if (cow==false)
				{
					cow=true;
					num+=q;
				}
				else num=0;
			}
		}
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&e);
	ADJLIST();
	for (i=1;i<=n;i++)
		a2[i]=i;
	dfs_first();
	for (i=1;i<=n;i++)	//之所以要建立一个辅助数组a2,是因为在dfs过程中a1中的值会改变
		a2[i]=a1[i];
	dfs_second();
	printf("%d\n",num);
	return 0;
}
