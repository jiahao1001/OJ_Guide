#include<stdio.h>
int main()
{
	int n,i,e,s;
	int guest[31];
	while (scanf("%d",&n),n!=0)
	{
		s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&guest[i]);
			s+=guest[i];
		}
		e=0;
		for (i=1;i<=n;i++)
		{
			e+=guest[i];
			if (e+e==s)
				break;
		}
		if (i<=n)
			printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);
		else printf("No equal partitioning.\n");
	}
	return 0;
}
