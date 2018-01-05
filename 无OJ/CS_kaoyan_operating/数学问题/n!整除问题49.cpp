#include<stdio.h>
int prime[1001];
int primeSize;
bool mark[1001];
void init()
{
	primeSize = 0;
	for(int i=1;i<=1000;i++)
		mark[i] = false;
	for(i=2;i<=1000;i++)
	{
		if(mark[i]==true)
			continue;
		prime[primeSize++] = i;
		for(int j=i*i;j<1000;j+=i)
			mark[j] = true;
	}
}
int main()
{
	init();
	int cnt[1010],cnt2[1010];
	//要注意cnt的空间和前面prime的大小关系，不能差太大
	int n,a;
	while(scanf("%d %d",&n,&a)!=EOF)
	{ 
		for(int i=0;i<primeSize;i++)
			cnt[i] = cnt2[i] = 0;
		for(i=0;i<primeSize;i++)
		{
			int t = n;
			while(t)
			{
				cnt[i] += t/prime[i];
				t = t/prime[i];
			}
		}
		int ans = 12312123;
		for(i=0;i<primeSize;i++)
		{
			while(a%prime[i]==0)
			{
				cnt2[i]++;
				a = a/prime[i];
			}
			if(cnt2[i]==0) continue;
			//a不能分解出该素数，就直接跳过
			if(cnt[i]/cnt2[i] < ans)
				ans = cnt[i]/cnt2[i]; 
		}
		printf("%d\n",ans);
	}
	return 0;
}