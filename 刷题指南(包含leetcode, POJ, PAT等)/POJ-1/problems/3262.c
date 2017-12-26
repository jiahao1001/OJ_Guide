#include<stdio.h>
#include<stdlib.h>
#define COW	100000
int t[COW],d[COW],sort[COW];
int cmp(const void *a, const void *b)
{
	int x=*(int *)a;
	int y=*(int *)b;
	int z=t[x]*d[y]-t[y]*d[x];
	if (z<0)
		return -1;
	else if (z==0)
		return 0;
	else return 1;
}
int main()
{
	int n,i,j,sum=0;
	__int64 max=0;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		sort[i]=i;
		scanf("%d%d",&t[i],&d[i]);
		sum+=d[i];
	}
	qsort(sort,n,sizeof(sort[0]),cmp);
	for (i=0;i<n;i++)
	{
		j=sort[i];
		sum-=d[j];
		max+=(t[j]+t[j])*sum;
	}
	printf("%I64d\n",max);
	return 0;
}
