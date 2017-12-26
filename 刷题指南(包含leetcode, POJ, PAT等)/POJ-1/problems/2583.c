#include <stdio.h>
int main()
{
	int a,b,c,x,y,z;
	while (scanf("%d%d%d",&c,&a,&b)!=EOF)
	{
		a=(b+c)/2-a;
		b=(b-c)/2-2*a;
		x=9*a+3*b+c;
		y=x+7*a+b;
		z=y+9*a+b;
		printf("%d %d %d\n",x,y,z);
	}
	return 0;
}
