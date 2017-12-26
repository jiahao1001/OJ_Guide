#include <stdio.h>
int main()
{
	int n,m,p,c;
	scanf("%d%d%d%d",&n,&m,&p,&c);
	while (n!=0 || m!=0 || p!=0 || c!=0)
	{
		printf("%d\n",p+n-m);
		scanf("%d%d%d%d",&n,&m,&p,&c);
	}
	return 0;
}
