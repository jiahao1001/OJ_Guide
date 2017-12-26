#include <stdio.h>
#include <stdlib.h>
#define MAX 15
int zuhe[MAX]={0};
char letter[15];
int n,k;
int cmp(const void *a, const void *b);
int equal(int m,int i);
void make(int m);
int main()
{
	int i;
	scanf("%d%d\n",&k,&n);
	for (i=0;i<n;i++)
	{
		scanf("%c",&letter[i]);
		getchar();
	}
	qsort(letter,n,sizeof(letter[0]),cmp);
	make(0);
	return 0;
}
int equal(int m,int i)
{
	int j;
	for (j=0;j<m;j++)
		if (zuhe[j]>=i)
			return 0;
	return 1;
}
void make(int m)
{
	int i,a,b;
	if (m==k)
	{
		a=0;
		b=0;
		for (i=0;i<k;i++)
		{
			if (letter[zuhe[i]-1]=='a' || letter[zuhe[i]-1]=='e' || letter[zuhe[i]-1]=='i' || letter[zuhe[i]-1]=='o' || letter[zuhe[i]-1]=='u')
				a=1;
			else b++;
		}
		if (a==1 && b>1)
		{
			for (i=0;i<k;i++)
				printf("%c",letter[zuhe[i]-1]);
			printf("\n");
		}
		return;
	}
	for (i=m;i<n;i++)
	{
		if (equal(m,i+1)==1)
		{
			zuhe[m]=i+1;
			make(m+1);
		}
	}
}
int cmp(const void *a, const void *b)
{
	char x,y;
	x=*(char *)a;
	y=*(char *)b;
	if (x<y)
		return -1;
	else if (x>y)
		return 1;
	else return 0;
}
