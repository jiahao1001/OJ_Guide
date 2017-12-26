#include<stdio.h>
int main()
{
	int i,j,t,T,n,p,x,y;
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		scanf("%d",&n);
		x=((n+n)+1)/3;
		printf("%d %d %d\n",t,n,x);
		if (n%3==2)
			n--;
		p=0;
		for (i=n-x/2+1,j=x;i<=n;i++,j--)
		{
			printf("[%d,%d]",i,j);
			p++;
			if (p%8==0)
				printf("\n");
			else printf(" ");
		}
		y=x-x/2;
		for (i=y,j=y;j>=1;i++,j--)
		{
			printf("[%d,%d]",i,j);
			p++;
			if (p%8==0 || p==x)
				printf("\n");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
