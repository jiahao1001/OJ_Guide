#include<stdio.h>
#include<stdlib.h>
int N,B;
int cow[20000];
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (x>y)
		return -1;
	else if (x<y)
		return 1;
	else return 0;
}
int main()
{
	int i;
	int sum=0;
	scanf("%d%d",&N,&B);
	for (i=0;i<N;i++)
		scanf("%d",&cow[i]);
	qsort(cow,N,sizeof(cow[0]),cmp);
	for (i=0;i<N;i++)
	{
		sum+=cow[i];
		if (sum>=B)
			break;
	}
	printf("%d\n",i+1);
	return 0;
}
