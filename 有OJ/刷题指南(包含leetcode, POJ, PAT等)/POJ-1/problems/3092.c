#include<stdio.h>
unsigned int power2,power3;
int mod(int n)
{
	int i=0;
	power2=1;
	while (n%2==0)
	{
		n/=2;
		power2*=2;
		i++;
	}
	return i;
}
int term(unsigned int n)
{
	int i;
	power3=1;
	for (i=0;n>=power2*power3;i++)
		power3*=3;
	i--;
	power3/=3;
	return i;
}
int main()
{
	int T,t,i,j;
	unsigned int n;
	int p2[100],p3[100];
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		scanf("%u",&n);
		i=0;
		while (n!=0)
		{
			p2[i]=mod(n);
			p3[i]=term(n);
			i++;
			n-=power2*power3;
		}
		printf("%d %d",t,i);
		for (j=0;j<i;j++)
			printf(" [%d,%d]",p2[j],p3[j]);
		printf("\n");
	}
	return 0;
}
