#include<stdio.h>
int N,K;
int s,t,r;
int main()
{
	int i,j;
	scanf("%d%d",&N,&K);
	for (i=0;i<K;i++)
	{
		scanf("%d%d%d",&s,&t,&r);
		j=N/(s*t);
		j*=t+r;
		if (N%(s*t)==0)
			j-=r;
		else j+=(N%(s*t)-1)/s+1;
		printf("%d\n",j);
	}
	return 0;
}
