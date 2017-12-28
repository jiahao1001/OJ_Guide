#include<stdio.h>
int base(int p,int a,int b)
{
	int i,j=p,k,s=0;
	for (i=0,k=1;j>0;i++)
	{
		s+=j%a*k;
		j/=a;
		k=k*b;
	}
	if (s%p==0)
		return 1;
	return 0;
}
int main()
{
	int i,j,n,a,b,x,y;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&x,&y);
		for (j=y-1;j>x;j--)
		{
			if (base(j,a,b))
			{
				printf("%d\n",j);
				break;
			}
		}
		if (j==x)
			printf("Non-existent.\n");
	}
	return 0;
}
