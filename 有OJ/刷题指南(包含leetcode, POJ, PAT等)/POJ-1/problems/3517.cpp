#include<stdio.h>
int n,k,m;
int main()
{
	int i,j;
	while (scanf("%d%d%d",&n,&k,&m),n!=0 || k!=0 || m!=0) 
	{
		for (i=2,j=0;i<n;i++)
		{
			j=(j+k)%i;
		}
		j=(j+m)%n+1;
		printf("%d\n",j);
	}
	return 0;
}
