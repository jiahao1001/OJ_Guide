#include<stdio.h>
#include<stdlib.h>
int N,S;
int cow[20000];
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
	int i,j;
	int sum=0;
	scanf("%d%d",&N,&S);
	for (i=0;i<N;i++)
		scanf("%d",&cow[i]);
	qsort(cow,N,sizeof(cow[0]),cmp);
	for (i=0,j=N-1;i<N && j>i;i++)
	{
		while (j>i && cow[i]+cow[j]>S)
			j--;
		sum+=j-i;
	}
	printf("%d\n",sum);
	return 0;
}
