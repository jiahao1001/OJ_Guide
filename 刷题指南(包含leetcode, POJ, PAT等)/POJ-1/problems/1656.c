#include <stdio.h>
char p[100][100]={0};
void snuc (int x,int y,int l,int j)
{
	int a,b;
	for (a=x;a<x+l;a++)
	{
		for (b=y;b<y+l;b++)
			p[a][b]=j;
	}
}
void test (int x,int y,int l)
{
	int a,b,c=0;
	for (a=x;a<x+l;a++)
	{
		for (b=y;b<y+l;b++)
		{
			if (p[a][b]!=0)
				c++;
		}
	}
	printf("%d\n",c);
}
int main()
{
	int i,n,x,y,l;
	char s[6];
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
	{
		scanf("%s %d%d%d",s,&x,&y,&l);
		if (s[0]=='W')
			snuc(x-1,y-1,l,0);
		else if (s[0]=='B')
			snuc(x-1,y-1,l,1);
		else test(x-1,y-1,l);
	}
	return 0;
}
