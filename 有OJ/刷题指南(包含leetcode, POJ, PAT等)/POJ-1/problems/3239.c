#include<stdio.h>
int main()
{
	int n,k,i;
	while (scanf("%d",&n),n!=0)
	{
		if (n%6!=2 && n%6!=3)
		{
			for (i=2;i<=n;i+=2)
				printf("%d ",i);
			for (i=1;i<=n;i+=2)
				printf("%d ",i);
			putchar('\n');
		}
		else {
			if (n%2==0)
			{
				k=n/2;
				for (i=k;i<=n;i+=2)
					printf("%d ",i);
				if (k%2==0)
				{
					for (i=2;i<k;i+=2)
						printf("%d ",i);
					for (i=k+3;i<n;i+=2)
						printf("%d ",i);
					for (i=1;i<=k+1;i+=2)
						printf("%d ",i);
				}
				else {
					for (i=1;i<k;i+=2)
						printf("%d ",i);
					for (i=k+3;i<=n;i+=2)
						printf("%d ",i);
					for (i=2;i<=k+1;i+=2)
						printf("%d ",i);
				}
				putchar('\n');
			}
			else {
				k=(n-1)/2;
				for (i=k;i<n;i+=2)
					printf("%d ",i);
				if (k%2==0)
				{
					for (i=2;i<k;i+=2)
						printf("%d ",i);
					for (i=k+3;i<n;i+=2)
						printf("%d ",i);
					for (i=1;i<=k+1;i+=2)
						printf("%d ",i);
				}
				else {
					for (i=1;i<k;i+=2)
						printf("%d ",i);
					for (i=k+3;i<n;i+=2)
						printf("%d ",i);
					for (i=2;i<=k+1;i+=2)
						printf("%d ",i);
				}
				printf("%d\n",n);
			}
		}
	}
	return 0;
}
