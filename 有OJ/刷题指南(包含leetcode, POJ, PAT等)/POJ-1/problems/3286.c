#include<stdio.h>
__int64 cal(__int64 p)
{
	__int64 q=p/10+1,r,s;
	int digi[20],i,j,k;
	for (i=0;p>0;i++)
	{
		digi[i]=p%10;
		p/=10;
	}
	for (j=1;j<i-1;j++)
	{
		for (k=i-1,r=0;k>j;k--)
		{
			r*=10;
			r+=digi[k];
		}
		for (k=0,s=1;k<j;k++)
			s*=10;
		if (digi[j]==0)
		{
			for (k=j-1;k>=0;k--)
			{
				r*=10;
				r+=digi[k];
			}
			q+=r-s+1;
		}
		else q+=r*s;
	}
	return q;
}
int main()
{
	__int64 p,a,b;
	while (scanf("%I64d%I64d",&a,&b),a!=-1 || b!=-1)
	{
		p=cal(b);
		if (a!=0)
			p-=cal(a-1);
		printf("%I64d\n",p);
	}
	return 0;
}
