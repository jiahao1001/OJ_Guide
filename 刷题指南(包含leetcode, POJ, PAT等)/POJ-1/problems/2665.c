#include <stdio.h>
int main()
{
	int l,m,i,a,b;
	scanf("%d%d",&l,&m);
	while (l!=0 || m!=0)
	{
		l++;
		for (i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			l-=(b-a+1);
		}
		printf("%d\n",l);
		scanf("%d%d",&l,&m);
	}
	return 0;
}
