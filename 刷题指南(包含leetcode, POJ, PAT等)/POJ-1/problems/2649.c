#include<stdio.h>
#include<math.h>
int main ()
{
	int n,m,t,i,j,s,k;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		if (m==0)
			printf("%d does not divide %d!\n",m,n);
		else if (m<=n)
			printf("%d divides %d!\n",m,n);
		else{
			t=(int)sqrt((double)m);
			s=m;
			k=0;
			for (i=2;s>1 && i<=t;i++)
			{
				if (s%i==0)
				{
					j=1;
					s/=i;
					while (s%i==0)
					{
						s/=i;
						j++;
					}
					if (n/i<j)
					{
						k=1;
						break;
					}
				}
			}
			if (s==m)
				k=1;
			if (k==1)
				printf("%d does not divide %d!\n",m,n);
			else printf("%d divides %d!\n",m,n);
		}
	}
	return 0;
}
