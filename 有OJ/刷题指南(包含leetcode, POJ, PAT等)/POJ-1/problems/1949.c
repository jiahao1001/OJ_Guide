#include<stdio.h>
int n,max,m=0;
int time[10001]={0};
int main()
{
	int i,j,k,l,chore;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&chore,&k);
		for (j=0,max=0;j<k;j++)
		{
			scanf("%d",&l);
			if (time[l]>max)
				max=time[l];
		}
		time[i]+=chore+max;
		if (time[i]>m)
			m=time[i];
	}
	printf("%d\n",m);
	return 0;
}
