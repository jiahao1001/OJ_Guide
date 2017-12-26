#include <stdio.h>
int stack[100],top;
int main()
{
	int test,t;
	int n,i,j,s,u;
	scanf("%d",&test);
	for (t=0;t<test;t++)
	{
		top=0;
		scanf("%d",&n);
		for (i=0,s=0;i<n;i++)
		{
			scanf("%d",&u);
			for (j=0;j<u-s;j++)
				stack[top++]=1;
			s=u;
			for (j=top-1,u=1;j>=0 && stack[j]==0;j--,u++);
			stack[j]=0;
			printf("%d ",u);
		}
		putchar('\n');
	}			
    return 0;
}
