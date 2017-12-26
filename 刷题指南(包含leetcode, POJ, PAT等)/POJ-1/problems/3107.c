#include<stdio.h>
#include<stdlib.h>
int n,balance[50001],num[50001]={0};
struct edge{
	int v;
	struct edge *next;
}*Node[50001]={NULL};
void insert(int a,int b)
{
	struct edge *p;
	p=(struct edge *)malloc(sizeof(struct edge));
	p->v=b;
	p->next=Node[a];
	Node[a]=p;
	num[a]++;
}
int cal(int father,int p)
{
	int i,j,k=0,s=num[p];
	struct edge *q=Node[p];
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
    int j,a,b,max=50000;
	scanf("%d",&n);
	for (j=n-1;j>0;j--)
	{
		scanf("%d%d",&a,&b);
		insert(a,b);
		insert(b,a);
	}
	cal(0,1);
	for (j=1;j<=n;j++)
		if (balance[j]<max)
			max=balance[j];
	for (j=1;j<=n;j++)
		if (balance[j]==max)
			printf("%d ",j);
	printf("\n");
	return 0;
}
