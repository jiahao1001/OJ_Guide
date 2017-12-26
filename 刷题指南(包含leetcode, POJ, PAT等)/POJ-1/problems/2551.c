#include <stdio.h>
int main()
{
	int n,s,i;
	while (scanf("%d",&n)!=EOF)
	{
		for (i=1,s=1;(s%=n)!=0;i++)
			s=s*10+1;
		printf("%d\n",i);
	}
	return 0;
}
