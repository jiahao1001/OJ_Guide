#include<stdio.h>
#include<string.h>
#define M 10007 // 槽数
int n,m,LiMing;
int score[10000]={0},hash[M],rank,s;
struct {
	char name[31];
	int next;
}student[10000];
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
int find(char *key)
{
	int h=ELFhash(key);
	h=hash[h];
	while (strcmp(student[h].name,key)!=0)
		h=student[h].next;
	return h;
}
int main()
{
	int i,j,p,q;
	char k[31];
	memset(hash,-1,sizeof(hash));
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
	{
		gets(student[i].name);
		if ((student[i].name,"Li Ming")==0)
			LiMing=i;
		student[i].next=-1;
		j=ELFhash(student[i].name);
		p=hash[j];
		if (p==-1)
			hash[j]=i;
		else {
			while (student[p].next!=-1)
				p=student[p].next;
			student[p].next=i;
		}
	}
	scanf("%d",&m);
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d ",&p);
			gets(k);
			q=find(k);
			score[q]+=p;
		}
		s=score[LiMing];
		for (j=0,rank=1;j<n;j++)
			if (score[j]>s)
				rank++;
		printf("%d\n",rank);
	}
	return 0;
}
