#include<stdio.h>
int main()
{
	int i,n,m,s;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		s=0;
		scanf("%d",&m);
		while (m)
		{
			m/=5;
			s+=m;
		}
		printf("%d\n",s);
	}
	return 0;
}
