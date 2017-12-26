#include <stdio.h>
int main()
{
	int t,n,k,i,j,a[100],c;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d%d",&n,&k);
		if (n>k)
			printf("0");
		else if (n==1)
			printf("%d",k);
		else {
			a[0]=k/n;
			c=k%n*10+a[0];
			j=1;
			while (j<100)
			{
				a[j]=c/n;
				if (a[j]==k && c%n==0)
					break;
				c=c%n*10+a[j];
				j++;
			}
			for (k=0;k<=j;k++)
				printf("%d",a[k]);
		}
		printf("\n");
	}
	return 0;
}
