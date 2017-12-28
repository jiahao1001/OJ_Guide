#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 20627 // 槽数，最好用素数
struct node{
	int hash;
	struct node *next;
}*link[M]={NULL};
char word[100000][11],dialect[100000][11];
int ELFhash(char *key);
int main()
{
	int i,e,n=0;
	char str[50];
	struct node *p;
	gets(str);
	while (strcmp(str,"")!=0)
	{
		for (i=0;str[i]!=' ';i++)
			word[n][i]=str[i];
		word[n][i++]='\0';
		strcpy(dialect[n],str+i);
		e=ELFhash(dialect[n]);
		p=(struct node *)malloc(sizeof(struct node));
		p->hash=n;
		p->next=link[e];
		link[e]=p;
		n++;
		gets(str);
	}
	while (gets(str)!=NULL)
	{
		e=ELFhash(str);
		p=link[e];
		while (p!=NULL)
		{
			if (strcmp(str,dialect[p->hash])==0)
				break;
			p=p->next;
		}
		if (p==NULL)
			printf("eh\n");
		else printf("%s\n",word[p->hash]);
	}
	return 0;
}
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
