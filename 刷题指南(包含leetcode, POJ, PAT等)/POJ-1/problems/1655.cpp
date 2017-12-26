#include<stdio.h>
#include<stdlib.h>
int n,balance[20001];
struct node{
	int num;
	struct edge *next;
}Node[20001];
struct edge{
	int v;
	struct edge *next;
};
int cal(int father,int p)
{
	int i,j,k=0,s=Node[p].num;
	struct edge *q=Node[p].next;
	while (q!=NULL)
	{
		if (q->v!=father)
		{
			j=cal(p,q->v);
			if (j>k)
				k=j;
			s+=j;
		}
		else s--;
		q=q->next;
	}
	i=n-1-s;
	k++;
	balance[p]=i>k ? i:k;
	return s;
}
int main()
{
    int t,i,j,a,b,max;
	struct edge *p,*q;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d",&n);
		for (j=1;j<=n;j++)
		{
			Node[j].num=0;
			Node[j].next=NULL;
		}
		for (j=n-1;j>0;j--)
		{
			scanf("%d%d",&a,&b);
			p=(struct edge *)malloc(sizeof(struct edge));
			p->v=b;
			p->next=NULL;
			if (Node[a].num==0)
				Node[a].next=p;
			else{
				q=Node[a].next;
				while (q->next!=NULL)
					q=q->next;
				q->next=p;
			}
			Node[a].num++;
			p=(struct edge *)malloc(sizeof(struct edge));
			p->v=a;
			p->next=NULL;
			if (Node[b].num==0)
				Node[b].next=p;
			else{
				q=Node[b].next;
				while (q->next!=NULL)
					q=q->next;
				q->next=p;
			}
			Node[b].num++;
		}
		cal(0,1);
		p=Node[1].next;
		while (p!=NULL)
		{
			q=p;
			p=p->next;
			free(q);
		}
		for (j=2,max=1;j<=n;j++)
		{
			if (balance[j]<balance[max])
				max=j;
			p=Node[j].next;
			while (p!=NULL)
			{
				q=p;
				p=p->next;
				free(q);
			}
		}
		printf("%d %d\n",max,balance[max]);
	}
	return 0;
}
