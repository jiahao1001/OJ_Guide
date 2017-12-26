#include <stdio.h>
int main()
{
	int n,i,j,a[4],x,y;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		for (j=0;j<4;j++)
		{
			scanf("%d",&a[j]);
			printf("%d ",a[j]);
		}
		x=a[1]-a[0];
		y=a[1]/a[0];
		if (x==a[2]-a[1] && x==a[3]-a[2])
			printf("%d\n",a[3]+x);
		else printf("%d\n",a[3]*y);
	}
	return 0;
}
