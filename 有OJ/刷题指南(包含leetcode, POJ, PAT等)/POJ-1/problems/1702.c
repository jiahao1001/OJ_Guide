#include<stdio.h>
int pow[20]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,
			 4782969,14348907,43046721,129140163,387420489,1162261467};
int bit[20];
int mod(int w)
{
	int s=0;
	while (w>0)
	{
		bit[s]=w%3;
		w/=3;
		if (bit[s++]==2)
			w++;
	}
	return s;
}
int main()
{
	int T,t,w,i,j;
	scanf("%d",&T);
	for (t=0;t<T;t++)
	{
		scanf("%d",&w);
		j=mod(w);
		for (i=0;i<j;i++)
		{
			if (bit[i]==2)
			{
				printf("%d",pow[i]);
				break;
			}
		}
		if (i==j)
			printf("empty");
		else {
			for (i++;i<j;i++)
				if (bit[i]==2)
					printf(",%d",pow[i]);
		}
		putchar(' ');
		for (i=0;i<j;i++)
		{
			if (bit[i]==1)
			{
				printf("%d",pow[i]);
				break;
			}
		}
		if (i==j)
			printf("empty");
		else {
			for (i++;i<j;i++)
				if (bit[i]==1)
					printf(",%d",pow[i]);
		}
		putchar('\n');
	}
	return 0;
}
