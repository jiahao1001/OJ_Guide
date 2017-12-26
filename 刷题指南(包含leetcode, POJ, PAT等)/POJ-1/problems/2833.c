#include<stdio.h>
int main()
{
	int b[11],s[11],n1,n2,n,i,j,t;
	__int64 p;
	double a;
	scanf("%d%d%d",&n1,&n2,&n);
	while (n1!=0 && n2!=0 && n!=0)
	{
		for (i=0;i<n1;i++)
		{
			scanf("%d",&b[i]);
			for (j=0;j<i;j++)
			{
				if (b[i]>b[j])
				{
					t=b[i];
					b[i]=b[j];
					b[j]=t;
				}
			}
		}
		for (i=1;i<=n2;i++)
		{
			scanf("%d",&s[i]);
			for (j=0;j<n1;j++)
			{
				if (s[i]>b[j])
				{
					t=s[i];
					s[i]=b[j];
					b[j]=t;
				}
			}
			for (j=1;j<i;j++)
			{
				if (s[i]>s[j])
				{
					t=s[i];
					s[i]=s[j];
					s[j]=t;
				}
			}
		}
		p=0;
		for (i=n1+n2;i<n;i++)
		{
			scanf("%d",&b[n1]);
			for (j=n1;j>0 && b[j]>b[j-1];j--)
			{
				t=b[j];
				b[j]=b[j-1];
				b[j-1]=t;
			}
			s[0]=b[n1];
			for (j=0;j<n2 && s[j]<s[j+1];j++)
			{
				t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
			}
			p+=s[0];
		}
		a=(double)p/(n-n1-n2);
		printf("%.6lf\n",a);
		scanf("%d%d%d",&n1,&n2,&n);
	}
	return 0;
}
