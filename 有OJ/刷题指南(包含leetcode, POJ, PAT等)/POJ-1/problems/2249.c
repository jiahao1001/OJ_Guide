#include<stdio.h>
int main()
{
	int n,k,i,j;
	__int64 t;
	scanf("%d%d",&n,&k);
	while (n!=0)
	{
		if (k>n-k)
			k=n-k;
		for (t=1,i=n-k+1,j=1;i<=n;i++,j++)
		{
			t*=i;
			t/=j;
		}
		printf("%I64d\n",t);
		scanf("%d%d",&n,&k);
	}
	return 0;
}
