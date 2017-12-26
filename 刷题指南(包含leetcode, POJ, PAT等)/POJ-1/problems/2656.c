#include <stdio.h>
int main()
{
	int i,n,d,v,a,b;
	scanf("%d",&n);
	while (n!=0)
	{
		v=-1;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if (a+b>v)
			{
				v=a+b;
				d=i;
			}
		}
		if (v<9)
			printf("0\n");
		else printf("%d\n",d);
		scanf("%d",&n);
	}
	return 0;
}
