#include<stdio.h>
int Hprime[110000]={0},q=0;
bool HSprime[1000002]={false};
void hprime()
{
	int i,j,k;
	bool prime[200016]={false};
	for (i=5;i<450;i+=4)
	{
		if (prime[i]==true)
			continue;
		k=4*i;
		for (j=i*i;j<200016;j+=k)
			prime[j]=true;
	}
	for (i=5;i<200016;i+=4)
	{
		if (prime[i]==false)
			Hprime[q++]=i;
	}
}
void hsprime()
{
	int i,j,k;
	bool HSprime[250002]={false};
	for (i=0;i<152;i++)
	{
		k=1000001/Hprime[i];
		for (j=i;Hprime[j]<=k;j++)
			HSprime[(Hprime[i]*Hprime[j]-1)>>2]=true;
	}
	for (i=6,q=0;i<250002;i++)
	{
		if (HSprime[i]==true)
			Hprime[q++]=(i<<2)+1;
	}
}
int main()
{
	int n,i;
	hprime();
	hsprime();
	while (scanf("%d",&n),n!=0)
	{
		for (i=0;i<q;i++)
			if (Hprime[i]>n)
				break;
		printf("%d %d\n",n,i);
	}
	return 0;
}
