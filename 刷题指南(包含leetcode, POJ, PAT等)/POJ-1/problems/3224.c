#include <stdio.h>
int n;
int main()
{
	int i,j,k,s;
	int max=0,num;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		for (j=0,k=0;j<n;j++)
		{
			scanf("%d",&s);
			if (s==3)
				k++;
		}
		if (k>max)
		{
			max=k;
			num=i+1;
		}
	}
	printf("%d\n",num);
    return 0;
}
