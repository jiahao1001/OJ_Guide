#include <stdio.h>
int main()
{
	int i,n,s;
	scanf("%d",&n);
	while (n!=0)
	{
		i=1;
		s=0;
		printf("%d ",n);
		while (n>0)
		{
			s+=i*i;
			n-=i;
			i++;
		}
		s+=(i-1)*n;
		printf("%d\n",s);
		scanf("%d",&n);
	}
	return 0;
}
