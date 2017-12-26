#include<stdio.h>
int main()
{
	int s[1000],n,i,j,c;
	scanf("%d",&n);
	while (n!=0)
	{
		scanf("%d",&s[0]);
		while (s[0]!=0)
		{
			for (i=1;i<n;i++)
				scanf("%d",&s[i]);
			for (i=0;i<n;i++)
			{
				c=s[i];
				for (j=i+1;j<n;j++)
				{
					if (s[j]>s[i])
						continue;
					if (c>s[j])
						c=s[j];
					else break;
				}
				if (j<n)
					break;
			}
			if (i<n)
				printf("No\n");
			else printf("Yes\n");
			scanf("%d",&s[0]);
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
