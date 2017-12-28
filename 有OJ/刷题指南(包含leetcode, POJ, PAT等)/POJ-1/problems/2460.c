#include<stdio.h>
int x[200000],y[200000];
int main()
{
	int n,i,j,k,a,b;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);
		a=x[n/2];
		b=y[n/2];
		for (i=0,j=0,k=0;i<n;i++)
		{
			if ((x[i]>a && y[i]>b) || (x[i]<a && y[i]<b))
				j++;
			else if ((x[i]>a && y[i]<b) || (x[i]<a && y[i]>b))
				k++;
		}
		printf("%d %d\n",j,k);
		scanf("%d",&n);
	}
	return 0;
}
