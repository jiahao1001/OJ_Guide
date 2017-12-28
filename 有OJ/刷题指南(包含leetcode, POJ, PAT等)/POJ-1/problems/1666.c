#include<stdio.h>
int n,candy[500];
int round()
{
	int i,k=candy[n-1]>>1,l;
	for (i=0;i<n;i++)
	{
		l=candy[i]>>1;
		candy[i]=l+k;
		if (candy[i]%2==1)
			candy[i]++;
		k=l;
	}
	k=candy[0];
	for (i=1;i<n;i++)
		if (candy[i]!=k)
			return 0;
	return 1;
}
int main()
{
	int i;
	while (scanf("%d",&n),n!=-0)
	{
		for (i=0;i<n;i++)
			scanf("%d",&candy[i]);
		i=1;
		while (round()==0)
			i++;
		printf("%d %d\n",i,candy[0]);
	}
	return 0;
}
