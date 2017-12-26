#include <stdio.h>
int main()
{
	int a,b,c,n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==2)
		{
			scanf("%d%d%d",&a,&b,&c);
			if (b*b>=4*a*c)
				printf("NO\n");
			else printf("YES\n");
		}
		else {
			if (n>2)
				printf("NO\n");
			else printf("YES\n");
			while (n>=0)
			{
				scanf("%d",&a);
				n--;
			}
		}
	}
	return 0;
}
