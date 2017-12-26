#include <stdio.h>
int main()
{
	int n,m,i,j,t,a[50000],b[50000],s,x,y;
	short p[50000];
	scanf("%d",&m);
	for (j=0;j<m;j++)
	{
		x=-10001;
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
			if (p[i]>x)
			{
				y=x;
				x=p[i];
			}
			else if (p[i]>y)
				y=p[i];
		}
		s=-10001;
		t=0;
		for (i=0;i<n;i++)
		{
			t+=p[i];
			if (t>s)
				s=t;
			if (t<0)
				t=0;
			a[i]=s;
		}
		s=-10001;
		t=0;
		b[n-1]=0;
		for (i=n-1;i>0;i--)
		{
			t+=p[i];
			if (t>s)
				s=t;
			if (t<0)
				t=0;
			b[i-1]=s;
		}
		s=-10001;
		for (i=0;i<n;i++)
		{
			if (a[i]+b[i]>s)
				s=a[i]+b[i];
		}
		if (s==x)
			s+=y;
		printf("%d\n",s);
	}
	return 0;
}
