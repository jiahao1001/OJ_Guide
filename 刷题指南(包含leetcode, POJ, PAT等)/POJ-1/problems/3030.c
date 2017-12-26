#include<stdio.h>
int main()
{
	int i,n,a,b,c;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		a+=c;
		if (a==b)
			printf("does not matter\n");
		else if (a<b)
			printf("advertise\n");
		else printf("do not advertise\n");
	}
	return 0;
}
