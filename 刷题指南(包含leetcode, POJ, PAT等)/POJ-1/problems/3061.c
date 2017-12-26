#include<stdio.h>
int n,S,sum,min;
short sen[100000];
int main()
{
	int i,j,k,t;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d%d",&n,&S);
		for (j=0,k=0;j<n;j++)
		{
			scanf("%d",&sen[j]);
			k+=sen[j];
		}
		if (S>k)
			printf("0\n");
		else if (S==k)
			printf("%d\n",n);
		else{
			j=0;
			k=0;
			sum=0;
			min=n;
			while (k<n)
			{
				while (sum<S)
					sum+=sen[k++];
				while (sum-sen[j]>=S)
					sum-=sen[j++];
				if (k-j<min)
					min=k-j;
				sum-=sen[j++];
			}
			printf("%d\n",min);
		}
	}
	return 0;
}
