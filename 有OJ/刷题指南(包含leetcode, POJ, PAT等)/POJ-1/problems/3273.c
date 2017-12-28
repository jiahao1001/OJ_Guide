#include<stdio.h>
#define MAX	100000
int Money[MAX],n,m;
int search(int p)
{
	int i,j=1,k=0;
	for (i=0;i<n;i++)
	{
		if (k+Money[i]>p)
		{
			k=Money[i];
			j++;
		}
		else k+=Money[i];
	}
	if (j>m)
		return 1;
	return 0;
}
int main()
{
	int i,min=0,max=0;
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++)
	{
		scanf("%d",&Money[i]);
		max+=Money[i];
		if (Money[i]>min)
			min=Money[i];
	}
	while (min<max)
	{
		i=(min+max)/2;
		if (search(i)==1)
			min=i+1;
		else max=i;
	}
	printf("%d\n",(min+max)/2);
	return 0;
}
