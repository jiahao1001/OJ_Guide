#include<stdio.h>
int main()
{
	int n,b,f,m,i,j,k,t,p[1000],x,y;
	scanf("%d",&m);
	for (i=0;i<m;i++)
	{
		scanf("%d%d%d",&n,&f,&b);
		x=0;
		for (j=0;j<n;j++)
		{
			scanf("%d%d",&p[j],&y);
			if (p[j]==0 && y==0 && b>0)
			{
				b--;
				y=1;
			}
			if (y==1)
			{
				if (f-p[j]>x)
					x=f-p[j];
				p[j]=2*f-p[j];
			}
		}
		t=b/n*2*f;
		b%=n;
		if (b!=0)
		{
			for (j=0;j<b;j++)
			{
				for (k=j+1;k<n;k++)
				{
					if (p[j]>p[k])
					{
						y=p[k];
						p[k]=p[j];
						p[j]=y;
					}
				}
			}
			t+=p[b-1]+f;
		}
		else t+=x;
		printf("%d\n",t);
	}
	return 0;
}
