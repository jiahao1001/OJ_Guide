#include<stdio.h>
int main()
{
	int i,n,a,b,x,y;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&x,&y);
		a=(a+b)%2;
		x=(x+y)%2;
		if (a==x)
			a=0;
		else a=1;
		printf("Scenario #%d:\n%d\n\n",i,a);
	}
	return 0;
}
