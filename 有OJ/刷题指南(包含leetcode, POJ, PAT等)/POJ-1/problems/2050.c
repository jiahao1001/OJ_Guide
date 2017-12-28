#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;							//文章的数目,0<n<100
int doc[101]={0};				//记录每段文章的起始位置
int l=0;						//总行数
char lines[2000][90]={0};
int num=0;						//单词数
int words[15000];				//单词索引
int step;
struct term{
	char Word[100];
	int Doc;
	int Line;
}Term[15000];					//单词
int cmp(const void *a, const void *b)
{
	int x,y,z;
	x=*(int *)a;
	y=*(int *)b;
	z=strcmp(Term[x].Word,Term[y].Word);
	if (z==0)
		z=Term[x].Line-Term[y].Line;
	return z;
}
void input(int p)
{
	int i,j;
	doc[p]=l;
	while (gets(lines[l]),strcmp(lines[l],"**********")!=0)
	{
		words[num]=num;
		j=0;
		for (i=0;lines[l][i]!='\0';i++)
		{
			if (isalpha(lines[l][i])==0)
			{
				if (j!=0)
				{
					Term[num].Doc=p;
					Term[num].Line=l;
					num++;
					words[num]=num;
					j=0;
				}
			}
			else Term[num].Word[j++]=tolower(lines[l][i]);
		}
		if (j!=0)
		{
			Term[num].Doc=p;
			Term[num].Line=l;
			num++;
		}
		l++;
	}
}
int search(char *w)
{
	int low=0;
	int high=num-1;
	int mid;
	int i,temp;
	step=-1;
	while (low<=high)
	{
		mid=(low+high)/2;
		temp=strcmp(Term[words[mid]].Word,w);
		if (temp<0)
			low=mid+1;
		else if (temp>0)
			high=mid-1;
		else break;
	}
	if (low<=high)
	{
		for (step=mid+1;strcmp(Term[words[step]].Word,w)==0;step++);
		do
			mid--;
		while (strcmp(Term[words[mid]].Word,w)==0);
		return mid+1;
	}
	return -1;
}
void AndOr(int and,char *s,char *t)
{
	int a,b,c,d,i,j,one=0;
	int not[2][101]={0};
	int sort[2000]={0};
	a=search(s);
	b=step;
	c=search(t);
	d=step;
	for (i=a;i<b;i++)
		not[0][Term[words[i]].Doc]=1;
	for (i=c;i<d;i++)
		not[1][Term[words[i]].Doc]=1;
	for (i=a;i<b;i++)
		if (not[0][Term[words[i]].Doc]+not[1][Term[words[i]].Doc]+and>1)
			one=1,sort[Term[words[i]].Line]=1;
	for (i=c;i<d;i++)
		if (not[0][Term[words[i]].Doc]+not[1][Term[words[i]].Doc]+and>1)
			one=1,sort[Term[words[i]].Line]=1;
	if (one==0)
	{
		puts("Sorry, I found nothing.");
		return;
	}
	one=0;
	for (i=0;i<n;i++)
	{
		if (not[0][i]+not[1][i]+and<=1)
			continue;
		if (one==1) puts("----------");
		one=1;
		for (j=doc[i];j<doc[i+1];j++)
		{
			if (sort[j]==1) 
				puts(lines[j]);
		}
	}
}
void query()
{
	int i,j,k;
	int one=0,and;
	int not[101]={0};
	int D,L;
	char str[200];
	char s[200],r[200];
	gets(str);
	for (i=0,j=0;str[i]!='\0' && str[i]!=' ';i++,j++)
		s[j]=str[i];
	s[j]='\0';
	if (strcmp("NOT",s)==0)
	{
		for (i++,j=0;str[i]!='\0';i++,j++)
			s[j]=str[i];
		s[j]='\0';
		k=search(s);
		while (k<step)
		{
			not[Term[words[k]].Doc]=1;
			k++;
		}
		for (i=0;i<n;i++)
		{
			if (not[i]==1)
				continue;
			if (one==1) puts("----------");
			for (j=doc[i];j<doc[i+1];j++)
				puts(lines[j]);
			one=1;
		}
	}
	else {
		if (str[i]=='\0')
		{
			k=search(s);
			if (k==-1)
			{
				puts("Sorry, I found nothing.");
				return;
			}
			D=Term[words[k]].Doc;
			L=Term[words[k]].Line;
			puts(lines[L]);
			for (i=k+1;i<step;i++)
			{
				if (D!=Term[words[i]].Doc)
				{
					puts("----------");
					D=Term[words[i]].Doc;
				}
				else if (L==Term[words[i]].Line)
					continue;
				L=Term[words[i]].Line;
				puts(lines[L]);
			}
			return ;
		}
		for (i++,j=0;str[i]!=' ';i++,j++)
			r[j]=str[i];
		r[j]='\0';
		if (strcmp(r,"AND")==0)	and=0;
		else	and=1;
		for (i++,j=0;str[i]!='\0';i++,j++)
			r[j]=str[i];
		r[j]='\0';
		AndOr(and,s,r);
	}
}
int main()
{
	int i,m;
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
		input(i);
	doc[n]=l;
	qsort(words,num,sizeof(words[0]),cmp);
	scanf("%d\n",&m);
	for (i=0;i<m;i++)
	{
		query();
		puts("==========");
	}
	return 0;
}
