#include <stdio.h>
#include <stdlib.h>
struct node{
	unsigned num;
	struct node *next;
};
int main()
{
	int i,n;
	struct node *list,*head,*rear,*p,*q,*r,*l;
	head=(struct node *)malloc(sizeof(struct node));
	head->num=1;
	head->next=NULL;
	rear=head;
	list=head;
	for (i=1;i<1289;i++)
	{
		l=head;
		if (head->num%3!=0 && head->num%5!=0)
		{
			p=(struct node *)malloc(sizeof(struct node));
			p->num=head->num*2;
			q=l->next;
			while (q!=NULL && q->num<p->num)
			{
				r=q;
				q=q->next;
			}
			if (q==NULL)
			{
				rear->next=p;
				rear=p;
				p->next=NULL;
			}
			else {
				r->next=p;
				p->next=q;
			}
			l=p;
		}
		if (head->num%5!=0)
		{
			p=(struct node *)malloc(sizeof(struct node));
			p->num=head->num*3;
			q=l->next;
			while (q!=NULL && q->num<p->num)
			{
				r=q;
				q=q->next;
			}
			if (q==NULL)
			{
				rear->next=p;
				rear=p;
				p->next=NULL;
			}
			else {
				r->next=p;
				p->next=q;
			}
			l=p;
		}
		p=(struct node *)malloc(sizeof(struct node));
		p->num=head->num*5;
		q=l->next;
		while (q!=NULL && q->num<p->num)
		{
			r=q;
			q=q->next;
		}
		if (q==NULL)
		{
			rear->next=p;
			rear=p;
			p->next=NULL;
		}
		else {
			r->next=p;
			p->next=q;
		}
		head=head->next;
	}
	scanf("%d",&n);
	while (n!=0)
	{
		p=list;
		for (i=1;i<n;i++)
			p=p->next;
		printf("%d\n",p->num);
		scanf("%d",&n);
	}
	return 0;
}
