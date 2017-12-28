#include <stdio.h>
int main()
{
	int n,i,s,t,r;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&s);
		t=1;
		r=s;
		while (r%2==0)
		{
			r/=2;
			t*=2;
		}
		printf("%d %d\n",s-t+1,s+t-1);
	}
	return 0;
}
