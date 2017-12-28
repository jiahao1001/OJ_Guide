#include<stdio.h>
int main()
{
	int n,i,j,k,a,b,s,r=2,x[200],y[200];
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			s=2;
			a=x[j]-x[i];
			b=y[j]-y[i];
			for (k=j+1;k<n;k++)
				if (b*(x[k]-x[i])==a*(y[k]-y[i]))
					s++;
			if (s>r)
				r=s;
		}
	}
	printf("%d\n",r);
	return 0;
}
