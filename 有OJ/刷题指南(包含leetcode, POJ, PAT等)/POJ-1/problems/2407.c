#include<stdio.h>
int main()
{
	int m,euler,r,i,x;
	scanf("%d",&m);
	while (m!=0)
	{
		r=0;
		x=m;
		euler=m;
		if (x%2==0)
		{
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
				r=1;
				euler-=euler/i;
				do{
					x/=i;
				}while(x%i==0);
			}
		}
		if (r==0)
		{
			if (m!=1)
				euler--;
		}
		printf("%d\n",euler);
		scanf("%d",&m);
	}
	return 0;
}
