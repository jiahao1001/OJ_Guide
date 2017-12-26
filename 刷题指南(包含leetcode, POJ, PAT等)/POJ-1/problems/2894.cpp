#include<stdio.h>
#include<string.h>
int t,n;
int count[2000];
int main()
{
	int i,j,k,a,b;
	char c;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d\n",&n);
		memset(count,0,sizeof(count));
		for (j=0;j<n;j++)
		{
			scanf("%c%d%d\n",&c,&a,&b);
			for (k=a;k<b;k++)
				count[k]++;
		}
		for (j=0;j<=1000;j++)
			if (count[j]!=0)
				putchar(count[j]+'A'-1);
		putchar('\n');
	}
	return 0;
}
