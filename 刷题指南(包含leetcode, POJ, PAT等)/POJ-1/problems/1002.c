#include <stdio.h>
#include <stdlib.h>
struct node
{
	int f;
	int times;
	struct node *lchild,*rchild;
};
void dfs(struct node *head);
int main()
{
	int n,i,a,b=0;
	char c;
	struct node *list=NULL,*p,*q,*r;
	scanf("%d\n",&n);
	for (i=1;i<=n;i++)
	{
		a=0;
		while((c=getchar())!='\n')
		{
			if (c>='0' && c<='9')
				a=a*10+c-'0';
			else if (c>='A' && c<'Q')
				a=a*10+(c-'A')/3+2;
			else if (c>'Q' && c<'Z')
				a=a*10+(c-'Q')/3+7;
		}
		if (list==NULL)
		{
			list=(struct node *)malloc(sizeof(struct node));
			list->f=a;
			list->times=0;
			list->lchild=NULL;
			list->rchild=NULL;
		}
		else{
			p=list;
			while (p!=NULL)
			{
				q=p;
				if (p->f==a)
				{
					b=1;
					p->times++;
					break;
				}
				else if (p->f<a)
					p=p->rchild;
				else p=p->lchild;
			}
			if (p==NULL)
			{
				r=(struct node *)malloc(sizeof(struct node));
				r->f=a;
				r->times=0;
				r->lchild=NULL;
				r->rchild=NULL;
				if (q->f>a)
					q->lchild=r;
				else q->rchild=r;		
			}
		}
	}
	if (b==0)
		printf("No duplicates.\n");
	else dfs (list);
	return 0;
}
void dfs(struct node *head)
{
	if (head==NULL)
		return ;
	dfs (head->lchild);
	if (head->times>0)
		printf("%.3d-%.4d %d\n",head->f/10000,head->f%10000,head->times+1);
	dfs (head->rchild);
}
