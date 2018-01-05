#include<stdio.h>
int prime[10001];
int primeSize;
bool mark[10001];
void init()
{
	primeSize = 0;
	for(int i=1;i<=10000;i++)
		mark[i] = false;
	for(i=2;i<=10000;i++)
	{
		if(mark[i]==true)
			continue;
		prime[primeSize++] = i;
		for(int j=i*i;j<10000;j+=i)
			mark[j] = true;
	}
}
int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ansPrime[30];
		int ansSize = 0;
		int ansNum[30];
		for(int i=0;i<primeSize;i++)
		{
			if(n%prime[i]==0)
			{
				ansPrime[ansSize] = prime[i];
				ansNum[ansSize] = 0;
				while(n%prime[i]==0)
				{
					ansNum[ansSize]++;
					n /= prime[i];
				}
				ansSize++;
				//必须在break之前
				if(n ==1) break;
				//直到分解成1为止
			}	
		}
		if(n!=1)
		{
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;
		}
		int ans = 0;
		for(i=0;i<ansSize;i++)
			ans += ansNum[i];
		printf("%d\n",ans);
		/*
		for(i=0;i<ansSize;i++)
			printf("%d^%d ",ansPrime[i],ansNum[i]);
		*/
	}
	return 0;
}