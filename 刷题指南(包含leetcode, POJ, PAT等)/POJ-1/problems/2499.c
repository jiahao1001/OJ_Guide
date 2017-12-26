#include<stdio.h>
int main()
{
	int n,i,a,b,x,y,t;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		x=0;
		y=0;
		while (a!=1 && b!=1)
		{
			if (a<b)
			{
				t=b/a;
				y+=t;
				b-=a*t;
			}
			else {
				t=a/b;
				x+=t;
				a-=b*t;
			}
		}
		if (a==1)
			y+=b-1;
		else x+=a-1;
		printf("Scenario #%d:\n%d %d\n\n",i,x,y);
	}
	return 0;
}
