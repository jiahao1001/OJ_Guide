#include<stdio.h>
#include<stdlib.h>
int N,K;
int cow[50000][2],rank[50000];
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (cow[x][0]>cow[y][0])
		return -1;
	else if (cow[x][0]<cow[y][0])
		return 1;
	else return 0;
}
int main()
{
	int i,j;
	scanf("%d%d",&N,&K);
	for (i=0;i<N;i++)
	{
		scanf("%d%d",&cow[i][0],&cow[i][1]);
		rank[i]=i;
	}
	qsort(rank,N,sizeof(rank[0]),cmp);
	for (i=1,j=0;i<K;i++)
	{
		if (cow[rank[i]][1]>cow[rank[j]][1])
			j=i;
	}
	printf("%d\n",rank[j]+1);
	return 0;
}
