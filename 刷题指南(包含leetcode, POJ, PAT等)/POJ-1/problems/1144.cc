#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int n;
int count;
bool flag[MAX];
typedef struct edge{
	int adjvex;//边的终点
	struct edge *next;//指向下一个边结点
}*ELink;
ELink G[MAX]={NULL};

void dfs(int p)
{
	ELink q=G[p];
	flag[p]=true;
	count++;
	while (q!=NULL) {
		if (flag[q->adjvex]==false)
			dfs(q->adjvex);
		q=q->next;
	}
}
int main()
{
	int i,j;
	int a,b;
	int sum;
	ELink p;
	scanf("%d",&n);
	while (n!=0)
	{
		memset(G,NULL,sizeof(G));
		sum=0;
		scanf("%d",&a);
		while (a!=0)
		{
			while (getchar() == ' ') {
				scanf("%d",&b);
				p=(ELink)malloc(sizeof(edge));
				p->adjvex=b-1;
				p->next=G[a-1];
				G[a-1]=p;
				p=(ELink)malloc(sizeof(edge));
				p->adjvex=a-1;
				p->next=G[b-1];
				G[b-1]=p;
			}
			scanf("%d",&a);
		}
		for (i=0; i<n; i++) {
			memset(flag,false,sizeof(flag));
			flag[i]=true;
			count=0;
			for (j=0; j<n; j++) {
				if (flag[j]==false)
					break;
			}
			dfs(j);
			if (count!=n-1) {
				sum++;
			}
		}
		printf("%d\n",sum);
		scanf("%d",&n);
	}
}
