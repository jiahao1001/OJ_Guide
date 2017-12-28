#include <stdio.h>
int main()
{
	int p[169]={1,2,3},i=5,j,q=3,n,c;
	while (i<1000)
	{
		j=2;
		while (2*p[j]<i)
		{
			if (i%p[j]==0)
				break;
			j++;
		}
		if (2*p[j]>i)
			p[q++]=i;
		i+=2;
	}
	while (scanf("%d%d",&n,&c)!=EOF)
	{
		printf("%d %d:",n,c);
		i=0;
		j=q-1;
		while (i<j)
		{
			if (p[(i+j)/2]>n)
				j=(i+j)/2-1;
			else if (p[(i+j)/2]<n)
				i=(i+j)/2+1;
			else {
				i=(i+j)/2;
				break;
			}
		}
		if (p[i]>n)
			i--;
		c=c*2-(i+1)%2;
		j=(0>(i+1-c)/2) ? 0 : (i+1-c)/2;
		for (i=j;i<j+c && p[i]<=n;i++)
			printf(" %d",p[i]);
		printf("\n\n");
	}
	return 0;
}
