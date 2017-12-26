#include <stdio.h>
#include <math.h>
int main()
{
	int n,m,i,j;
	double d;
	while (scanf("%d",&n)!=EOF)
	{
		d=(sqrt(8.0*n+1)-1)/2.0;
		m=(int)d;
		if (d!=(double)m)
			m++;
		j=n-m*(m-1)/2;
		if (m%2==0)
		{
			i=j;
			j=m+1-i;
		}
		else i=m+1-j;
		printf("TERM %d IS %d/%d\n",n,i,j);
	}
	return 0;
}
