#include<stdio.h>
#include<stdlib.h>
int difficult[30];
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (x<y)
		return -1;
	else if (x>y)
		return 1;
	else return 0;
}
int main()
{
	int i,j,t,time,problem,sum,slove,store;
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%d%d",&time,&problem);
		for (j=0;j<problem;j++)
			scanf("%d",&difficult[j]);
		qsort(difficult,problem,sizeof(difficult[0]),cmp);
		slove=0;
		store=0;
		for (j=0,sum=0;j<problem;j++)
		{
			sum+=difficult[j];
			if (time>=sum)
			{
				slove++;
				store+=sum;
			}
			else break;
		}
		printf("Scenario #%d:\n",i);
		printf("Steve wins with %d solved problems and a score of %d.\n\n",slove,store);
	}
	return 0;
}
