#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 997 // 槽数，最好用素数
struct node{
	int hash;
	struct node *next;
}*link[M]={NULL};
int m,n;
int salary[1000];
char word[1000][20];
int ELFhash(char *key)// UNIX 系统ELF字符串散列函数
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
int main()
{
	int i,e,sum;
	char str[100];
	struct node *p;
	scanf("%d%d",&m,&n);
	for (i=0;i<m;i++)
	{
		scanf("%s%d",word[i],&salary[i]);
		e=ELFhash(word[i]);
		p=(struct node *)malloc(sizeof(struct node));
		p->hash=i;
		p->next=link[e];
		link[e]=p;
	}
	for (i=0;i<n;i++)
	{
		sum=0;
		while (scanf("%s",str),strcmp(str,".")!=0)
		{
			e=ELFhash(str);
			p=link[e];
			while (p!=NULL)
			{
				if (strcmp(str,word[p->hash])==0)
					break;
				p=p->next;
			}
			if (p!=NULL)
				sum+=salary[p->hash];
		}
		printf("%d\n",sum);
	}
	return 0;
}
