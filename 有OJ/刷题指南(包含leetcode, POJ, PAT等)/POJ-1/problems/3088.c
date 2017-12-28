#include<stdio.h>
int jc[12]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800};
unsigned int g[12]={1,1,3},f[12];
int zuhe(int i,int j)
{
	return jc[j]/jc[i]/jc[j-i];
}
int main()
{
	int i,j,n;
	for (i=3;i<12;i++)
	{
		g[i]=0;
		for (j=0;j<i;j++)
			g[i]+=g[j]*zuhe(j,i);
	}
	for (i=1;i<12;i++)
	{
		f[i]=0;
		for (j=1;j<=i;j++)
			f[i]+=g[j]*zuhe(j,i);
	}
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&j);
		printf("%d %d %u\n",i,j,f[j]);
	}
	return 0;
}
