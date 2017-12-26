#include<stdio.h>
int main()
{
	int i,m,n,a,b;
	scanf("%d%d",&m,&n);
	while (m!=0 && n!=0)
	{
		a=m>n ? m:n;
		b=m>n ? n:m;
		for (i=1;a%b!=0;i=1-i)
		{
			if (a/b>1)
				break;
			n=b;
			b=a%b;
			a=n;
		}
		if (i==1)
			printf("Stan wins\n");
		else printf("Ollie wins\n");
		scanf("%d%d",&m,&n);
	}
	return 0;
}
