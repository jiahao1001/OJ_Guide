#include<stdio.h>
int prime(int p)
{
	int max=1,i=2;
	while (p!=1)
	{
		while (p%i==0)
		{
			max=i;
			p/=i;
		}
		i++;
	}
	return max;
}
int main()
{
	int n,i,j,m,num,max;
	scanf("%d",&n);
	scanf("%d",&m);
	max=prime(m);
	for (i=1;i<n;i++)
	{
		scanf("%d",&j);
		num=prime(j);
		if (num>max)
		{
			max=num;
			m=j;
		}
	}
	printf("%d\n",m);
	return 0;
}
