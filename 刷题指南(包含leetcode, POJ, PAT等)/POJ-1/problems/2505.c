#include<stdio.h>
int main()
{
	int i,a[2]={2,9};
	unsigned n;
	while (scanf("%d",&n)!=EOF)
	{
		for (i=1;n!=1;i=1-i)
		{
			if (n%a[i]==0)
				n/=a[i];
			else n=n/a[i]+1;
		}
		if (i==0)
			printf("Stan wins.\n");
		else printf("Ollie wins.\n");
	}
	return 0;
}
