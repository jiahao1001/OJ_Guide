#include<stdio.h>
int main()
{
	__int64 num;
	int d,n,i,j,k;
	scanf("%d%d",&d,&n);
	while (d!=0 || n!=0)
	{
		num=0;
		for (i=1,k=n;i<=k;i++)
		{
			j=d/i;
			if (d%i!=0)
				j++;
			if (j!=i)
				num+=j;
			if (k>=j)
			{
				num+=(k-j+1)*i;
				k=j-1;
			}
		}
		printf("%I64d\n",num);
		scanf("%d%d",&d,&n);
	}
	return 0;
}
