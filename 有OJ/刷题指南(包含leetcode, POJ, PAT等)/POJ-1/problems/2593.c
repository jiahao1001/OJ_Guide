#include <stdio.h>
int main()
{
	int n,max,min,p,q,i,a,b,c;
	scanf("%d",&n);
	while (n!=0)
	{
		p=0;
		q=0;
		max=-1001;
		min=0;
		b=-1001;
		c=-1001;
		for (i=0;i<n;i++)
		{
			scanf("%d",&a);
			if (a>b)
			{
				c=b;
				b=a;
			}
			else if (a>c)
				c=a;
			p+=a;
			q+=a;
			if (q>0)
				q=0;
			if (q<min)
				min=q;
			if (p-min>max)
				max=p-min;
			if (p<=min)
			{
				p=0;
				q=0;
				min=0;
			}
		}
		if (max==0 || max==b)
			max=b+c;
		printf("%d\n",max);
		scanf("%d",&n);
	}
	return 0;
}
