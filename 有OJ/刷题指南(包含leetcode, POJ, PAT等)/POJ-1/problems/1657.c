#include<stdio.h>
int main()
{
 	int a,b,c,d,i,n,x,y;
	char s[3],t[3];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%s%s",s,t);
		if (s[0]>t[0])
			x=s[0]-t[0];
		else x=t[0]-s[0];
		if (s[1]>t[1])
			y=s[1]-t[1];
		else y=t[1]-s[1];
		a=(x>y) ? x : y;
		if (x==0 && y==0)
		{
			b=0;
			c=0;
			d=0;
		}
		else {
			if ((x+y)%2!=0)
			{
				d=-1;
				b=2;
			}
			else if (x==y)
			{
				d=1;
				b=1;
			}
			else {
				d=2;
				b=2;
			}
			if (x==0 || y==0)
			{
				c=1;
				b=1;
			}
			else c=2;
		}
		printf("%d %d %d ",a,b,c);
		if (d==-1)
			printf("Inf\n");
		else printf("%d\n",d);
	}
 	return 0;
}
