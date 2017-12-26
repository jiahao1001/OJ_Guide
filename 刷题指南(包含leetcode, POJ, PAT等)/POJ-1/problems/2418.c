#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 10007
struct node{
	int hash;
	struct node *next;
}*link[M]={NULL};
int num[10000]={0},posi[10000],n=0,m=0;
char tree[10000][31];
int ELFhash(char *key);
int cmp(const void *a,const void *b);
int main()
{
	int i,e;
	struct node *p;
	while (gets(tree[n])!=NULL)
	{
		e=ELFhash(tree[n]);
		p=link[e];
		while (p!=NULL)
		{
			if (strcmp(tree[n],tree[p->hash])==0)
				break;
			p=p->next;
		}
		if (p==NULL)
		{
			p=(struct node *)malloc(sizeof(struct node));
			p->hash=n;
			p->next=link[e];
			link[e]=p;
			num[n]=1;
			posi[n]=n;
			n++;
		}
		else num[p->hash]++;
		m++;
	}
	qsort(posi,n,sizeof(posi[0]),cmp);
	for (i=0;i<n;i++)
		printf("%s %.4lf\n",tree[posi[i]],100.0*num[posi[i]]/m);
	return 0;
}
int ELFhash(char *key)
{
	unsigned long h=0,g;
	while (*key)
	{
		h=(h << 4) + *key++;
		g=h & 0xf0000000L;  
		if (g) 
			h ^= g >> 24;  
		h &= ~g;
	}
	return h % M;
}
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	return strcmp(tree[x],tree[y]);
}
