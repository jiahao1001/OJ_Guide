#include <stdio.h>
int pro(int p)
{
	int s=1;
	while (p!=1)
	{
		if (p%2==0)
			p=p>>1;
		else p=3*p+1;
		s++;
	}
	return s;
}
int main()
{
	int a,b,i,j,k;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d %d ",a,b);
		if (a>b)
		{
			i=b;
			b=a;
			a=i;
		}
		for (i=a,j=1;i<=b;i++)
		{
			k=pro(i);
			if (k>j)
				j=k;
		}
		printf("%d\n",j);
	}
	return 0;
}
