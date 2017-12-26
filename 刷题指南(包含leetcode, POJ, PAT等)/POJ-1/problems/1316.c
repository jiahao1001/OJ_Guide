#include <stdio.h>
int main()
{
	int i=1,j,k,a[10036]={0};
	for (;i<10000;i++)
	{
		if (a[i]==0)
			printf("%d\n",i);
		j=i;
		k=i;
		while (j!=0)
		{
			k+=j%10;
			j/=10;
		}
		a[k]=1;
	}
	return 0;
}
