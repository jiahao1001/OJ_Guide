#include<stdio.h>
int n,m,k;
int length[100000];
int Accelerator(int time)
{
	int i,j,p;
	__int64 count=(__int64)time*m;
	for (i=0;i<n;i++)
	{
		if ((p=length[i]-time)<=0) continue;
		j=p/(k-1);
		p=p%(k-1);
		if (p>0) j++;
		if (j>time) return -1;
		count-=j;
	}
	if (count<0) return -1;
	if (count==0) return 0;
	return 1;
}
int main()
{
	int test,t,i;
	int high,low,mid;
	scanf("%d",&test);
	for (t=0;t<test;t++)
	{
		scanf("%d",&n);
		low=1;
		high=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&length[i]);
			if (length[i]>high)
				high=length[i];
		}
		scanf("%d%d",&m,&k);
		if (k==1)
		{
			printf("%d\n",high);
			continue;
		}
		while (low<high)
		{
			mid=(low+high)>>1;
			i=Accelerator(mid);
			if (i==-1)
				low=mid+1;
			else if (i==1)
				high=mid;
			else break;
		}
		printf("%d\n",(low+high)>>1);
	}
	return 0;
}
