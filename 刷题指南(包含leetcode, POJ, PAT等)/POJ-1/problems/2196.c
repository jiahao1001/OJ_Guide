#include <stdio.h>
int main()
{
	int i,j,x,y;
	for (i=2992;i<10000;i++)
	{
		x=0;
		j=i;
		while(j)
		{
			x+=j%10;
			j/=10;
		}
		y=0;
		j=i;
		while(j)
		{
			y+=j%12;
			j/=12;
		}
		if (x!=y)
			continue;
		y=0;
		j=i;
		while(j)
		{
			y+=j%16;
			j/=16;
		}
		if (x==y)
			printf("%d\n",i);
	}
	return 0;
}
