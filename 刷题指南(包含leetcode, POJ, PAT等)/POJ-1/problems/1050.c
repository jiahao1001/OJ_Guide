#include<stdio.h>
int main()
{
	int n,i,j,k,l,max=0,t,r[100][100];
	scanf("%d",&n);
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d",&r[i][j]);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i;j++)
		{
			t=0;
			for (k=0;k<n;k++)
			{
				for (l=0;l<=i;l++)
					t+=r[l+j][k];
				if (t>max)
					max=t;
				if (t<0)
					t=0;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
