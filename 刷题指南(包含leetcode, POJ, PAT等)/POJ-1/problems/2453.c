#include<stdio.h>
int main()
{
	int i,j,k,l;
	char b[21]={0};
	scanf("%d",&i);
	while (i)
	{
		for (j=0;i;j++)
		{
			b[j]=i%2;
			i/=2;
		}
		k=0;
		for (i=0;i<j;i++)
		{
			if (b[i]==1)
			{
				k++;
				if (b[i+1]==0)
					break;
			}
		}
		b[i+1]=1;
		k--;
		for (l=0;l<k;l++)
			b[l]=1;
		while (l<=i)
			b[l++]=0;
		for (l=j,k=0;l>=0;l--)
		{
			k*=2;
			k+=b[l];
			b[l]=0;
		}
		printf("%d\n",k);
		scanf("%d",&i);
	}
	return 0;
}
