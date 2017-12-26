#include<stdio.h>
int main()
{
	int f[9999],n,i,j,x=1,y,z;
	scanf("%d%d",&n,&f[0]);
	y=n-1;
	for (i=1;i<n;i++)
	{
		scanf("%d",&z);
		if (z>f[0])
			f[y--]=z;
		else f[x++]=z;
	}
	z=n/2+1;
	if (x==z)
		printf("%d\n",f[0]);
	else if (x>z)
	{
		for (i=1;i<=x-z;i++)
		{
			for (j=i+1;j<x;j++)
			{
				if (f[i]<f[j])
				{
					y=f[i];
					f[i]=f[j];
					f[j]=y;
				}
			}
		}
		printf("%d\n",f[i-1]);
	}
	else {
		for (i=x;i<z;i++)
		{
			for (j=i+1;j<n;j++)
			{
				if (f[i]>f[j])
				{
					y=f[i];
					f[i]=f[j];
					f[j]=y;
				}
			}
		}
		printf("%d\n",f[i-1]);
	}
	return 0;
}
