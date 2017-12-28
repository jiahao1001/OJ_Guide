#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *a,const void *b)
{
	double x,y;
	x=*(double *)a;
	y=*(double *)b;
	if (x<y)
		return 1;
	else if (x>y)
		return -1;
	else return 0;
}
int main()
{
	int n,i;
	double m[100];
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%lf",&m[i]);
	qsort(m,n,sizeof(m[0]),cmp);
	for (i=1;i<n;i++)
		m[0]=2*sqrt(m[0]*m[i]);
	printf("%.3lf\n",m[0]);
	return 0;
}
