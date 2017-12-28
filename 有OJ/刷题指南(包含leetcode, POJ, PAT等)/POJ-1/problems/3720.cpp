#include<stdio.h>
int n,k;
int digit[101][10]={0};
void cal(int p)
{
	int temp[10]={0};
	int mod[100]={0,1};
	int i=1;
	while (1)
	{
		i*=10;
		temp[i/p]++;
		if (i%p==0 || mod[i%p]==1)
			break;
		mod[i%p]=1;
		i-=i/p*p;
	}
	for (i=0;i<10;i++)
		digit[p][i]=digit[p-1][i]+temp[i];
}
int main()
{
	int i;
	for (i=2;i<=100;i++)
		cal(i);
	while (scanf("%d%d",&n,&k)!=EOF)
		printf("%d\n",digit[n][k]);
	return 0;
}
