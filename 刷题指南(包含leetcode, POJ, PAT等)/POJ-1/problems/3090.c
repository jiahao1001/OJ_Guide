#include<stdio.h>
int eulerphi(int m)//1~n中与n互质的数的个数
{
	int euler=m,i;
	if (m%2==0)
	{
		euler/=2;
		do{
			m/=2;
		}while(m%2==0);
	}
	for (i=3;m>1;i+=2)
	{
		if (m%i==0)
		{
			euler-=euler/i;
			do{
				m/=i;
			}while(m%i==0);
		}
	}
	return euler;
}
int main()
{
	int i,n,m,E[1001]={0};
	for (i=1;i<1000;i++)
	{
		E[i+1]=E[i]+eulerphi(i+1);
		E[i]+=E[i]+3;
	}
	E[1000]+=E[1000]+3;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&m);
		printf("%d %d %d\n",i,m,E[m]);
	}
	return 0;
}
