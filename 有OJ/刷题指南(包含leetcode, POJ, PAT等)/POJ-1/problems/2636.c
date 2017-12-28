#include <stdio.h>
int main()
{
	int n,i,j,x,s,r;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&x);
		s=1-x;
		for (j=0;j<x;j++)
		{
			scanf("%d",&r);
			s+=r;
		}
		printf("%d\n",s);
	}
	return 0;
}
