#include<stdio.h>
int main()
{
	int m,k,f[10],euler,r,i,j,t,x,n;
	while (scanf("%d%d",&m,&k)!=EOF)
	{
		x=m;
		euler=m;
		if (x%2==0)
		{
			f[0]=2;
			euler/=2;
			do{
				x/=2;
			}while(x%2==0);
			r=1;
		}
		else r=0;
		for (i=3;x>1;i+=2)
		{
			if (x%i==0)
			{
				f[r++]=i;
				euler-=euler/i;
				do{
					x/=i;
				}while(x%i==0);
			}
		}
		if (r==0)
		{
			f[r++]=m;
			if (m!=1)
				euler--;
		}
		n=k/euler*m;
		k%=euler;
		if (k==0)
		{
			k=euler;
			n-=m;
		}
		t=1;
		for (i=1;i<k;i++)
		{
			t++;
			while (1)
			{
				for (j=0;j<r;j++)
				{
					if (t%f[j]==0)
						break;
				}
				if (j==r)
					break;
				t++;
			}
		}
		printf("%d\n",n+t);
	}
	return 0;
}
