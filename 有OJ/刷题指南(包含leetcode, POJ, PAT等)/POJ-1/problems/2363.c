#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k,m,p,q,s,c[10]={1,8,27,64,125,216,343,512,729,1000};
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&m);
		for (j=0;c[j]<=m;j++);
		if (m==0)
			printf("0\n");
		s=10000;
		while (j)
		{
			if (m%j==0)
			{
				p=m/j;
				for (k=(int)sqrt((double)p);k>0;k--)
				{
					if (p%k==0)
					{
						q=p*2+2*j*k+2*j*p/k;
						s=s>q ? q:s;
					}
				}
			}
			j--;
		}
		printf("%d\n",s);
	}
	return 0;
}
