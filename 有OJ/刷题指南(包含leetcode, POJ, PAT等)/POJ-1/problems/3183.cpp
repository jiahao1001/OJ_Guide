#include<stdio.h>
int main()
{
	int n,i,j,r,stump;
	scanf("%d",&n);
	r=0;
	stump=0;
	for (i=0;i<n;i++)
	{
		scanf("%d",&j);
		if (j>stump)
			r=0;
		else {
			if (r==0)
			{
				printf("%d\n",i);
				r=1;
			}
			if (j==stump)
				r=0;
		}
		stump=j;
	}
	if (r==0)
		printf("%d\n",i);
	return 0;
}
