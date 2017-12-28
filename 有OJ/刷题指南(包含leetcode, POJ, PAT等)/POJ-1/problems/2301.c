#include <stdio.h>
int main()
{
	int n,i,s,t;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&s,&t);
		if (s-t<0 || (s+t)%2==1)
			printf("impossible\n");
		else printf("%d %d\n",(s+t)/2,(s-t)/2);
	}
	return 0;
}
