#include <stdio.h>
int main()
{
	int i,j,t,n,p;
	char str[50];
	while (scanf("%d%d",&t,&n),t!=0 || n!=0)
	{
		for (i=0,p=0;i<t;i++)
		{
			scanf("%s%d",str,&j);
			p+=j;
		}
		printf("%d\n",3*n-p);
	}
}
