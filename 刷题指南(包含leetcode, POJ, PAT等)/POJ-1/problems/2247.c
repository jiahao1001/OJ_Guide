#include <stdio.h>
#include <stdlib.h>
struct node{
	unsigned num;
	struct node *next;
};
int main()
{
	int i,n,j;
	unsigned x=4294967295;
	char s[4][3]={"th","st","nd","rd"};
	struct node *list,*head,*rear,*p,*q,*r,*l;
	head=(struct node *)malloc(sizeof(struct node));
	head->num=1;
	head->next=NULL;
	rear=head;
	list=head;
	for (i=1;i<4817;i++)
	{
		l=head;
		if (head->num%3!=0 && head->num%5!=0 && head->num%7!=0 && head->num<=x/2)
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
		if (head->num%5!=0 && head->num%7!=0 && head->num<=x/3)
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
		if (head->num%7!=0 && head->num<=x/5)
		{
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
		}
		if (head->num<=x/7)
		{
			p=(struct node *)malloc(sizeof(struct node));
			p->num=head->num*7;
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
		}
		head=head->next;
	}
	scanf("%d",&n);
	while (n!=0)
	{
		if (n%10==1 && n%100!=11)
			j=1;
		else if (n%10==2 && n%100!=12)
			j=2;
		else if (n%10==3 && n%100!=13)
			j=3;
		else j=0;
		p=list;
		for (i=1;i<n;i++)
			p=p->next;
		printf("The %d%s humble number is %d.\n",n,s[j],p->num);
		scanf("%d",&n);
	}
	return 0;
}
