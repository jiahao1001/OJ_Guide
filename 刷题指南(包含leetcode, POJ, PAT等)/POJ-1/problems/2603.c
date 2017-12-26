#include<stdio.h>
int prime[1229]={2,3},q=2,num[1229]={0};
void add(int p)
{
	int i;
	for (i=0;p>1;i++)
	{
		while (p%prime[i]==0)
		{
			p/=prime[i];
			num[i]++;
		}
	}
}
int main()
{
	int i,j;
	for (i=5;i<10000;i+=2)
	{
		for (j=1;j<q;j++)
			if (i%prime[j]==0)
				break;
		if (j==q)
			prime[q++]=i;
	}
	for (i=0;i<10;i++)
	{
		scanf("%d",&j);
		add(j);
	}
	for (i=0,j=1;i<1229;i++)
		j*=(num[i]+1);
	printf("%d\n",j%10);
	return 0;
}
