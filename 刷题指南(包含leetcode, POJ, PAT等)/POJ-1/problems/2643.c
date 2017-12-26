#include<stdio.h>
#include<string.h>
int n,vote[20]={0};
char name[20][100],party[20][100],input[100];
int check()
{
	int i;
	for (i=0;i<n;i++)
	{
		if (strcmp(input,name[i])==0)
			return i;
	}
	return -1;
}
int main ()
{
	int i,j,c,m;
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
	{
		gets(name[i]);
		gets(party[i]);
	}
	scanf("%d\n",&m);
	for (i=0;i<m;i++)
	{
		gets(input);
		j=check();
		if (j!=-1)
			vote[j]++;
	}
	j=0;
	c=1;
	for (i=1;i<n;i++)
	{
		if (vote[i]>vote[j])
			j=i,c=1;
		else if (vote[i]==vote[j])
			c=0;
	}
	if (c==0)
		printf("tie\n");
	else printf("%s\n",party[j]);
	return 0;
}
