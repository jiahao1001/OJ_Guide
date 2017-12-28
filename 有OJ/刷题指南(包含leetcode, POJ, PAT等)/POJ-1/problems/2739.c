#include <stdio.h>
int main()
{
	int p[1229]={2,3},i,j,s=2,n,m;
	for (i=5;i<10000;i+=2)
	{
		for (j=1;j<s;j++)
			if (i%p[j]==0)
				break;
		if (j==s)
			p[s++]=i;
	}
	scanf("%d",&n);
	while (n!=0)
	{
		m=0;
		for (i=0,s=0,j=0;s<n;i++)
			s+=p[i];
		while (s>n)
			s-=p[j++];
		if (s==n)
			m++;
		for (;p[i]<=n;i++)
		{
			s+=p[i];
			while (s>n)
				s-=p[j++];
			if (s==n)
				m++;
		}
		printf("%d\n",m);
		scanf("%d",&n);
	}
	return 0;
}
