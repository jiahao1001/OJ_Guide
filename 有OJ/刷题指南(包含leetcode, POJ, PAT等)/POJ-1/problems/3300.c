#include<stdio.h>
#include<stdlib.h>
int f,r,q;
double front[10],rear[10];
double ratio[100];
int cmp(const void *a, const void *b)
{
	double x,y;
	x=*(double *)a;
	y=*(double *)b;
	if (x<y)
		return -1;
	else if (x>y)
		return 1;
	else return 0;
}

int main()
{
	int i,j;
	double max;
	while (scanf("%d",&f),f!=0)
	{
		scanf("%d",&r);
		for (i=0;i<f;i++)
			scanf("%lf",&front[i]);
		for (i=0;i<r;i++)
			scanf("%lf",&rear[i]);
		q=0;
		for (i=0;i<f;i++)
			for (j=0;j<r;j++)
				ratio[q++]=front[i]/rear[j];
		qsort(ratio,q,sizeof(ratio[0]),cmp);
		max=0;
		for (i=1;i<q;i++)
		{
			if (ratio[i]/ratio[i-1]>max)
				max=ratio[i]/ratio[i-1];
		}
		printf("%.2lf\n",max);
	}
	return 0;
}
